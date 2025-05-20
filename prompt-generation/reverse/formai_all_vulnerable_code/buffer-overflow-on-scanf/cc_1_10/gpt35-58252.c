//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROUTES 100
#define MAX_LOC 100
#define MAX_NAME 30

// Structure to hold location data
typedef struct loc {
    char name[MAX_NAME];
    float lat;
    float lng;
} loc_t;

// Structure to hold route data
typedef struct route {
    char name[MAX_NAME];
    int num_locs;
    loc_t locs[MAX_LOC];
} route_t;

int menu();
int read_input();
void add_route(route_t *routes, int *num_routes);
void display_routes(route_t *routes, int num_routes);
void navigate(route_t *routes, int num_routes);

int main() {
    route_t routes[MAX_ROUTES];
    int num_routes = 0;
    int option;
    
    while ((option = menu()) != 4) {
        switch(option) {
            case 1:
                add_route(routes, &num_routes);
                break;
            case 2:
                display_routes(routes, num_routes);
                break;
            case 3:
                navigate(routes, num_routes);
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    
    printf("Thank you for using the GPS Navigation Simulation.\n");
    
    return 0;
}

// Displays main menu
int menu() {
    int option;
    
    printf("GPS Navigation Simulation\n\n");
    printf("1. Add Route\n");
    printf("2. Display Routes\n");
    printf("3. Navigate\n");
    printf("4. Exit\n");
    
    printf("Enter your choice (1-4): ");
    option = read_input();
    
    return option;
}

// Reads integer input from user
int read_input() {
    int value;
    fflush(stdin);
    scanf("%d", &value);
    return value;
}

// Adds a new route to the system
void add_route(route_t *routes, int *num_routes) {
    if (*num_routes >= MAX_ROUTES) {
        printf("Maximum number of routes reached.\n");
        return;
    }
    
    printf("Enter route name: ");
    scanf("%s", routes[*num_routes].name);
    
    int num_locs;
    printf("Enter number of locations: ");
    num_locs = read_input();
    
    if (num_locs <= 0 || num_locs > MAX_LOC) {
        printf("Invalid number of locations.\n");
        return;
    }
    
    for (int i = 0; i < num_locs; i++) {
        printf("Enter location name: ");
        scanf("%s", routes[*num_routes].locs[i].name);
        
        printf("Enter latitude for %s: ", routes[*num_routes].locs[i].name);
        scanf("%f", &routes[*num_routes].locs[i].lat);
        
        printf("Enter longitude for %s: ", routes[*num_routes].locs[i].name);
        scanf("%f", &routes[*num_routes].locs[i].lng);
    }
    
    routes[*num_routes].num_locs = num_locs;
    (*num_routes)++;
    
    printf("Route added successfully.\n");
}

// Displays all routes
void display_routes(route_t *routes, int num_routes) {
    if (num_routes == 0) {
        printf("No routes added yet.\n");
        return;
    }
    
    printf("All Routes:\n");
    for (int i = 0; i < num_routes; i++) {
        printf("%d. %s (%d locations)\n", i+1, routes[i].name, routes[i].num_locs);
    }
}

// Allows user to navigate a selected route
void navigate(route_t *routes, int num_routes) {
    if (num_routes == 0) {
        printf("No routes added yet.\n");
        return;
    }
    
    display_routes(routes, num_routes);
    int route_choice;
    
    do {
        printf("Enter route choice (1-%d): ", num_routes);
        route_choice = read_input();
    } while (route_choice < 1 || route_choice > num_routes);
    
    int num_locs = routes[route_choice-1].num_locs;
    loc_t locs[num_locs];
    memcpy(locs, routes[route_choice-1].locs, sizeof(loc_t) * num_locs);
    
    int current_loc = 0;
    char destination[MAX_NAME];
    float distance;
    char unit[4];
    int speed;
    float time;
    
    printf("\nYou are at %s.\n", locs[current_loc].name);
    
    while (current_loc < num_locs-1) {
        printf("Enter your destination: ");
        scanf("%s", destination);
        
        for (int i = current_loc+1; i < num_locs; i++) {
            if (strcmp(destination, locs[i].name) == 0) {
                distance = sqrt(pow(locs[i].lat - locs[current_loc].lat, 2) +
                                 pow(locs[i].lng - locs[current_loc].lng, 2));
                
                printf("Distance to %s: %.2f km.\n", locs[i].name, distance);
                printf("Enter your preferred unit (km/miles): ");
                scanf("%s", unit);
                
                if (strcmp("miles", unit) == 0) {
                    distance *= 0.621371;
                }
                
                printf("Enter your speed (km/h or mph): ");
                scanf("%d", &speed);
                
                if (strcmp("mph", unit) == 0) {
                    speed *= 1.60934;
                }
                
                time = distance / speed;
                
                printf("Estimated time to %s: %.2f hours.\n", locs[i].name, time);
                current_loc = i;
                printf("You have reached %s.\n", locs[current_loc].name);
                break;
            } else if (i == num_locs-1) {
                printf("Invalid location entered, please try again.\n");
            }
        }
    }
    
    printf("You have reached your final destination.\n");
}