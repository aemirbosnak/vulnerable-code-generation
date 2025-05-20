//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPS 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int enabled;
} App;

App apps[MAX_APPS] = {
    {"NetworkManager", 1},
    {"cron", 1},
    {"systemd-timesyncd", 1},
    {"bluetooth", 1},
    {"cups", 1},
    {"avahi-daemon", 1},
    {"ssh", 1},
    {"firewalld", 1},
    {"snapd", 1},
    {"nm-applet", 1}
};

void display_apps() {
    printf("\n=== Boot Applications ===\n");
    for (int i = 0; i < MAX_APPS; i++) {
        printf("[%d] %s - %s\n", i + 1, apps[i].name, apps[i].enabled ? "Enabled" : "Disabled");
    }
    printf("==========================\n");
}

void toggle_app(int index) {
    if (index < 0 || index >= MAX_APPS) {
        printf("Invalid selection!\n");
        return;
    }
    apps[index].enabled = !apps[index].enabled;
    printf("%s is now %s.\n", apps[index].name, apps[index].enabled ? "Enabled" : "Disabled");
}

void optimizer_menu() {
    int choice;

    while (1) {
        display_apps();
        printf("Select an application to toggle (1-%d) or 0 to Exit: ", MAX_APPS);
        scanf("%d", &choice);
        if (choice == 0) {
            printf("Exiting Boot Optimizer. Have a nice boot!\n");
            break;
        }
        toggle_app(choice - 1);
    }
}

void save_permissions() {
    // Simulate saving user preferences to a file
    FILE *file = fopen("boot_optimizer_status.txt", "w");
    if (file) {
        for (int i = 0; i < MAX_APPS; i++) {
            fprintf(file, "%s: %s\n", apps[i].name, apps[i].enabled ? "Enabled" : "Disabled");
        }
        fclose(file);
        printf("Your changes have been saved to boot_optimizer_status.txt\n");
    } else {
        perror("Error saving changes");
    }
}

int main() {
    printf("=== Welcome to the Boot Optimizer ===\n");
    optimizer_menu();
    save_permissions();
    return 0;
}