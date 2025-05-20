//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LEN 1000

// Callback function to write response data to a file
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    FILE* file = (FILE*)userp;
    return fwrite(contents, size, nmemb, file);
}

// Callback function to log errors
void ErrorCallback(CURL* curl, curl_infotype type, char* message) {
    if (type == CURLINFO_TEXT) {
        fprintf(stderr, "Error: %s\n", message);
    }
}

// Function to check if a website is up
int CheckWebsite(const char* url) {
    CURL* curl;
    CURLcode res;
    FILE* file;
    char* response = NULL;
    int status = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        file = fopen("response.txt", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, response);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(file);

        if (response) {
            if (strstr(response, "200 OK")) {
                status = 1;
            } else {
                status = 0;
            }
        } else {
            status = 0;
        }
    }

    curl_global_cleanup();
    return status;
}

// Function to log website status
void LogStatus(const char* url, int status) {
    FILE* file = fopen("status.log", "a");
    fprintf(file, "%s - %d\n", url, status);
    fclose(file);
}

// Function to monitor websites and log status
void MonitorWebsites() {
    FILE* file;
    char url[MAX_URL_LEN];

    file = fopen("websites.txt", "r");
    while (fscanf(file, "%s", url)!= EOF) {
        int status = CheckWebsite(url);
        LogStatus(url, status);
    }
    fclose(file);
}

// Main function
int main() {
    MonitorWebsites();
    return 0;
}