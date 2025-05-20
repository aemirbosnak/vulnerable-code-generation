//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 50

typedef struct {
    int floor;
    int direction; // 1 for up, -1 for down
} Request;

typedef struct {
    int currentFloor;
    int totalTrips;
    double totalWaitTime;
    double totalRideTime;
    int totalRequestsServed;
} Elevator;

void generateRequests(Request requests[], int numRequests) {
    srand(time(0));
    for (int i = 0; i < numRequests; i++) {
        requests[i].floor = rand() % MAX_FLOORS;
        requests[i].direction = (rand() % 2) ? 1 : -1;
    }
}

void serveRequest(Elevator *elevator, Request request) {
    int waitTime = abs(request.floor - elevator->currentFloor) * 2; // 2 seconds per floor
    int rideTime = abs(request.floor - elevator->currentFloor) * 2;

    elevator->totalWaitTime += waitTime;
    elevator->totalRideTime += rideTime;
    elevator->totalRequestsServed++;
    elevator->currentFloor = request.floor;
    elevator->totalTrips++;

    printf("Elevator moving to floor %d\n", request.floor);
    printf("Wait time: %d seconds, Ride time: %d seconds\n", waitTime, rideTime);
}

void printStatistics(Elevator elevator) {
    if (elevator.totalRequestsServed > 0) {
        printf("\n--- Elevator Statistics ---\n");
        printf("Total Trips: %d\n", elevator.totalTrips);
        printf("Total Requests Served: %d\n", elevator.totalRequestsServed);
        printf("Average Wait Time: %.2f seconds\n", elevator.totalWaitTime / elevator.totalRequestsServed);
        printf("Average Ride Time: %.2f seconds\n", elevator.totalRideTime / elevator.totalRequestsServed);
    } else {
        printf("No requests were served.\n");
    }
}

int main() {
    Elevator elevator = {0, 0, 0.0, 0.0, 0};
    Request requests[MAX_REQUESTS];

    int numRequests;
    printf("Enter the number of requests (up to %d): ", MAX_REQUESTS);
    scanf("%d", &numRequests);

    if (numRequests < 1 || numRequests > MAX_REQUESTS) {
        printf("Invalid number of requests. Please run the program again.\n");
        return 1;
    }

    generateRequests(requests, numRequests);

    for (int i = 0; i < numRequests; i++) {
        serveRequest(&elevator, requests[i]);
    }

    printStatistics(elevator);
    
    return 0;
}