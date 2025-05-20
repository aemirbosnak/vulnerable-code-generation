//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX_TASKS 10

void task1();
void task2();
void task3();
void task4();
void task5();
void (*tasks[MAX_TASKS])() = {task1, task2, task3, task4, task5};

int main() {
    printf("Oh my god! I can't believe I just created a Task Scheduler!\n");
    printf("This program will schedule the following tasks:\n");
    printf("1. Display the current time\n");
    printf("2. Display the current date\n");
    printf("3. Display the current weather\n");
    printf("4. Calculate the square of a number\n");
    printf("5. Display a random number\n");

    int numTasks = 5;
    int interval[MAX_TASKS] = {5, 2, 10, 7, 3};
    printf("\nThe task scheduler will run the above %d tasks in the following intervals:\n", numTasks);
    for(int i = 0; i < numTasks; i++) {
        printf("Task %d every %d seconds\n", i+1, interval[i]);
    }

    printf("\nExecuting tasks...\n");
    time_t prevTime;
    prevTime = time(NULL);

    while(1) {
        for(int i = 0; i < numTasks; i++) {
            time_t currTime;
            currTime = time(NULL);
            if((currTime - prevTime) >= interval[i]) {
                prevTime = currTime;
                tasks[i]();
            }
        }
    }

    return 0;
}

void task1() {
    time_t t; 
    time(&t);
    printf("Current time: %s", ctime(&t));
}

void task2() {
    time_t t;
    struct tm *tm;
    char date[100];
    time(&t);
    tm = localtime(&t);
    strftime(date, sizeof(date), "%d-%m-%Y", tm);
    printf("Current date: %s\n", date);
}

void task3() {
    printf("Current weather: Sunny\n"); //Random weather :P
}

void task4() {
    int num;
    printf("Enter a number to square: ");
    scanf("%d", &num);
    printf("Square of %d is %d\n", num, num*num);
}

void task5() {
    printf("Random number: %d\n", rand());
}