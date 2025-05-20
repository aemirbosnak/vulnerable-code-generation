//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <curl/curl.h>

#define FILE_SIZE 1024 * 1024 // 1MB
#define NUM_TESTS 5
#define BUFFER_SIZE 8192

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    if (fwrite(contents, size, realsize, stdout) != realsize) {
        fprintf(stderr, "Failed writing to file\n");
        return 0;
    }

    return realsize;
}

int main(void) {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char *url = "https://example.com/testfile.bin";
    struct stat st;
    long long downloaded = 0;
    double total_time = 0;
    double speed = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        fp = fopen("testfile.bin", "wb");

        for (int i = 0; i < NUM_TESTS; ++i) {
            clock_t start = clock();
            res = curl_easy_setopt(curl, CURLOPT_URL, url);
            res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                fprintf(stderr, "Failed downloading file: %s\n", curl_easy_strerror(res));
                break;
            }

            fseek(fp, 0, SEEK_END);
            stat("testfile.bin", &st);
            downloaded += st.st_size;
            fseek(fp, 0, SEEK_SET);
            fclose(fp);

            clock_t end = clock();
            double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
            total_time += elapsed_time;

            printf("Test %d: Download speed: %.2f KB/s, Elapsed time: %.2f seconds\n", i + 1, (double)downloaded / total_time * 1024, elapsed_time);
            downloaded = 0;
        }

        speed = (double)downloaded / total_time * 1024;
        printf("Average download speed: %.2f KB/s\n", speed);

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}