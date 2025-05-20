//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define LOG_FILE "uptime.log"
#define WEBSITE_URL "http://www.example.com"
#define CHECK_INTERVAL 60 // seconds

FILE *log_file;
time_t last_check_time = 0;

void log_message(const char *message)
{
    time_t current_time = time(NULL);
    if (current_time - last_check_time >= CHECK_INTERVAL)
    {
        last_check_time = current_time;

        if (log_file == NULL)
        {
            log_file = fopen(LOG_FILE, "a");
            if (log_file == NULL)
            {
                printf("Unable to open log file.\n");
                exit(1);
            }
        }

        fprintf(log_file, "%s\n", message);
        fclose(log_file);
        log_file = NULL;
    }
}

int check_website_status()
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, WEBSITE_URL);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK)
        {
            log_message("Website is down");
            return 1;
        }
        else
        {
            log_message("Website is up");
            return 0;
        }
    }
    else
    {
        log_message("Unable to initialize curl");
        return 1;
    }
}

int main()
{
    while (1)
    {
        check_website_status();
        sleep(CHECK_INTERVAL);
    }

    return 0;
}