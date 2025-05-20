//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define SERVER_URL "http://speedtest.net"
#define DOWNLOAD_SPEED_KEY "download_speed"
#define UPLOAD_SPEED_KEY "upload_speed"
#define PING_KEY "ping"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[(size_t)nmemb - 1] = '\0';
    return size * nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;
    char* url;
    struct curl_slist* headers = NULL;
    char* data;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        url = SERVER_URL;
        headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            char* download_speed_str = strstr(data, DOWNLOAD_SPEED_KEY);
            char* upload_speed_str = strstr(data, UPLOAD_SPEED_KEY);
            char* ping_str = strstr(data, PING_KEY);

            if (download_speed_str && upload_speed_str && ping_str)
            {
                int download_speed, upload_speed, ping;
                sscanf(download_speed_str, "%d", &download_speed);
                sscanf(upload_speed_str, "%d", &upload_speed);
                sscanf(ping_str, "%d", &ping);

                printf("Download Speed: %d kbps\n", download_speed);
                printf("Upload Speed: %d kbps\n", upload_speed);
                printf("Ping: %d ms\n", ping);
            }
            else
            {
                fprintf(stderr, "Failed to parse response\n");
            }
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        free(data);
    }

    curl_global_cleanup();

    return 0;
}