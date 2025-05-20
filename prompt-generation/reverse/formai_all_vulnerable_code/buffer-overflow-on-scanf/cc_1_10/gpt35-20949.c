//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct process {
    char name[10];      //process name
    int arrival_time;   //arrival time of process
    int burst_time;     //burst time of process
};

struct process q1[10], q2[10], q3[10];  //queues for the processes
int time_quantum1 = 2, time_quantum2 = 4, total_process_count = 0, q1_count = 0, q2_count = 0, q3_count = 0;

void round_robin(struct process q[], int count, int time_quantum) {   //Round Robin CPU scheduling algorithm
    int remaining_burst_time[count], time_elapsed = 0, complete = 0, i, j;

    //copying the burst time of all the processes into the remaining_burst_time array
    for (i = 0; i < count; i++) {
        remaining_burst_time[i] = q[i].burst_time;
    }

    while (complete != count) {
        for (i = 0; i < count; i++) {
            if (remaining_burst_time[i] > 0) {
                if (remaining_burst_time[i] > time_quantum) {
                    time_elapsed += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                } else {
                    time_elapsed += remaining_burst_time[i];
                    q[i].arrival_time = time_elapsed;    //set the arrival time of the process as the time it completed execution
                    remaining_burst_time[i] = 0;
                    complete++;
                }
            }
        }
    }
}

void display_gantt_chart(struct process q[], int count) {    //function to display the Gantt chart
    int i, j;
    printf("\n\nGANTT CHART\n");
    for (i = 0; i < count; i++) {
        printf("---------------------------------------\n");
        printf("|%10s|\n", q[i].name);
        printf("---------------------------------------\n");
    }
    printf("\n\n");
}

void execute_processes() {      //function to execute all the processes
    int i, j, k, process_waiting_time = 0, total_waiting_time = 0, process_turnaround_time = 0, total_turnaround_time = 0;

    round_robin(q1, q1_count, time_quantum1);  // execute a round of the Round Robin algorithm on queue 1
    printf("\n\n\nQUEUE 1:\n");
    display_gantt_chart(q1, q1_count);

    for (i = 0; i < q1_count; i++) {    //move all the still unfinished processes from queue 1 to queue 2
        if (q1[i].burst_time > 0) {
            q2[q2_count++] = q1[i];
        }
    }

    round_robin(q2, q2_count, time_quantum2);   // execute a round of the Round Robin algorithm on queue 2
    printf("\n\n\nQUEUE 2:\n");
    display_gantt_chart(q2, q2_count);

    for (i = 0; i < q2_count; i++) {    //move all the still unfinished processes from queue 2 to queue 3
        if (q2[i].burst_time > 0) {
            q3[q3_count++] = q2[i];
        }
    }

    for (i = 0; i < q3_count; i++) {   //execute all remaining processes in queue 3 using the First Come First Serve algorithm
        process_waiting_time = 0;
        process_turnaround_time = 0;
        for (j = 0; j < i; j++) {
            process_waiting_time += q3[j].burst_time;
        }
        process_turnaround_time = process_waiting_time + q3[i].burst_time;
        total_waiting_time += process_waiting_time;
        total_turnaround_time += process_turnaround_time;
        q3[i].arrival_time = process_turnaround_time;
    }

    printf("\n\n\nQUEUE 3:\n");
    display_gantt_chart(q3, q3_count);

    printf("\n\n\nPROCESS\t\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < total_process_count; i++) {
        printf("%s\t\t%d\t\t%d\n", q3[i].name, q3[i].arrival_time - q3[i].burst_time, q3[i].arrival_time);
    }
    printf("\n\n\nAVERAGE WAITING TIME: %.2f\nAVERAGE TURNAROUND TIME: %.2f\n", (float) total_waiting_time / total_process_count, (float) total_turnaround_time / total_process_count);
}

int main() {    //main function
    int i, j;
    struct process p;
    char CH;

    printf("\n\n\nENTER THE PROCESSES:\n\n");

    do {   //loop to take input from user for new processes
        printf("\nPROCESS NAME: ");
        scanf("%s", p.name);
        printf("ARRIVAL TIME: ");
        scanf("%d", &p.arrival_time);
        printf("BURST TIME: ");
        scanf("%d", &p.burst_time);

        if (p.burst_time <= 0 || p.arrival_time < 0) {
            printf("\n\nINVALID INPUT! TRY AGAIN!\n\n");
            continue;
        }

        if (p.arrival_time == 0) {    //add to queue 1 if the process arrives at the start
            q1[q1_count++] = p;
        } else if (p.arrival_time <= 5) {     //add to queue 2 if the process arrives after 0 seconds but before or at 5 seconds
            q2[q2_count++] = p;
        } else {    //add to queue 3 otherwise
            q3[q3_count++] = p;
        }

        total_process_count++;    //increment the process count
        printf("\n\nADD ANOTHER PROCESS? (Y/N): ");
        CH = getchar();
        if (CH == '\n') {
            CH = getchar();
        }
    } while (CH == 'Y' || CH == 'y');

    execute_processes();    //execute all the processes

    return 0;
}