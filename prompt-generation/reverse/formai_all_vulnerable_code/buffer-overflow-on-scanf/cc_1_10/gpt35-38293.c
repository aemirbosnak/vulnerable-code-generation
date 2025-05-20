//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10

typedef struct {
    char name[20];
    float lat;
    float lon;
} City;

City cities[MAX_CITIES] = {
    {"Nashville", 36.1627, -86.7816},
    {"Memphis", 35.1495, -90.0490},
    {"Knoxville", 35.9606, -83.9207},
    {"Chattanooga", 35.0456, -85.3097},
    {"Clarksville", 36.5298, -87.3595},
    {"Jackson", 35.6145, -88.8139},
    {"Johnson City", 36.3134, -82.3535},
    {"Murfreesboro", 35.8456, -86.3903},
    {"Franklin", 35.9251, -86.8689},
    {"Oak Ridge", 36.0104, -84.2696}
};

float rand_float(float min, float max) {
    return min + (rand() / (float)RAND_MAX) * (max - min);
}

int main() {
    srand(time(NULL));
    
    char from[20], to[20];
    printf("Enter starting city: ");
    scanf("%s", from);
    printf("Enter destination city: ");
    scanf("%s", to);
    
    City *start = NULL, *end = NULL;
    for(int i=0; i<MAX_CITIES; i++) {
        if(strcmp(cities[i].name, from) == 0) {
            start = &cities[i];
        } else if(strcmp(cities[i].name, to) == 0) {
            end = &cities[i];
        }
    }
    if(start == NULL || end == NULL) {
        printf("Invalid input\n");
        return 1;
    }
    
    float lat = rand_float(start->lat, end->lat);
    float lon = rand_float(start->lon, end->lon);
    printf("You are currently at latitude %f and longitude %f\n", lat, lon);
    
    return 0;
}