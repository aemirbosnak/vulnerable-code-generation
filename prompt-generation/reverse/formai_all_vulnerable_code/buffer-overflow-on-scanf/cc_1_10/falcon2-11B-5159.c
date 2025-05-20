//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task_1() {
    printf("Task 1: Sleeping for 10 seconds.\n");
    sleep(10);
    printf("Task 1 completed.\n");
}

void task_2() {
    printf("Task 2: Sleeping for 5 seconds.\n");
    sleep(5);
    printf("Task 2 completed.\n");
}

void task_3() {
    printf("Task 3: Sleeping for 15 seconds.\n");
    sleep(15);
    printf("Task 3 completed.\n");
}

int main() {
    srand(time(0));
    int choice = rand() % 3 + 1;

    printf("Welcome to the task scheduler!\n");
    printf("Please select a task:\n");
    printf("1. Task 1\n");
    printf("2. Task 2\n");
    printf("3. Task 3\n");

    int task_num;
    scanf("%d", &task_num);

    switch (task_num) {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        case 3:
            task_3();
            break;
        default:
            printf("Invalid task number.\n");
            break;
    }

    return 0;
}