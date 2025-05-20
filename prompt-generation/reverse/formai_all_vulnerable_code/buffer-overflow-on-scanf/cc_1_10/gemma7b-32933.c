//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please select an option:\n");
    printf("1. Track Heart Rate\n");
    printf("2. Monitor Blood Pressure\n");
    printf("3. Record Exercise\n");
    printf("4. View Statistics\n");
    printf("Enter your choice:");
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your current heart rate:");
                int heart_rate;
                scanf("%d", &heart_rate);
                printf("Your heart rate is: %d", heart_rate);
                break;
            case 2:
                printf("Enter your blood pressure ( systolic/diastolic): ");
                int systolic, diastolic;
                scanf("%d/%d", &systolic, &diastolic);
                printf("Your blood pressure is: %d/%d", systolic, diastolic);
                break;
            case 3:
                printf("Enter the name of your exercise:");
                char exercise_name[20];
                scanf("%s", exercise_name);
                printf("Enter the duration of your exercise (in minutes): ");
                int duration;
                scanf("%d", &duration);
                printf("Enter the number of repetitions you completed:");
                int repetitions;
                scanf("%d", &repetitions);
                printf("Thank you for recording your exercise: %s, %d minutes, %d repetitions\n", exercise_name, duration, repetitions);
                break;
            case 4:
                printf("Your statistics:\n");
                // Display statistics
                break;
            default:
                printf("Invalid selection.\n");
        }
    } while (choice != 5);

    return 0;
}