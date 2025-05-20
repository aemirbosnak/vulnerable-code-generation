//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1048576 // 1 MB
#define URL "http://speed.hetzner.de/100MB.bin"

void romantic_pause(double seconds) {
    int milliseconds = (int)(seconds * 1000);
    usleep(milliseconds);
}

void print_heart() {
    printf("\n");
    printf("       .:::.   .:::. \n");
    printf("     .:::::::.:::::::. \n");
    printf("    ::::::::::::::::::: \n");
    printf("     ':::::::::::::::' \n");
    printf("       ':::::::::::' \n");
    printf("          ':::::' \n");
    printf("            ' \n\n");
}

void announce_love() {
    printf("In a world intertwined by invisible threads,\n");
    printf("Our love traverses the vast digital expanse,\n");
    printf("Shall we measure the speed of our connection,\n");
    printf("As we dance across this technological romance?\n\n");
}

double download_speed() {
    char command[200];
    sprintf(command, "curl -o /dev/null -s -w '%%{speed_download}' %s", URL);
    
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    double speed = 0;
    fscanf(fp, "%lf", &speed);
    pclose(fp);
    
    return speed / 1024; // convert to KB/s
}

double upload_speed() {
    char command[200];
    sprintf(command, "curl -T /dev/zero -s -w '%%{speed_upload}' --url http://regr.php -o /dev/null");
    
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    double speed = 0;
    fscanf(fp, "%lf", &speed);
    pclose(fp);
    
    return speed / 1024; // convert to KB/s
}

void present_results(double download, double upload) {
    printf("Oh sweetheart,\n");
    printf("Today our network sings a melody so sweet:\n");

    romantic_pause(2);

    printf("Your download speed caresses us at: %.2f KB/s\n", download);
    printf("And your upload speed, a gentle touch, reaches: %.2f KB/s\n\n", upload);
    
    romantic_pause(2);
    
    printf("Every byte flows like a poem across the sky,\n");
    printf("Tethered by love, a bond that cannot die.\n\n");
    print_heart();
}

int main() {
    printf("Welcome to the Internet Speed Test, my love.\n");
    romantic_pause(1);
    announce_love();
    
    romantic_pause(2);
    
    printf("Let us begin our quest...\n");
    romantic_pause(2);
    
    double download = download_speed();
    double upload = upload_speed();

    present_results(download, upload);

    printf("Our connection may fade, or break like a sigh,\n");
    printf("But know, in this realm, my love will never die.\n");
    
    return 0;
}