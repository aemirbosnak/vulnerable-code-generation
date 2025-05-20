//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
/*=============================================================================
|   TITLE: CPU Usage Monitor                                                
|   AUTHOR: Ada Lovelace                                                      
|   DATE: 28/10/2021                                                          
|==============================================================================|
|   DESCRIPTION: Provides a visual display of the current CPU usage for the       
|   system. The program is designed to constantly update and refresh this       
|   display, providing a real-time view of how much CPU is being used by           
|   the system.  This program is written in C language.                          
|=============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_LOAD_AVG 12
#define REFRESH_TIME 1 // Times in seconds
#define STR_WIDTH 50 // Width of each progress bar

void printProgressBar(int progress) {
    int marks = (progress * STR_WIDTH) / 100;
    printf("[");
    for (int i = 0; i < STR_WIDTH; i++) {
        if (i < marks) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("]");
    printf(" %d%c\n", progress, '%');
}

int main() {
    double load_avg[MAX_LOAD_AVG];
    while (1) {
        system("clear"); // Clear the console
        // Fetch the CPU usage data
        if (getloadavg(load_avg, MAX_LOAD_AVG) == -1) {
            printf("Error: getloadavg() failed\n");
            return 1;
        }
        // Calculate the average CPU usage
        double avg_cpu_load = 0.0;
        for (int i = 0; i < MAX_LOAD_AVG; i++) {
            avg_cpu_load += load_avg[i];
        }
        avg_cpu_load /= MAX_LOAD_AVG;
        // Print the CPU usage progress bar
        printProgressBar(avg_cpu_load * 100);
        // Sleep for 'REFRESH_TIME' seconds
        sleep(REFRESH_TIME);
    }
    return 0;
}