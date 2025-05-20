//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
} Appointment;

Appointment appointments[MAX_Appointments];

void displayAppointments() {
    int i = 0;
    for (i = 0; i < MAX_Appointments; i++) {
        if (appointments[i].name[0] != '\0') {
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("\n");
        }
    }
}

void createAppointment() {
    int i = 0;
    for (i = 0; i < MAX_Appointments; i++) {
        if (appointments[i].name[0] == '\0') {
            printf("Enter your name: ");
            scanf("%s", appointments[i].name);

            printf("Enter the date (dd/mm/yyyy): ");
            scanf("%s", appointments[i].date);

            printf("Enter the time (hh:mm): ");
            scanf("%s", appointments[i].time);

            break;
        }
    }

    if (i == MAX_Appointments) {
        printf("No more appointments can be created.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the C Appointment Scheduler!\n");

    printf("1. Display Appointments\n");
    printf("2. Create an Appointment\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            displayAppointments();
            break;
        case 2:
            createAppointment();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}