//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_APPS 10
#define NAME_SIZE 30

typedef struct {
    char name[NAME_SIZE];
    int priority; // Lower value means higher priority
    int loadTime; // Time taken to load in milliseconds
} App;

App apps[MAX_APPS];
int appCount = 0;

void addApp(const char* name, int priority, int loadTime) {
    if (appCount < MAX_APPS) {
        strncpy(apps[appCount].name, name, NAME_SIZE);
        apps[appCount].priority = priority;
        apps[appCount].loadTime = loadTime;
        appCount++;
    } else {
        printf("App list is full. Cannot add %s.\n", name);
    }
}

int compare(const void* a, const void* b) {
    App* appA = (App*)a;
    App* appB = (App*)b;
    return appA->priority - appB->priority;
}

void optimizeBoot() {
    printf("Optimizing boot sequence...\n");

    // Sort apps based on their priority
    qsort(apps, appCount, sizeof(App), compare);

    // Simulated boot sequence
    for (int i = 0; i < appCount; i++) {
        printf("Loading %s (priority %d)... ", apps[i].name, apps[i].priority);
        usleep(apps[i].loadTime * 1000); // Simulate load time in milliseconds
        printf("Loaded!\n");
    }
}

void displayApps() {
    printf("Current apps:\n");
    for (int i = 0; i < appCount; i++) {
        printf(" - %s [Priority: %d, Load Time: %dms]\n", apps[i].name, apps[i].priority, apps[i].loadTime);
    }
}

void showInstructions() {
    printf("Cyberpunk Boot Optimizer v1.0\n");
    printf("Usage:\n");
    printf("1. Add applications\n");
    printf("2. Optimize boot sequence\n");
    printf("3. Display application list\n");
    printf("4. Exit\n");
}

int main() {
    char command[50];
    showInstructions();

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strcmp(command, "exit") == 0) {
            printf("Shutting down the optimizer. Goodbye, hacker!\n");
            break;
        } else if (strcmp(command, "optimize") == 0) {
            optimizeBoot();
        } else if (strcmp(command, "show apps") == 0) {
            displayApps();
        } else if (strncmp(command, "add ", 4) == 0) {
            char name[NAME_SIZE];
            int priority, loadTime;
            sscanf(command + 4, "%s %d %d", name, &priority, &loadTime);
            addApp(name, priority, loadTime);
            printf("%s added with priority %d and load time %dms.\n", name, priority, loadTime);
        } else {
            printf("Unknown command. Try 'optimize', 'show apps', 'add <name> <priority> <load time>', or 'exit'.\n");
        }
    }

    return 0;
}