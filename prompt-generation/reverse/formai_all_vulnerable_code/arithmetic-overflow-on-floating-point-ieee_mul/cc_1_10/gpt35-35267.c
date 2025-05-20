//FormAI DATASET v1.0 Category: Physics simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate distance between two points
double distance(int x1, int y1, int x2, int y2){
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int main(){
    // Initializing variables
    int speed = 10; // Speed in meters per second
    int x1 = 0, y1 = 0, x2 = 30, y2 = 40; // Starting and ending points
    int steps = 100; // Number of steps
    double dx = (double)(x2 - x1) / steps; // Distance to move in x axis for each step
    double dy = (double)(y2 - y1) / steps; // Distance to move in y axis for each step
    double distance_travelled = 0; // Total distance travelled by the object
    double distance_to_target = distance(x1, y1, x2, y2); // Distance between starting and ending points
    double time_taken = 0; // Time taken to reach the target
    double time_per_step = 1 / (double)speed; // Time taken to move 1 meter at given speed
    
    // Main loop to simulate the movement of object
    for(int i = 1; i <= steps; i++){
        // Update position
        x1 += dx;
        y1 += dy;
        
        // Calculate distance travelled
        distance_travelled += distance(dx*(i-1), dy*(i-1), dx*i, dy*i);
        
        // Check if target is reached
        if(distance_travelled >= distance_to_target){
            time_taken = (i-1) * time_per_step + (distance_to_target - (distance_travelled - distance(dx*(i-1), dy*(i-1), dx*i, dy*i))) / speed;
            break;
        }
        
        // Wait for time_per_step seconds before next step
        printf("Step %d: (%d, %d)\n", i, x1, y1);
        for(int j = 0; j < round(time_per_step * 1000); j++){
            // wait for 1 ms
            int a = 1;
            for(int k = 0; k < 100000; k++){
                a += k * a;
            }
        }
    }
    
    printf("Target reached in %.2f seconds\n", time_taken);
    
    return 0;
}