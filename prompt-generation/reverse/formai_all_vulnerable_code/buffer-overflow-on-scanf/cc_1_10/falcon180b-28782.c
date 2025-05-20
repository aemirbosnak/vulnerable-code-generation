//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments available.\n");
        return;
    }

    char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH], email[MAX_EMAIL_LENGTH];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your phone number: ");
    scanf("%s", phone);
    printf("Enter your email address: ");
    scanf("%s", email);

    strncpy(appointments[num_appointments].name, name, MAX_NAME_LENGTH);
    strncpy(appointments[num_appointments].phone, phone, MAX_PHONE_LENGTH);
    strncpy(appointments[num_appointments].email, email, MAX_EMAIL_LENGTH);

    time_t now = time(NULL);
    appointments[num_appointments].appointment_time = now + 60 * 60 * 24; // 24 hours from now

    num_appointments++;
    printf("Appointment added for %s at %s.\n", name, ctime(&appointments[num_appointments - 1].appointment_time));
}

void view_appointments() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Upcoming appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s (%s)\n", ctime(&appointments[i].appointment_time), appointments[i].name, appointments[i].phone);
    }
}

void cancel_appointment() {
    if (num_appointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("Appointment cancelled for %s.\n", name);
            memmove(&appointments[i], &appointments[i + 1], sizeof(Appointment) * (num_appointments - i - 1));
            num_appointments--;
            return;
        }
    }

    printf("No appointment found for %s.\n", name);
}

int main() {
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Cancel appointment\n");
        printf("4. Exit\n");

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
            cancel_appointment();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}