//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 100

typedef struct Appointment {
    char* name;
    char* date;
    char* time;
} Appointment;

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    int choice = 0;

    printf("Welcome to the Appointment Scheduler!\n\n");

    while (1) {
        printf("Choose an option:\n"
               "1. Add an appointment\n"
               "2. View all appointments\n"
               "3. Cancel an appointment\n"
               "4. Exit\n"
               "Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char* name = (char*) malloc(100 * sizeof(char));
                char* date = (char*) malloc(50 * sizeof(char));
                char* time = (char*) malloc(50 * sizeof(char));

                printf("Enter appointment name: ");
                scanf("%s", name);
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%s", date);
                printf("Enter time (HH:MM AM/PM): ");
                scanf("%s", time);

                Appointment new_appointment = {
                    .name = name,
                    .date = date,
                    .time = time
                };

                appointments[num_appointments++] = new_appointment;
                printf("Appointment added!\n\n");

                break;
            }
            case 2: {
                if (num_appointments == 0) {
                    printf("No appointments to display.\n\n");
                } else {
                    printf("Appointments:\n");
                    printf("%-20s%-20s%-20s\n", "Name", "Date", "Time");
                    for (int i = 0; i < num_appointments; i++) {
                        printf("%-20s%-20s%-20s\n", appointments[i].name, appointments[i].date, appointments[i].time);
                    }
                    printf("\n");
                }

                break;
            }
            case 3: {
                if (num_appointments == 0) {
                    printf("No appointments to cancel.\n\n");
                } else {
                    printf("Enter index of appointment to cancel: ");
                    int index = 0;
                    scanf("%d", &index);

                    if (index < 0 || index >= num_appointments) {
                        printf("Invalid index.\n\n");
                    } else {
                        free(appointments[index].name);
                        free(appointments[index].date);
                        free(appointments[index].time);

                        for (int i = index; i < num_appointments - 1; i++) {
                            appointments[i] = appointments[i + 1];
                        }

                        num_appointments--;
                        printf("Appointment cancelled.\n\n");
                    }
                }

                break;
            }
            case 4: {
                printf("Goodbye!\n");
                exit(0);

                break;
            }
            default: {
                printf("Invalid choice.\n\n");

                break;
            }
        }
    }

    return 0;
}