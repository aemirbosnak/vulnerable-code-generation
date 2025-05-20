//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void print_usage() {
    printf("\nRetro Internet Speed Test v1.0\n");
    printf("Usage: ./speedtest <URL>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        exit(1);
    }

    CURL *curl;
    FILE *fp;
    CURLcode res;
    size_t file_size;
    double start_time, end_time, elapsed_time, downloaded_bytes;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen("test.bin", "wb");

        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        start_time = time(NULL);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            exit(1);
        }

        fseek(fp, 0, SEEK_END);
        file_size = ftell(fp);
        rewind(fp);

        downloaded_bytes = (double)file_size;
        end_time = time(NULL);
        elapsed_time = end_time - start_time;

        printf("Download completed! Size: %.2f bytes, Download speed: %.2f kB/s\n", downloaded_bytes, downloaded_bytes / elapsed_time / 1024);

        curl_easy_cleanup(curl);
        fclose(fp);
    }

    return 0;
}