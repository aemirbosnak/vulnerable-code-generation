//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    FILE* file = (FILE*)userp;
    return fwrite(contents, size, nmemb, file);
}

int main(int argc, char* argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s <URL> <output file>\n", argv[0]);
        return 1;
    }

    CURL* curl = curl_easy_init();
    FILE* file = fopen(argv[2], "wb");

    if (!curl ||!file)
    {
        printf("Error: Failed to initialize CURL or open output file.\n");
        if (curl)
            curl_easy_cleanup(curl);
        if (file)
            fclose(file);
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    double start_time = difftime(time(NULL), time(NULL));
    curl_easy_perform(curl);
    double end_time = difftime(time(NULL), time(NULL));

    double duration = end_time - start_time;
    double speed = BUFFER_SIZE / duration;

    printf("Downloaded %zu bytes in %.2f seconds at a speed of %.2f bytes/second.\n",
           BUFFER_SIZE, duration, speed);

    curl_easy_cleanup(curl);
    fclose(file);

    return 0;
}