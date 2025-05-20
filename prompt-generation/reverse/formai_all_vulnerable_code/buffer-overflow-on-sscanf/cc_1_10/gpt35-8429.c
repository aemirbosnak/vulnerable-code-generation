//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define THRESHOLD 80 // The threshold percentage at which the display changes
#define MAX_TITLE 20 // Maximum length of the program's name

void shift_display(int usage);
char* get_process_name();

int main()
{
    long int pagesize = sysconf(_SC_PAGESIZE); // Get page size for proper memory allocation
    FILE* meminfo = fopen("/proc/meminfo", "r"); // Open file for RAM usage info
    char* line = malloc(pagesize); // Allocate memory for reading in file lines
    char* name = get_process_name(); // Get the name of this program for the title
    
    while(1)
    {
        int usage;
        fgets(line, pagesize, meminfo); // Read in the first line for total memory
        sscanf(line, "MemTotal: %d", &usage); // Parse the usage value
        fgets(line, pagesize, meminfo); // Read in the next line for free memory
        sscanf(line, "MemFree: %d", &usage); // Subtract free memory from total for used memory
        usage = 100 - ((usage * 100) / THRESHOLD); // Calculate RAM usage as a percentage of the threshold
        
        if (usage >= THRESHOLD)
        {
            // If the usage is above the threshold, shift the display to a warning
            shift_display(usage);
        }
        else
        {
            // If the usage is below the threshold, shift the display to a normal state
            shift_display(usage);
        }
        
        fprintf(stderr, "\x1b[2J\x1b[H"); // Clear the terminal screen for the next update
        printf("%s | RAM Usage: %d%%\n", name, usage); // Print the updated title and RAM usage
        fflush(stdout); // Flush the output buffer to update the display
        
        // Wait for a short time before updating the display again
        usleep(100000);
    }
    
    free(line); // Free allocated memory
    return 0;
}

void shift_display(int usage)
{
    // This function changes the appearance of the program based on RAM usage percent
    
    if (usage >= THRESHOLD) // If the usage is above the threshold
    {
        printf("\x1b[31m"); // Set the text color to red
    }
    else // If the usage is below the threshold
    {
        printf("\x1b[32m"); // Set the text color to green
    }
}

char* get_process_name()
{
    // This function retrieves the name of the currently running program
    char* name = malloc(MAX_TITLE);
    memset(name, 0, MAX_TITLE); // Zero out memory for safety
    
    readlink("/proc/self/exe", name, MAX_TITLE); // Read the symbolic link for the program name
    
    return name;
}