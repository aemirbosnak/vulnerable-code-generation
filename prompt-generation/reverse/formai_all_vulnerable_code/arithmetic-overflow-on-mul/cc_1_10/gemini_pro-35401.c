//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <curl/curl.h>

#define URL "https://www.google.com"

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    struct timeval start, end;
    double diff;

    // Initialize the CURL handle.
    curl = curl_easy_init();
    if (curl == NULL) {
        printf("Error: Could not initialize the CURL handle.\n");
        return EXIT_FAILURE;
    }

    // Set the URL to fetch.
    curl_easy_setopt(curl, CURLOPT_URL, URL);

    // Set the write callback.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    // Set the header list.
    headers = curl_slist_append(headers, "Accept: text/html");
    headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.61 Safari/537.36");
    headers = curl_slist_append(headers, "Cache-Control: no-cache");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Get the start time.
    gettimeofday(&start, NULL);

    // Perform the request.
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        printf("Error: Could not perform the request (%s).\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        return EXIT_FAILURE;
    }

    // Get the end time.
    gettimeofday(&end, NULL);

    // Calculate the time difference.
    diff = ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec);

    // Print the results.
    printf("Time: %f ms\n", diff / 1000);

    // Clean up.
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    return EXIT_SUCCESS;
}