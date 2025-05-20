//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    char date[10];
    char time[10];
};

void add_appointment(struct appointment *appointments, int num_appointments, char *name, char *date, char *time) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].date, date);
    strcpy(appointments[num_appointments].time, time);

    num_appointments++;
}

void display_appointments(struct appointment *appointments, int num_appointments) {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s on %s at %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    struct appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    while (1) {
        printf("Enter 1 to add an appointment, 2 to display appointments, or 0 to quit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice == 1) {
            char name[50], date[10], time[10];
            printf("Enter name:\n");
            scanf("%s", name);
            printf("Enter date (YYYY-MM-DD):\n");
            scanf("%s", date);
            printf("Enter time (HH:MM):\n");
            scanf("%s", time);

            add_appointment(appointments, num_appointments, name, date, time);
        }

        if (choice == 2) {
            display_appointments(appointments, num_appointments);
        }
    }

    return 0;
}