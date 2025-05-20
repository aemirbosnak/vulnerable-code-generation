//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

// Function to write data to a file
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    FILE* file = (FILE*)userp;
    return fwrite(contents, size, nmemb, file);
}

// Function to handle progress updates
int ProgressCallback(void* clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    printf("\rDownload progress: %ld bytes of %ld (%d%%)", dlnow, dltotal, (int)(dlnow * 100 / dltotal));
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    // Initialize curl
    CURL* curl = curl_easy_init();
    if (!curl)
    {
        printf("Error initializing curl\n");
        return 1;
    }

    // Set URL to download
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // Set file to write download to
    FILE* file = fopen("download.txt", "wb");
    if (!file)
    {
        printf("Error opening file for writing\n");
        return 1;
    }

    // Set write callback function
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Set progress callback function
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, file);

    // Perform download
    CURLcode res = curl_easy_perform(curl);
    if (res!= CURLE_OK)
    {
        printf("Error downloading URL: %s\n", curl_easy_strerror(res));
        return 1;
    }

    // Close file and curl
    fclose(file);
    curl_easy_cleanup(curl);

    printf("\nDownload complete!\n");
    return 0;
}