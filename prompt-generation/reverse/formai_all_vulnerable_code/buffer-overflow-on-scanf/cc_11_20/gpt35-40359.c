//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int carsComing = 0, carsLeaving = 0, currentTraffic = 0, timeOfDay = 0, maxTraffic = 0, totalCars = 0;
    printf("Welcome to the Traffic Flow Simulation Program!\n");
    printf("Enter the maximum number of cars that can be on the road at once: ");
    scanf("%d", &maxTraffic);
    printf("Enter the total number of cars you want to simulate: ");
    scanf("%d", &totalCars);
    printf("Starting simulation...\n\n");

    for(int i = 1; i <= totalCars; i++) {
        int direction = rand() % 2;
        timeOfDay = rand() % 24 + 1;
        if(timeOfDay >= 6 && timeOfDay <= 11) {
            printf("It is %d AM, ", timeOfDay);
        } else if(timeOfDay == 12) {
            printf("It is noon, ");
        } else if(timeOfDay >= 13 && timeOfDay <= 18) {
            printf("It is %d PM, ", timeOfDay - 12);
        } else if(timeOfDay >= 19 && timeOfDay <= 23) {
            printf("It is %d PM, ", timeOfDay - 12);
        } else {
            printf("It is %d AM, ", timeOfDay);
        }

        if(direction == 0) {
            printf("a car is arriving.\n");
            carsComing++;
            if(currentTraffic < maxTraffic) {
                currentTraffic++;
                printf("The car is able to enter the road. Current traffic: %d\n\n", currentTraffic);
            } else {
                printf("The car is unable to enter the road, the road is full. Current traffic: %d\n\n", currentTraffic);
            }
        } else {
            printf("a car is leaving.\n");
            carsLeaving++;
            if(currentTraffic > 0) {
                currentTraffic--;
                printf("The car is able to leave the road. Current traffic: %d\n\n", currentTraffic);
            } else {
                printf("No cars on the road, the road is empty. Current traffic: %d\n\n", currentTraffic);
            }
        }
    }

    printf("Traffic simulation complete!\n");
    printf("%d cars arrived and %d cars left. Final traffic: %d\n", carsComing, carsLeaving, currentTraffic);

    return 0;
}