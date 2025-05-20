//FormAI DATASET v1.0 Category: System boot optimizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the C System Boot Optimizer!\n");

    // Define variables for user input
    int numPrograms, numServices;

    // Ask user for number of programs and services
    printf("How many programs do you want to optimize? ");
    scanf("%d", &numPrograms);

    printf("How many services do you want to optimize? ");
    scanf("%d", &numServices);

    // Define arrays to store program and service names
    char programs[numPrograms][50];
    char services[numServices][50];

    // Ask user for program and service names
    printf("\nPlease input the names of the programs you want to optimize:\n");
    for (int i = 0; i < numPrograms; i++) {
        printf("> Program %d: ", i+1);
        scanf("%s", programs[i]);
    }

    printf("\nPlease input the names of the services you want to optimize:\n");
    for (int i = 0; i < numServices; i++) {
        printf("> Service %d: ", i+1);
        scanf("%s", services[i]);
    }

    // Display user input
    printf("\nYou have chosen to optimize the following %d programs:\n", numPrograms);
    for (int i = 0; i < numPrograms; i++) {
        printf("- %s\n", programs[i]);
    }

    printf("\nYou have chosen to optimize the following %d services:\n", numServices);
    for (int i = 0; i < numServices; i++) {
        printf("- %s\n", services[i]);
    }

    // Find programs and services in startup folder
    printf("\nSearching for programs and services in startup folder...\n");
    char command[200] = "ls /etc/init.d/ > startup.txt";
    system(command);

    // Open startup.txt and search for programs and services
    FILE *fp = fopen("startup.txt", "r");
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        // Check for programs
        for (int i = 0; i < numPrograms; i++) {
            if (strstr(line, programs[i]) != NULL) {
                printf("Found program %s in startup folder.\n", programs[i]);
                sprintf(command, "update-rc.d %s disable", programs[i]);
                system(command);
            }
        }

        // Check for services
        for (int i = 0; i < numServices; i++) {
            if (strstr(line, services[i]) != NULL) {
                printf("Found service %s in startup folder.\n", services[i]);
                sprintf(command, "update-rc.d %s disable", services[i]);
                system(command);
            }
        }
    }
    fclose(fp);

    // Clean up files
    printf("\nCleaning up files...\n");
    system("rm startup.txt");

    printf("\nDone! Your system will now boot faster without these programs and services running on startup.\n");
    return 0;
}