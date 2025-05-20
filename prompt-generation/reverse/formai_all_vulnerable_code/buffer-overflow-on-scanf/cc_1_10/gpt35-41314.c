//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

void display_menu();
int get_choice();
void input_calories(float *total);
void input_distance(float *total);
void input_steps(int *total);
void input_time(float *total);

int main()
{
    float calories = 0, distance = 0, time = 0;
    int steps = 0;
    int choice;
    do{
        display_menu();
        choice= get_choice();
        switch(choice){
            case 1:
                input_calories(&calories);
                break;
            case 2:
                input_distance(&distance);
                break;
            case 3:
                input_steps(&steps);
                break;
            case 4:
                input_time(&time);
                break;
            case 5:
                printf("\nCalories burned: %.2f", calories);
                printf("\nDistance walked: %.2f", distance);
                printf("\nSteps taken: %d", steps);
                printf("\nTime spent: %.2f minutes", time);
                break;
            case 6:
                printf("\nExiting Fitness Tracker...");
                exit(0);
                break;
            default:
                printf("\nInvalid Choice!! Try Again!!");
        }
    }while(choice!=6);
    return 0;
}

void display_menu()
{
    printf("\n\n*** Fitness Tracker ***");
    printf("\n1. Input Calories Burned");
    printf("\n2. Input Distance Walked");
    printf("\n3. Input Steps Taken");
    printf("\n4. Input Time Spent");
    printf("\n5. Display Fitness Stats");
    printf("\n6. Exit Tracker");
    printf("\nEnter your choice: ");
}

int get_choice()
{
    int ch;
    scanf("%d", &ch);
    return ch;
}

void input_calories(float *total)
{
    float burn;
    printf("\nEnter calories burned: ");
    scanf("%f",&burn);
    *total+=burn;
    printf("\nTotal calories burned: %.2f",*total);
}

void input_distance(float *total)
{
    float walk;
    printf("\nEnter distance walked: ");
    scanf("%f",&walk);
    *total+=walk;
    printf("\nTotal distance walked: %.2f",*total);
}

void input_steps(int *total)
{
    int take;
    printf("\nEnter steps taken: ");
    scanf("%d",&take);
    *total+=take;
    printf("\nTotal steps taken: %d", *total);
}

void input_time(float *total)
{
    float min;
    printf("\nEnter time spent (in minutes): ");
    scanf("%f",&min);
    *total+=min;
    printf("\nTotal time spent: %.2f minutes", *total);
}