//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Ken Thompson
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
    int appointment_id;
} appointment;

int num_appointments = 0;
appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter your name: ");
    scanf("%s", name);
    strcpy(appointments[num_appointments].name, name);

    printf("Enter your phone number: ");
    scanf("%s", phone);
    strcpy(appointments[num_appointments].phone, phone);

    printf("Enter your email address: ");
    scanf("%s", email);
    strcpy(appointments[num_appointments].email, email);

    appointments[num_appointments].appointment_id = num_appointments + 1;
    num_appointments++;

    printf("Appointment added successfully.\n");
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Appointment Schedule:\n");
    printf("ID\tName\tPhone\tEmail\n");

    for (int i = 0; i < num_appointments; i++) {
        printf("%d\t%s\t%s\t%s\n", appointments[i].appointment_id, appointments[i].name, appointments[i].phone, appointments[i].email);
    }
}

void main() {
    while (1) {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Exit\n");

        int choice;
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
            printf("Invalid choice. Try again.\n");
        }
    }
}