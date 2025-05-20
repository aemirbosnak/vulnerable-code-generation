//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *url;
    char *user_agent;
    CURL *curl;
} SpeedTest;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char*)userp)[(strlen((char*)userp)) + (size*nmemb)] = '\0';
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    char *buffer;
    SpeedTest *speed_test;
    double download_speed;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    speed_test = (SpeedTest*)malloc(sizeof(SpeedTest));
    speed_test->curl = curl_easy_init();
    speed_test->user_agent = (char*)malloc(strlen("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3") + 1);
    strcpy(speed_test->user_agent, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3");
    speed_test->url = (char*)malloc(strlen("https://speedtest.net/speedtest.php?test=1") + 1);
    strcpy(speed_test->url, "https://speedtest.net/speedtest.php?test=1");

    curl_easy_setopt(speed_test->curl, CURLOPT_URL, speed_test->url);
    curl_easy_setopt(speed_test->curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(speed_test->curl, CURLOPT_WRITEDATA, &buffer);
    curl_easy_setopt(speed_test->curl, CURLOPT_USERAGENT, speed_test->user_agent);

    res = curl_easy_perform(speed_test->curl);
    if (res!= CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }

    curl_easy_cleanup(speed_test->curl);
    curl_global_cleanup();

    download_speed = atof(buffer) / 1024;
    printf("Download Speed: %.2f KB/s\n", download_speed);

    free(buffer);
    free(speed_test->url);
    free(speed_test->user_agent);
    free(speed_test);

    return 0;
}