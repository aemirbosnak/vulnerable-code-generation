//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct Appointment {
    char* name;
    char* description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

Appointment* appointments[MAX_APPOINTMENTS];

int main() {
    int numAppointments = 0;

    while (1) {
        char command[100];
        printf("Enter a command (add, list, delete, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            Appointment* appointment = malloc(sizeof(Appointment));

            printf("Enter the name of the appointment: ");
            scanf(" %s", appointment->name);

            printf("Enter a description for the appointment: ");
            scanf(" %s", appointment->description);

            printf("Enter the day of the appointment (1-31): ");
            scanf("%d", &appointment->day);

            printf("Enter the month of the appointment (1-12): ");
            scanf("%d", &appointment->month);

            printf("Enter the year of the appointment: ");
            scanf("%d", &appointment->year);

            printf("Enter the hour of the appointment (0-23): ");
            scanf("%d", &appointment->hour);

            printf("Enter the minute of the appointment (0-59): ");
            scanf("%d", &appointment->minute);

            appointments[numAppointments] = appointment;
            numAppointments++;
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < numAppointments; i++) {
                Appointment* appointment = appointments[i];
                printf("%s: %s (%d/%d/%d %d:%02d)\n", appointment->name, appointment->description, appointment->day, appointment->month, appointment->year, appointment->hour, appointment->minute);
            }
        } else if (strcmp(command, "delete") == 0) {
            int index;
            printf("Enter the index of the appointment to delete: ");
            scanf("%d", &index);

            if (index >= 0 && index < numAppointments) {
                Appointment* appointment = appointments[index];
                free(appointment->name);
                free(appointment->description);
                free(appointment);

                for (int i = index; i < numAppointments - 1; i++) {
                    appointments[i] = appointments[i + 1];
                }

                numAppointments--;
            } else {
                printf("Invalid index.\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}