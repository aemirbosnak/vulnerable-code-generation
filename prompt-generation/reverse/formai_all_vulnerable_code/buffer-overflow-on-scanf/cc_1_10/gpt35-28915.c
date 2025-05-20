//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate random speed in Mbps
float generate_speed(){
    float speed = ((float)rand()/(float)(RAND_MAX)) * 100.0;
    return speed;
}

int main(){

    //seed the random number generator
    srand(time(NULL));

    //get user input for number of tests to be conducted
    int num_tests;
    printf("Enter the number of speed tests to be conducted: ");
    scanf("%d", &num_tests);

    //initialize variables to store maximum, minimum and average speed test results
    float max_speed = 0.0, min_speed = 100.0, total_speed = 0.0;

    //conduct speed tests
    for(int i=1; i<=num_tests; i++){
        //generate random speed in Mbps for each test
        float speed = generate_speed();

        //print test result
        printf("Speed Test #%d: %.2f Mbps\n", i, speed);

        //update maximum speed if current speed is greater
        if(speed > max_speed){
            max_speed = speed;
        }

        //update minimum speed if current speed is smaller
        if(speed < min_speed){
            min_speed = speed;
        }

        //add current speed to total speed for average calculation
        total_speed += speed;
    }

    //calculate and print average speed
    float avg_speed = total_speed/num_tests;
    printf("\nAverage Speed: %.2f Mbps\n", avg_speed);

    //print maximum and minimum speed test results
    printf("Maximum Speed: %.2f Mbps\n", max_speed);
    printf("Minimum Speed: %.2f Mbps\n", min_speed);

    return 0;
}