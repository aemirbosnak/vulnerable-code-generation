//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

void addAppointment(Appointment* appointments, int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);
    printf("Enter phone number: ");
    scanf("%s", appointments[numAppointments].phone);
    printf("Enter day (1-31): ");
    scanf("%d", &appointments[numAppointments].day);
    printf("Enter month (1-12): ");
    scanf("%d", &appointments[numAppointments].month);
    printf("Enter year (4 digits): ");
    scanf("%d", &appointments[numAppointments].year);
    printf("Enter hour (0-23): ");
    scanf("%d", &appointments[numAppointments].hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &appointments[numAppointments].minute);
    numAppointments++;
}

void printAppointment(Appointment appointment) {
    printf("%s\n", appointment.name);
    printf("%s\n", appointment.phone);
    printf("Day: %d\n", appointment.day);
    printf("Month: %d\n", appointment.month);
    printf("Year: %d\n", appointment.year);
    printf("Hour: %d\n", appointment.hour);
    printf("Minute: %d\n", appointment.minute);
}

void printAppointments(Appointment* appointments, int numAppointments) {
    for (int i = 0; i < numAppointments; i++) {
        printAppointment(appointments[i]);
    }
}

int main() {
    int numAppointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("Enter 1 to add an appointment, 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            addAppointment(appointments, numAppointments);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    printAppointments(appointments, numAppointments);

    return 0;
}