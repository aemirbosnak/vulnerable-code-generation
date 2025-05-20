//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

struct workout {
    char *name;
    int duration;
    int calories_burned;
};

void display_workout(struct workout *workout) {
    printf("Name: %s\nDuration: %d minutes\nCalories Burned: %d\n", workout->name, workout->duration, workout->calories_burned);
}

int main() {
    struct workout workout1 = {"Running", 30, 300};
    struct workout workout2 = {"Swimming", 45, 500};
    struct workout workout3 = {"Cycling", 60, 600};

    int choice;
    int total_calories_burned = 0;

    printf("Welcome to the Fitness Tracker!\n");

    while(1) {
        printf("Please choose a workout:\n1. Running\n2. Swimming\n3. Cycling\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                total_calories_burned += workout1.calories_burned;
                display_workout(&workout1);
                break;
            case 2:
                total_calories_burned += workout2.calories_burned;
                display_workout(&workout2);
                break;
            case 3:
                total_calories_burned += workout3.calories_burned;
                display_workout(&workout3);
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("\nTotal Calories Burned: %d\n", total_calories_burned);
    }

    return 0;
}