//FormAI DATASET v1.0 Category: System boot optimizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random number generator
    
    printf("Welcome to the C System Boot Optimizer!\n\n");
    printf("This program will optimize your system by randomly reordering boot processes.\n");
    printf("Enter the number of boot processes you want to optimize:\n");
    
    int num_processes;
    scanf("%d", &num_processes); // get user input for number of processes
    
    char** processes = malloc(num_processes * sizeof(char*)); // allocate memory for process names
    int* times = malloc(num_processes * sizeof(int)); // allocate memory for process times
    
    printf("\nEnter the names of the %d processes and their execution times in seconds (separated by spaces):\n", num_processes);
    
    for (int i = 0; i < num_processes; i++) {
        processes[i] = malloc(50 * sizeof(char)); // allocate memory for process name
        
        scanf("%s %d", processes[i], &times[i]); // get user input for process names and times
        
        printf("Process %d: %s (%d seconds)\n", i+1, processes[i], times[i]);
    }
    
    printf("\nOptimizing boot processes...\n\n");
    
    int* order = malloc(num_processes * sizeof(int)); // allocate memory for process order
    
    for (int i = 0; i < num_processes; i++) {
        order[i] = i;
    }
    
    for (int i = num_processes-1; i > 0; i--) { // Fisher-Yates shuffle algorithm for randomizing process order
        int j = rand() % (i+1);
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
    
    for (int i = 0; i < num_processes; i++) { // print optimized process order
        printf("%d. %s (%d seconds)\n", i+1, processes[order[i]], times[order[i]]);
    }
    
    printf("\nBoot processes optimized successfully!");
    
    free(processes); // free allocated memory
    free(times);
    free(order);
    
    return 0;
}