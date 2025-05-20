//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i;
    double cars, traffic, carsPerSec, trafficPerSec;
    int carCount = 0;
    int trafficCount = 0;
    int maxCars = 0;
    int maxTraffic = 0;
    double avgCarsPerSec = 0;
    double avgTrafficPerSec = 0;
    srand(time(0));

    printf("Traffic Flow Simulation\n");
    printf("Enter number of cars to simulate: ");
    scanf("%d", &n);
    cars = n * 100;
    printf("Number of cars: %f\n", cars);

    for (i = 0; i < cars; i++) {
        carCount++;
        if (carCount > maxCars) {
            maxCars = carCount;
        }
    }

    printf("Max number of cars: %d\n", maxCars);
    printf("Average cars per second: %f\n", (double)carCount / cars);

    printf("Enter number of traffic counts to simulate: ");
    scanf("%d", &n);
    traffic = n * 100;
    printf("Number of traffic counts: %f\n", traffic);

    for (i = 0; i < traffic; i++) {
        trafficCount++;
        if (trafficCount > maxTraffic) {
            maxTraffic = trafficCount;
        }
    }

    printf("Max number of traffic counts: %d\n", maxTraffic);
    printf("Average traffic counts per second: %f\n", (double)trafficCount / traffic);

    printf("Cars per second: %f\n", carsPerSec);
    printf("Traffic counts per second: %f\n", trafficPerSec);

    return 0;
}