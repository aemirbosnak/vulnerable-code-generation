//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <sys/time.h>

#define BUFF_SIZE 1024
#define URL "https://example.com"

static size_t download_callback(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    (void)userdata;
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    struct timeval start, end;
    double time_taken;
    char *buffer;

    // Initialize CURL
    curl = curl_easy_init();
    if (curl == NULL)
    {
        fprintf(stderr, "Error initializing CURL\n");
        return EXIT_FAILURE;
    }

    // Set URL
    curl_easy_setopt(curl, CURLOPT_URL, URL);

    // Allocate memory for data
    buffer = malloc(BUFF_SIZE);
    if (buffer == NULL)
    {
        fprintf(stderr, "Error allocating memory for data\n");
        return EXIT_FAILURE;
    }

    // Set callback function for data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, download_callback);

    // Set data buffer
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

    // Start the timer
    gettimeofday(&start, NULL);

    // Perform the download
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        fprintf(stderr, "Error performing download: %s\n", curl_easy_strerror(res));
        return EXIT_FAILURE;
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate time taken
    time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    // Print the download speed in Kb/s
    printf("Download speed: %.2f Kb/s\n", BUFF_SIZE * 8 / 1024 / time_taken);

    // Cleanup
    curl_easy_cleanup(curl);
    free(buffer);
    return EXIT_SUCCESS;
}