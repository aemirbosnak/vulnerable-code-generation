//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointmentTime;
} Appointment;

void addAppointment(Appointment* appointments, int numAppointments) {
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[numAppointments].phone);

    printf("Enter email address: ");
    scanf("%s", appointments[numAppointments].email);

    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[numAppointments].appointmentTime);

    numAppointments++;
}

void viewAppointments(Appointment* appointments, int numAppointments) {
    printf("\nAppointments:\n");
    printf("==================================================\n");
    printf("Name\t\tPhone\tEmail\tAppointment Time\n");
    printf("==================================================\n");

    for (int i = 0; i < numAppointments; i++) {
        printf("%s\t\t%s\t\t%s\t\t%s\n", appointments[i].name, appointments[i].phone, appointments[i].email, ctime(&appointments[i].appointmentTime));
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    while (numAppointments < MAX_APPOINTMENTS) {
        printf("\nEnter 1 to add an appointment or 0 to view appointments: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, numAppointments);
                break;
            case 0:
                viewAppointments(appointments, numAppointments);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}