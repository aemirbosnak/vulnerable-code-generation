//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define TIME_PERIOD_COUNT 5

const char *time_periods[TIME_PERIOD_COUNT] = {
    "Ancient Egypt - 2500 BC",
    "Middle Ages - 1300 AD",
    "Renaissance - 1500 AD",
    "Industrial Revolution - 1800 AD",
    "Future - 3000 AD"
};

typedef struct {
    int period_index;
    int duration;
} TravelInfo;

void *simulate_time_travel(void *info) {
    TravelInfo *travel_info = (TravelInfo *)info;
    int index = travel_info->period_index;
    int duration = travel_info->duration;

    printf("Starting time travel to %s...\n", time_periods[index]);
    sleep(duration);  // Simulate time travel duration
    printf("Arrived in %s! Welcome to a different time!\n", time_periods[index]);

    if (index == 0) {
        printf("You see the Great Pyramids being built!\n");
    } else if (index == 1) {
        printf("Knights in shiny armor roam the land, and you can hear the clash of swords.\n");
    } else if (index == 2) {
        printf("Art and science flourish; meet Galileo!\n");
    } else if (index == 3) {
        printf("Smoke and machines surround you; welcome to the Industrial Age!\n");
    } else {
        printf("Flying cars and robots everywhere; welcome to the Future!\n");
    }

    free(info);  // Free the allocated memory for travel info
    return NULL;
}

int main() {
    while (1) {
        printf("\nSelect a time period to travel to:\n");
        for (int i = 0; i < TIME_PERIOD_COUNT; i++) {
            printf("[%d] %s\n", i + 1, time_periods[i]);
        }
        printf("[0] Exit\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the time travel simulator. Safe travels!\n");
            break;
        } else if (choice < 1 || choice > TIME_PERIOD_COUNT) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        int duration = 3; // Simulate 3 seconds of time travel
        TravelInfo *info = malloc(sizeof(TravelInfo));
        if (info == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        info->period_index = choice - 1;  // Convert to 0 index
        info->duration = duration;

        pthread_t travel_thread;
        if (pthread_create(&travel_thread, NULL, simulate_time_travel, info) != 0) {
            fprintf(stderr, "Error creating thread\n");
            free(info);
            return 1;
        }

        // Detach the thread to allow it to run independently
        pthread_detach(travel_thread);
    }

    return 0;
}