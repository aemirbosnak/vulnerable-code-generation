//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_APPOINTMENT_LENGTH 50

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    char date[MAX_APPOINTMENT_LENGTH];
    char time[MAX_APPOINTMENT_LENGTH];
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, cannot add more appointments.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);

    num_appointments++;
}

void remove_appointment() {
    if (num_appointments == 0) {
        printf("No appointments to remove.\n");
        return;
    }

    int index;
    printf("Enter index of appointment to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_appointments) {
        num_appointments--;
        for (int i = index; i < num_appointments; i++) {
            strcpy(appointments[i].name, appointments[i+1].name);
            strcpy(appointments[i].date, appointments[i+1].date);
            strcpy(appointments[i].time, appointments[i+1].time);
        }
    } else {
        printf("Invalid index.\n");
    }
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments.\n");
        return;
    }

    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s @ %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

int main() {
    int choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Remove appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                remove_appointment();
                break;
            case 3:
                view_appointments();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}