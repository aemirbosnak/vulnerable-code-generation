//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_APPOINTMENT_LENGTH 50

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    int start_time;
    int end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void print_schedule() {
    printf("\nCurrent Schedule:\n");
    for (int i = 0; i < num_appointments; ++i) {
        printf("%s: %d:%d - %d:%d\n", appointments[i].name,
               appointments[i].start_time / 60, appointments[i].start_time % 60,
               appointments[i].end_time / 60, appointments[i].end_time % 60);
    }
}

void add_appointment(const char *name, int start_time, int end_time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    ++num_appointments;
}

int main() {
    char command[MAX_APPOINTMENT_LENGTH];
    int start_time, end_time;

    while (1) {
        printf("\nAppointment Scheduler\n"
               "1. Add appointment\n"
               "2. Print schedule\n"
               "3. Exit\n"
               "Enter command: ");
        scanf("%s", command);

        if (!strcmp(command, "1")) {
            printf("Enter appointment name: ");
            scanf("%s", command);
            printf("Enter start time (hhmm): ");
            scanf("%d%d", &start_time);
            printf("Enter end time (hhmm): ");
            scanf("%d%d", &end_time);
            add_appointment(command, start_time * 60, end_time * 60);
        } else if (!strcmp(command, "2")) {
            print_schedule();
        } else if (!strcmp(command, "3")) {
            break;
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}