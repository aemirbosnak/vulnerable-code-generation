//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void delay(int milliseconds){
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

int main(){
    int current_location[] = {0, 0}; //initial location at (0,0)
    int dest_location[] = {rand() % 100, rand() % 100}; //random destination location
    bool is_arrived = false;

    printf("Destination location: (%d,%d)\n", dest_location[0], dest_location[1]);
    printf("\nStarting GPS Navigation Simulation...\n");

    while(!is_arrived){
        int x_diff = dest_location[0] - current_location[0];
        int y_diff = dest_location[1] - current_location[1];

        if(x_diff > 0){
            printf("Go east %d meters\n", x_diff);
            current_location[0] += x_diff;
        }else if(x_diff < 0){
            printf("Go west %d meters\n", abs(x_diff));
            current_location[0] += x_diff;
        }

        if(y_diff > 0){
            printf("Go north %d meters\n", y_diff);
            current_location[1] += y_diff;
        }else if(y_diff < 0){
            printf("Go south %d meters\n", abs(y_diff));
            current_location[1] += y_diff;
        }

        printf("\nCurrent location: (%d,%d)\n", current_location[0], current_location[1]);

        if(current_location[0] == dest_location[0] && current_location[1] == dest_location[1]){
            //reached destination
            printf("Arrived at destination!\n");
            is_arrived = true;
        }

        delay(2000); //wait for 2 seconds before next movement
    }

    return 0;
}