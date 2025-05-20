//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct appointment {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void display_menu() {
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add an appointment\n");
    printf("2. View appointments\n");
    printf("3. Exit\n");
}

void add_appointment() {
    if (num_appointments == MAX_APPOINTMENTS) {
        printf("Maximum appointments reached.\n");
        return;
    }

    Appointment a;
    printf("Enter name: ");
    scanf("%s", a.name);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &a.day, &a.month, &a.year);
    printf("Enter time (HH:MM): ");
    scanf("%d:%d", &a.hour, &a.minute);

    appointments[num_appointments] = a;
    num_appointments++;
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Scheduled Appointments\n");
    printf("----------------------\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %02d/%02d/%04d at %02d:%02d\n", 
                appointments[i].name,
                appointments[i].day,
                appointments[i].month,
                appointments[i].year,
                appointments[i].hour,
                appointments[i].minute);
    }
}

int main() {
    int choice;

    do {
        display_menu();
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}