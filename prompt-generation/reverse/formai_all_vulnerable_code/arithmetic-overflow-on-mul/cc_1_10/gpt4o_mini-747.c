//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BUFSIZE 1024
#define SLEEP_TIME 1

void simulate_download(int size_in_mb) {
    long sleep_time = (size_in_mb * 1000) / 10; // Mocking speed: 10MB/s
    printf("Initiating download of %d MB. This might take a while...\n", size_in_mb);
    for (int i = 0; i < size_in_mb; i++) {
        printf("Downloading... %d MB\r", i + 1);
        fflush(stdout);
        usleep(sleep_time);
    }
    printf("\nDownload complete!\n");
}

void simulate_upload(int size_in_mb) {
    long sleep_time = (size_in_mb * 1000) / 20; // Mocking speed: 20MB/s
    printf("Initiating upload of %d MB. Be patient, good things take time!\n", size_in_mb);
    for (int i = 0; i < size_in_mb; i++) {
        printf("Uploading... %d MB\r", i + 1);
        fflush(stdout);
        usleep(sleep_time);
    }
    printf("\nUpload complete!\n");
}

int main() {
    int download_size;
    int upload_size;
    
    // The program main - where all the fun begins!
    printf("Welcome to the Great Internet Speed Test!\n");
    printf("We will see how slow your internet really is! Just kidding...\n");
    
    printf("How many megabytes do you want to download? (e.g., 10) > ");
    scanf("%d", &download_size);
    
    if (download_size <= 0) {
        printf("Please enter a positive number, or I'll cry...\n");
        return 1;
    }

    simulate_download(download_size);

    printf("\nNow we are going to upload something equally useless!\n");
    printf("How many megabytes do you want to upload? (e.g., 5) > ");
    scanf("%d", &upload_size);

    if (upload_size <= 0) {
        printf("Please enter a positive number, or I won't process this data.\n");
        return 1;
    }

    simulate_upload(upload_size);

    printf("\nCongratulations! You've successfully completed the speed test!\n");
    printf("Your download and upload stats will now be presented on a throne...\n");
    
    // Simulate displaying fake stats
    sleep(SLEEP_TIME);
    printf("😄 Download Speed: %d MB/s\n", 10);
    printf("😄 Upload Speed: %d MB/s\n", 20);

    printf("Please don't be offended if your speed doesn't match these stats; it’s all in good fun! 😜\n");
    printf("Thank you for using the Great Internet Speed Test - powered by pixels and caffeine!\n");
    
    return 0;
}