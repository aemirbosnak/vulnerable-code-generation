//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define KB 1024
#define MB 1024 * 1024

float downloadSpeed(float mbps, float duration);
float uploadSpeed(float mbps, float duration);

int main() {
    int choice;
    float mbps, duration, speed;
    srand(time(NULL));
    do {
        printf("\nWelcome to Internet Speed Test\n\n");
        printf("Please choose an option:\n");
        printf("1. Download Speed Test\n");
        printf("2. Upload Speed Test\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                mbps = (rand() % 100) + 1;
                duration = (rand() % 10) + 1;
                printf("\nYour Download Speed: %.2f Mbps\n", mbps);
                printf("Duration: %.2f seconds\n", duration);
                printf("Calculating Speed...\n");
                speed = downloadSpeed(mbps, duration);
                printf("\nYour Download Speed is: %.2f KB/s or %.2f MB/s\n", speed, speed/KB);
                break;
            case 2:
                mbps = (rand() % 100) + 1;
                duration = (rand() % 10) + 1;
                printf("\nYour Upload Speed: %.2f Mbps\n", mbps);
                printf("Duration: %.2f seconds\n", duration);
                printf("Calculating Speed...\n");
                speed = uploadSpeed(mbps, duration);
                printf("\nYour Upload Speed is: %.2f KB/s or %.2f MB/s\n", speed, speed/KB);
                break;
            case 3:
                printf("\nThank you for using our Internet Speed Test\n");
                break;
            default:
                printf("\nInvalid option. Please choose again.\n");
        }
    } while(choice != 3);
    return 0;
}

float downloadSpeed(float mbps, float duration) {
    float data = mbps * duration * MB;
    float speed = data / (duration * KB);
    return speed;
}

float uploadSpeed(float mbps, float duration) {
    float data = mbps * duration * MB;
    float speed = data / (duration * KB);
    return speed;
}