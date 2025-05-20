//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01
#define DEG_TO_RAD 0.0174532925

//structures to hold latitude and longitude
typedef struct {
    double latitude;
    double longitude;
} Coordinates;

//function to calculate distance between two coordinates
double distance(Coordinates c1, Coordinates c2) {
    double dLat = c2.latitude - c1.latitude;
    double dLon = c2.longitude - c1.longitude;
    double a = sin(dLat/2)*sin(dLat/2) + cos(c1.latitude)*cos(c2.latitude)*sin(dLon/2)*sin(dLon/2);
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    return EARTH_RADIUS*c; //returns distance in kilometers
}

//function to get current time in seconds
int getCurrTime() {
    time_t t = time(NULL);
    return (int)t;
}

//function to get user input for coordinates
void getUserInput(Coordinates* c) {
    printf("Enter latitude: ");
    scanf("%lf", &c->latitude);
    printf("Enter longitude: ");
    scanf("%lf", &c->longitude);
}

//function to print coordinates
void printCoordinates(Coordinates c) {
    printf("Latitude: %.6lf\n", c.latitude);
    printf("Longitude: %.6lf\n", c.longitude);
}

//function to simulate GPS navigation
void simulateGPS(Coordinates start, Coordinates end, int timeLimit) {
    double distanceTraveled = 0;
    int currTime = getCurrTime();
    while (currTime < timeLimit) {
        distanceTraveled += 1; //assume 1 meter per second for simplicity
        currTime++;
    }
    double totalDistance = distance(start, end);
    double percentageComplete = (distanceTraveled/totalDistance)*100;
    printf("You have traveled %.2lf%% of the distance.\n", percentageComplete);
}

int main() {
    Coordinates start, end;
    getUserInput(&start);
    getUserInput(&end);
    int timeLimit;
    printf("Enter time limit in seconds: ");
    scanf("%d", &timeLimit);
    simulateGPS(start, end, timeLimit);
    return 0;
}