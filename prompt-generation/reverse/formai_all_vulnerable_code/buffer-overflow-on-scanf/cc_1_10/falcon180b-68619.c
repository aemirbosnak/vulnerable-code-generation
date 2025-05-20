//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

void add_appointment(struct appointment *appointments, int num_appointments) {
    printf("Enter name (max %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", appointments[num_appointments].name);

    printf("Enter year: ");
    scanf("%d", &appointments[num_appointments].year);

    printf("Enter month (1-12): ");
    scanf("%d", &appointments[num_appointments].month);

    printf("Enter day: ");
    scanf("%d", &appointments[num_appointments].day);

    printf("Enter hour (0-23): ");
    scanf("%d", &appointments[num_appointments].hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &appointments[num_appointments].minute);

    num_appointments++;
}

void display_appointments(struct appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %04d-%02d-%02d %02d:%02d\n", appointments[i].name, appointments[i].year, appointments[i].month, appointments[i].day, appointments[i].hour, appointments[i].minute);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
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