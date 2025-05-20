//FormAI DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include<stdio.h>

// Function to execute task1
void task1(){
    printf("Task 1\n");
}

// Function to execute task2
void task2(){
    printf("Task 2\n");
}

// Function to execute task3
void task3(){
    printf("Task 3\n");
}

// Function to execute task4
void task4(){
    printf("Task 4\n");
}

// Function to execute all tasks in sequence
void execute_tasks(){
    task1();
    task2();
    task3();
    task4();
}

// Function to create schedule for tasks
void create_schedule(int time_interval){
    while(1){
        // Call execute_tasks after every time interval
        execute_tasks();
        // Sleep for specified time interval
        sleep(time_interval);
    }
}

int main(){

    int time_interval;

    // Ask user for time interval
    printf("Enter the time interval (in seconds): ");
    scanf("%d", &time_interval);

    // Create schedule for tasks
    create_schedule(time_interval);

    return 0;
}