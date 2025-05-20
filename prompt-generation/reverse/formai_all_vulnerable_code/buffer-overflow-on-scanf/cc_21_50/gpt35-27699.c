//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Initialize variables
    int download_speed, upload_speed, latency;
    int download_result, upload_result, latency_result;
    char wifi_name[50];

    // Prompt user for wifi name
    printf("Please enter the name of your wifi network: ");
    scanf("%s", wifi_name);

    // Simulate download speed test
    download_speed = rand() % 100 + 1;
    printf("\nSimulating download speed test...\n");
    printf("Your download speed on %s is: %d Mbps\n", wifi_name, download_speed);

    // Simulate upload speed test
    upload_speed = rand() % 100 + 1;
    printf("\nSimulating upload speed test...\n");
    printf("Your upload speed on %s is: %d Mbps\n", wifi_name, upload_speed);

    // Simulate latency test
    latency = rand() % 100 + 1;
    printf("\nSimulating latency test...\n");
    printf("Your latency on %s is: %d ms\n", wifi_name, latency);

    // Calculate download, upload, and latency results
    download_result = download_speed <= 10 ? 1 : download_speed <= 30 ? 2 : download_speed <= 70 ? 3 : 4;
    upload_result = upload_speed <= 5 ? 1 : upload_speed <= 15 ? 2 : upload_speed <= 35 ? 3 : 4;
    latency_result = latency <= 20 ? 1 : latency <= 50 ? 2 : latency <= 80 ? 3 : 4;

    // Print out the results
    printf("\n\n***RESULTS***\n");
    printf("Download Speed Result: ");
    switch(download_result) {
        case 1:
            printf("Poor\n");
            break;
        case 2:
            printf("Fair\n");
            break;
        case 3:
            printf("Good\n");
            break;
        case 4:
            printf("Excellent\n");
            break;
    }
    printf("Upload Speed Result: ");
    switch(upload_result) {
        case 1:
            printf("Poor\n");
            break;
        case 2:
            printf("Fair\n");
            break;
        case 3:
            printf("Good\n");
            break;
        case 4:
            printf("Excellent\n");
            break;
    }
    printf("Latency Result: ");
    switch(latency_result) {
        case 1:
            printf("Excellent\n");
            break;
        case 2:
            printf("Good\n");
            break;
        case 3:
            printf("Fair\n");
            break;
        case 4:
            printf("Poor\n");
            break;
    }

    return 0;
}