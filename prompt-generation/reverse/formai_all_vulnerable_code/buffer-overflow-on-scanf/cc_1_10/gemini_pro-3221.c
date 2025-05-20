//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char date[11];
    char time[6];
    char location[50];
    char notes[100];
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Appointment list is full.\n");
        return;
    }

    appointment *appt = &appointments[num_appointments];

    printf("Enter appointment name: ");
    scanf("%s", appt->name);

    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", appt->date);

    printf("Enter appointment time (HH:MM): ");
    scanf("%s", appt->time);

    printf("Enter appointment location: ");
    scanf("%s", appt->location);

    printf("Enter appointment notes: ");
    scanf("%s", appt->notes);

    num_appointments++;
}

void print_appointment(appointment *appt) {
    printf("Appointment Name: %s\n", appt->name);
    printf("Appointment Date: %s\n", appt->date);
    printf("Appointment Time: %s\n", appt->time);
    printf("Appointment Location: %s\n", appt->location);
    printf("Appointment Notes: %s\n", appt->notes);
    printf("\n");
}

void print_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }
}

void delete_appointment() {
    char name[50];

    printf("Enter the name of the appointment to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            for (int j = i; j < num_appointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            num_appointments--;
            printf("Appointment deleted.\n");
            return;
        }
    }

    printf("Error: Appointment not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}