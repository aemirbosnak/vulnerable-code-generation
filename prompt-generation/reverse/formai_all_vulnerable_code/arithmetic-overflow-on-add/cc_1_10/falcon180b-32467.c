//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 1000000 // Maximum number of steps that can be tracked

struct fitness_data {
    char name[50]; // User's name
    int steps; // Number of steps taken
    time_t last_updated; // Time when the step count was last updated
};

void init_fitness_data(struct fitness_data* data) {
    strcpy(data->name, "Unknown");
    data->steps = 0;
    data->last_updated = 0;
}

void print_fitness_data(struct fitness_data* data) {
    printf("Name: %s\n", data->name);
    printf("Steps: %d\n", data->steps);
    printf("Last updated: %s", ctime(&data->last_updated));
}

void update_step_count(struct fitness_data* data) {
    data->steps++;
    data->last_updated = time(NULL);
}

int main() {
    struct fitness_data user_data;
    init_fitness_data(&user_data);

    while (1) {
        printf("Enter your name (max 50 characters): ");
        scanf("%s", user_data.name);

        if (strlen(user_data.name) > 50) {
            printf("Name is too long! Try again.\n");
            continue;
        }

        break;
    }

    int choice;
    do {
        printf("\nFitness Tracker Menu:\n");
        printf("1. View fitness data\n");
        printf("2. Update step count\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_fitness_data(&user_data);
                break;
            case 2:
                update_step_count(&user_data);
                printf("\nStep count updated!\n");
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice!= 3);

    return 0;
}