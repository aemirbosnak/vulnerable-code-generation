//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int generate_car();
void delay(int);

int main()
{
    int i, cars = 0, lane1 = 0, lane2 = 0, total_cars = 0;
    srand((unsigned) time(NULL)); // seed random number generator with current time
    
    printf("\n===========================================");
    printf("\n       TRAFFIC FLOW SIMULATION PROGRAM      ");
    printf("\n===========================================\n");
    
    // simulate traffic flow for 10 minutes
    for(i = 0; i < 600; i++){
      
        // generate a car if probability is met
        if(generate_car()){
            total_cars++;
            
            // add the car to the lane with the least cars
            if(lane1 <= lane2) lane1++;
            else lane2++;
        }
      
        // print the current traffic flow every 30 seconds
        if(i % 30 == 0){
            printf("\n-------------------------------------------\n");
            printf("Time elapsed: %d seconds\n", i);
            printf("Total cars generated: %d\n", total_cars);
            printf("Lane 1 traffic flow: %d\n", lane1);
            printf("Lane 2 traffic flow: %d\n", lane2);
            printf("-------------------------------------------\n");    
        }
        
        // delay program execution for 100 milliseconds
        delay(100);
      
    }
  
    return 0;
}

// generates a random number between 0 and 9
int generate_car(){
    int rand_num = rand() % 10;
    if(rand_num > 7) return 1; // car generated
    else return 0; // no car generated
}

// delays program execution for specified amount of milliseconds
void delay(int milliseconds){
    long pause;
    clock_t now, start;
    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    start = clock();
    now = start;
    while((now-start) < pause) now = clock();
}