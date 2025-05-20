//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCATIONS 20
#define MIN_DISTANCE 1000
#define MAX_DISTANCE 10000

typedef struct {
    int x;
    int y;
    char name[20];
} location;

void generate_random_location(location* loc) {
    loc->x = rand() % 1000;
    loc->y = rand() % 1000;
    sprintf(loc->name, "Location %d", rand() % 100);
}

int calculate_distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void print_location(location* loc) {
    printf("(%d, %d) - %s\n", loc->x, loc->y, loc->name);
}

int main() {
    srand(time(NULL));

    location user_location;
    generate_random_location(&user_location);

    location locations[MAX_LOCATIONS];
    int num_locations = 0;

    while (num_locations < MAX_LOCATIONS) {
        generate_random_location(&locations[num_locations]);
        num_locations++;
    }

    printf("Enter your current location:\n");
    scanf("%d %d", &user_location.x, &user_location.y);

    printf("Nearby locations:\n");
    for (int i = 0; i < num_locations; i++) {
        int distance = calculate_distance(user_location.x, user_location.y, locations[i].x, locations[i].y);
        if (distance >= MIN_DISTANCE && distance <= MAX_DISTANCE) {
            print_location(&locations[i]);
        }
    }

    return 0;
}