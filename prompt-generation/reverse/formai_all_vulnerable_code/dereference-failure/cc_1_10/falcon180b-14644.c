//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    return 0;
}

int main(void)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char website[100];
    char buffer[1000];

    printf("Enter the website URL: ");
    scanf("%s", website);

    fp = fopen("website_status.txt", "w");
    if (fp == NULL)
    {
        printf("Error: Failed to open file\n");
        exit(1);
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, website);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, FALSE);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, NULL);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK)
        {
            fprintf(fp, "Error: %s\n", curl_easy_strerror(res));
        }
        else
        {
            fprintf(fp, "Website is up and running.\n");
        }

        curl_easy_cleanup(curl);
        fclose(fp);
    }

    curl_global_cleanup();

    printf("Website status has been saved to website_status.txt\n");

    return 0;
}