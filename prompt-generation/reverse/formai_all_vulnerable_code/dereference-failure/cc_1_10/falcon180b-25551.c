//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    return fwrite(contents, size, nmemb, (FILE*)userp);
}

static int ProgressCallback(void* clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    double progress = ((double)dlnow / (double)dltotal) * 100.0;
    printf("Download progress: %.2f%%\r", progress);
    return 0;
}

int main(int argc, char** argv)
{
    CURL* curl;
    FILE* fp;
    CURLcode res;
    struct stat st;

    if(argc!= 4)
    {
        printf("Usage: %s <username> <password> <remote_file>\n", argv[0]);
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        char url[1024];
        sprintf(url, "ftp://%s:%s@%s", argv[1], argv[2], argv[3]);

        fp = fopen("download.bin", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
        {
            printf("FTP download failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            fclose(fp);
            printf("FTP download completed.\n");
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}