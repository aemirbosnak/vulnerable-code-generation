//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// function to calculate internet speed
float internet_speed_calculation(float time_taken, float data_size){
    return data_size/time_taken;
}

int main(){

    // welcome message
    printf("Welcome to the C Internet Speed Test Application!\n");
    printf("This application will help you calculate your internet speed.\n");
    printf("Please be sure your internet connection is stable before running this test.\n");

    // prompt user to enter the data size to be used in the test
    float data_size;
    printf("\nPlease enter the size of data (in MB) to be used for the test:\n");
    scanf("%f",&data_size);

    // prompt user to start the test
    printf("\nPress enter to start the test!");
    getchar();

    // variables to hold the start and end time
    clock_t start_time, end_time;
    start_time = clock();

    // simulate the test by sleeping for a random amount of time between 5 to 10 seconds
    int sleep_time = rand() % 6 + 5;
    printf("\nSimulating test...\n");
    printf("\nPlease wait for %d seconds.", sleep_time);
    sleep(sleep_time);

    // calculate time taken
    end_time = clock();
    float time_taken = (float)(end_time - start_time)/CLOCKS_PER_SEC;

    // calculate internet speed
    float internet_speed = internet_speed_calculation(time_taken, data_size);

    // display the results
    printf("\nTest completed in %.2f seconds.\n", time_taken);
    printf("Your internet speed is %.2f MB/s.\n", internet_speed);
    printf("\nThank you for using the C Internet Speed Test Application!\n");

    return 0;
}