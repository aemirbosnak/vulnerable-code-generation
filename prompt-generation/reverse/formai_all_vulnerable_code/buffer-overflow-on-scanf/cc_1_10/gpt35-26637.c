//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Struct for storing appointment information */
typedef struct Appointment {
    char name[50];
    int day;
    int time;
} Appointment;

/* Function to check if a time slot is available */
bool isAvailable(Appointment appointments[], int day, int time) {
    for (int i = 0; i < 5; i++) {
        if (appointments[i].day == day && appointments[i].time == time) {
            return false;
        }
    }
    return true;
}

/* Function to print out appointment information */
void printAppointment(Appointment appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Day: %d\n", appointment.day);
    printf("Time: %d\n", appointment.time);
}

int main() {
    /* Initialize appointment array with empty values */
    Appointment appointments[5];
    for (int i = 0; i < 5; i++) {
        strcpy(appointments[i].name, "");
        appointments[i].day = 0;
        appointments[i].time = 0;
    }

    /* Loop to allow user to schedule appointments */
    while (true) {
        printf("\nEnter 1 to schedule an appointment, or 2 to quit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            /* Get name, day, and time from user */
            char name[50];
            int day, time;
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter day (1-7): ");
            scanf("%d", &day);
            printf("Enter time (10-16): ");
            scanf("%d", &time);

            /* Check if time slot is available */
            if (isAvailable(appointments, day, time)) {
                /* Add appointment to appointments array */
                for (int i = 0; i < 5; i++) {
                    if (strlen(appointments[i].name) == 0) {
                        strcpy(appointments[i].name, name);
                        appointments[i].day = day;
                        appointments[i].time = time;
                        printf("\nAppointment scheduled:\n");
                        printAppointment(appointments[i]);
                        break;
                    }
                }
            } else {
                printf("\nSorry, that time slot is not available.\n");
            }
        } else if (choice == 2) {
            /* Quit */
            break;
        } else {
            printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}