//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
/*
 * appointment_scheduler.c
 *
 * Simple appointment scheduler program in C.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment_t;

void print_appointment(appointment_t appointment) {
    printf("Appointment with %s on %d/%d/%d at %d:%d\n", appointment.name, appointment.day, appointment.month, appointment.year, appointment.hour, appointment.minute);
}

int main(int argc, char *argv[]) {
    appointment_t appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        char command[16];
        scanf("%15s", command);

        if (strcmp(command, "add") == 0) {
            appointment_t appointment;
            scanf("%s %d/%d/%d %d:%d", appointment.name, &appointment.day, &appointment.month, &appointment.year, &appointment.hour, &appointment.minute);
            appointments[num_appointments++] = appointment;
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < num_appointments; i++) {
                print_appointment(appointments[i]);
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command: %s\n", command);
        }
    }

    return 0;
}