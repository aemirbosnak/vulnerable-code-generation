//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARS 100
#define ROAD_LENGTH 10

int main()
{
    int num_cars, i, j, k;
    int cars_on_road[MAX_CARS];
    int road[ROAD_LENGTH];

    srand(time(0));

    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    if(num_cars > MAX_CARS){
        printf("Maximum cars allowed is %d\n", MAX_CARS);
        return -1;
    }

    // initialize the cars on the road
    for(i=0; i<num_cars; i++){
        cars_on_road[i] = i+1;
    }

    // initialize the road
    for(i=0; i<ROAD_LENGTH; i++){
        road[i] = 0;
    }

    // randomly place cars on the road
    for(i=0; i<num_cars; i++){
        k = rand()%ROAD_LENGTH;
        while(road[k] != 0){
            k = rand()%ROAD_LENGTH;
        }
        road[k] = cars_on_road[i];
    }

    // simulate traffic flow
    for(i=0; i<100; i++){
        // move all cars one step forward
        for(j=ROAD_LENGTH-1; j>=0; j--){
            if(j==0){
                road[j] = 0;
            }else{
                road[j] = road[j-1];
            }
        }

        // randomly stop some cars
        for(j=0; j<num_cars; j++){
            k = rand()%2;
            if(k==1 && road[0]==cars_on_road[j]){
                road[0] = 0;
            }
        }

        // randomly add new cars to the road
        k = rand()%2;
        if(k==1){
            for(j=0; j<num_cars; j++){
                if(road[0]==0){
                    road[0] = cars_on_road[j];
                    break;
                }
            }
        }

        // print the current state of the road
        printf("Iteration %d: ", i+1);
        for(j=0; j<ROAD_LENGTH; j++){
            if(road[j]==0){
                printf("-");
            }else{
                printf("%d", road[j]);
            }
        }
        printf("\n");
    }

    return 0;
}