//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEALTH_POINTS 100
#define MAX_STEPS 10000

typedef struct {
    char name[20];
    int health_points;
    int steps;
    int calories_burned;
    time_t last_updated;
} User;

void init_user(User* user) {
    user->health_points = MAX_HEALTH_POINTS;
    user->steps = 0;
    user->calories_burned = 0;
    user->last_updated = time(NULL);
}

void update_user(User* user, int steps) {
    user->steps += steps;
    user->calories_burned += steps * 10;
    if (user->steps >= MAX_STEPS) {
        user->health_points--;
        user->steps = 0;
    }
    user->last_updated = time(NULL);
}

void print_user(User* user) {
    printf("Name: %s\n", user->name);
    printf("Health Points: %d\n", user->health_points);
    printf("Steps: %d\n", user->steps);
    printf("Calories Burned: %d\n", user->calories_burned);
    printf("Last Updated: %s\n", ctime(&user->last_updated));
}

int main() {
    User user;
    init_user(&user);

    int choice;
    while (1) {
        printf("Fitness Tracker Menu:\n");
        printf("1. Update Steps\n");
        printf("2. Print User Info\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of steps: ");
            int steps;
            scanf("%d", &steps);
            update_user(&user, steps);
            break;
        case 2:
            print_user(&user);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}