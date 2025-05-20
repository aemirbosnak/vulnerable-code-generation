//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 50

struct Date {
    int day;
    int month;
    int year;
};

struct Appointment {
    char name[20];
    struct Date date;
    char time[10];
};

void printMenu() {
    printf("Welcome to the Appointment Scheduler\n");
    printf("-----------------------------------\n");
    printf("1. Schedule an appointment\n");
    printf("2. View scheduled appointments\n");
    printf("3. Cancel an appointment\n");
    printf("4. Exit\n");
}

void scheduleAppointment(struct Appointment appointments[], int *numAppointments) {
    if (*numAppointments < MAX_APPOINTMENTS) {
        printf("Enter name: ");
        scanf("%s", appointments[*numAppointments].name);
        printf("Enter date (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &appointments[*numAppointments].date.day, &appointments[*numAppointments].date.month, &appointments[*numAppointments].date.year);
        printf("Enter time (hh:mm): ");
        scanf("%s", appointments[*numAppointments].time);
        (*numAppointments)++;
        printf("Appointment scheduled successfully!\n");
    } else {
        printf("Sorry, the maximum number of appointments have been scheduled.\n");
    }
}

void viewAppointments(struct Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Scheduled Appointments\n");
    printf("-----------------------\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s on %02d/%02d/%d at %s\n", i+1, appointments[i].name, appointments[i].date.day, appointments[i].date.month, appointments[i].date.year, appointments[i].time);
    }
}

void cancelAppointment(struct Appointment appointments[], int *numAppointments) {
    viewAppointments(appointments, *numAppointments);
    if (*numAppointments == 0) {
        return;
    }
    int appointmentNum;
    printf("Enter appointment number to cancel: ");
    scanf("%d", &appointmentNum);
    if (appointmentNum < 1 || appointmentNum > *numAppointments) {
        printf("Invalid appointment number.\n");
        return;
    }
    printf("Are you sure you want to cancel the appointment with %s on %02d/%02d/%d at %s? (y/n)\n", appointments[appointmentNum-1].name, appointments[appointmentNum-1].date.day, appointments[appointmentNum-1].date.month, appointments[appointmentNum-1].date.year, appointments[appointmentNum-1].time);
    char choice;
    scanf(" %c", &choice);
    choice = tolower(choice);
    if (choice == 'y') {
        for (int i = appointmentNum-1; i < *numAppointments-1; i++) {
            appointments[i] = appointments[i+1];
        }
        (*numAppointments)--;
        printf("Appointment cancelled successfully!\n");
    } else if (choice == 'n') {
        printf("Appointment not cancelled.\n");
    } else {
        printf("Invalid choice. Appointment not cancelled.\n");
    }
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scheduleAppointment(appointments, &numAppointments);
                printf("\n");
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                printf("\n");
                break;
            case 3:
                cancelAppointment(appointments, &numAppointments);
                printf("\n");
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler!\n");
                printf("\n");
                break;
            default:
                printf("Invalid choice.\n");
                printf("\n");
                break;
        }
    } while (choice != 4);
    return 0;
}