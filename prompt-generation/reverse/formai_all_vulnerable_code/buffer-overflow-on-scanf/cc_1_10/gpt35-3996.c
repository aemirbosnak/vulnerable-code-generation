//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int red_time, yellow_time, green_time; // time for each light
    int signal; // variable to store signal of traffic light
    time_t start, end; // variables to store start and end time

    srand(time(0)); // initialize the random seed

    printf("Enter the time for Red Light: ");
    scanf("%d",&red_time);

    printf("Enter the time for Yellow Light: ");
    scanf("%d",&yellow_time);

    printf("Enter the time for Green Light: ");
    scanf("%d",&green_time);

    while(1){
        signal = rand() % 3; // generate random signal

        if(signal == 0){
            printf("Red Light On\n");
            time(&start); // start the timer

            while(1){
                time(&end);
                if(difftime(end, start) >= red_time) // wait for red_time seconds
                    break;
            }
        }
        else if(signal == 1){
            printf("Yellow Light On\n");
            time(&start); // start the timer

            while(1){
                time(&end);
                if(difftime(end, start) >= yellow_time) // wait for yellow_time seconds
                    break;
            }
        }
        else{
            printf("Green Light On\n");
            time(&start); // start the timer

            while(1){
                time(&end);
                if(difftime(end, start) >= green_time) // wait for green_time seconds
                    break;
            }
        }
    }
    return 0;
}