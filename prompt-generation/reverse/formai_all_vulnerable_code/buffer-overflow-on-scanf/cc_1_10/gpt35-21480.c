//FormAI DATASET v1.0 Category: System boot optimizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printHeader() {
    printf("\n------------------------------------------------");
    printf("\n--------------- Boot Optimizer 3000 ---------------");
    printf("\n------------------------------------------------\n\n");
}

void printLoadingScreen() {
    printf("Loading...\n");
    for(int i = 0; i < 5; i++) {
        printf(".");
        sleep(1); // sleep for 1 second
    }
    printf("Done!\n");
}

void runBootOptimizer() {
    printf("Running Boot Optimizer...\n");

    // Code for optimizing the system boot process goes here
    // This could include disabling unnecessary services, removing unwanted startup programs, etc.

    printf("Boot Optimization Complete!\n");
}

void promptForReboot() {
    char answer[10];
    printf("Would you like to reboot your system now? (Y/N): ");
    scanf("%s", answer);

    if(strcmp(answer, "Y") == 0 || strcmp(answer, "y") == 0) {
        printf("Rebooting...\n");
        sleep(2); // sleep for 2 seconds
        printf("System has been rebooted.\n");
    } else {
        printf("Okay, shutting down optimizer...\n");
        sleep(1); // sleep for 1 second
    }
}

int main() {
    printHeader();
    printLoadingScreen();
    runBootOptimizer();
    promptForReboot();

    return 0;
}