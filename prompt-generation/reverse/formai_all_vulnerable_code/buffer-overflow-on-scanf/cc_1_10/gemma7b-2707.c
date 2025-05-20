//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[20];
    int day;
    int month;
    int year;
} Appointment;

void schedule_appointment(Appointment *appointments, int *num_appointments) {
    *num_appointments++;
    appointments = (Appointment *)realloc(appointments, *num_appointments * sizeof(Appointment));
    appointments[*num_appointments - 1].name[0] = '\0';
    printf("Enter name: ");
    scanf("%s", appointments[*num_appointments - 1].name);
    printf("Enter day: ");
    scanf("%d", &appointments[*num_appointments - 1].day);
    printf("Enter month: ");
    scanf("%d", &appointments[*num_appointments - 1].month);
    printf("Enter year: ");
    scanf("%d", &appointments[*num_appointments - 1].year);
}

int main() {
    int num_appointments = 0;
    Appointment *appointments = NULL;

    while (1) {
        printf("1. Schedule Appointment\n");
        printf("2. List Appointments\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                schedule_appointment(appointments, &num_appointments);
                break;
            case 2:
                // List appointments
                break;
            default:
                exit(0);
        }
    }

    return 0;
}