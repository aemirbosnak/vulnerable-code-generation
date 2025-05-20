//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_BOOT_PARAMETERS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
} BootParam;

// Function to display boot parameters
void displayBootParams(BootParam params[], int count) {
    printf("\nCurrent Boot Parameters:\n");
    printf("------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("Name: %s, Priority: %d\n", params[i].name, params[i].priority);
    }
    printf("------------------------\n");
}

// Function to sort boot parameters based on priority
void sortBootParams(BootParam params[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (params[j].priority > params[j + 1].priority) {
                BootParam temp = params[j];
                params[j] = params[j + 1];
                params[j + 1] = temp;
            }
        }
    }
    printf("Boot parameters sorted by priority!\n");
}

// Function to optimize boot parameters based on user input
void optimizeBootParams(BootParam params[], int* count) {
    printf("Enter the number of boot parameters (max %d): ", MAX_BOOT_PARAMETERS);
    scanf("%d", count);
    if (*count > MAX_BOOT_PARAMETERS) {
        printf("Limit exceeded! Setting count to %d.\n", MAX_BOOT_PARAMETERS);
        *count = MAX_BOOT_PARAMETERS;
    }
    printf("Input boot parameters with priority:\n");

    for (int i = 0; i < *count; ++i) {
        printf("Parameter %d Name: ", i + 1);
        scanf("%s", params[i].name);
        printf("Parameter %d Priority (lower numbers are higher priority): ", i + 1);
        scanf("%d", &params[i].priority);
    }

    sortBootParams(params, *count);
    displayBootParams(params, *count);
}

// Function to save the boot parameters to a file
void saveBootParamsToFile(BootParam params[], int count) {
    FILE *file = fopen("boot_parameters.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%s %d\n", params[i].name, params[i].priority);
    }
    fclose(file);
    printf("Boot parameters saved to 'boot_parameters.txt'.\n");
}

// Function to read the boot parameters from a file
void loadBootParamsFromFile(BootParam params[], int* count) {
    FILE *file = fopen("boot_parameters.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    while (fscanf(file, "%s %d", params[*count].name, &params[*count].priority) != EOF) {
        (*count)++;
        if (*count >= MAX_BOOT_PARAMETERS) {
            break;
        }
    }
    fclose(file);
    printf("Boot parameters loaded from 'boot_parameters.txt'.\n");
}

// Function to display system information
void displaySystemInfo() {
    struct sysinfo info;
    sysinfo(&info);
    printf("\nSystem Information:\n");
    printf("Uptime: %ld seconds\n", info.uptime);
    printf("Total RAM: %ld MB\n", info.totalram / 1024 / 1024);
    printf("Free RAM: %ld MB\n", info.freeram / 1024 / 1024);
    printf("Number of Processes: %d\n", info.procs);
}

int main() {
    BootParam bootParams[MAX_BOOT_PARAMETERS];
    int bootParamCount = 0;
    int option;

    // Display system information at startup
    displaySystemInfo();
    
    printf("Welcome to the C System Boot Optimizer!\n");
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Optimize boot parameters\n");
        printf("2. Save boot parameters\n");
        printf("3. Load boot parameters\n");
        printf("4. Display current boot parameters\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            optimizeBootParams(bootParams, &bootParamCount);
            break;
        case 2:
            saveBootParamsToFile(bootParams, bootParamCount);
            break;
        case 3:
            loadBootParamsFromFile(bootParams, &bootParamCount);
            break;
        case 4:
            displayBootParams(bootParams, bootParamCount);
            break;
        case 5:
            printf("Exiting the optimizer. Have a great day!\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}