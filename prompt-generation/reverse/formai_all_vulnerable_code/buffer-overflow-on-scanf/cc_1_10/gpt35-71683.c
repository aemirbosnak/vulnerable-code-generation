//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROC 10

struct Process{
    char name;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
    int priority;
};

struct Process queue[MAX_PROC];
int count = 0;

void init_queue(){
    for(int i = 0; i < MAX_PROC; i++){
        queue[i].name = ' ';
        queue[i].arrival_time = 0;
        queue[i].burst_time = 0;
        queue[i].waiting_time = 0;
        queue[i].turnaround_time = 0;
        queue[i].remaining_time = 0;
        queue[i].priority = 0;
    }
}

void add_process(char name, int at, int bt, int priority){
    queue[count].name = name;
    queue[count].arrival_time = at;
    queue[count].burst_time = bt;
    queue[count].remaining_time = bt;
    queue[count].priority = priority;
    count++;
}

int select_process_fcfs(int current_time){
    int min_at = 9999;
    int index = -1;
    for(int i = 0; i < count; i++){
        if(queue[i].remaining_time > 0 && queue[i].arrival_time <= current_time){
            if(queue[i].arrival_time < min_at){
                min_at = queue[i].arrival_time;
                index = i;
            }
        }
    }
    return index;
}

int select_process_priority(int current_time){
    int max_priority = -1;
    int index = -1;
    for(int i = 0; i < count; i++){
        if(queue[i].remaining_time > 0 && queue[i].arrival_time <= current_time){
            if(queue[i].priority > max_priority){
                max_priority = queue[i].priority;
                index = i;
            }
        }
    }
    return index;
}

int select_process_sjf(int current_time){
    int min_bt = 9999;
    int index = -1;
    for(int i = 0; i < count; i++){
        if(queue[i].remaining_time > 0 && queue[i].arrival_time <= current_time){
            if(queue[i].burst_time < min_bt){
                min_bt = queue[i].burst_time;
                index = i;
            }
        }
    }
    return index;
}

int select_process_rr(int current_time, int remain_time[], int quantum) {
    for(int i = 0; i < count; i++){
        if(queue[i].remaining_time > 0 && queue[i].arrival_time <= current_time){
            if(remain_time[i] <= quantum){
                return i;
            }
        }
    }
    for(int i = 0; i < count; i++){
        if(queue[i].remaining_time > 0 && queue[i].arrival_time <= current_time){
            return i;
        }
    }
    return -1;
}

void fcfs(){
    int current_time = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    int index;
    while(true){
        index = select_process_fcfs(current_time);
        if(index == -1){
            break;
        }
        queue[index].waiting_time = current_time - queue[index].arrival_time;
        queue[index].turnaround_time = queue[index].waiting_time + queue[index].burst_time;

        avg_waiting_time += queue[index].waiting_time;
        avg_turnaround_time += queue[index].turnaround_time;

        current_time += queue[index].burst_time;
        queue[index].remaining_time = 0;
    }

    int total_time = current_time;
    avg_waiting_time /= count;
    avg_turnaround_time /= count;

    printf("First Come First Serve Scheduling\n");
    printf("--------------------------------------------\n");
    printf("Process\t| Arrival Time\t| Burst Time\t|\n");
    printf("--------------------------------------------\n");

    for(int i = 0; i < count; i++){
        printf("%c\t| %d\t\t| %d\t\t|\n", queue[i].name, queue[i].arrival_time, queue[i].burst_time);
    }

    printf("--------------------------------------------\n");
    printf("Total Time: %d units\n", total_time);
    printf("Avg Waiting Time: %.2f units\n", avg_waiting_time);
    printf("Avg Turnaround Time: %.2f units\n\n", avg_turnaround_time);
}

void priority(){
    int current_time = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    int index;
    while(true){
        index = select_process_priority(current_time);
        if(index == -1){
            break;
        }
        queue[index].waiting_time = current_time - queue[index].arrival_time;
        queue[index].turnaround_time = queue[index].waiting_time + queue[index].burst_time;

        avg_waiting_time += queue[index].waiting_time;
        avg_turnaround_time += queue[index].turnaround_time;

        current_time += queue[index].burst_time;
        queue[index].remaining_time = 0;
    }

    int total_time = current_time;
    avg_waiting_time /= count;
    avg_turnaround_time /= count;

    printf("Priority Scheduling\n");
    printf("--------------------------------------------\n");
    printf("Process\t| Arrival Time\t| Burst Time\t| Priority\n");
    printf("--------------------------------------------\n");

    for(int i = 0; i < count; i++){
        printf("%c\t| %d\t\t| %d\t\t| %d\n", queue[i].name, queue[i].arrival_time, queue[i].burst_time, queue[i].priority);
    }

    printf("--------------------------------------------\n");
    printf("Total Time: %d units\n", total_time);
    printf("Avg Waiting Time: %.2f units\n", avg_waiting_time);
    printf("Avg Turnaround Time: %.2f units\n\n", avg_turnaround_time);
}

void sjf(){
    int current_time = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    int index;
    while(true){
        index = select_process_sjf(current_time);
        if(index == -1){
            break;
        }
        queue[index].waiting_time = current_time - queue[index].arrival_time;
        queue[index].turnaround_time = queue[index].waiting_time + queue[index].burst_time;

        avg_waiting_time += queue[index].waiting_time;
        avg_turnaround_time += queue[index].turnaround_time;

        current_time += queue[index].burst_time;
        queue[index].remaining_time = 0;
    }

    int total_time = current_time;
    avg_waiting_time /= count;
    avg_turnaround_time /= count;

    printf("Shortest Job First Scheduling\n");
    printf("--------------------------------------------\n");
    printf("Process\t| Arrival Time\t| Burst Time\t|\n");
    printf("--------------------------------------------\n");

    for(int i = 0; i < count; i++){
        printf("%c\t| %d\t\t| %d\t\t|\n", queue[i].name, queue[i].arrival_time, queue[i].burst_time);
    }

    printf("--------------------------------------------\n");
    printf("Total Time: %d units\n", total_time);
    printf("Avg Waiting Time: %.2f units\n", avg_waiting_time);
    printf("Avg Turnaround Time: %.2f units\n\n", avg_turnaround_time);
}

void rr(int quantum){
    int current_time = 0;
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    int remain_time[MAX_PROC];
    for(int i = 0; i < count; i++){
        remain_time[i] = queue[i].burst_time;
    }

    int index;
    while(true){
        index = select_process_rr(current_time, remain_time, quantum);

        if(index == -1){
            break;
        }

        if(remain_time[index] > quantum){
            current_time += quantum;
            remain_time[index] -= quantum;
        }
        else{
            current_time += remain_time[index];
            queue[index].waiting_time = current_time - queue[index].burst_time - queue[index].arrival_time;
            queue[index].turnaround_time = queue[index].waiting_time + queue[index].burst_time;

            avg_waiting_time += queue[index].waiting_time;
            avg_turnaround_time += queue[index].turnaround_time;

            remain_time[index] = 0;
        }
    }

    int total_time = current_time;
    avg_waiting_time /= count;
    avg_turnaround_time /= count;

    printf("Round Robin Scheduling\n");
    printf("--------------------------------------------\n");
    printf("Process\t| Arrival Time\t| Burst Time\t|\n");
    printf("--------------------------------------------\n");

    for(int i = 0; i < count; i++){
        printf("%c\t| %d\t\t| %d\t\t|\n", queue[i].name, queue[i].arrival_time, queue[i].burst_time);
    }

    printf("--------------------------------------------\n");
    printf("Total Time: %d units\n", total_time);
    printf("Avg Waiting Time: %.2f units\n", avg_waiting_time);
    printf("Avg Turnaround Time: %.2f units\n\n", avg_turnaround_time);
}

void surprise_msg(){
    for(int i = 0; i < 3; i++){
        printf("Surprise! I am a CPU Scheduling Algorithms program in C!\n");
        printf("Would you like to see some cool examples?\n");
        printf("Just enter '1', '2', '3' or '4' to select from the available options. Or 'q' to quit.\n\n");

        int choice;
        printf("1. First Come First Serve Scheduling\n");
        printf("2. Priority Scheduling\n");
        printf("3. Shortest Job First Scheduling\n");
        printf("4. Round Robin Scheduling\n");
        printf("q. Quit\n");

        scanf(" %c", &choice);

        switch (choice){
            case '1':
                init_queue();
                add_process('A', 0, 7, 1);
                add_process('B', 2, 4, 2);
                add_process('C', 4, 1, 3);
                add_process('D', 5, 4, 4);
                fcfs();
                break;
            case '2':
                init_queue();
                add_process('A', 0, 7, 2);
                add_process('B', 2, 4, 1);
                add_process('C', 4, 1, 3);
                add_process('D', 5, 4, 4);
                priority();
                break;
            case '3':
                init_queue();
                add_process('A', 0, 7, 1);
                add_process('B', 2, 4, 2);
                add_process('C', 4, 1, 3);
                add_process('D', 5, 4, 4);
                sjf();
                break;
            case '4':
                init_queue();
                add_process('A', 0, 7, 1);
                add_process('B', 2, 4, 2);
                add_process('C', 4, 1, 3);
                add_process('D', 5, 4, 4);
                rr(2);
                break;
            case 'q':
            case 'Q':
                printf("Goodbye! Hope you enjoyed the program.\n");
                return;
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

int main(){
    surprise_msg();
    return 0;
}