//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define DAYS_IN_WEEK 7
#define MAX_WORKOUTS 10

struct workout {
    char name[50];
    int duration;
    int calories_burned;
};

int main() {
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;
    int total_calories_burned = 0;
    
    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please enter your workouts for this week:\n");
    
    for (int i = 0; i < DAYS_IN_WEEK; i++) {
        char day[10];
        int duration, calories_burned;
        
        switch (i) {
            case 0:
                strcpy(day, "Monday");
                break;
            case 1:
                strcpy(day, "Tuesday");
                break;
            case 2:
                strcpy(day, "Wednesday");
                break;
            case 3:
                strcpy(day, "Thursday");
                break;
            case 4:
                strcpy(day, "Friday");
                break;
            case 5:
                strcpy(day, "Saturday");
                break;
            case 6:
                strcpy(day, "Sunday");
                break;
        }
        
        printf("Enter workout information for %s:\n", day);
        printf("Workout name: ");
        scanf("%s", workouts[num_workouts].name);
        printf("Duration (in minutes): ");
        scanf("%d", &duration);
        printf("Calories burned: ");
        scanf("%d", &calories_burned);
        
        workouts[num_workouts].duration = duration;
        workouts[num_workouts].calories_burned = calories_burned;
        total_calories_burned += calories_burned;
        
        num_workouts++;
    }
    
    printf("Here are your workouts for this week:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("Workout %d: %s (%d minutes, %d calories burned)\n", i+1, workouts[i].name, workouts[i].duration, workouts[i].calories_burned);
    }
    printf("Total calories burned this week: %d\n", total_calories_burned);
    
    return 0;
}