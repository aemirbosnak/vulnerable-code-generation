//FormAI DATASET v1.0 Category: System boot optimizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int seconds) {
    int i;
    clock_t start = clock();
    while (clock() < start + (seconds * CLOCKS_PER_SEC)) {}
}

int main() {
    printf("Welcome to RetroBoot Optimizer v1.0\n");
    delay(3);
    printf("Scanning system for boot time optimization...\n");
    delay(5);

    int numPrograms = 10;
    char programs[][20] = {"chrome", "spotify", "discord", "steam", "notepad", "paint", "calculator", "photoshop", "outlook", "word"};
    int bootTimes[] = {12, 8, 10, 14, 2, 3, 1, 18, 6, 5};

    printf("Found %d programs running at startup:\n", numPrograms);
    for (int i = 0; i < numPrograms; i++) {
        printf("%s - %d seconds\n", programs[i], bootTimes[i]);
    }
    delay(4);

    printf("\nOptimizing boot times...\n\n");
    delay(3);

    int maxIndex = 0;
    for (int i = 1; i < numPrograms; i++) {
        if (bootTimes[i] > bootTimes[maxIndex]) {
            maxIndex = i;
        }
    }

    printf("Removing %s from startup...\n", programs[maxIndex]);
    memmove(programs[maxIndex], programs[maxIndex+1], (numPrograms-maxIndex-1)*20);
    memmove(bootTimes+maxIndex, bootTimes+maxIndex+1, (numPrograms-maxIndex-1)*sizeof(int));
    numPrograms--;

    delay(3);
    printf("\nNew optimized startup configuration:\n");
    for (int i = 0; i < numPrograms; i++) {
        printf("%s - %d seconds\n", programs[i], bootTimes[i]);
    }

    delay(4);
    printf("\nOptimization completed. Restarting system...\n");
    delay(5);

    return 0;
}