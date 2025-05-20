//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define CHECK_INTERVAL 60 // Check website every 60 seconds

char website_url[100] = "https://www.example.com";
int check_count = 0;
int error_count = 0;
struct timeb last_check;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    return size * nmemb;
}

int main()
{
    CURL* curl;
    FILE* log_file;
    char log_entry[200];
    time_t now;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, website_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    else
    {
        printf("Error initializing curl\n");
        return 1;
    }

    last_check.time = 0;
    last_check.millitm = 0;

    log_file = fopen("website_uptime.log", "a");

    while (1)
    {
        now = time(NULL);
        if (difftime(now, last_check.time) >= CHECK_INTERVAL)
        {
            check_count++;

            curl_global_init(CURL_GLOBAL_DEFAULT);
            curl = curl_easy_init();

            if (curl)
            {
                curl_easy_setopt(curl, CURLOPT_URL, website_url);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
                curl_easy_perform(curl);
                curl_easy_cleanup(curl);

                if (curl_easy_getinfo(curl, CURLINFO_HTTP_CODE, &error_count)!= CURLE_OK)
                {
                    printf("Error getting HTTP code\n");
                    error_count = 0;
                }

                if (error_count!= 200)
                {
                    sprintf(log_entry, "Website down at %s (HTTP code %d)\n", ctime(&now), error_count);
                    fputs(log_entry, log_file);
                }
                else
                {
                    sprintf(log_entry, "Website up at %s\n", ctime(&now));
                    fputs(log_entry, log_file);
                }

                fclose(log_file);
            }
            else
            {
                printf("Error initializing curl\n");
            }

            last_check.time = now;
            last_check.millitm = 0;
        }
        sleep(1);
    }

    return 0;
}