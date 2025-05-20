//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
/*
 * Appointment Scheduler
 *
 * By Linus Torvalds
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_NAME_LEN 50
#define MAX_APPOINTMENT_DATE_LEN 10

struct appointment {
    char name[MAX_APPOINTMENT_NAME_LEN];
    char date[MAX_APPOINTMENT_DATE_LEN];
    int time;
};

void print_appointment(struct appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Date: %s\n", appointment->date);
    printf("Time: %d\n", appointment->time);
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    printf("Welcome to the appointment scheduler!\n");

    while (1) {
        char command[10];
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            struct appointment appointment;
            printf("Enter appointment name: ");
            scanf("%s", appointment.name);
            printf("Enter appointment date: ");
            scanf("%s", appointment.date);
            printf("Enter appointment time: ");
            scanf("%d", &appointment.time);
            appointments[num_appointments++] = appointment;
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < num_appointments; i++) {
                print_appointment(&appointments[i]);
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    printf("Goodbye!\n");
    return 0;
}