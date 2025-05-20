//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <sys/timeb.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    FILE* fp = (FILE*)userp;
    return fwrite(contents, size, nmemb, fp);
}

int main()
{
    CURL* curl;
    FILE* fp;
    CURLcode res;
    time_t now;
    struct tm* tm_now;
    char* url = "http://example.com";
    char* filename = "response.txt";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        fp = fopen(filename, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            fclose(fp);
            now = time(NULL);
            tm_now = localtime(&now);
            printf("Response saved to %s at %02d:%02d:%02d\n", filename, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}