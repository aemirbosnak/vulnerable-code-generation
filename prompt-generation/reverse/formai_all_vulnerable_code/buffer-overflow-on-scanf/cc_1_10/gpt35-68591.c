//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random download speed
float generateDownloadSpeed() {
    return ((float) rand() / RAND_MAX) * 100;
}

// Function to generate random upload speed
float generateUploadSpeed() {
    return ((float) rand() / RAND_MAX) * 50;
}

int main() {
    // Seed the random number generator
    srand(time(0));
    printf("Welcome to the Internet Speed Test\n");

    // Get user information
    char name[50];
    printf("What is your name? ");
    scanf("%s", &name);

    int age;
    printf("How old are you? ");
    scanf("%d", &age);

    char isp[50];
    printf("Who is your internet service provider? ");
    scanf("%s", &isp);

    // Test internet speed
    printf("Testing download speed...\n");
    float downloadSpeed = generateDownloadSpeed();
    printf("Your download speed is %.2f Mbps\n", downloadSpeed);

    printf("Testing upload speed...\n");
    float uploadSpeed = generateUploadSpeed();
    printf("Your upload speed is %.2f Mbps\n", uploadSpeed);

    // Determine internet connection quality
    if (downloadSpeed > 50 && uploadSpeed > 25) {
        printf("Congratulations %s! You have a great internet connection with %s!\n", name, isp);
    } else if (downloadSpeed > 20 && uploadSpeed > 10) {
        printf("Your internet connection with %s is good, %s. Keep it up!\n", isp, name);
    } else {
        printf("Uh oh %s, your internet connection with %s needs improvement!\n", name, isp);
    }

    return 0;
}