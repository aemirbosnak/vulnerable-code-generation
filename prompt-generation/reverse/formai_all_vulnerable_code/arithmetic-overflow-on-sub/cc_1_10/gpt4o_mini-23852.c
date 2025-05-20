//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_URL_LENGTH 256
#define BUFFER_SIZE 8192

// Function prototypes
void display_header();
double measure_download_speed(const char *url);
double measure_upload_speed(const char *url);
void perform_speed_test(const char *url);

int main() {
    char url[MAX_URL_LENGTH];

    display_header();

    // Welcome message
    printf("Welcome to the C Internet Speed Test Application!\n");
    printf("Please enter the URL to test the speed (e.g., http://example.com): ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0; // Remove newline character

    // Let's perform the speed test
    perform_speed_test(url);

    return 0;
}

// Function to display header
void display_header() {
    printf("***********************************************\n");
    printf("*         C Internet Speed Test App         *\n");
    printf("***********************************************\n");
}

// Function to measure download speed
double measure_download_speed(const char *url) {
    struct timeval start, end;
    char command[BUFFER_SIZE];
    FILE *fp;
    double speed = 0.0;
    
    snprintf(command, sizeof(command), "curl -so /dev/null %s", url);

    gettimeofday(&start, NULL);
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error executing command for download speed!\n");
        return 0.0;
    }
    pclose(fp);
    gettimeofday(&end, NULL);

    double elapsed_time = (end.tv_sec - start.tv_sec) * 1.0 + (end.tv_usec - start.tv_usec) / 1000000.0;
    speed = (1.0 / elapsed_time) * 8.0; // speed in Mbps
    printf("Download Speed: %.2f Mbps\n", speed);
    return speed;
}

// Function to simulate upload speed measurement
double measure_upload_speed(const char *url) {
    struct timeval start, end;
    char command[BUFFER_SIZE];
    FILE *fp;
    double speed = 0.0;

    snprintf(command, sizeof(command), "curl -XPUT -d \"Testing upload speed...\" %s", url);

    gettimeofday(&start, NULL);
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error executing command for upload speed!\n");
        return 0.0;
    }
    pclose(fp);
    gettimeofday(&end, NULL);

    double elapsed_time = (end.tv_sec - start.tv_sec) * 1.0 + (end.tv_usec - start.tv_usec) / 1000000.0;
    speed = (1.0 / elapsed_time) * 8.0; // speed in Mbps
    printf("Upload Speed: %.2f Mbps\n", speed);
    return speed;
}

// Function to perform the speed test
void perform_speed_test(const char *url) {
    printf("Testing your internet speed...\n");
    printf("--------------------------------------------------\n");

    // Measure download speed
    measure_download_speed(url);

    // Measure upload speed
    measure_upload_speed(url);

    printf("--------------------------------------------------\n");
    printf("Thank you for using the C Internet Speed Test App!\n");
    printf("Goodbye and stay connected!\n");
}