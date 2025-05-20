//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments) {
    printf("Enter name for appointment: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter day (1-31): ");
    scanf("%d", &appointments[num_appointments].day);

    printf("Enter month (1-12): ");
    scanf("%d", &appointments[num_appointments].month);

    printf("Enter year: ");
    scanf("%d", &appointments[num_appointments].year);

    printf("Enter hour (0-23): ");
    scanf("%d", &appointments[num_appointments].hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &appointments[num_appointments].minute);

    num_appointments++;
}

void print_appointment(Appointment appointment) {
    printf("%s on %d/%d/%d at %d:%d\n", appointment.name, appointment.day, appointment.month, appointment.year, appointment.hour, appointment.minute);
}

void print_appointments(Appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        add_appointment(appointments, num_appointments);
    }

    print_appointments(appointments, num_appointments);

    return 0;
}