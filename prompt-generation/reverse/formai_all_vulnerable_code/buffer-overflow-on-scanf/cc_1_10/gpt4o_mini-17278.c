//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int enabled; // 1 for enabled, 0 for disabled
    int boot_time; // simulated boot time in milliseconds
} Application;

Application apps[MAX_APPS];
int app_count = 0;

// Function to initialize sample applications
void initialize_apps() {
    strcpy(apps[0].name, "App1");
    apps[0].enabled = 1;
    apps[0].boot_time = 200;

    strcpy(apps[1].name, "App2");
    apps[1].enabled = 1;
    apps[1].boot_time = 300;

    strcpy(apps[2].name, "App3");
    apps[2].enabled = 1;
    apps[2].boot_time = 150;

    strcpy(apps[3].name, "App4");
    apps[3].enabled = 0;
    apps[3].boot_time = 250;

    app_count = 4; // We have 4 sample applications
}

// Function to list applications
void list_apps() {
    printf("\nAvailable Startup Applications:\n");
    for (int i = 0; i < app_count; i++) {
        printf("%d. %s [%s] - Boot Time: %d ms\n", 
               i + 1, 
               apps[i].name, 
               apps[i].enabled ? "Enabled" : "Disabled", 
               apps[i].boot_time);
    }
}

// Function to enable an application
void enable_app(int index) {
    if (index < 0 || index >= app_count) {
        printf("Invalid index. Please choose a valid application number.\n");
        return;
    }
    apps[index].enabled = 1;
    printf("%s has been enabled.\n", apps[index].name);
}

// Function to disable an application
void disable_app(int index) {
    if (index < 0 || index >= app_count) {
        printf("Invalid index. Please choose a valid application number.\n");
        return;
    }
    apps[index].enabled = 0;
    printf("%s has been disabled.\n", apps[index].name);
}

// Function to optimize boot time
void optimize_boot_time() {
    int total_time = 0;
    printf("\nCalculating total boot time...\n");
    for (int i = 0; i < app_count; i++) {
        if (apps[i].enabled) {
            total_time += apps[i].boot_time;
        }
    }
    printf("Total Boot Time with enabled applications: %d ms\n", total_time);
}

int main() {
    int choice, app_number;

    initialize_apps();

    while (1) {
        printf("\nSystem Boot Optimizer Menu:\n");
        printf("1. List Startup Applications\n");
        printf("2. Enable an Application\n");
        printf("3. Disable an Application\n");
        printf("4. Optimize Boot Time\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_apps();
                break;
            case 2:
                printf("Enter the application number to enable (1 to %d): ", app_count);
                scanf("%d", &app_number);
                enable_app(app_number - 1);
                break;
            case 3:
                printf("Enter the application number to disable (1 to %d): ", app_count);
                scanf("%d", &app_number);
                disable_app(app_number - 1);
                break;
            case 4:
                optimize_boot_time();
                break;
            case 5:
                printf("Exiting the Boot Optimizer...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}