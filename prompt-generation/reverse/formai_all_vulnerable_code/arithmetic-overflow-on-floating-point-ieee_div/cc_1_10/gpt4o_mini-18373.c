//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void displayMemoryStatus(int totalMem, int freeMem, int usedMem, double usagePercentage) {
    // A poet's heart translates memory data into romantic sonnets
    printf("\n");
    printf("                ✧✧ Memory Usage Romance ✧✧\n");
    printf("----------------------------------------------------\n");
    printf("   Total Memory: %d MB\n", totalMem);
    printf("       Free Memory: %d MB\n", freeMem);
    printf("       Used Memory: %d MB\n", usedMem);
    printf("   Usage Percentage: %.2f%%\n", usagePercentage);
    printf("----------------------------------------------------\n");
}

void loveLetter(int totalMem) {
    // The metaphor of memory as love, growing, changing, yet always substantial
    printf("Oh, my darling memory!\n");
    printf("In your embrace, %d MB of dreams reside.\n", totalMem);
    printf("Like a soft whisper, you cradle my thoughts,\n");
    printf("We dance, together, in perfect harmony.\n\n");
}

void memoryRomance() {
    // Coursing through the rhythmic allure of memory management
    
    FILE *fp = popen("free -m", "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        exit(1);
    }

    char line[256];
    fgets(line, sizeof(line), fp); // Skip header
    fgets(line, sizeof(line), fp); // Get line with memory info

    // Parse the memory values from free command output
    int totalMem, usedMem, freeMem;

    sscanf(line, "%*s %d %d %d", &totalMem, &usedMem, &freeMem);

    // Calculate usage percentage
    double usagePercentage = (double)usedMem / totalMem * 100;

    displayMemoryStatus(totalMem, freeMem, usedMem, usagePercentage);
    loveLetter(totalMem);

    pclose(fp);
}

int main() {
    // The beginning of our romantic odyssey
    printf("❤️ Welcome to the Memory Usage Romance! ❤️\n");
    
    while (1) {
        memoryRomance();
        printf("Let us pause our dance for a while...\n");
        sleep(5); // Pause for 5 seconds for a tender moment
    }

    return 0;
}