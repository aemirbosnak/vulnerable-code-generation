//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[(size_t)strlen((char*)userp) + size * nmemb - 1] = '\0';
    return size * nmemb;
}

int main(int argc, char* argv[])
{
    CURL* curl;
    FILE* file;
    char* url;
    char* user_agent;
    char* buffer;
    long http_code;
    time_t last_check;
    struct tm* last_check_tm;
    int check_interval = 60; // seconds

    if(argc!= 4)
    {
        fprintf(stderr, "Usage: %s <url> <user_agent> <check_interval>\n", argv[0]);
        exit(1);
    }

    url = argv[1];
    user_agent = argv[2];
    check_interval = atoi(argv[3]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, user_agent);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

        http_code = curl_easy_perform(curl);

        if(http_code == 200)
        {
            fprintf(stdout, "Website is up and running.\n");
        }
        else
        {
            fprintf(stdout, "Website is down. HTTP response code: %ld\n", http_code);
        }

        curl_easy_cleanup(curl);
    }
    else
    {
        fprintf(stderr, "Failed to initialize curl.\n");
    }

    curl_global_cleanup();

    file = fopen("last_check.txt", "r");
    if(file)
    {
        fscanf(file, "%ld", &last_check);
        fclose(file);
    }
    else
    {
        last_check = time(NULL) - check_interval;
    }

    last_check_tm = localtime(&last_check);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", last_check_tm);

    fprintf(stdout, "Last check: %s\n", buffer);

    file = fopen("last_check.txt", "w");
    if(file)
    {
        fprintf(file, "%ld", time(NULL));
        fclose(file);
    }

    return 0;
}