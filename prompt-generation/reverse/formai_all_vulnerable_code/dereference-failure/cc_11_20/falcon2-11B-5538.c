//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 5; // number of processes
    int i;
    int *p = malloc(n * sizeof(int)); // array to store process information
    int *c = malloc(n * sizeof(int)); // array to store process priorities
    int *arrival = malloc(n * sizeof(int)); // array to store process arrival times
    int *burst = malloc(n * sizeof(int)); // array to store process burst times

    // generate random process information
    for (i = 0; i < n; i++) {
        p[i] = rand() % 100; // process ID
        c[i] = rand() % 100; // process priority
        arrival[i] = rand() % 1000; // process arrival time
        burst[i] = rand() % 1000; // process burst time
    }

    // sort processes by priority
    for (i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i] > c[j]) {
                int temp = c[i];
                c[i] = c[j];
                c[j] = temp;
                int temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
                int temp3 = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp3;
                int temp4 = burst[i];
                burst[i] = burst[j];
                burst[j] = temp4;
            }
        }
    }

    // print sorted process information
    printf("Process ID\tArrival Time\tBurst Time\tPriority\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i], arrival[i], burst[i], c[i]);
    }

    // simulate CPU scheduling
    int turn = 0; // turn index
    int running = 0; // running process ID
    int time = 0; // simulation time
    while (running!= -1) {
        if (time >= arrival[running]) {
            turn++;
            running = -1;
        }
        if (running!= -1 && time >= arrival[running] && time <= arrival[running] + burst[running]) {
            time += burst[running];
            running = -1;
        }
        if (turn >= n) {
            turn = 0;
        }
        if (time >= arrival[turn]) {
            running = turn;
            turn++;
        }
    }

    // print final simulation result
    printf("Simulation finished.\n");
    return 0;
}