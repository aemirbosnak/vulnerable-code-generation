//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000

typedef struct {
    char name[50];
    char phone[15];
    char email[50];
    char reason[100];
    int date;
    int time;
} Appointment;

void addAppointment(Appointment* appointments, int count) {
    printf("Enter patient name: ");
    scanf("%s", appointments[count].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[count].phone);

    printf("Enter email address: ");
    scanf("%s", appointments[count].email);

    printf("Enter reason for appointment: ");
    scanf("%s", appointments[count].reason);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%d", &appointments[count].date);

    printf("Enter time (HH:MM): ");
    scanf("%d", &appointments[count].time);

    count++;
}

void displayAppointments(Appointment* appointments, int count) {
    printf("\nAppointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s - %s - %s - %d/%d/%d %d:%d\n", appointments[i].name, appointments[i].phone, appointments[i].email, appointments[i].reason, appointments[i].date, appointments[i].date, appointments[i].time);
    }
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;

    while (count < MAX_APPOINTMENTS) {
        printf("\nEnter 1 to add an appointment or 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addAppointment(appointments, count);
        } else if (choice == 0) {
            printf("\nGoodbye!\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    displayAppointments(appointments, count);

    return 0;
}