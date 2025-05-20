//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int waterIntake, caloriesBurned, minutesExercised, stepsTaken;
    int currentDate, lastDate = 0, daysPassed = 0;
    
    printf("Welcome to the fitness tracker program for the post-apocalyptic world!\n");
    printf("Please enter today's date (in days since the apocalypse): ");
    scanf("%d", &currentDate);
    
    if(currentDate == lastDate)
    {
        printf("You have already logged your information for today!");
        return 0;
    }
    
    printf("\nEnter water intake (in ounces): ");
    scanf("%d", &waterIntake);
    
    printf("Enter calories burned: ");
    scanf("%d", &caloriesBurned);
    
    printf("Enter minutes exercised: ");
    scanf("%d", &minutesExercised);
    
    printf("Enter steps taken: ");
    scanf("%d", &stepsTaken);
    
    printf("\nInformation logged successfully!\n");
    
    srand((unsigned) time(NULL));
    int random = rand() % 10;
    
    if(random == 0 || random == 1 || random == 2)
    {
        printf("\nWater intake: %d ounces (try to drink more!)\n", waterIntake);
    }
    else if(random == 3 || random == 4 || random == 5)
    {
        printf("\nWater intake: %d ounces (good job!)\n", waterIntake);
    }
    else
    {
        printf("\nWater intake: %d ounces (amazing job!)\n", waterIntake);
    }
    
    printf("Calories burned: %d\n", caloriesBurned);
    printf("Minutes exercised: %d\n", minutesExercised);
    printf("Steps taken: %d\n", stepsTaken);
    
    if(lastDate != 0)
    {
        daysPassed = currentDate - lastDate;
        printf("\nIt has been %d days since your last log.\n", daysPassed);
    }
    
    lastDate = currentDate;
    
    return 0;
}