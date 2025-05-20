//FormAI DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef void (*TaskFunction)(void *);

typedef struct Task {
    int priority;
    time_t next_execution;
    TaskFunction function;
    void *arg;
} Task;

Task tasks[10];
int num_tasks = 0;
time_t current_time;
int day = 1;

void print_apocalyptic_msg() {
    printf("You wake up to the sound of silence. The world as you knew it has ended.\n");
    sleep(2);
    printf("The sun is blocked out by thick clouds of ash. The air is thick and stale.\n");
    sleep(2);
    printf("You are alone in a desolate wasteland.\n");
    sleep(2);
    printf("You must survive to see another day.\n\n");
    sleep(2);
}

void task1(void *arg) {
    printf("Task 1: Scavenge for supplies.\n");
    sleep(2);
    printf("You search through the rubble for anything useful.\n");
    sleep(2);
    printf("You find some canned food and a first-aid kit.\n");
    sleep(2);
    printf("You add the supplies to your backpack and continue on.\n");
    sleep(2);
    tasks[0].next_execution = current_time + 60;
}

void task2(void *arg) {
    printf("Task 2: Find shelter.\n");
    sleep(2);
    printf("You search for a safe place to rest for the night.\n");
    sleep(2);
    printf("You find a partially intact building and make your way inside.\n");
    sleep(2);
    printf("You reinforce the entrance and settle in for the night.\n");
    sleep(2);
    tasks[1].next_execution = current_time + 180;
}

void task3(void *arg) {
    printf("Task 3: Gather firewood.\n");
    sleep(2);
    printf("You venture out into the cold to find firewood.\n");
    sleep(2);
    printf("You find some fallen branches and start gathering them up.\n");
    sleep(2);
    printf("As you are about to return to your shelter, you hear a loud noise.\n");
    sleep(2);
    printf("You quickly grab your weapons and turn to see a pack of wild dogs.\n");
    sleep(2);
    printf("You fight them off and return to your shelter with the firewood.\n");
    sleep(2);
    tasks[2].next_execution = current_time + 90;
}

void add_task(int priority, time_t next_execution, TaskFunction function, void *arg) {
    Task task = {priority, next_execution, function, arg};
    tasks[num_tasks++] = task;
}

void sort_tasks() {
    int i, j;
    Task temp;
    for (i = 0; i < num_tasks - 1; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority < tasks[j].priority || 
                (tasks[i].priority == tasks[j].priority && 
                 tasks[i].next_execution > tasks[j].next_execution)) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    print_apocalyptic_msg();
    current_time = time(NULL);
    add_task(1, current_time + 10, task1, NULL);
    add_task(2, current_time + 20, task2, NULL);
    add_task(1, current_time + 30, task3, NULL);
    while (1) {
        current_time = time(NULL);
        if (current_time % 60 == 0) {
            day++;
            printf("Day %d begins.\n\n", day);
        }
        sort_tasks();
        int i;
        for (i = 0; i < num_tasks; i++) {
            Task task = tasks[i];
            if (task.next_execution <= current_time) {
                task.function(task.arg);
            }
        }
    }
    return 0;
}