//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYSTEM_NAME_LENGTH 20
#define MAX_ERROR_MESSAGE_LENGTH 80

typedef enum {
    SYSTEM_ENGINES,
    SYSTEM_LIFE_SUPPORT,
    SYSTEM_RADAR,
    SYSTEM_COMMUNICATIONS,
    NUM_SYSTEMS
} System;

typedef struct {
    char name[MAX_SYSTEM_NAME_LENGTH + 1];
    int status;
    char error[MAX_ERROR_MESSAGE_LENGTH + 1];
} SystemStatus;

SystemStatus systems[NUM_SYSTEMS] = {
    {"Engines", 1, ""},
    {"Life Support", 1, ""},
    {"Radar", 1, ""},
    {"Communications", 1, ""}
};

void print_system_status(System system) {
    printf("System %s status:\n", systems[system].name);
    printf("  Status: %s\n", systems[system].status ? "ON" : "OFF");
    if (strlen(systems[system].error) > 0) {
        printf("  Error: %s\n", systems[system].error);
    }
}

int get_system_status(System system) {
    return systems[system].status;
}

void set_system_status(System system, int status) {
    if (status < 0) {
        strcpy(systems[system].error, "Invalid status. Please set to 0 or 1.");
        systems[system].status = get_system_status(system);
        return;
    }

    systems[system].status = status;
    strcpy(systems[system].error, "");
}

void print_error_message(char *message) {
    printf("\n%s\n", message);
}

void handle_input_error(char *input, char *error_message) {
    if (strlen(input) > MAX_SYSTEM_NAME_LENGTH) {
        strcpy(error_message, "Error: System name too long.");
    } else {
        for (int i = 0; i < NUM_SYSTEMS; i++) {
            if (strcmp(input, systems[i].name) == 0) {
                break;
            }

            if (i == NUM_SYSTEMS - 1) {
                strcpy(error_message, "Error: System not found.");
            }
        }
    }
}

void control_center() {
    char input[MAX_SYSTEM_NAME_LENGTH + 1];
    char error_message[MAX_ERROR_MESSAGE_LENGTH + 1];
    int system;
    int status;

    while (1) {
        printf("Enter a system name to control (Q to quit): ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

        if (strlen(input) > 0 && toupper(input[0]) == 'Q') {
            break;
        }

        handle_input_error(input, error_message);
        if (strlen(error_message) > 0) {
            print_error_message(error_message);
            continue;
        }

        for (system = 0; system < NUM_SYSTEMS; system++) {
            if (strcmp(input, systems[system].name) == 0) {
                break;
            }
        }

        if (system >= NUM_SYSTEMS) {
            print_error_message("Error: System not found.");
            continue;
        }

        printf("Enter a status for system %s (0 for OFF, 1 for ON): ", systems[system].name);
        scanf("%d", &status);

        if (status < 0) {
            print_error_message("Error: Invalid status.");
            continue;
        }

        set_system_status(system, status);

        if (status == 0) {
            printf("System %s turned OFF.\n", systems[system].name);
        } else {
            printf("System %s turned ON.\n", systems[system].name);
        }

        print_system_status(system);
    }
}

int main() {
    control_center();
    return 0;
}