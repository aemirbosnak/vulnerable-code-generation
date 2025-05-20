//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    int id = (long) clientp;
    printf("Thread %d: Downloaded %ld of %ld bytes\n", id, dlnow, dltotal);
    return 0;
}

void *ThreadSpeedTest(void *arg)
{
    char *url = (char *) arg;
    CURL *curl;
    CURLcode res;
    long response_code;
    double speed;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, (void *)1L);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "Thread %d: Download failed: %s\n", (long) arg, curl_easy_strerror(res));

        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return (void *)0;
}

int main(int argc, char *argv[])
{
    pthread_t threads[10];
    char urls[10][100];

    printf("Enter URLs to test:\n");
    for(int i=0; i<10; i++) {
        scanf("%s", urls[i]);
        strcat(urls[i], " ");
    }

    for(int i=0; i<10; i++) {
        pthread_create(&threads[i], NULL, ThreadSpeedTest, (void *)urls[i]);
    }

    for(int i=0; i<10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}