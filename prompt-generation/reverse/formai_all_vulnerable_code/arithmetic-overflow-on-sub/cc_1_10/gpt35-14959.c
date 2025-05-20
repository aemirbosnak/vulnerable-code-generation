//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

/* Constants */
#define REFRESH_RATE 0.5 // Set refresh rate in seconds
#define CPU_USAGE_FILE "/proc/stat" // File to read CPU usage from

/* Function prototypes */
float getCurrentCPUUsage();
void printUsageBar(float usagePercentage);
void clearScreen();

int main()
{
    float currentUsage = 0.0;
    float previousUsage = 0.0;
    float difference = 0.0;

    while(1)
    {
        clearScreen(); // Clear screen to refresh display

        currentUsage = getCurrentCPUUsage(); // Read current CPU usage
        difference = currentUsage - previousUsage; // Calculate difference in usage

        printf("CPU Usage: %2.2f%%\n", currentUsage); // Print current CPU usage
        printUsageBar(currentUsage); // Print usage bar
        printf("\n");

        if(difference >= 0)
            printf("Usage Increased By: %2.2f%%\n", difference); // Print usage increase
        else
            printf("Usage Decreased By: %2.2f%%\n", -difference); // Print usage decrease

        previousUsage = currentUsage; // Set previous usage for next comparison

        sleep(REFRESH_RATE); // Wait before refreshing display
    }

    return 0;
}

/* Function to get current CPU usage percentage */
float getCurrentCPUUsage()
{
    FILE* file = fopen(CPU_USAGE_FILE, "r"); // Open file for reading
    char line[256];
    int processor = -1;
    int user = -1;
    int nice = -1;
    int system = -1;
    int idle = -1;

    /* Read first line of file */
    fgets(line, sizeof(line), file);
    sscanf(line, "cpu %d %d %d %d %d", &processor, &user, &nice, &system, &idle);

    /* Calculate time */
    int timeTotal = user + nice + system + idle;
    int timeUsed = user + nice + system;
    float usagePercentage = (float)timeUsed / (float)timeTotal * 100;

    /* Clean up */
    fclose(file);

    return usagePercentage;
}

/* Function to print CPU usage bar graph */
void printUsageBar(float usagePercentage)
{
    int barLength = 40;
    int filledLength = (int)(usagePercentage / 100 * barLength);
    int emptyLength = barLength - filledLength;

    printf("[");
    for(int i = 0; i < filledLength; i++)
        printf("#");
    for(int i = 0; i < emptyLength; i++)
        printf(".");
    printf("]");
}

/* Function to clear console */
void clearScreen()
{
    // Clear console using ANSI escape sequence
    printf("\033[2J\033[1;1H");
}