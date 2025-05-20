//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 100

struct appointment {
    char name[MAX_NAME_LENGTH];
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

void add_appointment(struct appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter year: ");
    scanf("%d", &appointments[num_appointments].year);

    printf("Enter month: ");
    scanf("%d", &appointments[num_appointments].month);

    printf("Enter day: ");
    scanf("%d", &appointments[num_appointments].day);

    printf("Enter hour: ");
    scanf("%d", &appointments[num_appointments].hour);

    printf("Enter minute: ");
    scanf("%d", &appointments[num_appointments].minute);

    num_appointments++;
}

void print_appointments(struct appointment* appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].year, appointments[i].month, appointments[i].day, appointments[i].hour, appointments[i].minute);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("Enter 1 to add an appointment, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_appointment(appointments, num_appointments);
        } else if (choice!= 0) {
            printf("Invalid choice.\n");
        }
    }

    print_appointments(appointments, num_appointments);

    return 0;
}