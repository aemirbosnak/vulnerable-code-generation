//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct Appointment {
    int day, month, year;
    int hour, minute;
    char description[50];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment(int day, int month, int year, int hour, int minute, const char *description) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Maximum number of appointments reached.\n");
        return;
    }

    appointments[num_appointments].day = day;
    appointments[num_appointments].month = month;
    appointments[num_appointments].year = year;
    appointments[num_appointments].hour = hour;
    appointments[num_appointments].minute = minute;
    strcpy(appointments[num_appointments].description, description);

    num_appointments++;
}

void delete_appointment(int day, int month, int year, int hour, int minute) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i].day == day && appointments[i].month == month && appointments[i].year == year &&
            appointments[i].hour == hour && appointments[i].minute == minute) {

            for (int j = i; j < num_appointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }

            num_appointments--;
            i--;
            break;
        }
    }
}

void list_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Date: %d-%02d-%02d\n", appointments[i].year, appointments[i].month, appointments[i].day);
        printf("Time: %02d:%02d\n", appointments[i].hour, appointments[i].minute);
        printf("Description: %s\n", appointments[i].description);
        printf("\n");
    }
}

int main() {
    int choice;
    int day, month, year, hour, minute;
    char description[50];

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. List appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter appointment day: ");
                scanf("%d", &day);
                printf("Enter appointment month: ");
                scanf("%d", &month);
                printf("Enter appointment year: ");
                scanf("%d", &year);
                printf("Enter appointment hour: ");
                scanf("%d", &hour);
                printf("Enter appointment minute: ");
                scanf("%d", &minute);
                printf("Enter appointment description: ");
                scanf("%s", description);

                add_appointment(day, month, year, hour, minute, description);
                break;

            case 2:
                printf("Enter appointment day: ");
                scanf("%d", &day);
                printf("Enter appointment month: ");
                scanf("%d", &month);
                printf("Enter appointment year: ");
                scanf("%d", &year);
                printf("Enter appointment hour: ");
                scanf("%d", &hour);
                printf("Enter appointment minute: ");
                scanf("%d", &minute);

                delete_appointment(day, month, year, hour, minute);
                break;

            case 3:
                list_appointments();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}