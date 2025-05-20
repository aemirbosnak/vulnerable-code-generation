//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>

int main()
{
    int steps = 0;
    int calories = 0;
    float distance = 0.0;

    printf("Welcome to the Fitness Tracker!\n");

    while (1)
    {
        int choice;
        printf("\nWhat do you want to do?\n");
        printf("1. Record your steps\n");
        printf("2. Record your calories\n");
        printf("3. Record your distance\n");
        printf("4. Exit the program\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int s;
                printf("\nEnter the number of steps you have taken today: ");
                scanf("%d", &s);
                steps += s;
                printf("Total Steps: %d\n", steps);
                break;
            }
            case 2:
            {
                int c;
                printf("\nEnter the number of calories burnt today: ");
                scanf("%d", &c);
                calories += c;
                printf("Total Calories: %d\n", calories);
                break;
            }
            case 3:
            {
                float d;
                printf("\nEnter the distance you covered today (in meters): ");
                scanf("%f", &d);
                distance += d;
                printf("Total Distance: %.2f meters\n", distance);
                break;
            }
            case 4:
            {
                printf("\nThank you for using the Fitness Tracker!\n");
                return 0;
            }
            default:
            {
                printf("\nInvalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}