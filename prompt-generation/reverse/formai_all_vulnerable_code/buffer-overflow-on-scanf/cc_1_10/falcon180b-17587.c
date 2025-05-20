//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 50

typedef struct {
    char name[MAX_APPOINTMENT_LENGTH];
    char date[MAX_APPOINTMENT_LENGTH];
    char time[MAX_APPOINTMENT_LENGTH];
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter the name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter the time (hh:mm): ");
    scanf("%s", appointments[num_appointments].time);

    num_appointments++;
}

void view_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    printf("Enter the name of the appointment to delete: ");
    char name[MAX_APPOINTMENT_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            memmove(&appointments[i], &appointments[i+1], sizeof(appointment) * (num_appointments - i - 1));
            num_appointments--;
            break;
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add appointment\n2. View appointments\n3. Delete appointment\n4. Exit\n");
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
    }

    return 0;
}