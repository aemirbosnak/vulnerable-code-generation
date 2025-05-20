//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char phone_number[20];
    char email_address[50];
    char appointment_date[20];
    char appointment_time[20];
    char appointment_notes[200];
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, you can't add any more appointments.\n");
        return;
    }

    appointment new_appointment;

    printf("Enter the patient's name: ");
    scanf(" %s", new_appointment.name);

    printf("Enter the patient's phone number: ");
    scanf(" %s", new_appointment.phone_number);

    printf("Enter the patient's email address: ");
    scanf(" %s", new_appointment.email_address);

    printf("Enter the appointment date: ");
    scanf(" %s", new_appointment.appointment_date);

    printf("Enter the appointment time: ");
    scanf(" %s", new_appointment.appointment_time);

    printf("Enter any notes about the appointment: ");
    scanf(" %[^\n]", new_appointment.appointment_notes);

    appointments[num_appointments++] = new_appointment;

    printf("Appointment added successfully!\n");
}

void list_appointments() {
    if (num_appointments == 0) {
        printf("No appointments to list.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s - %s - %s - %s - %s - %s\n", i + 1, appointments[i].name, appointments[i].phone_number, appointments[i].email_address, appointments[i].appointment_date, appointments[i].appointment_time, appointments[i].appointment_notes);
    }
}

void delete_appointment() {
    int appointment_number;

    printf("Enter the number of the appointment you want to delete: ");
    scanf(" %d", &appointment_number);

    if (appointment_number < 1 || appointment_number > num_appointments) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = appointment_number - 1; i < num_appointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }

    num_appointments--;

    printf("Appointment deleted successfully!\n");
}

int main() {
    int choice;

    do {
        printf("Appointment Scheduler\n");
        printf("1. Add an appointment\n");
        printf("2. List appointments\n");
        printf("3. Delete an appointment\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                list_appointments();
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