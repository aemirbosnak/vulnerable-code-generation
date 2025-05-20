//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_APPOINTMENTS 100 // maximum number of appointments that can be scheduled

typedef struct appointment {
    char name[50]; // name of the person scheduled for this appointment
    char date[20]; // date of the appointment
    int time; // time in hours (0-23)
} appointment_t;

int num_appointments = 0; // number of appointments currently scheduled
appointment_t appointments[MAX_APPOINTMENTS]; // array to store all the scheduled appointments

void schedule_an_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be scheduled.\n");
        return;
    }

    appointment_t new_appointment;

    printf("Enter name: ");
    scanf("%s", new_appointment.name);

    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s", new_appointment.date);

    printf("Enter time (0-23): ");
    scanf("%d", &new_appointment.time);

    appointments[num_appointments++] = new_appointment;

    printf("Appointment scheduled successfully!\n");
}

void cancel_an_appointment() {
    if (num_appointments <= 0) {
        printf("Sorry, no appointments to cancel.\n");
        return;
    }

    char name[50];

    printf("Enter name of the person whose appointment you want to cancel: ");
    scanf("%s", name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            printf("Appointment for %s on %s at %d hours cancelled successfully.\n", 
                   appointments[i].name, appointments[i].date, appointments[i].time);
            for (int j = i; j < num_appointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            num_appointments--;
            return;
        }
    }

    printf("Sorry, no appointment found for %s.\n", name);
}

void list_all_appointments() {
    if (num_appointments <= 0) {
        printf("Sorry, no appointments yet.\n");
        return;
    }

    printf("All scheduled appointments:\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%d. Name: %s, Date: %s, Time: %d hours\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    int choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Schedule an appointment\n");
        printf("2. Cancel an appointment\n");
        printf("3. List all appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                schedule_an_appointment();
                break;
            case 2:
                cancel_an_appointment();
                break;
            case 3:
                list_all_appointments();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}