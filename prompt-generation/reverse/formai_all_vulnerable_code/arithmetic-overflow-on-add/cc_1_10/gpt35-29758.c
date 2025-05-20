//FormAI DATASET v1.0 Category: System boot optimizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Artistic style C System boot optimizer example program
*/

int main() {

    srand(time(NULL)); // initialize random seed

    // print out art header
    printf("######################################\n");
    printf("#    C System Boot Optimizer v1.0    #\n");
    printf("#              Artistic              #\n");
    printf("#         Created by Chatbot         #\n");
    printf("######################################\n\n");

    // initialize variables
    int boot_time = 0;
    int optimization_time = 0;
    int optimization_success_rate = rand() % 100 + 1;
    char optimization_type[10];
    char disk_drive[20];
    char system_timezone[50];

    // prompt user for inputs
    printf("Enter current boot time in seconds:\n");
    scanf("%d", &boot_time);
    printf("\nEnter type of optimization (Quick/Full):\n");
    scanf("%s", optimization_type);
    printf("\nEnter name of disk drive (C/D/E...):\n");
    scanf("%s", disk_drive);
    printf("\nEnter system timezone (e.g. America/Los_Angeles):\n");
    scanf("%s", system_timezone);

    // calculate optimization time based on type of optimization and success rate
    if (optimization_type[0] == 'Q') {
        optimization_time = rand() % 20 + 1;
    } else {
        optimization_time = rand() % 60 + 1;
    }
    optimization_time *= optimization_success_rate;

    // print out summary information
    printf("\n\n******************************\n");
    printf("** BOOT OPTIMIZATION SUMMARY **\n");
    printf("******************************\n\n");
    printf("Previous boot time: %d seconds\n", boot_time);
    printf("Optimization type: %s\n", optimization_type);
    printf("Disk drive: %s\n", disk_drive);
    printf("System timezone: %s\n", system_timezone);
    printf("Optimization success rate: %d%%\n", optimization_success_rate);
    printf("Optimization time: %d seconds\n\n", optimization_time);

    // wrap up and exit program
    printf("######################################\n");
    printf("#         Optimization Complete      #\n");
    printf("#         Total Boot Time: %d seconds      #\n", boot_time + optimization_time);
    printf("######################################\n");

    return 0;
}