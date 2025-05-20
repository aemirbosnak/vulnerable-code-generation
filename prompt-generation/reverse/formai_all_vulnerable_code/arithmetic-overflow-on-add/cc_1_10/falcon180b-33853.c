//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct date
{
    int day;
    int month;
    int year;
};

struct fitness
{
    int steps;
    int calories;
};

void setdate(struct date *date)
{
    time_t now = time(0);
    struct tm *t = localtime(&now);
    date->day = t->tm_mday;
    date->month = t->tm_mon+1;
    date->year = t->tm_year+1900;
}

void setfitness(struct fitness *fitness)
{
    fitness->steps = 0;
    fitness->calories = 0;
}

void displaydate(struct date date)
{
    printf("Today's date is: %d/%d/%d\n",date.day,date.month,date.year);
}

void displayfitness(struct fitness fitness)
{
    printf("You have taken %d steps and burned %d calories today.\n",fitness.steps,fitness.calories);
}

int main()
{
    struct date date;
    struct fitness fitness;

    setdate(&date);
    setfitness(&fitness);

    printf("Welcome to the Fitness Tracker!\n");
    printf("Today's date is: ");
    displaydate(date);

    int choice;
    do
    {
        printf("\nEnter your choice:\n");
        printf("1. Record Steps\n");
        printf("2. Record Calories\n");
        printf("3. Display Fitness\n");
        printf("4. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of steps taken today: ");
                scanf("%d",&fitness.steps);
                break;

            case 2:
                printf("Enter number of calories burned today: ");
                scanf("%d",&fitness.calories);
                break;

            case 3:
                displayfitness(fitness);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while(choice!= 4);

    return 0;
}