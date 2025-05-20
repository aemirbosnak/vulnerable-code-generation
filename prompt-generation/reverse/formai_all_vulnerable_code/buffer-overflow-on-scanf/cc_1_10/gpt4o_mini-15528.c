//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPTIONS 5

typedef struct {
    char name[30];
    int speedupFactor; // Factor by which boot time is decreased (for simulation)
} OptimizationOption;

// Function Prototypes
void displayOptions(OptimizationOption options[], int count);
void simulateBoot(int baseBootTime, OptimizationOption selectedOption);
void logOptimizations(OptimizationOption selectedOption, int originalTime, int optimizedTime);

int main() {
    OptimizationOption options[MAX_OPTIONS] = {
        {"Disable Startup Programs", 15},
        {"Enable Fast Boot", 20},
        {"Optimize Drivers", 10},
        {"Increase RAM Allocation", 25},
        {"Clean Boot Configuration", 30}
    };

    int baseBootTime = 120; // Base boot time in seconds
    int userChoice;
    srand(time(NULL)); // Seed for randomization

    printf("Welcome to the Boot Optimizer!\n");
    printf("Current Boot Time: %d seconds\n", baseBootTime);
    
    while (1) {
        printf("\nChoose an optimization option (1-%d) or 0 to Exit:\n", MAX_OPTIONS);
        displayOptions(options, MAX_OPTIONS);
        printf("Your choice: ");
        scanf("%d", &userChoice);

        if (userChoice == 0) {
            printf("Exiting Boot Optimizer. Stay speedy!\n");
            break;
        } else if (userChoice < 1 || userChoice > MAX_OPTIONS) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        // Simulating the boot time optimization
        OptimizationOption selectedOption = options[userChoice - 1];
        simulateBoot(baseBootTime, selectedOption);
    }
    
    return 0;
}

void displayOptions(OptimizationOption options[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d: %s (Speedup: %d seconds)\n", i + 1, options[i].name, options[i].speedupFactor);
    }
}

void simulateBoot(int baseBootTime, OptimizationOption selectedOption) {
    int optimizedTime = baseBootTime - selectedOption.speedupFactor;
    if (optimizedTime < 0) optimizedTime = 0; // Prevent negative boot time

    printf("Applying optimization: %s\n", selectedOption.name);
    printf("Original Boot Time: %d seconds\n", baseBootTime);
    printf("Optimized Boot Time: %d seconds\n", optimizedTime);

    // Log the optimization effect
    logOptimizations(selectedOption, baseBootTime, optimizedTime);
}

void logOptimizations(OptimizationOption selectedOption, int originalTime, int optimizedTime) {
    FILE *logFile = fopen("boot_optimizer_log.txt", "a");
    if (logFile == NULL) {
        perror("Failed to open log file");
        return;
    }

    time_t now = time(NULL);
    fprintf(logFile, "[%s] Optimization Applied: %s\n", ctime(&now), selectedOption.name);
    fprintf(logFile, "Original Boot Time: %d seconds, Optimized Boot Time: %d seconds\n\n", originalTime, optimizedTime);
    
    fclose(logFile);
    printf("Optimization logged successfully!\n");
}