//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>

int main()
{
    int sit_ups = 0;
    int push_ups = 0;
    int squats = 0;
    int total_calories_burned = 0;

    printf("Welcome to the FunFitness Tracker!\n");
    printf("Get ready to have a great workout!\n");

    while(1)
    {
        printf("What workout did you do today?\n");
        printf("1) Sit-ups\n");
        printf("2) Push-ups\n");
        printf("3) Squats\n");
        printf("4) Quit\n");

        int option;
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Great choice! Let's get those abs working!\n");
                printf("How many sit-ups did you do?\n");
                int temp_sit_ups;
                scanf("%d", &temp_sit_ups);
                sit_ups += temp_sit_ups;
                total_calories_burned += temp_sit_ups * 2;
                break;

            case 2:
                printf("Get ready to strengthen those arms and chest!\n");
                printf("How many push-ups did you do?\n");
                int temp_push_ups;
                scanf("%d", &temp_push_ups);
                push_ups += temp_push_ups;
                total_calories_burned += temp_push_ups * 3;
                break;

            case 3:
                printf("Squats are a great way to tone your legs and butt!\n");
                printf("How many squats did you do?\n");
                int temp_squats;
                scanf("%d", &temp_squats);
                squats += temp_squats;
                total_calories_burned += temp_squats * 5;
                break;

            case 4:
                printf("Thanks for using FunFitness Tracker!\n");
                printf("Here's your workout summary:\n");
                printf("Sit-ups: %d\n", sit_ups);
                printf("Push-ups: %d\n", push_ups);
                printf("Squats: %d\n", squats);
                printf("Total Calories Burned: %d\n", total_calories_burned);
                return 0;

            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }
}