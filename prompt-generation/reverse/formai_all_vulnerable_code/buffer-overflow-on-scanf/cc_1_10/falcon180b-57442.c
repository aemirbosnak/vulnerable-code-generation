//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    char* data = (char*)contents;
    if (userp!= NULL) {
        FILE* file = (FILE*)userp;
        fwrite(data, realsize, 1, file);
    }
    return realsize;
}

int main()
{
    FILE* file;
    char url[1000];
    char* data;
    long response_code;
    CURL* curl;
    CURLcode res;
    double speed;
    time_t start, end;
    int elapsed;

    printf("Enter the URL to test internet speed:");
    scanf("%s", url);

    file = fopen("speed.txt", "w");
    if (file == NULL) {
        printf("Unable to open file!\n");
        exit(1);
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        res = curl_easy_perform(curl);

        if (res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            speed = ((double)response_code / 1000) * 1000000;
            elapsed = (int)difftime(end, start);
            printf("Internet speed: %.2lf Mbps\n", speed / elapsed);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    } else {
        printf("Error: unable to initialize curl!\n");
    }

    fclose(file);
    return 0;
}