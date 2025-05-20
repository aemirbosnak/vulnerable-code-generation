//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Function to write data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Function to handle response data
size_t handle_response_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    FILE *file = (FILE*)userp;
    return fwrite(ptr, size, nmemb, file);
}

int main() {
    CURL *curl;
    CURLcode res;
    FILE *file;

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    // Set the URL to fetch
    char url[] = "https://jsonplaceholder.typicode.com/posts";

    // Open a file to write the response data
    file = fopen("response.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Set the callback function to handle response data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Perform the fetch
    res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Fetch failed: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    // Close the file
    fclose(file);

    // Cleanup curl
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}