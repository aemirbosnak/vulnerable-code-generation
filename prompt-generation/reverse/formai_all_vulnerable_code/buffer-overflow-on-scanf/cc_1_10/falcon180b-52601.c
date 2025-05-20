//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 100

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    char date[MAX_APPOINTMENT_LENGTH];
    char time[MAX_APPOINTMENT_LENGTH];
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, the schedule is full.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter the time (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);

    num_appointments++;
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s on %s at %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Enter the name of the appointment to delete: ");
    scanf("%s", appointments[0].name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, appointments[0].name) == 0) {
            memmove(&appointments[i], &appointments[i+1], sizeof(Appointment) * (num_appointments - i - 1));
            num_appointments--;
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("1. Add appointment\n2. View appointments\n3. Delete appointment\n4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_appointment();
            break;
        case 2:
            view_appointments();
            break;
        case 3:
            delete_appointment();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}