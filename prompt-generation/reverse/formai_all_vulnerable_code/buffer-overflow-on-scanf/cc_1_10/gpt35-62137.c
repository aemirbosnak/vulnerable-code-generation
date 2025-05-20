//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 3

typedef struct appointment {
    char* name;
    char* date;
    char* time;
} Appointment;

int main(void) {
    int choice, count = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (1) {
        printf("Choose an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. View all appointments\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if (count >= MAX_APPOINTMENTS) {
                    printf("Maximum appointments reached.\n");
                    break;
                }

                Appointment new_appointment;

                new_appointment.name = malloc(sizeof(char) * 50);
                new_appointment.date = malloc(sizeof(char) * 20);
                new_appointment.time = malloc(sizeof(char) * 20);

                printf("Enter name: ");
                scanf("%s", new_appointment.name);

                printf("Enter date (mm/dd/yyyy): ");
                scanf("%s", new_appointment.date);

                printf("Enter time (hh:mm AM/PM): ");
                scanf("%s", new_appointment.time);

                appointments[count] = new_appointment;
                count++;

                break;
            }

            case 2: {
                printf("Appointments:\n");

                for (int i = 0; i < count; i++) {
                    printf("%s | %s | %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
                }

                break;
            }

            case 3: {
                printf("Exiting program.\n");

                for (int i = 0; i < count; i++) {
                    free(appointments[i].name);
                    free(appointments[i].date);
                    free(appointments[i].time);
                }

                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }

    return 0;
}