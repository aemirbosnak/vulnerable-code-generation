//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int speedTest(int download, int upload){
    int speed, level;
    srand(time(0));

    if(download < 1){
        speed = rand() % 20 + 1;
    }
    else if(download >= 1 && download < 10){
        speed = rand() % 85 + 1;
    }
    else if(download >= 10 && download < 50){
        speed = rand() % 150 + 1;
    }
    else if(download >= 50 && download < 100){
        speed = rand() % 300 + 1;
    }
    else{
        speed = rand() % 600 + 1;
    }

    if(speed >= 1 && speed < 20){
        level = 1;
    }
    else if(speed >= 20 && speed < 85){
        level = 2;
    }
    else if(speed >= 85 && speed < 150){
        level = 3;
    }
    else if(speed >= 150 && speed < 300){
        level = 4;
    }
    else{
        level = 5;
    }

    printf("Your internet speed is %dMbps. \n", speed);
    printf("Your internet speed level is %d. \n", level);

    if(speed < upload){
        printf("Your internet speed is not good enough for uploading. \n");
        speedTest(download, upload);
    }

    return speed;
}

int main(){
    int download, upload;

    printf("Please enter your download speed in Mbps: ");
    scanf("%d", &download);

    printf("Please enter your upload speed in Mbps: ");
    scanf("%d", &upload);

    speedTest(download, upload);

    return 0;
}