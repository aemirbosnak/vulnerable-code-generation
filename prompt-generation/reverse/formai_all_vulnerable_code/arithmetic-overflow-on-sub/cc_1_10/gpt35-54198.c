//FormAI DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

#define MAX_TASKS 10

typedef void (*task_fn)(void);

typedef struct{
    task_fn func;
    int interval;
    int repeat;
    int active;
} task_t;

task_t tasks[MAX_TASKS];
int next_index = 0;

void add_task(task_fn func, int interval, int repeat){
    if(next_index >= MAX_TASKS){
        printf("Scheduler error: maximum number of tasks reached\n");
        return;
    }
    task_t t;
    t.func = func;
    t.interval = interval;
    t.repeat = repeat;
    t.active = 1;

    tasks[next_index++] = t;
}

void run_scheduler(){
    time_t last_tick = time(NULL);
    while(1){
        time_t cur_time = time(NULL);
        if(cur_time - last_tick >= 1){
            for(int i=0; i<next_index; i++){
                if(tasks[i].active){
                    tasks[i].func();
                    if(tasks[i].repeat == 0){ // task is infinite
                        tasks[i].active = 0;
                    }
                    else{
                        tasks[i].repeat--;
                    }
                }
            }
            last_tick = cur_time;
        }
    }
}

void task1(){
    printf("Task 1 is running\n");
}

void task2(){
    printf("Task 2 is running\n");
}

int main(){
    add_task(&task1, 1, 5); // run task1 every second, 5 times
    add_task(&task2, 3, 0); // run task2 every 3 seconds, infinite times
    run_scheduler();
    return 0;
}