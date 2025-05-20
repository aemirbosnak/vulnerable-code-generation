//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 256
#define MAX_DATETIME_LENGTH 20
#define MAX_LOG_LENGTH 256

void logEvent(char* event) {
    time_t rawTime;
    struct tm *timeInfo;
    char dateTime[MAX_DATETIME_LENGTH];
    char log[MAX_LOG_LENGTH];

    time(&rawTime);
    timeInfo = localtime(&rawTime);
    strftime(dateTime, MAX_DATETIME_LENGTH, "%Y-%m-%d %H:%M:%S", timeInfo);
    sprintf(log, "[%s] %s\n", dateTime, event);

    FILE* logFile;
    logFile = fopen("log.txt", "a");
    fputs(log, logFile);
    fclose(logFile);
}

int main() {
    int numUrls;
    char urls[MAX_URL_LENGTH][MAX_URL_LENGTH];
    CURL* curlHandle[numUrls];
    CURLcode res[numUrls];
    int i;

    printf("Enter the number of URLs to monitor: ");
    scanf("%d", &numUrls);

    printf("Enter the URLs to monitor (one URL per line):\n");
    for(i = 0; i < numUrls; i++) {
        scanf("%s", urls[i]);
    }

    curl_global_init(CURL_GLOBAL_ALL);

    for(i = 0; i < numUrls; i++) {
        curlHandle[i] = curl_easy_init();
        curl_easy_setopt(curlHandle[i], CURLOPT_URL, urls[i]);
        curl_easy_setopt(curlHandle[i], CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curlHandle[i], CURLOPT_NOSIGNAL, 1L);
    }

    while(1) {
        for(i = 0; i < numUrls; i++) {
            if(curlHandle[i] != NULL) {
                res[i] = curl_easy_perform(curlHandle[i]);

                if(res[i] != CURLE_OK) {
                    char event[MAX_LOG_LENGTH];
                    sprintf(event, "%s is down!", urls[i]);
                    logEvent(event);
                    curl_easy_cleanup(curlHandle[i]);
                    curlHandle[i] = NULL;
                }
            }
        }

        int allHandlesDone = 1;
        for(i = 0; i < numUrls; i++) {
            if(curlHandle[i] != NULL) {
                allHandlesDone = 0;
                break;
            }
        }

        if(allHandlesDone) {
            printf("All URLs are down. Exiting.\n");
            break;
        }

        printf("Pausing for 60 seconds...\n");
        sleep(60);
    }

    curl_global_cleanup();
    return 0;
}