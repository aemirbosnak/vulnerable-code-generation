//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

#define MAX_DOWNLOAD_SPEED 1000000 // 1Mbps
#define MAX_UPLOAD_SPEED 1000000 // 1Mbps

typedef struct {
    char *url;
    char *ip;
    double download_speed;
    double upload_speed;
} speedtest_result_t;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((char *)userp)[(size_t)strlen((char *)userp) + size * nmemb - 1] = '\0';
    return size * nmemb;
}

void speedtest_result_free(speedtest_result_t *result)
{
    if (result->url) {
        free(result->url);
        result->url = NULL;
    }

    if (result->ip) {
        free(result->ip);
        result->ip = NULL;
    }
}

speedtest_result_t *speedtest_run(const char *server_url)
{
    CURL *curl;
    CURLcode res;
    speedtest_result_t *result = malloc(sizeof(speedtest_result_t));

    if (!result) {
        return NULL;
    }

    result->url = strdup(server_url);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (!curl) {
        speedtest_result_free(result);
        return NULL;
    }

    curl_easy_setopt(curl, CURLOPT_URL, result->url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result->ip);

    res = curl_easy_perform(curl);

    if (res!= CURLE_OK) {
        speedtest_result_free(result);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return NULL;
    }

    curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &result->download_speed);
    curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &result->upload_speed);

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return result;
}

int main()
{
    speedtest_result_t *result = speedtest_run("https://speedtest.net/speedtest.php");

    if (result) {
        printf("Server URL: %s\n", result->url);
        printf("IP Address: %s\n", result->ip);
        printf("Download Speed: %.2f Mbps\n", result->download_speed / (1024 * 1024));
        printf("Upload Speed: %.2f Mbps\n", result->upload_speed / (1024 * 1024));

        if (result->download_speed >= MAX_DOWNLOAD_SPEED && result->upload_speed >= MAX_UPLOAD_SPEED) {
            printf("Internet speed is blazing fast!\n");
        } else {
            printf("Internet speed is satisfactory.\n");
        }

        speedtest_result_free(result);
    } else {
        printf("Speed test failed.\n");
    }

    return 0;
}