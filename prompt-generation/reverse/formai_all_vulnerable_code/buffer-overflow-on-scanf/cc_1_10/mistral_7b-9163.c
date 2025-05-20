//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct {
    char name[50];
    int start_time;
    int end_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    printf("Enter name of appointment: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter start time (in minutes): ");
    scanf("%d", &appointments[num_appointments].start_time);

    printf("Enter end time (in minutes): ");
    scanf("%d", &appointments[num_appointments].end_time);

    num_appointments++;
}

void remove_appointment() {
    if (num_appointments == 0) {
        printf("No appointments to remove.\n");
        return;
    }

    printf("Enter index of appointment to remove: ");
    int index;
    scanf("%d", &index);

    if (index < 0 || index >= num_appointments) {
        printf("Invalid index.\n");
        return;
    }

    memmove(&appointments[index], &appointments[index + 1],
             (num_appointments - index - 1) * sizeof(Appointment));

    num_appointments--;
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments to view.\n");
        return;
    }

    printf("Appointments:\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%s (%d-%d)\n", appointments[i].name,
               appointments[i].start_time, appointments[i].end_time);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Remove appointment\n");
        printf("3. View appointments\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
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
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}