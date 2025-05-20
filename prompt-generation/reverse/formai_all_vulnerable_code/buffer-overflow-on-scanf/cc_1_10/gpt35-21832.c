//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

bool is_integer(char* input) {
    // Check if input is an integer
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] < '0' || input[i] > '9') {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    char choice[10];
    int steps = 0;
    int calories_burned = 0;
    float distance_covered = 0.0;

    printf("Welcome to the Fitness Tracker!\n\n");

    while (true) {
        //Options Menu
        printf("Choose your option:\n");
        printf("1. Enter number of steps\n");
        printf("2. Calculate burned calories\n");
        printf("3. Calculate distance covered\n");
        printf("4. Exit program\n\n");
        printf("Enter your choice: ");

        scanf("%s", choice);

        if (!is_integer(choice)) {
            printf("\nInvalid input. Please enter a number.\n\n");
            continue;
        }

        switch (atoi(choice)) {
            case 1:
                printf("\nPlease enter the number of steps taken: ");
                scanf("%d",&steps);
                printf("Number of steps entered: %d\n\n", steps);
                break;
            case 2:
                calories_burned = steps * 0.05; //assuming 1 step = 0.05 calories
                printf("\nThe number of calories burned: %d\n\n", calories_burned);
                break;
            case 3:
                distance_covered = steps * 0.8; //assuming 1 step = 0.8 meters
                printf("\nThe distance covered in meters: %.2f\n\n", distance_covered);
                break;
            case 4:
                printf("\nThank you for using the Fitness Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid input. Please enter a number between 1 and 4.\n\n");
                break;
        }
    }
    return 0;
}