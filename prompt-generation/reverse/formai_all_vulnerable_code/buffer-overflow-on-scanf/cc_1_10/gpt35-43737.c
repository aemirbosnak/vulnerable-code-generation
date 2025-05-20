//FormAI DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef void (*Task)();

void task1()
{
    printf("Time to dance in the sunshine!\n");
}

void task2()
{
    printf("Yay! Time to cuddle with fluffy puppies!\n");
}

void task3()
{
    printf("It's adventure time, let's go backpacking!\n");
}

void task4()
{
    printf("Let's bake chocolate chip cookies, yum!\n");
}

void scheduleTask(Task task, int delay)
{
    time_t start_time, current_time;
    double elapsed_time;
    
    start_time = time(NULL);
    do
    {
        current_time = time(NULL);
        elapsed_time = difftime(current_time, start_time);
    } while(elapsed_time < delay);
    
    task();
}

int main()
{
    printf("Welcome to the Cheerful C Task Scheduler!\n\n");
    
    while(1)
    {
        printf("What would you like to do?\n");
        printf("1. Dance in the sunshine!\n");
        printf("2. Cuddle with fluffy puppies!\n");
        printf("3. Go backpacking!\n");
        printf("4. Bake chocolate chip cookies!\n");
        printf("5. Quit\n");
        
        int choice;
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                scheduleTask(task1, 5);
                break;
            case 2:
                scheduleTask(task2, 10);
                break;
            case 3:
                scheduleTask(task3, 15);
                break;
            case 4:
                scheduleTask(task4, 20);
                break;
            case 5:
                printf("\nGoodbye! Have a cheerful day ahead!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n\n");
                break;
        }
    }
    
    return 0;
}