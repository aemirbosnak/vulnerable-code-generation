//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10
#define NAME_LENGTH 30

typedef enum {
    OFF,
    ON
} State;

typedef struct {
    char name[NAME_LENGTH];
    State state;
} SmartDevice;

typedef struct {
    SmartDevice devices[MAX_DEVICES];
    int device_count;
} SmartHome;

void initialize(SmartHome *home) {
    home->device_count = 0;
}

void add_device(SmartHome *home, const char *name) {
    if (home->device_count < MAX_DEVICES) {
        strcpy(home->devices[home->device_count].name, name);
        home->devices[home->device_count].state = OFF;
        home->device_count++;
        printf("Device '%s' added successfully.\n", name);
    } else {
        printf("Cannot add more devices. Maximum limit reached.\n");
    }
}

void toggle_device(SmartHome *home, const char *name) {
    for (int i = 0; i < home->device_count; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            home->devices[i].state = (home->devices[i].state == OFF) ? ON : OFF;
            printf("Device '%s' is now %s.\n", name, (home->devices[i].state == ON) ? "ON" : "OFF");
            return;
        }
    }
    printf("Device '%s' not found.\n", name);
}

void status_report(SmartHome *home) {
    printf("Home Automation Status Report:\n");
    for (int i = 0; i < home->device_count; i++) {
        printf("Device: %s, Status: %s\n", home->devices[i].name, 
                (home->devices[i].state == ON) ? "ON" : "OFF");
    }
}

void schedule_device(SmartHome *home, const char *name, int hour, int minute) {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_hour = hour;
    timeinfo->tm_min = minute;
    timeinfo->tm_sec = 0;

    // Please note that this is a simple blocking code. 
    // A real implementation would require asynchronous handling.
    timeinfo->tm_isdst = -1;
    mktime(timeinfo);
    printf("Scheduled device '%s' at %02d:%02d.\n", name, hour, minute);
    
    while (1) {
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        if (timeinfo->tm_hour == hour && timeinfo->tm_min == minute) {
            toggle_device(home, name);
            break;
        }
        sleep(30); // Check every 30 seconds
    }
}

void delete_device(SmartHome *home, const char *name) {
    int found = 0;
    for (int i = 0; i < home->device_count; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < home->device_count - 1; j++) {
                home->devices[j] = home->devices[j + 1];
            }
            home->device_count--;
            printf("Device '%s' removed successfully.\n", name);
            break;
        }
    }
    if (!found) {
        printf("Device '%s' not found.\n", name);
    }
}

void print_menu() {
    printf("\nSmart Home Automation Menu:\n");
    printf("1. Add Device\n");
    printf("2. Toggle Device\n");
    printf("3. Status Report\n");
    printf("4. Schedule Device\n");
    printf("5. Delete Device\n");
    printf("6. Exit\n");
}

int main() {
    SmartHome home;
    initialize(&home);
    int choice;
    char name[NAME_LENGTH];
    int hour, minute;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline character
                add_device(&home, name);
                break;
            case 2:
                printf("Enter device name to toggle: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                toggle_device(&home, name);
                break;
            case 3:
                status_report(&home);
                break;
            case 4:
                printf("Enter device name to schedule: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';

                printf("Enter hour (0-23): ");
                scanf("%d", &hour);
                printf("Enter minute (0-59): ");
                scanf("%d", &minute);
                
                schedule_device(&home, name, hour, minute);
                break;
            case 5:
                printf("Enter device name to delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                delete_device(&home, name);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}