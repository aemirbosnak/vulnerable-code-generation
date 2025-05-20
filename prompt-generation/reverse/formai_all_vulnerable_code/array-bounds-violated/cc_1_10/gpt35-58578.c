//FormAI DATASET v1.0 Category: Smart home automation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct device_t {
    char name[20];
    int state;
} device_t;

device_t device_list[MAX_DEVICES];

int current_device_count = 0;

void add_device(char *name, int state) {
    if (current_device_count < MAX_DEVICES) {
        strcpy(device_list[current_device_count].name, name);
        device_list[current_device_count].state = state;
        current_device_count++;
        printf("%s device added.\n", name);
    } else {
        printf("Maximum device limit reached.\n");
    }
}

void remove_device(char *name) {
    for (int i = 0; i < current_device_count; i++) {
        if (strcmp(device_list[i].name, name) == 0) {
            for (int j = i; j < current_device_count - 1; j++) {
                device_list[j] = device_list[j + 1];
            }
            current_device_count--;
            printf("%s device removed.\n", name);
            return;
        }
    }
    printf("Device not found.\n");
}

void toggle_device(char *name) {
    for (int i = 0; i < current_device_count; i++) {
        if (strcmp(device_list[i].name, name) == 0) {
            device_list[i].state = !device_list[i].state;
            printf("%s device is now %s.\n", name, device_list[i].state ? "on" : "off");
            return;
        }
    }
    printf("Device not found.\n");
}

void print_devices() {
    printf("Current devices:\n");
    for (int i = 0; i < current_device_count; i++) {
        printf("- %s is %s\n", device_list[i].name, device_list[i].state ? "on" : "off");
    }
}

int main() {
    char input[20], arg1[20], arg2[20];

    printf("Welcome to Retro Smart Home Automation!\n");
    printf("Type 'help' for a list of commands.\n");

    while (1) {
        printf("> ");
        fgets(input, 20, stdin);
        input[strlen(input) - 1] = '\0';

        sscanf(input, "%s %s %s", arg1, arg2);

        if (strcmp(arg1, "help") == 0) {
            printf("Available commands:\n");
            printf("- add [device name]: add a device\n");
            printf("- remove [device name]: remove a device\n");
            printf("- toggle [device name]: toggle a device on/off\n");
            printf("- list: list all devices\n");
            printf("- exit: exit the program\n");
        } else if (strcmp(arg1, "add") == 0) {
            add_device(arg2, 0);
        } else if (strcmp(arg1, "remove") == 0) {
            remove_device(arg2);
        } else if (strcmp(arg1, "toggle") == 0) {
            toggle_device(arg2);
        } else if (strcmp(arg1, "list") == 0) {
            print_devices();
        } else if (strcmp(arg1, "exit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }
}