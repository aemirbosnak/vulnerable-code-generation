//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i, j, sum = 0, speed = 0, avg_speed = 0;
    double time_taken = 0.0;
    clock_t t;

    printf("Welcome to the C Internet Speed Test Application!\n\n");

    printf("This program will simulate your internet speed by measuring the time taken\n");
    printf("for your computer to download and upload a set amount of data to a server.\n\n");

    printf("Please enter the size of the data you would like to download and upload (in MB): ");
    scanf("%d", &j);

    printf("\nPlease wait while we run the speed test...\n\n");

    for (i = 1; i <= 10; i++) {

        t = clock();

        // Simulates downloading data by looping and summing up 1s
        while (sum < (j*1024*1024)) {
            sum++;
        }

        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;

        // Calculates speed in mbps and adds it to total speed
        speed = (double)j / ((double)t/CLOCKS_PER_SEC * 1024 * 1024);
        avg_speed += speed;

        printf("Download Test %d: Speed = %d mbps, Time Taken = %lf sec\n", i, speed, ((double)t)/CLOCKS_PER_SEC);

        sum = 0;

        t = clock();

        // Simulates uploading data by looping and summing up 1s
        while (sum < (j*1024*1024)) {
            sum++;
        }

        t = clock() - t;
        time_taken += ((double)t)/CLOCKS_PER_SEC;

        // Calculates speed in mbps and adds it to total speed
        speed = (double)j / ((double)t/CLOCKS_PER_SEC * 1024 * 1024);
        avg_speed += speed;

        printf("Upload Test %d: Speed = %d mbps, Time Taken = %lf sec\n", i, speed, ((double)t)/CLOCKS_PER_SEC);

        sum = 0;

    }

    // Calculates average speed and time taken
    avg_speed /= 20;
    time_taken /= 20;

    printf("\n\nSpeed Test Complete!\n\n");

    printf("Average Download Speed: %d mbps\n", avg_speed);
    printf("Average Upload Speed: %d mbps\n", avg_speed);

    printf("Total Time Taken: %lf sec\n", time_taken);

    return 0;
}