//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char *name;
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        printf("Welcome to the Appointment Scheduler. Please select an option:\n");
        printf("1. Add an appointment\n");
        printf("2. List appointments\n");
        printf("3. Quit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (num_appointments == MAX_APPOINTMENTS) {
                    printf("Error: Maximum number of appointments reached.\n");
                } else {
                    Appointment *appointment = &appointments[num_appointments++];

                    printf("Enter the appointment name:\n");
                    scanf(" %[^\n]", appointment->name);

                    printf("Enter the appointment description:\n");
                    scanf(" %[^\n]", appointment->description);

                    printf("Enter the appointment start time (YYYY-MM-DD HH:MM):\n");
                    scanf(" %[^\n]", &appointment->start_time);

                    printf("Enter the appointment end time (YYYY-MM-DD HH:MM):\n");
                    scanf(" %[^\n]", &appointment->end_time);
                }
                break;
            case 2:
                if (num_appointments == 0) {
                    printf("Error: No appointments found.\n");
                } else {
                    for (int i = 0; i < num_appointments; i++) {
                        Appointment *appointment = &appointments[i];

                        printf("Appointment %d:\n", i + 1);
                        printf("Name: %s\n", appointment->name);
                        printf("Description: %s\n", appointment->description);
                        printf("Start time: %s\n", ctime(&appointment->start_time));
                        printf("End time: %s\n", ctime(&appointment->end_time));
                    }
                }
                break;
            case 3:
                printf("Thank you for using the Appointment Scheduler. Goodbye!\n");
                return 0;
            default:
                printf("Error: Invalid option.\n");
        }
    }

    return 0;
}