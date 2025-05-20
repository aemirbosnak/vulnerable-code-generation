//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>

int main()
{
    CURL *curl;
    CURLcode res;

    char url[100];
    int statusCode = 0;

    printf("Enter the URL: ");
    scanf("%s",url);

    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);

        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

        res = curl_easy_perform(curl);

        if(res == CURLE_OK)
        {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &statusCode);

            if(statusCode == 200)
            {
                printf("\nThe website '%s' is UP and RUNNING!\n", url);
            }
            else
            {
                printf("\nOops! The website '%s' seems to be DOWN with error code '%d'\n", url, statusCode);
            }
        }
        else
        {
            printf("\nError Occurred: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }
    else
    {
        printf("\nCurl Initialization Failed!\n");
    }

    return 0;
}