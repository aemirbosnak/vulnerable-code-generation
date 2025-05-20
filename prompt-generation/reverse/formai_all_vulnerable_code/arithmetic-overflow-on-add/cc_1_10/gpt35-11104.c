//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <time.h>

void delay(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while(clock() < endwait){}
}

int main() {
    int downloadSpeed = 0;
    int uploadSpeed = 0;
    int testDuration = 10;
    int fileSize = 100;

    printf("Welcome to the Medieval Internet Speed Test!\n");
    printf("We will now test your download and upload speed, brave warrior.\n\n");

    printf("Preparing to download a file...\n");
    delay(3);

    printf("Beginning download...\n");
    delay(testDuration);

    printf("Download complete, checking file size...\n");
    delay(2);

    downloadSpeed = fileSize / testDuration;

    printf("Your download speed is %.2f MB/s.\n", downloadSpeed);

    printf("\nNow, let's test your upload speed. Prepare yourself!\n\n");

    printf("Preparing to upload a file...\n");
    delay(3);

    printf("Beginning upload...\n");
    delay(testDuration);

    printf("Upload complete, checking file size...\n");
    delay(2);

    uploadSpeed = fileSize / testDuration;

    printf("Your upload speed is %.2f MB/s.\n", uploadSpeed);

    printf("\nThank you for taking the Medieval Internet Speed Test.\n");
    printf("You are ready to battle in the online arena with the swiftness of your connection!\n");

    return 0;
}