//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_URL_LEN 1024
#define MAX_LOG_FILE_LEN 1024
#define MAX_LOG_ENTRIES 100

typedef struct {
    char url[MAX_URL_LEN];
    int status;
    time_t timestamp;
} LogEntry;

void log_entry(LogEntry* entry) {
    FILE* log_file = fopen("website_uptime_log.txt", "a");

    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    fprintf(log_file, "URL: %s\n", entry->url);
    fprintf(log_file, "Status: %d\n", entry->status);
    fprintf(log_file, "Timestamp: %s\n\n", ctime(&entry->timestamp));

    fclose(log_file);
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    LogEntry* entry = (LogEntry*)userp;
    strncat(entry->url, (char*)contents, size*nmemb);
    return size*nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl) {
        char url[MAX_URL_LEN];
        LogEntry entry;

        while (1) {
            printf("Enter URL to check (leave blank to exit): ");
            scanf("%s", url);

            if (strcmp(url, "") == 0) {
                break;
            }

            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &entry);

            res = curl_easy_perform(curl);

            if (res!= CURLE_OK) {
                printf("Error: %s\n", curl_easy_strerror(res));
            } else {
                entry.status = res;
                entry.timestamp = time(NULL);
                log_entry(&entry);
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}