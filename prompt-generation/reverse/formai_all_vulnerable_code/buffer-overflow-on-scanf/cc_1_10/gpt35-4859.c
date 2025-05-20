//FormAI DATASET v1.0 Category: System boot optimizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MIN_CPU_REQ 1
#define MAX_CPU_REQ 10
#define MIN_IO_REQ 100
#define MAX_IO_REQ 200

struct process {
    int id;
    int cpu_time_required;
    int io_time_required;
    int priority;
    int wait_time;
};

void initialize_processes(struct process *procs, int num_procs) {
    srand(time(0));
    for(int i=0; i<num_procs; ++i) {
        procs[i].id = i+1;
        procs[i].cpu_time_required = MIN_CPU_REQ + rand() % (MAX_CPU_REQ - MIN_CPU_REQ + 1);
        procs[i].io_time_required = MIN_IO_REQ + rand() % (MAX_IO_REQ - MIN_IO_REQ + 1);
        procs[i].priority = rand() % 5 + 1;
        procs[i].wait_time = 0;
    }
}

void print_process_info(struct process proc) {
    printf("Process ID: %d, CPU Time: %d, IO Time: %d, Priority: %d, Wait Time: %d\n", proc.id, proc.cpu_time_required, proc.io_time_required, proc.priority, proc.wait_time);
}

void print_all_processes_info(struct process *procs, int num_procs) {
    for(int i=0; i<num_procs; ++i) {
        print_process_info(procs[i]);
    }
}

void sort_processes_by_priority(struct process *procs, int num_procs) {
    for(int i=0; i<num_procs-1; ++i) {
        int max_idx = i;
        for(int j=i+1; j<num_procs; ++j) {
            if(procs[j].priority > procs[max_idx].priority) {
                max_idx = j;
            }
        }
        struct process temp = procs[i];
        procs[i] = procs[max_idx];
        procs[max_idx] = temp;
    }
}

void run_processes(struct process *procs, int num_procs) {
    for(int i=0; i<num_procs; ++i) {
        while(procs[i].cpu_time_required > 0) {
            printf("Running process %d for CPU...\n", procs[i].id);
            procs[i].cpu_time_required--;
            procs[i].wait_time++;
            if(procs[i].cpu_time_required == 0) {
                printf("Process %d has completed its CPU tasks\n", procs[i].id);
                break;
            }
            printf("Putting process %d into IO wait...\n", procs[i].id);
            int io_time_required = MIN_IO_REQ + rand() % (MAX_IO_REQ - MIN_IO_REQ + 1);
            for(int j=0; j<io_time_required; ++j) {
                procs[i].wait_time++;
                printf("Running process %d for IO...\n", procs[i].id);
            }
            printf("Process %d has completed its IO tasks and is now back in CPU\n", procs[i].id);
        }
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes;
    printf("Enter the number of processes to run (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);
    if(num_processes > MAX_PROCESSES) {
        printf("Invalid input. Setting the number of processes to the maximum value %d.\n", MAX_PROCESSES);
        num_processes = MAX_PROCESSES;
    }
    initialize_processes(processes, num_processes);
    printf("Initial process info:\n");
    print_all_processes_info(processes, num_processes);
    printf("Sorting processes by priority...\n");
    sort_processes_by_priority(processes, num_processes);
    printf("Sorted process info:\n");
    print_all_processes_info(processes, num_processes);
    printf("Running the processes...\n");
    run_processes(processes, num_processes);
    printf("Final process info:\n");
    print_all_processes_info(processes, num_processes);
    return 0;
}