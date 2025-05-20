//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    int day, month, year, hour, minute;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, you cannot add more appointments.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter day (1-31): ");
    scanf("%d", &appointments[num_appointments].day);

    printf("Enter month (1-12): ");
    scanf("%d", &appointments[num_appointments].month);

    printf("Enter year (2000-2099): ");
    scanf("%d", &appointments[num_appointments].year);

    printf("Enter hour (0-23): ");
    scanf("%d", &appointments[num_appointments].hour);

    printf("Enter minute (0-59): ");
    scanf("%d", &appointments[num_appointments].minute);

    num_appointments++;
}

void display_appointments() {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].hour, appointments[i].minute);
    }
}

void main() {
    srand(time(NULL));

    int choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Display appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                display_appointments();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);
}