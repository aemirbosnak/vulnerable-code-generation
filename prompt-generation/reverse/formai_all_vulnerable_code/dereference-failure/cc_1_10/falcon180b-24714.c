//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curl/curl.h>
#include<math.h>
#include<time.h>

typedef struct {
    char* host;
    double speed;
    char* ip;
} speed_test_result;

static size_t write_callback(void* buffer, size_t size, size_t nmemb, void* userp) {
    speed_test_result* result = (speed_test_result*)userp;
    result->speed += size * nmemb;
    return size * nmemb;
}

static int progress_callback(void* userp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    speed_test_result* result = (speed_test_result*)userp;
    double speed = (double)dlnow / (double)dltotal * 100.0;
    result->speed = speed;
    return 0;
}

speed_test_result* speed_test(char* server) {
    CURL* curl = curl_easy_init();
    CURLcode res;
    speed_test_result* result = (speed_test_result*)malloc(sizeof(speed_test_result));
    result->host = strdup(server);
    curl_easy_setopt(curl, CURLOPT_URL, server);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, result);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, result);
    res = curl_easy_perform(curl);
    if(res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
    return result;
}

int main() {
    char* server = "speedtest.net";
    speed_test_result* result = speed_test(server);
    printf("Server: %s\n", result->host);
    printf("Speed: %.2f Mbps\n", result->speed);
    printf("IP Address: %s\n", result->ip);
    free(result->host);
    free(result->ip);
    free(result);
    return 0;
}