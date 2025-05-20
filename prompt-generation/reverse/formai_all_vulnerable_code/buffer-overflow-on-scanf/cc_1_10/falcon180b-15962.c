//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LEN 512
#define TIMEOUT 10
#define INTERVAL 60 // in seconds

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main()
{
    CURL *curl;
    FILE *fp;
    char url[MAX_URL_LEN];
    char response[1024];
    int response_code;

    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen("website_status.log", "a");
        if (fp)
        {
            while (1)
            {
                printf("Enter the URL to monitor: ");
                scanf("%s", url);

                curl_easy_setopt(curl, CURLOPT_URL, url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

                response_code = curl_easy_perform(curl);
                if (response_code!= CURLE_OK)
                {
                    fprintf(fp, "Error: %s\n", curl_easy_strerror(response_code));
                }
                else
                {
                    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
                    fprintf(fp, "Response code: %d\n", response_code);

                    curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, url);
                    fprintf(fp, "Effective URL: %s\n", url);

                    curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, url);
                    fprintf(fp, "Content type: %s\n", url);

                    curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &response_code);
                    fprintf(fp, "Response size: %d\n", response_code);

                    curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &response_code);
                    fprintf(fp, "Download speed: %d\n", response_code);

                    curl_easy_cleanup(curl);
                }

                fclose(fp);
            }
        }
    }
    else
    {
        printf("Error: Failed to initialize curl\n");
    }

    return 0;
}