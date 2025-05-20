//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function for writing response data to a file
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    FILE *file = (FILE *)userp;
    return fwrite(contents, realsize, 1, file);
}

// Callback function for handling progress updates
int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    int id = *((int *)clientp);
    double progress = ((double)dlnow / (double)dltotal) * 100.0;
    printf("Thread %d: Download progress: %.2f%%\n", id, progress);
    return 0;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    FILE *file;
    int id;

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Create a new curl handle
    curl = curl_easy_init();

    // Set the URL to download
    if(argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // Set the output file
    file = fopen("output.txt", "wb");
    if(file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Set the progress callback function
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &id);

    // Perform the download
    res = curl_easy_perform(curl);
    if(res!= CURLE_OK) {
        printf("Download failed: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    // Clean up
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    fclose(file);

    return 0;
}