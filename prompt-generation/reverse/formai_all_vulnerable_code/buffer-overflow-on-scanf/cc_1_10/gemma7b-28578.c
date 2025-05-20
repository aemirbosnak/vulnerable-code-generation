//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
} Appointment;

Appointment appointments[MAX_Appointments];

void schedule_appointment() {
    int i = 0;
    printf("Enter your name: ");
    scanf("%s", appointments[i].name);
    printf("Enter the date of your appointment: ");
    scanf("%s", appointments[i].date);
    printf("Enter the time of your appointment: ");
    scanf("%s", appointments[i].time);
    i++;
}

void list_appointments() {
    int i = 0;
    printf("Your appointments:\n");
    for (i = 0; i < MAX_Appointments; i++) {
        if (appointments[i].name[0] != '\0') {
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("\n");
        }
    }
}

int main() {
    int choice;

    printf("Welcome to the Appointment Scheduler!\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Schedule an appointment\n");
        printf("2. List your appointments\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                schedule_appointment();
                break;
            case 2:
                list_appointments();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}