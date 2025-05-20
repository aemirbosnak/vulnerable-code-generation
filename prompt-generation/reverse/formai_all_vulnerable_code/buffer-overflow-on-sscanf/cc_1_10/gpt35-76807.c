//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char date[20];
    char time[20];
    char name[50];
} Appointment;

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int appointmentCount = 0;
    char input[50];
    char command[20];
    bool running = true;

    printf("Welcome to the Appointment Scheduler!\n");

    while (running) {
        printf("\nWhat would you like to do? (add, view, exit): ");
        fgets(input, 50, stdin);
        sscanf(input, "%s", command);

        if (strcmp(command, "add") == 0) {
            if (appointmentCount >= MAX_APPOINTMENTS) {
                printf("Sorry, the schedule is full.\n");
            } else {
                printf("Enter the date (dd/mm/yyyy): ");
                fgets(appointments[appointmentCount].date, 20, stdin);

                printf("Enter the time (hh:mm): ");
                fgets(appointments[appointmentCount].time, 20, stdin);

                printf("Enter the name: ");
                fgets(appointments[appointmentCount].name, 50, stdin);

                printf("Appointment added for %s at %s with %s\n",
                       appointments[appointmentCount].date,
                       appointments[appointmentCount].time,
                       appointments[appointmentCount].name);

                appointmentCount++;
            }
        } else if (strcmp(command, "view") == 0) {
            if (appointmentCount == 0) {
                printf("No appointments scheduled.\n");
            } else {
                for (int i = 0; i < appointmentCount; i++) {
                    printf("%d. %s at %s with %s\n",
                           i + 1,
                           appointments[i].date,
                           appointments[i].time,
                           appointments[i].name);
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Thank you for using the Appointment Scheduler!\n");
            running = false;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}