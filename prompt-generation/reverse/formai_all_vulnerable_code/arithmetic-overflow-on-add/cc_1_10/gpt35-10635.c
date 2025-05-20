//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    char name[50];
    int interval;
    time_t next_execution_time;
} Task;

Task task_list[MAX_TASKS];

time_t current_time;

void init_tasks() {
    int i;
    srand(time(NULL));
    for(i=0; i<MAX_TASKS; i++) {
        task_list[i].id = i;
        sprintf(task_list[i].name, "Task %d", i);
        task_list[i].interval = (rand() % 10) + 1;
        task_list[i].next_execution_time = current_time + task_list[i].interval;
    }
}

void print_tasks() {
    int i;
    for(i=0; i<MAX_TASKS; i++) {
        printf("Task %d: %s, Interval: %d, Next Execution Time: %s", 
               task_list[i].id, task_list[i].name, 
               task_list[i].interval, ctime(&task_list[i].next_execution_time));
    }
}

int main() {
    printf("Wow! I can't believe I just created a C Task Scheduler example program!\n");
    printf("This program will randomly create %d tasks with intervals between 1 and 10 seconds,\n",
           MAX_TASKS);
    printf("and then execute each task when its interval has passed.\n\n");
    
    current_time = time(NULL);
    init_tasks();
    
    printf("Initial Tasks:\n");
    print_tasks();
    
    while(1) {
        int i;
        current_time = time(NULL);
        for(i=0; i<MAX_TASKS; i++) {
            if(current_time >= task_list[i].next_execution_time) {
                printf("Executing %s at %s", task_list[i].name, ctime(&current_time));
                task_list[i].next_execution_time = current_time + task_list[i].interval;
            }
        }
        // Pause for 1 second to prevent continuous loop from hogging resources
        sleep(1);
    }
    
    return 0;
}