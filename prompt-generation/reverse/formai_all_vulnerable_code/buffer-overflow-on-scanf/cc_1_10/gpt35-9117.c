//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 20

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[100];
    Date date;
    char time[10];
    char reason[200];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    printf("Enter appointment name: ");
    scanf(" %[^\n]", appointments[num_appointments].name);

    printf("Enter appointment date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &appointments[num_appointments].date.day, 
                      &appointments[num_appointments].date.month, 
                      &appointments[num_appointments].date.year);

    printf("Enter appointment time (HH:MM AM/PM): ");
    scanf(" %[^\n]", appointments[num_appointments].time);

    printf("Enter reason for appointment: ");
    scanf(" %[^\n]", appointments[num_appointments].reason);

    printf("Appointment added!\n");
    num_appointments++;
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n");
    printf("Scheduled Appointments\n");
    printf("=====================\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d\n", i+1);
        printf("----------------\n");
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %02d/%02d/%04d\n", appointments[i].date.day, 
                                          appointments[i].date.month, 
                                          appointments[i].date.year);
        printf("Time: %s\n", appointments[i].time);
        printf("Reason: %s\n", appointments[i].reason);
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("Appointment Scheduler Menu\n");
        printf("===========================\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("\n");
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
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}