//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include<stdio.h>
#include<stdlib.h>

//Defining the structure for each fitness record
struct fitnessRecord{
    char date[20];
    int steps;
    float distance;
    int caloriesBurnt;
};

//Function to add a new fitness record
void addRecord(struct fitnessRecord records[], int count)
{
    printf("Enter the details for the fitness record: \n");
    printf("Enter the date (dd/mm/yyyy format): ");
    scanf("%s", records[count].date);
    printf("Enter the number of steps: ");
    scanf("%d", &records[count].steps);
    printf("Enter the distance covered (in km): ");
    scanf("%f", &records[count].distance);
    printf("Enter the number of calories burnt: ");
    scanf("%d", &records[count].caloriesBurnt);
}

//Function to display all the fitness records
void displayRecords(struct fitnessRecord records[], int count)
{
    if(count==0)
    {
        printf("No records found\n");
        return;
    }
    printf("Fitness Records: \n");
    for(int i=0; i<count; i++)
    {
        printf("\n Record %d:\n", i+1);
        printf("Date: %s\n", records[i].date);
        printf("Steps taken: %d\n", records[i].steps);
        printf("Distance covered: %.2f km\n", records[i].distance);
        printf("Calories burnt: %d\n", records[i].caloriesBurnt);
    }
}

//Function to show the total number of steps taken
void showTotalSteps(struct fitnessRecord records[], int count)
{
    int steps = 0;
    for(int i=0; i<count; i++)
    {
        steps += records[i].steps;
    }
    printf("\nTotal number of steps taken: %d\n", steps);
}

int main()
{
    struct fitnessRecord records[100];
    int count = 0, choice;

    while(1)
    {
        printf("\n---------- C Fitness Tracker Menu ----------\n\n");
        printf("1. Add new fitness record\n");
        printf("2. Display all fitness records\n");
        printf("3. Show total number of steps taken\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addRecord(records, count);
                    count++;
                    break;

            case 2: displayRecords(records, count);
                    break;

            case 3: showTotalSteps(records, count);
                    break;

            case 4: printf("\nExiting program...");
                    exit(0);
                    break;

            default: printf("\nInvalid Choice\n");
                     break;
        }
    }

    return 0;
}