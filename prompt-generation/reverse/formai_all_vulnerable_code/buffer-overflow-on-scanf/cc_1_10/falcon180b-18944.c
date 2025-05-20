//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URLS 10
#define MAX_URL_LEN 256

struct url_info {
    char url[MAX_URL_LEN];
    float speed;
};

void get_url(char *url, int index) {
    if (index >= MAX_URLS) {
        printf("Error: Too many URLs.\n");
        exit(1);
    }

    printf("Enter URL %d: ", index + 1);
    scanf("%s", url);
}

float download_file(char *url) {
    FILE *fp;
    char buffer[1024];
    long file_size = 0;
    time_t start_time, end_time;
    float elapsed_time;

    fp = fopen(url, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        return -1;
    }

    start_time = time(NULL);
    while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
        file_size += sizeof(buffer);
    }
    end_time = time(NULL);

    fclose(fp);

    elapsed_time = difftime(end_time, start_time);
    return (float)file_size / elapsed_time;
}

int main() {
    int num_urls;
    struct url_info urls[MAX_URLS];

    printf("Enter number of URLs to test: ");
    scanf("%d", &num_urls);

    for (int i = 0; i < num_urls; i++) {
        get_url(urls[i].url, i);
    }

    for (int i = 0; i < num_urls; i++) {
        urls[i].speed = download_file(urls[i].url);
    }

    printf("URL\tSpeed (KB/s)\n");
    for (int i = 0; i < num_urls; i++) {
        printf("%s\t%.2f\n", urls[i].url, urls[i].speed);
    }

    return 0;
}