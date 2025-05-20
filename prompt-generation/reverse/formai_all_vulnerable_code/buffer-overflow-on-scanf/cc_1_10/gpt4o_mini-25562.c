//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define MAX_DESTINATIONS 5
#define BUFFER_SIZE 256

typedef struct {
    char destination[BUFFER_SIZE];
    int estimated_time;
} Route;

volatile int running = 1;

void* gpsUpdateThread(void* arg) {
    Route* route = (Route*)arg;
    int elapsed_time = 0;

    printf("Navigating to %s...\n", route->destination);
    while (elapsed_time < route->estimated_time && running) {
        sleep(1);
        elapsed_time++;
        printf("GPS Update: %d seconds elapsed on route to %s...\n", elapsed_time, route->destination);
    }

    if (running) {
        printf("Arrived at %s! Congratulations!\n", route->destination);
    }
    return NULL;
}

void signalHandler(int signal) {
    if (signal == SIGINT) {
        running = 0;
        printf("\nNavigation cancelled. Exiting...\n");
    }
}

void initializeRoute(Route* route, const char* destination, int estimated_time) {
    strncpy(route->destination, destination, BUFFER_SIZE);
    route->estimated_time = estimated_time;
}

int main() {
    signal(SIGINT, signalHandler);
    
    Route routes[MAX_DESTINATIONS];
    pthread_t gps_thread[MAX_DESTINATIONS];
    int choice;
    int route_count = 0;

    while (1) {
        printf("GPS Navigation System:\n");
        printf("1. Set Destination\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                if (route_count >= MAX_DESTINATIONS) {
                    printf("Maximum destinations reached.\n");
                    break;
                }
                printf("Enter destination: ");
                char destination[BUFFER_SIZE];
                fgets(destination, sizeof(destination), stdin);
                destination[strcspn(destination, "\n")] = 0; // Remove newline

                printf("Enter estimated time (in seconds): ");
                int est_time;
                scanf("%d", &est_time);

                initializeRoute(&routes[route_count], destination, est_time);
                pthread_create(&gps_thread[route_count], NULL, gpsUpdateThread, &routes[route_count]);
                route_count++;
                break;

            case 2:
                running = 0; // Stop all threads
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        if (!running) {
            break;
        }
    }

    for (int i = 0; i < route_count; i++) {
        pthread_join(gps_thread[i], NULL);
    }

    printf("All navigation threads completed.\n");
    return 0;
}