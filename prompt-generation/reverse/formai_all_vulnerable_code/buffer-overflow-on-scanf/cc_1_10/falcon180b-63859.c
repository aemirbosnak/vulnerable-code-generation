//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_NUMBER_LENGTH];
    int appointment_date;
    int appointment_time;
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone_number);

    printf("Enter appointment date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appointments[num_appointments].appointment_date, &appointments[num_appointments].appointment_date, &appointments[num_appointments].appointment_date);

    printf("Enter appointment time (hh:mm): ");
    scanf("%d:%d", &appointments[num_appointments].appointment_time, &appointments[num_appointments].appointment_time);

    num_appointments++;
}

void display_appointments(appointment* appointments, int num_appointments) {
    printf("Name\t\tPhone Number\tAppointment Date\tAppointment Time\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t\t%s\t\t%d/%d/%d\t\t%d:%d\n", appointments[i].name, appointments[i].phone_number, appointments[i].appointment_date, appointments[i].appointment_date, appointments[i].appointment_date, appointments[i].appointment_time, appointments[i].appointment_time);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("1. Add appointment\n2. Display appointments\n3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                break;
            case 2:
                display_appointments(appointments, num_appointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}