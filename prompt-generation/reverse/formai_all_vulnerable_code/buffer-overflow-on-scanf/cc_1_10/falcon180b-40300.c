//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 80

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    char date[MAX_APPOINTMENT_LENGTH];
    char time[MAX_APPOINTMENT_LENGTH];
} appointment;

int num_appointments = 0;
appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);

    num_appointments++;
}

void view_appointments() {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s on %s at %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    int index;
    printf("Enter appointment index to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_appointments) {
        for (int i = index; i < num_appointments-1; i++) {
            strcpy(appointments[i].name, appointments[i+1].name);
            strcpy(appointments[i].date, appointments[i+1].date);
            strcpy(appointments[i].time, appointments[i+1].time);
        }
        num_appointments--;
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}