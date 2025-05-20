//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTES 10
#define MAX_STEPS 100

typedef struct {
    int distance;
    char *address;
} Route;

typedef struct {
    int current_step;
    Route routes[MAX_ROUTES];
} Navigation;

void add_route(Navigation *nav, int distance, char *address) {
    if (nav->current_step >= MAX_ROUTES) {
        printf("Maximum number of routes reached.\n");
        return;
    }
    nav->routes[nav->current_step].distance = distance;
    nav->routes[nav->current_step].address = address;
    nav->current_step++;
}

void print_routes(Navigation *nav) {
    printf("Available routes:\n");
    for (int i = 0; i < nav->current_step; i++) {
        printf("%s - %d meters\n", nav->routes[i].address, nav->routes[i].distance);
    }
}

void navigate(Navigation *nav, char *destination) {
    if (nav->current_step == 0) {
        printf("No routes available.\n");
        return;
    }
    printf("Entering navigation mode...\n");
    char input[100];
    while (1) {
        printf("Current location: %s\n", nav->routes[nav->current_step - 1].address);
        printf("Enter next step (address or quit): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, destination) == 0) {
            printf("Arrived at destination: %s\n", destination);
            break;
        } else {
            int found = 0;
            for (int i = 0; i < nav->current_step; i++) {
                if (strcmp(input, nav->routes[i].address) == 0) {
                    nav->current_step = i + 1;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Invalid address.\n");
            }
        }
    }
}

int main() {
    Navigation nav;
    nav.current_step = 0;
    add_route(&nav, 500, "Home");
    add_route(&nav, 1000, "School");
    add_route(&nav, 2000, "Work");
    print_routes(&nav);
    char destination[100];
    printf("Enter destination: ");
    scanf("%s", destination);
    navigate(&nav, destination);
    return 0;
}