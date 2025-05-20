//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URLS 10
#define MAX_URL_LENGTH 100
#define MAX_ERROR_LENGTH 200

typedef struct {
    char urls[MAX_URLS][MAX_URL_LENGTH];
    int num_urls;
    int interval;
} Config;

typedef struct {
    char url[MAX_URL_LENGTH];
    long http_code;
    double connect_time;
    double total_time;
    char error[MAX_ERROR_LENGTH];
} Result;

int load_config(Config *config, const char *filename);
int get_url_status(const char *url, Result *result);
void log_result(const Result *result);
void sleep_milliseconds(int milliseconds);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return 1;
    }
    Config config;
    if (!load_config(&config, argv[1])) {
        return 1;
    }
    while (1) {
        for (int i = 0; i < config.num_urls; i++) {
            Result result;
            if (get_url_status(config.urls[i], &result)) {
                log_result(&result);
            }
        }
        sleep_milliseconds(config.interval * 1000);
    }
}

int load_config(Config *config, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open config file '%s'\n", filename);
        return 0;
    }
    char line[MAX_URL_LENGTH + 10];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#') { // skip comments
            continue;
        }
        if (strstr(line, "url ") == line) {
            if (config->num_urls == MAX_URLS) {
                printf("Error: Maximum number of URLs (%d) exceeded\n", MAX_URLS);
                fclose(file);
                return 0;
            }
            sscanf(line, "url %s", config->urls[config->num_urls]);
            config->num_urls++;
        }
        else if (strstr(line, "interval ") == line) {
            sscanf(line, "interval %d", &config->interval);
        }
    }
    fclose(file);
    return 1;
}

int get_url_status(const char *url, Result *result) {
    CURL *curl = curl_easy_init();
    if (!curl) {
        printf("Error: Could not initialize libcurl\n");
        return 0;
    }
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 1000L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 3000L);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        sprintf(result->error, "Failed to connect to '%s': %s", url, curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }
    long http_code;
    double connect_time;
    double total_time;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_getinfo(curl, CURLINFO_CONNECT_TIME, &connect_time);
    curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &total_time);
    strcpy(result->url, url);
    result->http_code = http_code;
    result->connect_time = connect_time;
    result->total_time = total_time;
    curl_easy_cleanup(curl);
    return 1;
}

void log_result(const Result *result) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);
    if (result->http_code != 200) {
        printf("[%s] ERROR: %s (HTTP Code %ld)\n", timestamp, result->error, result->http_code);
    }
    else {
        printf("[%s] OK: '%s' in %.2f seconds (%.2f seconds to connect)\n", timestamp, result->url, result->total_time, result->connect_time);
    }
}

void sleep_milliseconds(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#endif
}