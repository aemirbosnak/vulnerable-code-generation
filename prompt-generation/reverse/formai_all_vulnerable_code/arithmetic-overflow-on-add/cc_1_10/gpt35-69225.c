//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void delay(int num_seconds) { 
    int milliseconds = 1000 * num_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milliseconds); 
}

int main(void) {
    int download_speed = 0;
    int upload_speed = 0;
    char response[50];
    char internet_provider[20];
    int response_len;
    int i;

    printf("Welcome to the Internet Speed Test Application\n");
    printf("Please enter your internet provider: ");
    scanf("%s", internet_provider);

    printf("Starting download test...\n");
    delay(2);

    for (i = 0; i < 10; i++) {
        printf("Downloading packet %d of 10...\n", i + 1);
        delay(1);
        download_speed += rand() % 100;        
    }

    printf("Download test complete!\n");

    printf("Starting upload test...\n");
    delay(2);

    for (i = 0; i < 10; i++) {
        printf("Uploading packet %d of 10...\n", i + 1);
        delay(1);
        upload_speed += rand() % 100;        
    }

    printf("Upload test complete!\n");

    printf("Calculating results...\n");
    delay(2);

    download_speed /= 10;
    upload_speed /= 10;

    printf("Results for %s:\n", internet_provider);
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Upload speed: %d Mbps\n", upload_speed);

    printf("Would you like to save your results? (y/n): ");
    scanf("%s", response);
    response_len = strlen(response);
    for (i = 0; i < response_len; i++) {
        response[i] = tolower(response[i]);
    }

    if (strcmp(response, "y") == 0) {
        printf("Saving results...\n");
        delay(2);
        printf("Results saved successfully!\n");
    } else {
        printf("Results not saved.\n");
    }

    return 0;
}