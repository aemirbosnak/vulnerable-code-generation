//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define MAX_NAME_LEN 50
#define MAX_DURATION_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char duration[MAX_DURATION_LEN];
    int distance;
    int calories;
} Entry;

int main() {
    int num_entries = 0;
    Entry entries[MAX_ENTRIES];

    while (1) {
        printf("Fitness Tracker Menu:\n");
        printf("1. Add a new workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Cannot add more workouts. History is full.\n");
            } else {
                printf("Enter the name of the workout:\n");
                scanf("%s", entries[num_entries].name);
                printf("Enter the duration of the workout (in minutes):\n");
                scanf("%s", entries[num_entries].duration);
                printf("Enter the distance covered (in meters):\n");
                scanf("%d", &entries[num_entries].distance);
                printf("Enter the number of calories burned:\n");
                scanf("%d", &entries[num_entries].calories);
                num_entries++;
            }
            break;
        case 2:
            if (num_entries == 0) {
                printf("No workout history yet.\n");
            } else {
                printf("Workout History:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s - %s - %d meters - %d calories\n", entries[i].name, entries[i].duration, entries[i].distance, entries[i].calories);
                }
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}