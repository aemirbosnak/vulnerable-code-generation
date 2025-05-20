//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <math.h>
#include <time.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[size*nmemb - 1] = 0;
    return size * nmemb;
}

void update_status(char* hostname, char* status)
{
    char query[200];
    sprintf(query, "UPDATE websites SET status='%s' WHERE hostname='%s'", status, hostname);
    system(query);
}

int main()
{
    CURL* curl;
    CURLcode res;
    char* hostname;
    char* response;
    double uptime;
    struct tm* current_time;
    time_t current_timestamp;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        while(1)
        {
            hostname = (char*)malloc(100*sizeof(char));
            printf("Enter hostname: ");
            scanf("%s", hostname);

            curl_easy_setopt(curl, CURLOPT_URL, hostname);
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "HEAD");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            res = curl_easy_perform(curl);

            if(res!= CURLE_OK)
            {
                printf("Error: %s\n", curl_easy_strerror(res));
            }
            else
            {
                update_status(hostname, response);
                uptime = (double)time(NULL) - strtod(response, NULL);
                current_time = localtime(&current_timestamp);
                printf("Uptime: %lf days\n", uptime/86400);
            }

            free(response);
            free(hostname);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}