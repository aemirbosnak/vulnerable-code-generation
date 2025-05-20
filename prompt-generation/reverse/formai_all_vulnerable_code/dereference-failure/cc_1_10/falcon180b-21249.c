//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    FILE* file = (FILE*)userp;
    return fwrite(contents, realsize, 1, file);
}

void progress_callback(void* clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    double progress = ((double)dlnow / (double)dltotal) * 100.0;
    printf("\rDownload progress: %.2f%%", progress);
}

int main()
{
    CURL* curl = curl_easy_init();
    if (curl == NULL) {
        printf("Error initializing curl\n");
        exit(1);
    }

    char* url = "ftp://example.com/file.txt";
    FILE* file = fopen("file.txt", "wb");
    if (file == NULL) {
        printf("Error creating file\n");
        exit(1);
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);

    CURLcode res = curl_easy_perform(curl);
    if (res!= CURLE_OK) {
        printf("Error downloading file: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    fclose(file);
    curl_easy_cleanup(curl);

    printf("\nDownload complete!\n");
    return 0;
}