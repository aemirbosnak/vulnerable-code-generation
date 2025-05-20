//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10
#define APPOINTMENT_LENGTH 60

typedef struct {
    int id;
    char name[50];
    int start_time;
    int end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];

int find_empty_slot(int start_time) {
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].start_time == 0) {
            int duration = appointments[i].end_time - appointments[i].start_time;
            if (start_time + APPOINTMENT_LENGTH > appointments[i].start_time &&
                start_time < appointments[i].start_time + duration) {
                return i;
            }
            return i;
        }
    }

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].end_time == 0) {
            return i;
        }
    }

    return -1;
}

void print_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].start_time != 0) {
            printf("%d: %s (%d-%d)\n", appointments[i].id, appointments[i].name,
                  appointments[i].start_time, appointments[i].end_time);
        }
    }
}

int main() {
    int current_time = 0;
    char command[20];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            if (find_empty_slot(current_time) == -1) {
                printf("No empty slot found.\n");
                continue;
            }

            Appointment new_appointment;
            scanf("%s %d %d", new_appointment.name, &new_appointment.start_time, &new_appointment.end_time);
            new_appointment.id = current_time + 1;
            appointments[find_empty_slot(current_time)].start_time = new_appointment.start_time;
            appointments[find_empty_slot(current_time)].end_time = new_appointment.start_time + new_appointment.end_time;
            current_time += new_appointment.end_time;

        } else if (strcmp(command, "schedule") == 0) {
            int start_time;
            scanf("%d", &start_time);
            int index = find_empty_slot(start_time);

            if (index == -1) {
                printf("No empty slot found at %d.\n", start_time);
                continue;
            }

            printf("Appointment scheduled at %d.\n", start_time);
            appointments[index].start_time = start_time;
            appointments[index].end_time = start_time + APPOINTMENT_LENGTH;
            current_time += APPOINTMENT_LENGTH;

        } else if (strcmp(command, "list") == 0) {
            print_appointments();

        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}