//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include<stdio.h>

int main(){

    int daysNoExercise = 0;
    int totalPushups = 0;
    int totalSitups = 0;
    int totalSquats = 0;

    printf("\n\nWelcome to the C Fitness Tracker app!\n\nGet ready to sweat and pump those muscles!\n\n");

    while(1){

        printf("Have you exercised today? (Enter 1 for Yes / 0 for No)\n");
        int exerciseStatus;
        scanf("%d", &exerciseStatus);

        if(exerciseStatus == 0){
            printf("\nWoopsie! You gotta get up and get moving!\n");
            daysNoExercise++;
        }

        else if(exerciseStatus == 1){

            int pushups, situps, squats;
            printf("\nEnter the number of pushups you did today:\n");
            scanf("%d", &pushups);
            
            printf("Enter the number of situps you did today:\n");
            scanf("%d", &situps);

            printf("Enter the number of squats you did today:\n");
            scanf("%d", &squats);

            totalPushups += pushups;
            totalSitups += situps;
            totalSquats += squats;

            printf("\nWoohoo! You're making progress!\n");

        }

        else{
            printf("\nInvalid input! Please try again.\n");
        }

        int totalExercises = totalPushups + totalSitups + totalSquats;

        if (totalExercises > 50) {
            printf("\nCongratulations! You're on your way to become the next Arnold Schwarzenegger!\n");
        }

        printf("\nDays without exercise: %d\n", daysNoExercise);
        printf("Total pushups: %d\n", totalPushups);
        printf("Total situps: %d\n", totalSitups);
        printf("Total squats: %d\n\n", totalSquats);
    }

    return 0;
}