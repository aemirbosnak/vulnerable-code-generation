//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    double speed = 0;
    char url[100] = "https://www.speedtest.net/speedtest.png";
    FILE *fp;
    long file_size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &speed);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    fp = fopen("speedtest.png", "rb");
    if (fp!= NULL)
    {
        fseek(fp, 0, SEEK_END);
        file_size = ftell(fp);
        fclose(fp);
    }

    speed = (double)file_size / (double)(speed / 1000);

    printf("Internet Speed: %.2f kbps\n", speed);

    curl_global_cleanup();
    return 0;
}