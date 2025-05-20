//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int appointment_time;
} appointment;

int num_appointments = 0;
appointment appointments[MAX_APPOINTMENTS];

int add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: maximum number of appointments reached.\n");
        return 1;
    }
    appointment *new_appointment = &appointments[num_appointments];
    printf("Enter name: ");
    scanf("%s", new_appointment->name);
    printf("Enter phone number: ");
    scanf("%s", new_appointment->phone);
    printf("Enter email: ");
    scanf("%s", new_appointment->email);
    printf("Enter appointment time (in minutes): ");
    scanf("%d", &new_appointment->appointment_time);
    num_appointments++;
    return 0;
}

int view_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Phone: %s\n", appointments[i].phone);
        printf("Email: %s\n", appointments[i].email);
        printf("Appointment time: %d minutes\n\n", appointments[i].appointment_time);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_appointment();
            break;
        case 2:
            view_appointments();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}