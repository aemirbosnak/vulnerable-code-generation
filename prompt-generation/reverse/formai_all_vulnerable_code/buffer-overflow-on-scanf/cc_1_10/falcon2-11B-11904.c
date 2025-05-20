//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <string.h>

struct Appointment {
    char name[100];
    char date[100];
    char time[100];
    char purpose[100];
};

struct Appointment appointments[100];
int num_appointments = 0;

int main() {
    int choice;
    int appointment_id;

    printf("Welcome to the Royal Appointment Scheduler!\n");
    printf("1. Add an Appointment\n");
    printf("2. Delete an Appointment\n");
    printf("3. List Appointments\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter appointment details:\n");
                fflush(stdin);
                gets(appointments[num_appointments].name);
                fgets(appointments[num_appointments].date, 100, stdin);
                fgets(appointments[num_appointments].time, 100, stdin);
                fgets(appointments[num_appointments].purpose, 100, stdin);
                appointment_id = num_appointments;
                num_appointments++;
                printf("Appointment %d added successfully!\n", appointment_id);
                break;

            case 2:
                printf("Enter appointment ID to delete:\n");
                scanf("%d", &appointment_id);
                if (appointment_id < num_appointments) {
                    memmove(appointments, appointments + 1, (num_appointments - 1) * sizeof(struct Appointment));
                    num_appointments--;
                    printf("Appointment %d deleted successfully!\n", appointment_id);
                } else {
                    printf("Invalid appointment ID!\n");
                }
                break;

            case 3:
                printf("Appointments:\n");
                for (int i = 0; i < num_appointments; i++) {
                    printf("%d. %s - %s - %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
                }
                break;

            case 4:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}