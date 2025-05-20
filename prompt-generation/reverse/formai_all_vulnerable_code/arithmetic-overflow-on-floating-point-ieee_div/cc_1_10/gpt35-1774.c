//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize the variables to be used
    int downloadSpeed = 0;
    int uploadSpeed = 0;
    int pingSpeed = 0;
    int dataDownloadTime = 0;
    int dataUploadTime = 0;
    double downloadSize = 50.0;
    double uploadSize = 25.0;
    clock_t start, end;

    // Start the Download Test
    printf("Starting download test...\n");
    start = clock();
    // Simulating download by sleeping for some time
    sleep(5);
    end = clock();

    dataDownloadTime = (int) ((end - start) / CLOCKS_PER_SEC);
    downloadSpeed = (int) (downloadSize / dataDownloadTime);
    printf("Your download speed is: %d Mbps\n", downloadSpeed);

    // Start the Upload Test
    printf("Starting upload test...\n");
    start = clock();
    // Simulating upload by sleeping for some time
    sleep(3);
    end = clock();

    dataUploadTime = (int) ((end - start) / CLOCKS_PER_SEC);
    uploadSpeed = (int) (uploadSize / dataUploadTime);
    printf("Your upload speed is: %d Mbps\n", uploadSpeed);

    // Start the Ping Test
    printf("Starting ping test...\n");
    start = clock();
    // Simulating ping by sleeping for some time
    sleep(1);
    end = clock();

    pingSpeed = (int) ((end - start) / CLOCKS_PER_SEC);
    printf("Your ping speed is: %d ms\n", pingSpeed);

    return 0;
}