//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

struct FileInfo {
    char name[256];
    char mode[10];
    off_t size;
};

size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    FILE *file = (FILE *)userp;
    return fwrite(ptr, realsize, 1, file);
}

int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    struct FileInfo *fileinfo = (struct FileInfo *)clientp;
    int progress = (int)((dlnow * 100) / dltotal);
    printf("Downloading %s: %d%%\r", fileinfo->name, progress);
    return 0;
}

int main(int argc, char **argv) {
    CURL *curl;
    FILE *output;
    CURLcode res;
    struct FileInfo fileinfo;

    if (argc!= 4) {
        printf("Usage: %s <username> <password> <filename>\n", argv[0]);
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        strcpy(fileinfo.name, argv[3]);
        sprintf(fileinfo.mode, "STOR %s", argv[3]);

        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_USERPWD, argv[2]);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, fileinfo.mode);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &fileinfo);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("FTP upload failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("FTP upload successful!\n");
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}