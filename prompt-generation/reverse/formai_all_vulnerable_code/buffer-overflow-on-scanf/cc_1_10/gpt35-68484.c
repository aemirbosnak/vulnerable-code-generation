//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Function to generate random number between 1 and 100 */
int rand_num(){
    int num = (rand() % 100) + 1;
    return num;
}

/* Function to calculate internet speed */
void internet_speed_test(){
    float speed;
    int download_speed, upload_speed;
    int download_time, upload_time;
    int download_size, upload_size;

    printf("Enter the download size in megabytes: ");
    scanf("%d", &download_size);
    printf("Enter the upload size in megabytes: ");
    scanf("%d", &upload_size);

    /* Download speed test */
    printf("\nTesting download speed...\n");
    download_speed = rand_num();
    download_time = (download_size * 8.0) / download_speed;
    printf("Download speed: %d Mbps\n", download_speed);
    printf("Download time: %d seconds\n\n", download_time);

    /* Upload speed test */
    printf("Testing upload speed...\n");
    upload_speed = rand_num();
    upload_time = (upload_size * 8.0) / upload_speed;
    printf("Upload speed: %d Mbps\n", upload_speed);
    printf("Upload time: %d seconds\n\n", upload_time);

    /* Calculate average speed */
    speed = (download_speed + upload_speed) / 2.0;
    printf("Average speed: %.2f Mbps", speed);
}

int main(){

    /* Seed random number generator */
    srand(time(NULL));

    /* Call internet speed test function */
    internet_speed_test();

    return 0;
}