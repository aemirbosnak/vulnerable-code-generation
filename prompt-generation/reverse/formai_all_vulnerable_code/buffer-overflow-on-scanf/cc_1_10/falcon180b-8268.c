//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t appointment_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);

    num_appointments++;
}

void view_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s\n", appointments[i].name, ctime(&appointments[i].appointment_time));
    }
}

void remove_appointment() {
    if (num_appointments == 0) {
        printf("No appointments to remove.\n");
        return;
    }

    printf("Enter name of appointment to remove: ");
    scanf("%s", appointments[num_appointments - 1].name);

    num_appointments--;
}

int main() {
    printf("Welcome to the Appointment Scheduler!\n");

    int choice;
    do {
        printf("Enter 1 to add an appointment\n"
               "Enter 2 to view appointments\n"
               "Enter 3 to remove an appointment\n"
               "Enter 4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                remove_appointment();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}