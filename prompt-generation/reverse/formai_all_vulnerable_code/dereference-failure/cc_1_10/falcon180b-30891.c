//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((char*)userp)[(size_t)strlen((char*)userp) + size * nmemb - 1] = '\0';
    return size * nmemb;
}

int main() {
    CURL* curl;
    FILE* file;
    char* url;
    char* output;
    int response_code;
    time_t start_time;
    time_t end_time;
    double elapsed_time;
    struct tm* time_info;

    // Initialize cURL
    curl = curl_easy_init();
    if(curl == NULL) {
        fprintf(stderr, "curl_easy_init() failed\n");
        exit(1);
    }

    // Set cURL options
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);

    // Perform request
    curl_easy_perform(curl);

    // Get response code
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    // Close cURL
    curl_easy_cleanup(curl);

    // Open file for writing
    file = fopen("uptime.log", "a");
    if(file == NULL) {
        fprintf(stderr, "fopen() failed\n");
        exit(1);
    }

    // Get current time
    time(&start_time);

    // Convert start time to human-readable format
    time_info = localtime(&start_time);
    strftime(output, strlen(output), "%Y-%m-%d %H:%M:%S", time_info);

    // Write data to file
    fprintf(file, "Website is up at %s\n", output);

    // Close file
    fclose(file);

    // Calculate elapsed time
    time(&end_time);
    elapsed_time = difftime(end_time, start_time);

    // Print elapsed time
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}