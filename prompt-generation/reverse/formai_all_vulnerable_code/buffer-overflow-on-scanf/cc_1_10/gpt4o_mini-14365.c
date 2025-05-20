//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_BOOT_TIME 15       // maximum boot time in seconds
#define NUM_BOOT_OPTIONS 5     // number of boot options
#define REBOOT_THRESHOLD 5      // threshold to reboot

typedef struct {
    char name[50];
    int init_time;            // time to initialize the option
} BootOption;

void initializeBootOptions(BootOption options[]) {
    const char *names[NUM_BOOT_OPTIONS] = {
        "Linux Kernel",
        "System Recovery",
        "Safe Mode",
        "Custom OS",
        "Network Boot"
    };
    
    srand(time(NULL)); // Seed random number generator
    
    for (int i = 0; i < NUM_BOOT_OPTIONS; i++) {
        snprintf(options[i].name, sizeof(options[i].name), "%s", names[i]);
        options[i].init_time = rand() % (MAX_BOOT_TIME + 1); // Random initialization time
    }
}

void displayBootOptions(BootOption options[]) {
    printf("Boot Options:\n");
    for (int i = 0; i < NUM_BOOT_OPTIONS; i++) {
        printf(" [%d] %s (Init Time: %ds)\n", i + 1, options[i].name, options[i].init_time);
    }
}

void optimizeBoot(BootOption options[]) {
    int total_time = 0;
    int boot_choice = -1;

    // Calculate total boot time
    for (int i = 0; i < NUM_BOOT_OPTIONS; i++) {
        total_time += options[i].init_time;
    }

    printf("\nTotal boot time calculation: %ds\n", total_time);
    
    if (total_time > REBOOT_THRESHOLD) {
        printf("Total boot time exceeds threshold! Rebooting in 3 seconds...\n");
        sleep(3);
        // Simulate re-initialization
        initializeBootOptions(options);
        total_time = 0; // Reset total time
    }

    displayBootOptions(options);
    printf("\nChoose a boot option by entering the number: ");
    scanf("%d", &boot_choice);

    if (boot_choice > 0 && boot_choice <= NUM_BOOT_OPTIONS) {
        printf("Booting %s...\n", options[boot_choice - 1].name);
        sleep(options[boot_choice - 1].init_time); // simulate booting process
        printf("%s has booted successfully!\n", options[boot_choice - 1].name);
    } else {
        printf("Invalid choice, exiting...\n");
    }
}

void logBootEvent(const char *event) {
    FILE *logFile = fopen("boot_log.txt", "a");
    if (logFile == NULL) {
        perror("Failed to open log file");
        return;
    }
    
    time_t now = time(NULL);
    fprintf(logFile, "[%s] %s\n", ctime(&now), event);
    fclose(logFile);
}

int main() {
    BootOption bootOptions[NUM_BOOT_OPTIONS];
    
    printf("Welcome to the Boot Optimizer!\n");
    
    initializeBootOptions(bootOptions);
    logBootEvent("Boot optimization started.");

    optimizeBoot(bootOptions);

    logBootEvent("Boot optimization completed.");
    printf("Thank you for using the Boot Optimizer! Goodbye!\n");
    
    return 0;
}