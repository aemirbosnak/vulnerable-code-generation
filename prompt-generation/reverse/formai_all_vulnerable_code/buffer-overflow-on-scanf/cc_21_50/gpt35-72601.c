//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {

    char process[10][10], temp[10];
    int arrival[10], burst[10], waiting[10], turnaround[10], completion[10];
    int i, j, k, n, sum = 0, time_quantum, choice, flag=0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter process name: ");
        scanf("%s", &process[i]);
        printf("Enter arrival time: ");
        scanf("%d", &arrival[i]);
        printf("Enter burst time: ");
        scanf("%d", &burst[i]);
        printf("\n");
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
    printf("\n");

    printf("Select scheduling algorithm:\n");
    printf("1. Round Robin\n");
    printf("2. Shortest Job First\n");
    scanf("%d", &choice);
    printf("\n");

    switch(choice) {

        case 1: //Round Robin Scheduling

            printf("Round Robin Scheduling Algorithm\n\n");

            for(i = 0; i < n; i++) {
                for(j = i+1; j < n; j++) {
                    if(arrival[i] > arrival[j]) {
                        int temp = arrival[i];
                        arrival[i] = arrival[j];
                        arrival[j] = temp;

                        temp = burst[i];
                        burst[i] = burst[j];
                        burst[j] = temp;

                        char temp_c[10];
                        strcpy(temp_c, process[i]);
                        strcpy(process[i], process[j]);
                        strcpy(process[j], temp_c);
                    }
                }
            }

            int time = 0, remaining = n;
            int k1 = 0, q1[10];
            for(i = 0; i < n; i++) {
                q1[i] = burst[i];
                waiting[i] = 0;
            }

            printf("Gantt Chart:\n");
            printf("|");
            for(i = 0; i < n; i++) {
                printf(" P%d |", i+1);
            }
            printf("\n");

            while(remaining != 0) {
                if(q1[k1] <= time_quantum && q1[k1] > 0) {
                    time += q1[k1];
                    q1[k1] = 0;
                    flag = 1;
                }
                else if(q1[k1] > 0) {
                    q1[k1] -= time_quantum;
                    time += time_quantum;
                }
                if(q1[k1] == 0 && flag == 1) {
                    remaining--;
                    completion[k1] = time;
                    turnaround[k1] = completion[k1] - arrival[k1];
                    waiting[k1] = turnaround[k1] - burst[k1];
                    flag = 0;
                }
                if(k1 == n-1) {
                    k1 = 0;
                }
                else if(arrival[k1+1] <= time) {
                    k1++;
                }
                else {
                    k1 = 0;
                }
            }

            printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
            for(i = 0; i < n; i++) {
                printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival[i], burst[i], waiting[i], turnaround[i], completion[i]);
            }
            printf("\n");

            float avg_waiting = 0, avg_turnaround = 0;
            for(i = 0; i < n; i++) {
                avg_waiting += waiting[i];
                avg_turnaround += turnaround[i];
            }

            avg_waiting = avg_waiting/n;
            avg_turnaround = avg_turnaround/n;

            printf("Average Waiting Time: %f\n", avg_waiting);
            printf("Average Turnaround Time: %f\n", avg_turnaround);

            break;

        case 2: //Shortest Job First Scheduling

            printf("Shortest Job First Scheduling Algorithm\n\n");

            for(i = 0; i < n; i++) {
                for(j = i+1; j < n; j++) {
                    if(burst[i] > burst[j]) {
                        int temp = arrival[i];
                        arrival[i] = arrival[j];
                        arrival[j] = temp;

                        temp = burst[i];
                        burst[i] = burst[j];
                        burst[j] = temp;

                        char temp_c[10];
                        strcpy(temp_c, process[i]);
                        strcpy(process[i], process[j]);
                        strcpy(process[j], temp_c);
                    }
                }
            }

            int time1 = 0;
            for(i = 0; i < n; i++) {
                completion[i] = 0;
            }

            while(1) {
                int min = 1000,  c = n;
                if(sum == n) {
                    break;
                }
                for(i = 0; i < n; i++) {
                    if(arrival[i] <= time1 && completion[i] == 0) {
                        if(burst[i] < min) {
                            min = burst[i];
                            c = i;
                        }
                    }
                }
                if(c == n) {
                    time1++;
                }
                else {
                    completion[c] = time1 + burst[c];
                    time1 += burst[c];
                    turnaround[c] = completion[c] - arrival[c];
                    waiting[c] = turnaround[c] - burst[c];
                    sum++;
                }
            }

            printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
            for(i = 0; i < n; i++) {
                printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival[i], burst[i], waiting[i], turnaround[i], completion[i]);
            }
            printf("\n");

            float avg_waiting1 = 0, avg_turnaround1 = 0;
            for(i = 0; i < n; i++) {
                avg_waiting1 += waiting[i];
                avg_turnaround1 += turnaround[i];
            }

            avg_waiting1 = avg_waiting1/n;
            avg_turnaround1 = avg_turnaround1/n;

            printf("Average Waiting Time: %f\n", avg_waiting1);
            printf("Average Turnaround Time: %f\n", avg_turnaround1);

            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}