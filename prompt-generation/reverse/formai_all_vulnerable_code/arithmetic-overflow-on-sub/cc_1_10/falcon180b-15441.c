//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <math.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    double download_speed = 0.0;
    double upload_speed = 0.0;
    char url[100];
    struct timeval start, end;

    printf("Enter the URL to test the internet speed: ");
    scanf("%s", url);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    gettimeofday(&start, NULL);
    system("ping -c 5 google.com > /dev/null");
    gettimeofday(&end, NULL);

    upload_speed = (double)(5 * 1024 * 8) / (double)(end.tv_usec - start.tv_usec);

    printf("Upload Speed: %.2f kbps\n", upload_speed);

    return 0;
}