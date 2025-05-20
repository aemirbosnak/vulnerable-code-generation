//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024 * 1024 * 10 // 10 MB
#define SERVER "speedtest.net"
#define PORT 80

void send_request(char *request) {
    char url[100];
    sprintf(url, "http://%s:%d/", SERVER, PORT);
    strcat(url, request);

    FILE *fp;
    fp = fopen(url, "r");

    if (fp == NULL) {
        printf("Error: Unable to connect to server.\n");
        exit(1);
    }

    fclose(fp);
}

int main() {
    char buffer[MAX_SIZE];
    double start_time, end_time, elapsed_time;
    int bytes_received = 0;

    send_request("test10.html");

    FILE *fp;
    fp = fopen("test10.html", "rb");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    start_time = clock() / (double) CLOCKS_PER_SEC;

    while (fread(buffer, 1, MAX_SIZE, fp) > 0) {
        bytes_received += fread(buffer, 1, MAX_SIZE, fp);
    }

    end_time = clock() / (double) CLOCKS_PER_SEC;

    elapsed_time = end_time - start_time;

    double speed = (double) bytes_received / elapsed_time;

    printf("File size: %d bytes\n", file_size);
    printf("Bytes received: %d\n", bytes_received);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Internet speed: %.2f bytes/second\n", speed);

    fclose(fp);
    remove("test10.html");

    return 0;
}