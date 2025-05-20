//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_APPS 10
#define MAX_NAME_LENGTH 50
#define CONFIG_FILE "boot_config.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int priority;
} App;

App appList[MAX_APPS];
int appCount = 0;

void loadConfig() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) {
        perror("Could not open config file");
        return;
    }

    while (fscanf(file, "%s %d", appList[appCount].name, &appList[appCount].priority) != EOF) {
        appCount++;
        if (appCount >= MAX_APPS) break;
    }
    fclose(file);
}

void sortAppsByPriority() {
    for (int i = 0; i < appCount - 1; i++) {
        for (int j = 0; j < appCount - i - 1; j++) {
            if (appList[j].priority < appList[j + 1].priority) {
                App temp = appList[j];
                appList[j] = appList[j + 1];
                appList[j + 1] = temp;
            }
        }
    }
}

void optimizeBootSequence() {
    sortAppsByPriority();
    printf("Boot sequence optimized. Launching apps in priority order:\n");

    for (int i = 0; i < appCount; i++) {
        printf("Launching %s with priority %d\n", appList[i].name, appList[i].priority);
        // Simulate app launch
        sleep(1);
    }
}

void displayApps() {
    printf("Configured Applications:\n");
    for (int i = 0; i < appCount; i++) {
        printf("App Name: %s, Priority: %d\n", appList[i].name, appList[i].priority);
    }
}

void addApp(const char *name, int priority) {
    if (appCount >= MAX_APPS) {
        printf("Cannot add more apps, maximum reached.\n");
        return;
    }

    strncpy(appList[appCount].name, name, MAX_NAME_LENGTH - 1);
    appList[appCount].priority = priority;
    appCount++;
}

int main() {
    loadConfig();
    displayApps();
    optimizeBootSequence();

    // Example: Adding a new app dynamically
    addApp("FileSync", 2);
    printf("\nAfter adding FileSync:\n");
    displayApps();
    optimizeBootSequence();

    return 0;
}