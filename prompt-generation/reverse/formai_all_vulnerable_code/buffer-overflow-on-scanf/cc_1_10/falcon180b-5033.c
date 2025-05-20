//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
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

void add_appointment(struct appointment *appointments, int num_appointments, char *name, int year, int month, int day, int hour, int minute) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more appointments.\n");
        return;
    }

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    appointments[num_appointments].year = year;
    appointments[num_appointments].month = month;
    appointments[num_appointments].day = day;
    appointments[num_appointments].hour = hour;
    appointments[num_appointments].minute = minute;

    num_appointments++;
}

void display_appointments(struct appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].year, appointments[i].month, appointments[i].day, appointments[i].hour, appointments[i].minute);
    }
}

void remove_appointment(struct appointment *appointments, int num_appointments, char *name) {
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            for (int j = i; j < num_appointments - 1; j++) {
                strcpy(appointments[j].name, appointments[j + 1].name);
                appointments[j].year = appointments[j + 1].year;
                appointments[j].month = appointments[j + 1].month;
                appointments[j].day = appointments[j + 1].day;
                appointments[j].hour = appointments[j + 1].hour;
                appointments[j].minute = appointments[j + 1].minute;
            }

            num_appointments--;
            break;
        }
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    char name[MAX_NAME_LENGTH];
    int year, month, day, hour, minute;

    while (1) {
        printf("Enter name (leave blank to finish): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter year: ");
        scanf("%d", &year);

        printf("Enter month: ");
        scanf("%d", &month);

        printf("Enter day: ");
        scanf("%d", &day);

        printf("Enter hour: ");
        scanf("%d", &hour);

        printf("Enter minute: ");
        scanf("%d", &minute);

        add_appointment(appointments, num_appointments, name, year, month, day, hour, minute);
    }

    display_appointments(appointments, num_appointments);

    while (1) {
        printf("Enter name to remove (leave blank to finish): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        remove_appointment(appointments, num_appointments, name);
    }

    display_appointments(appointments, num_appointments);

    return 0;
}