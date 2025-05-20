//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    FILE *fp = (FILE *)userp;
    size_t realsize = size * nmemb;
    return fwrite(contents, size, nmemb, fp);
}

int http_get(const char *url, FILE *fp)
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return res;
}

int main()
{
    char url[100];
    FILE *fp;
    int i, j, n, k, m;
    struct timespec start, end;
    double elapsed, speed;
    char hostname[100];

    printf("Enter the URL of the website to test: ");
    scanf("%s", url);

    fp = fopen("output.txt", "w");
    if(fp == NULL) {
        printf("Error: could not create output file.\n");
        exit(1);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    http_get(url, fp);
    clock_gettime(CLOCK_REALTIME, &end);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    speed = (double)strlen(url) / elapsed;

    printf("Test complete!\n");
    printf("Elapsed time: %.6f seconds\n", elapsed);
    printf("Speed: %.2f bytes/second\n", speed);

    fclose(fp);
    return 0;
}