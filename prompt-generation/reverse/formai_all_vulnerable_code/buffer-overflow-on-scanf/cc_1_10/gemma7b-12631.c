//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char time[50];
    char date[50];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];

int main() {
    int i = 0;
    int appointment_count = 0;

    printf("Welcome to the Totally Awesome Appointment Scheduler!\n");

    // Loop until the user enters a valid command
    while (1) {
        char command[50];
        printf("Enter 'add', 'list', or 'exit': ");
        scanf("%s", command);

        // Add an appointment
        if (strcmp(command, "add") == 0) {
            Appointment new_appointment;
            printf("Enter your name: ");
            scanf("%s", new_appointment.name);
            printf("Enter the time: ");
            scanf("%s", new_appointment.time);
            printf("Enter the date: ");
            scanf("%s", new_appointment.date);

            appointments[appointment_count++] = new_appointment;

            printf("Appointment added!\n");
        }

        // List all appointments
        else if (strcmp(command, "list") == 0) {
            for (i = 0; i < appointment_count; i++) {
                printf("%s, %s, %s\n", appointments[i].name, appointments[i].time, appointments[i].date);
            }
        }

        // Exit the scheduler
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye, and thanks for using the Totally Awesome Appointment Scheduler!\n");
            break;
        }

        // Invalid command
        else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}