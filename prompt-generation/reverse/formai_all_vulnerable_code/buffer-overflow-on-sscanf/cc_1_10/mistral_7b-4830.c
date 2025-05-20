//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 50

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    int start_time;
    int end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(const char *name, int start_time, int end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        fprintf(stderr, "Too many appointments.\n");
        return;
    }
    strncpy(appointments[num_appointments].name, name, MAX_APPOINTMENT_LENGTH);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    num_appointments++;
}

void print_schedule() {
    printf("Schedule:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s: %d-%d\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time);
    }
}

int main() {
    char command[10];
    int arg1, arg2, arg3;

    while (fgets(command, sizeof(command), stdin) != NULL) {
        sscanf(command, "%s %d %d", command, &arg1, &arg2);

        if (strcmp(command, "ADD") == 0) {
            if (sscanf(command + 3, "%s %d %d", command + 3, &arg3, &arg2) != 2) {
                fprintf(stderr, "Invalid ADD command format.\n");
                continue;
            }
            add_appointment(command + 3, arg1, arg2 + arg1);
        } else if (strcmp(command, "SCHEDULE") == 0) {
            print_schedule();
            break;
        } else {
            fprintf(stderr, "Invalid command.\n");
        }
    }

    return 0;
}