//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char phone[20];
    char email[100];
} Contact;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    Contact contact;
    Date date;
} Appointment;

void scheduleAppointment(Appointment appointments[], int *numOfAppointments) {
    printf("\nEnter the following details to schedule an appointment\n");
    printf("Name: ");
    fgets(appointments[*numOfAppointments].contact.name, 100, stdin);
    appointments[*numOfAppointments].contact.name[strcspn(appointments[*numOfAppointments].contact.name, "\n")] = 0; // remove trailing '\n'
    printf("Phone: ");
    fgets(appointments[*numOfAppointments].contact.phone, 20, stdin);
    appointments[*numOfAppointments].contact.phone[strcspn(appointments[*numOfAppointments].contact.phone, "\n")] = 0;
    printf("Email: ");
    fgets(appointments[*numOfAppointments].contact.email, 100, stdin);
    appointments[*numOfAppointments].contact.email[strcspn(appointments[*numOfAppointments].contact.email, "\n")] = 0;
    printf("Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appointments[*numOfAppointments].date.day, &appointments[*numOfAppointments].date.month, &appointments[*numOfAppointments].date.year);
    getchar(); // remove trailing '\n'
    (*numOfAppointments)++;
}

void viewAppointments(Appointment appointments[], int numOfAppointments) {
    if (numOfAppointments == 0) {
        printf("\nThere are no appointments scheduled\n");
    } else {
        printf("\nScheduled Appointments:\n");
        for (int i = 0; i < numOfAppointments; i++) {
            printf("Appointment %d:\n", i+1);
            printf("Name: %s\n", appointments[i].contact.name);
            printf("Phone: %s\n", appointments[i].contact.phone);
            printf("Email: %s\n", appointments[i].contact.email);
            printf("Date: %d/%d/%d\n", appointments[i].date.day, appointments[i].date.month, appointments[i].date.year);
        }
    }
}

int main() {
    int choice, numOfAppointments = 0;
    Appointment appointments[100];

    printf("Appointment Scheduler\n");
    printf("----------------------\n");

    do {
        printf("\n1. Schedule Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // remove trailing '\n'

        switch(choice) {
            case 1:
                scheduleAppointment(appointments, &numOfAppointments);
                break;
            case 2:
                viewAppointments(appointments, numOfAppointments);
                break;
            case 3:
                printf("\nThank you for using Appointment Scheduler!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}