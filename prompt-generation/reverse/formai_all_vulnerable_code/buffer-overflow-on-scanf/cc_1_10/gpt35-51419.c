//FormAI DATASET v1.0 Category: System boot optimizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate random numbers for boot optimization
    int bootTime = rand() % 101;
    int numOfProcesses = rand() % 101;
    int numOfServices = rand() % 101;
    int numOfStartUpApps = rand() % 101;

    // Calculate overall boot time based on random numbers
    int overallBootTime = bootTime + (numOfProcesses * 2) + (numOfServices * 3) + (numOfStartUpApps * 4);
    
    // Print initial boot time
    printf("Initial boot time: %d seconds\n", bootTime);
    
    // Print stats for number of processes, services, and startup apps
    printf("Number of processes: %d\n", numOfProcesses);
    printf("Number of services: %d\n", numOfServices);
    printf("Number of startup apps: %d\n", numOfStartUpApps);

    // Offer options for optimization
    printf("Do you want to optimize the boot time? (y/n)\n");
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'y') {
        // Generate more random numbers for optimization
        int numToAddProcesses = rand() % 51;
        int numToDisableServices = rand() % (numOfServices + 1);
        int numToRemoveStartUpApps = rand() % (numOfStartUpApps + 1);

        // Calculate new boot time after optimization
        int newBootTime = bootTime - (numToAddProcesses * 2) + (numToDisableServices * 5) - (numToRemoveStartUpApps * 6);
        
        // Calculate overall boot time based on new boot time and original number of processes, services, and startup apps
        int newOverallBootTime = newBootTime + (numOfProcesses * 2) + ((numOfServices - numToDisableServices) * 3) + ((numOfStartUpApps - numToRemoveStartUpApps) * 4);
        
        // Print stats for optimization
        printf("Number of processes to add: %d\n", numToAddProcesses);
        printf("Number of services to disable: %d\n", numToDisableServices);
        printf("Number of startup apps to remove: %d\n", numToRemoveStartUpApps);
        
        // Print new boot time
        printf("New boot time: %d seconds\n", newBootTime);
        
        // Print overall boot time improvement
        printf("Overall improvement: %d seconds\n", overallBootTime - newOverallBootTime);
    } else {
        // Print final boot time if optimization is not chosen
        printf("Final boot time: %d seconds\n", overallBootTime);
    }

    return 0;
}