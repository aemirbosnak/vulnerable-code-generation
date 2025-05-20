//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 50

typedef struct {
    char name[MAX_TASK_NAME_LEN];
    int priority;
    int interval;
    void (*task)(void);
} Task;

Task taskList[MAX_TASKS];
int nextTaskIndex = 0;

void addTask(char *name, int priority, int interval, void (*task)(void)){
    if (nextTaskIndex < MAX_TASKS){
        Task newTask;
        strcpy(newTask.name, name);
        newTask.priority = priority;
        newTask.interval = interval;
        newTask.task = task;

        taskList[nextTaskIndex++] = newTask;
    }
}

void removeTask(char *name){
    int i;
    for(i = 0; i < nextTaskIndex; i++){
        if (strcmp(taskList[i].name, name) == 0){
            // move tasks after it up in the list
            int j;
            for(j = i+1; j < nextTaskIndex; j++){
                taskList[j-1] = taskList[j];
            }

            // decrease the index of the nextTask
            nextTaskIndex--;

            break;
        }
    }
}

void startScheduler(){
    int i;
    while(1){
        // find the highest priority task that is due
        int highestPriority = 1000;
        int selectedTaskIndex = -1;
        for(i = 0; i < nextTaskIndex; i++){
            if (taskList[i].interval == 0){
                if (taskList[i].priority < highestPriority){
                    highestPriority = taskList[i].priority;
                    selectedTaskIndex = i;
                }
            } else if (taskList[i].interval < 0){
                if (taskList[i].priority < highestPriority){
                    highestPriority = taskList[i].priority;
                    selectedTaskIndex = i;
                }
            } else if ((time(NULL) - taskList[i].interval) >= taskList[i].interval){
                if (taskList[i].priority < highestPriority){
                    highestPriority = taskList[i].priority;
                    selectedTaskIndex = i;
                }
            }
        }
        
        if (selectedTaskIndex >= 0){
            // execute the selected task
            taskList[selectedTaskIndex].task();

            // reset the interval if it's a periodic task
            if (taskList[selectedTaskIndex].interval > 0){
                taskList[selectedTaskIndex].interval = time(NULL);
            }
        }

        usleep(100000); // wait 100ms
    }
}

void task1(){
    printf("Task 1\n");
}

void task2(){
    printf("Task 2\n");
}

void task3(){
    printf("Task 3\n");
}

int main(){
    // initialize the task list
    addTask("Task 1", 1, -1, task1); // highest priority
    addTask("Task 2", 2, 5, task2);
    addTask("Task 3", 3, 10, task3); // lowest priority

    // start the scheduler
    startScheduler();

    return 0;
}