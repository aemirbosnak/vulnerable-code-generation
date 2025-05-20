//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    int month;
    int day;
    int year;
    int hour;
    int minute;
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter the name of the person for the appointment: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter the phone number of the person for the appointment: ");
    scanf("%s", appointments[num_appointments].phone_number);

    printf("Enter the month of the appointment (1-12): ");
    scanf("%d", &appointments[num_appointments].month);

    printf("Enter the day of the appointment (1-31): ");
    scanf("%d", &appointments[num_appointments].day);

    printf("Enter the year of the appointment (YYYY): ");
    scanf("%d", &appointments[num_appointments].year);

    printf("Enter the hour of the appointment (0-23): ");
    scanf("%d", &appointments[num_appointments].hour);

    printf("Enter the minute of the appointment (0-59): ");
    scanf("%d", &appointments[num_appointments].minute);

    num_appointments++;
}

void display_appointments(appointment* appointments, int num_appointments) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Phone number: %s\n", appointments[i].phone_number);
        printf("Date: %d/%d/%d\n", appointments[i].month, appointments[i].day, appointments[i].year);
        printf("Time: %02d:%02d\n", appointments[i].hour, appointments[i].minute);
        printf("\n");
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        printf("\n1. Add appointment\n2. Display appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                break;
            case 2:
                display_appointments(appointments, num_appointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}