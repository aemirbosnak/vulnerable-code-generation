//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

#define MAX_TASKS 10

typedef struct task_t{
    int id;
    int priority;
    int time_slice;
    int time_left;
    int start_time;
    int end_time;
    int status;
    int* result;
}task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void* run_task(void* arg){
    int task_id = *(int*)arg;
    task_t* task = &tasks[task_id];

    if(task->status == 0){
        task->start_time = time(NULL);
        task->status = 1;
    }else{
        return NULL;
    }

    if(task->time_slice > 0){
        int time_diff = task->end_time - task->start_time;
        int time_left = task->time_slice - time_diff;
        if(time_left > 0){
            sleep(time_left);
        }else{
            task->status = 2;
        }
    }else{
        task->status = 2;
    }

    return NULL;
}

int add_task(int id, int priority, int time_slice, int start_time, int end_time){
    if(num_tasks >= MAX_TASKS){
        printf("Error: Maximum number of tasks reached.\n");
        return -1;
    }

    task_t* task = &tasks[num_tasks];
    task->id = id;
    task->priority = priority;
    task->time_slice = time_slice;
    task->time_left = time_slice;
    task->start_time = start_time;
    task->end_time = end_time;
    task->result = NULL;
    task->status = 0;

    num_tasks++;
    return 0;
}

int remove_task(int id){
    int i;
    for(i=0;i<num_tasks;i++){
        if(tasks[i].id == id){
            tasks[i].status = 0;
            num_tasks--;
            return 0;
        }
    }

    printf("Error: Task not found.\n");
    return -1;
}

int main(){
    int i;

    //initialize tasks
    add_task(1, 1, 1000, 0, 10000);
    add_task(2, 2, 500, 0, 10000);
    add_task(3, 3, 200, 0, 10000);

    //run tasks
    for(i=0;i<num_tasks;i++){
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, run_task, (void*)&i);
    }

    //wait for tasks to finish
    for(i=0;i<num_tasks;i++){
        pthread_join(NULL, NULL);
    }

    return 0;
}