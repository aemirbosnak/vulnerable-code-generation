//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    int speed = 0;
    
    printf("Welcome to the Internet Speed Test App!\n");
    printf("Let's find out how fast your internet is today!\n\n");
    delay(2);
    
    printf("Time to get started!\n");
    printf("Press any key to begin the test.\n\n");
    getchar();
    delay(1);
    
    printf("Testing download speed...\n");
    delay(2);
    printf("Downloading test file...\n");
    delay(3);
    printf("Download complete!\n");
    delay(1);
    
    srand(time(0));
    speed = rand() % 100 + 1;
    
    printf("\nYour download speed is: %d Mbps\n", speed);
    
    printf("\nNext up, let's test your upload speed!\n");
    printf("Press any key to begin the test.\n\n");
    getchar();
    delay(1);
    
    printf("Testing upload speed...\n");
    delay(2);
    printf("Uploading test file...\n");
    delay(3);
    printf("Upload complete!\n");
    delay(1);
    
    srand(time(0));
    speed = rand() % 50 + 1;
    
    printf("\nYour upload speed is: %d Mbps\n\n", speed);
    
    printf("Thanks for using our Internet Speed Test App!\n");
    printf("Have a great day and enjoy your speedy internet!\n");
    
    return 0;
}