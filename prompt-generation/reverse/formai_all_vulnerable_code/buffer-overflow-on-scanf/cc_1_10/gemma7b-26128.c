//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char time[20];
    char date[20];
} Appointment;

int main() {
    int numAppointments = 0;
    Appointment appointments[MAX_Appointments];

    // Loop until the user enters a valid command
    while (1) {
        char command[20];
        printf("Enter command (add, list, exit): ");
        scanf("%s", command);

        // Add an appointment
        if (strcmp(command, "add") == 0) {
            if (numAppointments >= MAX_Appointments) {
                printf("Error: too many appointments.\n");
            } else {
                appointments[numAppointments].name[0] = '\0';
                printf("Enter name: ");
                scanf("%s", appointments[numAppointments].name);

                appointments[numAppointments].time[0] = '\0';
                printf("Enter time: ");
                scanf("%s", appointments[numAppointments].time);

                appointments[numAppointments].date[0] = '\0';
                printf("Enter date: ");
                scanf("%s", appointments[numAppointments].date);

                numAppointments++;
                printf("Appointment added.\n");
            }
        }

        // List appointments
        else if (strcmp(command, "list") == 0) {
            if (numAppointments == 0) {
                printf("No appointments.\n");
            } else {
                for (int i = 0; i < numAppointments; i++) {
                    printf("Name: %s\n", appointments[i].name);
                    printf("Time: %s\n", appointments[i].time);
                    printf("Date: %s\n", appointments[i].date);
                    printf("\n");
                }
            }
        }

        // Exit
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}