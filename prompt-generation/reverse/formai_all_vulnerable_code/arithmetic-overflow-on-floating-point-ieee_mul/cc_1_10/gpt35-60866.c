//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define DOWNLOAD_SIZE 10000000 // 10 MB
#define UPLOAD_SIZE 5000000 // 5 MB

double get_download_speed();
double get_upload_speed();

int main() {
    double download_speed, upload_speed;
    
    printf("Starting Internet Speed Test Application...\n");
    
    download_speed = get_download_speed();
    printf("Download Speed: %.2f Mbps\n", download_speed);
    
    upload_speed = get_upload_speed();
    printf("Upload Speed: %.2f Mbps\n", upload_speed);
    
    return 0;
}

double get_download_speed() {
    double download_speed, download_time;
    time_t start_time, end_time;
    FILE *fp;

    printf("Measuring Download Speed...\n");

    fp = fopen("speedtest.bin", "wb");
    if (fp == NULL) {
        printf("ERROR: Could not create file!\n");
        exit(1);
    }

    char *buffer = malloc(DOWNLOAD_SIZE * sizeof(char));
    if (buffer == NULL) {
        printf("ERROR: Could not allocate memory!\n");
        exit(1);
    }

    time(&start_time);
    fwrite(buffer, sizeof(char), DOWNLOAD_SIZE, fp);
    time(&end_time);
    fclose(fp);
    free(buffer);

    download_time = difftime(end_time, start_time);
    download_speed = ((double)DOWNLOAD_SIZE / download_time) * 8 / 1000000;

    return download_speed;
}

double get_upload_speed() {
    double upload_speed, upload_time;
    time_t start_time, end_time;
    FILE *fp;

    printf("Measuring Upload Speed...\n");

    fp = fopen("speedtest.bin", "rb");
    if (fp == NULL) {
        printf("ERROR: Could not open file!\n");
        exit(1);
    }

    char *buffer = malloc(UPLOAD_SIZE * sizeof(char));
    if (buffer == NULL) {
        printf("ERROR: Could not allocate memory!\n");
        exit(1);
    }

    fread(buffer, sizeof(char), UPLOAD_SIZE, fp);
    rewind(fp);

    time(&start_time);
    fwrite(buffer, sizeof(char), UPLOAD_SIZE, fp);
    fflush(fp);
    time(&end_time);

    fclose(fp);
    free(buffer);

    upload_time = difftime(end_time, start_time);
    upload_speed = ((double)UPLOAD_SIZE / upload_time) * 8 / 1000000;

    return upload_speed;
}