//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_APPS 100
#define MAX_NAME_LENGTH 50
#define COMMAND_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char command[COMMAND_LENGTH];
    int priority; // Lower number means higher priority
} Application;

Application apps[MAX_APPS];
int app_count = 0;

void add_application(char *name, char *command, int priority) {
    if (app_count < MAX_APPS) {
        strcpy(apps[app_count].name, name);
        strcpy(apps[app_count].command, command);
        apps[app_count].priority = priority;
        app_count++;
    } else {
        printf("Maximum application limit reached.\n");
    }
}

int compare_applications(const void *a, const void *b) {
    return ((Application *)a)->priority - ((Application *)b)->priority;
}

void optimize_boot() {
    printf("Optimizing boot sequence...\n");
    qsort(apps, app_count, sizeof(Application), compare_applications);
    for (int i = 0; i < app_count; i++) {
        printf("%d: %s\n", i + 1, apps[i].name);
    }
    printf("Boot sequence optimized based on application priority.\n");
}

void launch_applications() {
    printf("Launching applications in optimized order...\n");
    for (int i = 0; i < app_count; i++) {
        printf("Launching: %s...\n", apps[i].name);
        system(apps[i].command);
        sleep(1); // Simulating some time for the app to launch
    }
}

void display_menu() {
    printf("\n--- Boot Optimizer Menu ---\n");
    printf("1. Add Application\n");
    printf("2. Optimize Boot\n");
    printf("3. Launch Applications\n");
    printf("4. Exit\n");
    printf("--------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    char name[MAX_NAME_LENGTH];
    char command[COMMAND_LENGTH];
    int priority;

    while (1) {
        display_menu();
        scanf("%d", &option);
        getchar(); // Consume newline

        switch (option) {
            case 1:
                printf("Enter application name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter application command: ");
                fgets(command, COMMAND_LENGTH, stdin);
                command[strcspn(command, "\n")] = 0; // Remove newline

                printf("Enter application priority (lower number means higher priority): ");
                scanf("%d", &priority);
                getchar(); // Consume newline

                add_application(name, command, priority);
                break;

            case 2:
                optimize_boot();
                break;

            case 3:
                launch_applications();
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}