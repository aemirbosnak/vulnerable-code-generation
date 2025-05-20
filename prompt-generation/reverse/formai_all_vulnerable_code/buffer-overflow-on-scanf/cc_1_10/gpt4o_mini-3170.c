//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_USERS 5
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int status;  // 0: off, 1: on
} Device;

typedef struct {
    char username[NAME_LENGTH];
    Device devices[MAX_DEVICES];
    int device_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void addUser(const char* username) {
    if (user_count < MAX_USERS) {
        strncpy(users[user_count].username, username, NAME_LENGTH);
        users[user_count].device_count = 0;
        user_count++;
        printf("User %s added!\n", username);
    } else {
        printf("Maximum user limit reached.\n");
    }
}

void addDevice(const char* username, const char* device_name) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (users[i].device_count < MAX_DEVICES) {
                strncpy(users[i].devices[users[i].device_count].name, device_name, NAME_LENGTH);
                users[i].devices[users[i].device_count].status = 0;  // Off by default
                users[i].device_count++;
                printf("Device %s added to user %s!\n", device_name, username);
            } else {
                printf("User %s has reached maximum device limit.\n", username);
            }
            return;
        }
    }
    printf("User not found: %s\n", username);
}

void commandDevice(const char* username, const char* device_name, const char* command) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            for (int j = 0; j < users[i].device_count; j++) {
                if (strcmp(users[i].devices[j].name, device_name) == 0) {
                    if (strcmp(command, "on") == 0) {
                        users[i].devices[j].status = 1;
                        printf("Device %s is turned ON by %s.\n", device_name, username);
                    } else if (strcmp(command, "off") == 0) {
                        users[i].devices[j].status = 0;
                        printf("Device %s is turned OFF by %s.\n", device_name, username);
                    } else {
                        printf("Invalid command. Use 'on' or 'off'.\n");
                    }
                    return;
                }
            }
            printf("Device not found: %s\n", device_name);
            return;
        }
    }
    printf("User not found: %s\n", username);
}

void listDevices(const char* username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (users[i].device_count == 0) {
                printf("No devices found for user %s.\n", username);
                return;
            }
            printf("Devices for user %s:\n", username);
            for (int j = 0; j < users[i].device_count; j++) {
                printf(" - %s: %s\n", users[i].devices[j].name, 
                    users[i].devices[j].status ? "ON" : "OFF");
            }
            return;
        }
    }
    printf("User not found: %s\n", username);
}

int main() {
    int choice;
    char username[NAME_LENGTH], device_name[NAME_LENGTH], command[4];

    do {
        printf("\nSmart Home Automation System\n");
        printf("1. Add User\n");
        printf("2. Add Device\n");
        printf("3. Control Device\n");
        printf("4. List Devices\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username to add: ");
                scanf("%s", username);
                addUser(username);
                break;
            case 2:
                printf("Enter username to add device to: ");
                scanf("%s", username);
                printf("Enter device name: ");
                scanf("%s", device_name);
                addDevice(username, device_name);
                break;
            case 3:
                printf("Enter username to control device: ");
                scanf("%s", username);
                printf("Enter device name: ");
                scanf("%s", device_name);
                printf("Enter command (on/off): ");
                scanf("%s", command);
                commandDevice(username, device_name, command);
                break;
            case 4:
                printf("Enter username to list devices: ");
                scanf("%s", username);
                listDevices(username);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}