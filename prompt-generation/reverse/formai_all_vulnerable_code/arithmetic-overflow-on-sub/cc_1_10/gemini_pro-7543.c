//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_URL_SIZE 256

char *url;
int size;
char *data;

void gather_evidence() {
    printf("Watson, prepare the URL for investigation: ");
    scanf("%s", url);

    printf("Excellent, Watson! Now, tell me the size of the data to download: ");
    scanf("%d", &size);
}

void download_data() {
    printf("My dear Watson, I shall now download the data for analysis: ");

    // Allocate memory for the data
    data = malloc(size);

    // Open a connection to the URL
    FILE *fp = fopen(url, "rb");

    // Read the data into the buffer
    fread(data, 1, size, fp);

    // Close the connection
    fclose(fp);
}

void analyze_data() {
    // Calculate the time taken to download the data
    clock_t start = clock();
    download_data();
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the download speed
    double speed = (double)size / time_taken;

    // Determine the culprit
    if (speed < 0.5) {
        printf("Elementary, my dear Watson! The culprit is a slow connection.");
    } else if (speed < 1) {
        printf("Interesting, Watson. It appears that the server is the bottleneck.");
    } else {
        printf("Remarkable, Watson! The internet speed is blazing fast.");
    }
}

int main() {
    gather_evidence();
    analyze_data();
    return 0;
}