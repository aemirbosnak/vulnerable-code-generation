//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: unmistakable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// function to calculate internet speed
double internetSpeedTest(long long int downloadTime, long long int fileSize) {
    double speed = (8 * fileSize) / downloadTime;
    return speed;
}

int main() {
    // welcome message
    printf("Welcome to the Internet Speed Test Application\n");

    // input file size 
    printf("Please enter the size of the file to download in MB: ");
    double fileSize;
    scanf("%lf", &fileSize);

    // convert MB into bytes
    long long int fileSizeBytes = (long long int) (fileSize * pow(10,6));

    // simulate download time using random number generator
    srand(time(NULL));
    long long int downloadTime = rand() % 11 + 10;

    // display simulated download time
    printf("Simulating download...\n");
    printf("Download time: %lld seconds\n", downloadTime);

    // calculate internet speed
    double speed = internetSpeedTest(downloadTime, fileSizeBytes);

    // display internet speed
    printf("Your internet speed is: %.2f Mbps\n", speed);

    // give recommendations based on internet speed
    if (speed >= 50) {
        printf("Wow! Your internet speed is extremely fast. Enjoy surfing the internet!\n");
    } else if (speed >= 25) {
        printf("Your internet speed is good. You should be able to stream videos and download files without any problems.\n");
    } else if (speed >= 10) {
        printf("Your internet speed is average. You might experience some buffering while streaming videos or downloading files, but overall, your experience should be decent.\n");
    } else {
        printf("Your internet speed is slow. You might experience a lot of buffering while streaming videos or downloading files. Consider upgrading your internet plan to get a better experience.\n");
    }

    return 0;
}