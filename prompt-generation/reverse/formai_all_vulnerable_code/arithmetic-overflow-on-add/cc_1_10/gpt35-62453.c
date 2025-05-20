//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds);
} 

int main(){
    printf("C Traffic Flow Simulation Example\n\n");
    printf("Initializing roads...");
    delay(2);
    
    printf("\n\nRoads initialized!\n");
    printf("\n\nStarting simulation...\n\n");
    delay(2);
    
    int total_cars=0, north_south_cars=0, east_west_cars=0;
    int north_cars_waiting=0, south_cars_waiting=0, east_cars_waiting=0, west_cars_waiting=0;
    
    for(int i=0;i<10;i++){
        printf("\n\n----------Iteration %d begins----------\n\n",i+1);
        delay(2);
        int new_cars=rand()%15;
        printf("%d new cars approached the traffic signal.",new_cars);
        total_cars+=new_cars;
        printf("\nTotal cars waiting in queue: %d\n",total_cars);
        for(int j=0;j<new_cars;j++){
            int road=rand()%4;
            if(road==0){
                printf("A car wants to go North.\n");
                north_cars_waiting++;
            }
            else if(road==1){
                printf("A car wants to go South.\n");
                south_cars_waiting++;
            }
            else if(road==2){
                printf("A car wants to go East.\n");
                east_cars_waiting++;
            }
            else{
                printf("A car wants to go West.\n");
                west_cars_waiting++;
            }
        }
        
        printf("\nNumber of cars currently waiting:\n");
        printf("North : %d\nSouth : %d\nEast : %d\nWest : %d\n\n",north_cars_waiting,south_cars_waiting,east_cars_waiting,west_cars_waiting);
        delay(2);
        
        while(north_cars_waiting>0 || south_cars_waiting>0 || east_cars_waiting>0 || west_cars_waiting>0){
            
            if(north_cars_waiting>0||south_cars_waiting==0){
                printf("Green signal for North-South has been turned on, %d cars will proceed.",north_cars_waiting);
                north_south_cars+=north_cars_waiting;
                total_cars-=north_cars_waiting;
                north_cars_waiting=0;
                delay(2);
            }
            else if(south_cars_waiting>0||north_cars_waiting==0){
                printf("Green signal for North-South has been turned on, %d cars will proceed.",south_cars_waiting);
                north_south_cars+=south_cars_waiting;
                total_cars-=south_cars_waiting;
                south_cars_waiting=0;
                delay(2);
            }
            
            if(east_cars_waiting>0||west_cars_waiting==0){
                printf("Green signal for East-West has been turned on, %d cars will proceed.",east_cars_waiting);
                east_west_cars+=east_cars_waiting;
                total_cars-=east_cars_waiting;
                east_cars_waiting=0;
                delay(2);
            }
            else if(west_cars_waiting>0||east_cars_waiting==0){
                printf("Green signal for East-West has been turned on, %d cars will proceed.",west_cars_waiting);
                east_west_cars+=west_cars_waiting;
                total_cars-=west_cars_waiting;
                west_cars_waiting=0;
                delay(2);
            }
        }
        printf("\n\nAt the end of iteration %d...\n",i+1);
        printf("North-South Road had %d cars pass through.",north_south_cars);
        printf("\nEast-West Road had %d cars pass through.\n",east_west_cars);
        delay(2);
        north_south_cars=0;
        east_west_cars=0;
    }
    printf("\n\nSimulation has ended!");
    return 0;
}