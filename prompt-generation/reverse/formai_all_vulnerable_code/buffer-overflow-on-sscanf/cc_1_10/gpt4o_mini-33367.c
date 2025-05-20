//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_MEMORY_STRING 256

// Function to simulate getting RAM usage
void get_ram_usage() {
    FILE *fp;
    char buffer[MAX_MEMORY_STRING];
    long total_memory, free_memory, used_memory;

    // Open the /proc/meminfo file, it's like a treasure map!
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        fprintf(stderr, "Oops! Can't find your treasure! Maybe it's buried in the sand...\n");
        exit(EXIT_FAILURE);
    }

    // Read memory info - it’s a bit like unwrapping a gift, but less exciting
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            // Found total memory!
        } else if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            // Found free memory!
        }
    }
    fclose(fp);

    // Let's calculate the used memory like a math wizard!
    used_memory = total_memory - free_memory;

    // Print the results in a way that would make your grandma giggle
    printf("** RAM Usage Report **\n");
    printf(" Total RAM: %.2f GB\n", total_memory / 1024.0 / 1024.0);
    printf(" Free RAM: %.2f GB\n", free_memory / 1024.0 / 1024.0);
    printf(" Used RAM: %.2f GB\n", used_memory / 1024.0 / 1024.0);
    
    // Pretty sparkles indicating how much you've used
    if (used_memory < total_memory * 0.5) {
        printf("Wohoo! You're under the RAM limit! Keep it up, superstar! 🌟\n");
    } else {
        printf("Oh no! You're almost out of RAM! Time to kick some apps out! 🦵📱\n");
    }
}

int main() {
    // Declare magic potion variables
    char choice;

    // Welcome message that's cheesier than a pizza
    printf("Welcome to the Magical RAM Usage Monitor! 🧙‍♂️\n");
    printf("Press 'm' to magically measure your RAM usage or 'q' to quit this enchanted land:\n");

    // Keep the magic alive until the user wants to leave
    while (1) {
        choice = getchar(); // Get user input
        
        if (choice == 'm') {
            get_ram_usage(); // Call the function to monitor RAM
            printf("Press 'm' again for another magical analysis or 'q' to escape!\n");
        } else if (choice == 'q') {
            printf("Thank you for visiting! May your RAM be ever in your favor! 👋😄\n");
            break; // Exit the loop
        } else {
            printf("That key doesn't summon any magic! Try 'm' or 'q'. 🧙‍♂️🔮\n");
        }
        while (getchar() != '\n'); // Clear the input buffer for clean readings
    }
    
    return 0; // Exit the program like a proper magician!
}