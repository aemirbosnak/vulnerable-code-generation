//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random speed for the speed test
int generateRandSpeed() {
    int speed = rand() % 100;
    return speed;
}

// Function to format the speed into Mbps or Gbps
char* formatSpeed(int speed) {
    char* formattedSpeed = malloc(sizeof(char) * 5);
    if (speed >= 1000) {
        sprintf(formattedSpeed, "%.2f Gbps", (float)speed/1000);
    } else {
        sprintf(formattedSpeed, "%d Mbps", speed);
    }
    return formattedSpeed;
}

int main() {
    char name[20];
    printf("Hello there! What is your name?\n");
    scanf("%s", name);
    printf("\nNice to meet you, %s! Let's test your internet speed!\n", name);

    srand(time(NULL));
    int downloadSpeed = generateRandSpeed();
    int uploadSpeed = generateRandSpeed();
    int ping = rand() % 50;

    printf("\nTesting download speed....\n\n");
    printf("Download speed: %s\n", formatSpeed(downloadSpeed));
    printf("\nTesting upload speed....\n\n");
    printf("Upload speed: %s\n", formatSpeed(uploadSpeed));
    printf("\nTesting ping....\n\n");
    printf("Ping: %d ms\n", ping);

    printf("\nCongratulations %s! Your internet speed test is complete! \n\n", name);
    printf("Do you want to test again? (y/n)\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        system("clear");
        main();
    } else {
        printf("\nThank you for testing your internet speed with us, %s!\n", name);
    }

    return 0;
}