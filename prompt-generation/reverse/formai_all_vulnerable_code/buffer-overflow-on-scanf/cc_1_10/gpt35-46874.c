//FormAI DATASET v1.0 Category: System boot optimizer ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random percentage
int random_percentage() {
    return rand() % 100 + 1;
}

int main() {
    srand((unsigned)time(NULL)); // Seed random number generator
    
    int boot_time = 60; // Default boot time is 60 seconds
    int threshold = 80; // Default threshold for optimization is 80%
    
    // Print welcome message
    printf("Welcome to the C System Boot Optimizer!\n\n");
    
    // Prompt user for boot time and threshold
    printf("Enter the maximum allowable boot time (in seconds): ");
    scanf("%d", &boot_time);
    printf("Enter the optimization threshold (as a percentage): ");
    scanf("%d", &threshold);
    
    // Print current boot time and optimization threshold
    printf("\nYour current boot time is set to %d seconds.\n", boot_time);
    printf("Your optimization threshold is set to %d%%.\n\n", threshold);
    
    // Initialize variables for boot time optimization
    float optimization_percentage = 0.0;
    bool optimized = false;
    
    // Start boot time optimization process
    printf("Optimizing boot time...\n\n");
    while (!optimized) {
        // Generate random optimization percentage
        optimization_percentage = (float)random_percentage() / 100;
        
        // Check if optimization percentage meets threshold
        if (optimization_percentage >= threshold / 100.0) {
            // Optimization successful
            printf("Boot time successfully optimized!\n");
            printf("Your new boot time is %d seconds.\n", (int)(boot_time * optimization_percentage));
            optimized = true;
        } else {
            // Optimization unsuccessful, try again
            printf("Optimization unsuccessful, retrying...\n");
        }
    }
    
    return 0;
}