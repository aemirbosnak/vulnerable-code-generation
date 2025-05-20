//FormAI DATASET v1.0 Category: System boot optimizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

typedef struct {
    char *name;
    double time;
} task;

int compare_task(const void *a, const void *b) {
    task taskA = *(task *)a;
    task taskB = *(task *)b;
    if (taskA.time < taskB.time) {
        return -1;
    } else if (taskA.time > taskB.time) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    struct timeval start, end;
    int num_tasks = 5;
    double task_times[num_tasks];
    task tasks[num_tasks];
    char *task_names[num_tasks];
    
    // simulate some boot tasks with random execution times
    task_names[0] = "Load BIOS";
    task_times[0] = rand() % 10000 / 1000.0;
    task_names[1] = "Initialize memory";
    task_times[1] = rand() % 10000 / 1000.0;
    task_names[2] = "Load drivers";
    task_times[2] = rand() % 10000 / 1000.0;
    task_names[3] = "Initialize peripherals";
    task_times[3] = rand() % 10000 / 1000.0;
    task_names[4] = "Load operating system";
    task_times[4] = rand() % 10000 / 1000.0;
    
    // measure the execution time of each task
    for (int i = 0; i < num_tasks; i++) {
        gettimeofday(&start, NULL);
        // simulate execution of task
        sleep(task_times[i]); 
        gettimeofday(&end, NULL);
        double time_taken = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;
        tasks[i].name = task_names[i];
        tasks[i].time = time_taken;
    }
    
    // sort tasks by execution time
    qsort(tasks, num_tasks, sizeof(task), compare_task);
    
    // print results
    printf("Optimizing boot sequence...\n\n");
    printf("%-30s %s\n", "Task", "Execution Time");
    printf("-----------------------------------------\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%-30s %.3f seconds\n", tasks[i].name, tasks[i].time);
    }
    printf("\nBoot sequence optimized!");
    
    return 0;
}