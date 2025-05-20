//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_NAME_LENGTH 50
#define MAX_APPOINTMENT_DATE_LENGTH 20
#define MAX_APPOINTMENT_TIME_LENGTH 10
#define MAX_APPOINTMENT_DESCRIPTION_LENGTH 100

typedef struct appointment {
    char name[MAX_APPOINTMENT_NAME_LENGTH];
    char date[MAX_APPOINTMENT_DATE_LENGTH];
    char time[MAX_APPOINTMENT_TIME_LENGTH];
    char description[MAX_APPOINTMENT_DESCRIPTION_LENGTH];
} appointment_t;

void add_appointment(appointment_t* appointments, int num_appointments) {
    printf("Enter the name of the appointment: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter the date of the appointment (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter the time of the appointment (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);

    printf("Enter the description of the appointment: ");
    scanf("%s", appointments[num_appointments].description);

    num_appointments++;
}

void display_appointments(appointment_t* appointments, int num_appointments) {
    printf("\nAppointments:\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Description: %s\n\n", appointments[i].description);
    }
}

int main() {
    appointment_t appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("\nEnter 1 to add an appointment, 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_appointment(appointments, num_appointments);
        } else if (choice!= 0) {
            printf("Invalid choice\n");
        }
    }

    display_appointments(appointments, num_appointments);

    return 0;
}