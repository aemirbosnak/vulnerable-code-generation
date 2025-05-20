//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char date[20];
    char time[20];
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, maximum number of appointments reached.\n");
        return;
    }
    printf("Enter name:\n");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter date (YYYY-MM-DD):\n");
    scanf("%s", appointments[num_appointments].date);
    printf("Enter time (HH:MM):\n");
    scanf("%s", appointments[num_appointments].time);
    num_appointments++;
    printf("Appointment added successfully.\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments available.\n");
        return;
    }
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    if (num_appointments == 0) {
        printf("No appointments available.\n");
        return;
    }
    printf("Enter name of appointment to delete:\n");
    scanf("%s", appointments[num_appointments - 1].name);
    for (int i = 0; i < num_appointments - 1; i++) {
        strcpy(appointments[i].name, appointments[i + 1].name);
        strcpy(appointments[i].date, appointments[i + 1].date);
        strcpy(appointments[i].time, appointments[i + 1].time);
    }
    num_appointments--;
    printf("Appointment deleted successfully.\n");
}

int main() {
    int choice;
    do {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
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
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}