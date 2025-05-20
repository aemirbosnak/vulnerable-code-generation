//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <math.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    char server_name[64] = "speedtest.net";
    char url[256];
    double download_speed, upload_speed;
    struct timeval start, end;
    double elapsed_time;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        sprintf(url, "http://%s/speedtest", server_name);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    gettimeofday(&start, NULL);
    system("ping -c 5 speedtest.net");
    gettimeofday(&end, NULL);

    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    if(elapsed_time > 0)
    {
        download_speed = 5.0 / elapsed_time;
        upload_speed = 0.0;
    }
    else
    {
        download_speed = 0.0;
        upload_speed = 0.0;
    }

    printf("Download Speed: %.2f Mbps\n", download_speed);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);

    curl_global_cleanup();

    return 0;
}