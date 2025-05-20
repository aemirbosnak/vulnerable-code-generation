//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_PHONE_NUMBER_LENGTH 15

struct appointment {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

void add_appointment(struct appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone_number);

    printf("Enter day: ");
    scanf("%d", &appointments[num_appointments].day);

    printf("Enter month: ");
    scanf("%d", &appointments[num_appointments].month);

    printf("Enter year: ");
    scanf("%d", &appointments[num_appointments].year);

    printf("Enter hour: ");
    scanf("%d", &appointments[num_appointments].hour);

    printf("Enter minute: ");
    scanf("%d", &appointments[num_appointments].minute);

    num_appointments++;
}

void display_appointments(struct appointment* appointments, int num_appointments) {
    printf("Name\t\tPhone Number\tDate and Time\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t\t%s\t\t%d/%d/%d %d:%d\n", appointments[i].name, appointments[i].phone_number, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter 1 to add an appointment or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_appointment(appointments, num_appointments);
        } else if (choice!= 0) {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("Appointments:\n");
    display_appointments(appointments, num_appointments);

    return 0;
}