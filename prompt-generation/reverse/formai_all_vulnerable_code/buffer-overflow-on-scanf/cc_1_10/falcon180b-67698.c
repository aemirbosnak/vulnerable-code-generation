//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 100 // Maximum number of appointments
#define MAX_NAME_LENGTH 50 // Maximum length of client name
#define MAX_PHONE_LENGTH 20 // Maximum length of client phone number

typedef struct {
    char name[MAX_NAME_LENGTH]; // Client name
    char phone[MAX_PHONE_LENGTH]; // Client phone number
    time_t date; // Appointment date and time
} Appointment;

int numAppointments = 0; // Number of appointments
Appointment appointments[MAX_APPOINTMENTS]; // Array to store appointments

void addAppointment() {
    if (numAppointments >= MAX_APPOINTMENTS) {
        printf("Sorry, no more appointments can be added.\n");
        return;
    }

    printf("Enter client name: ");
    scanf("%s", appointments[numAppointments].name);

    printf("Enter client phone number: ");
    scanf("%s", appointments[numAppointments].phone);

    printf("Enter appointment date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[numAppointments].date);

    numAppointments++;
}

void viewAppointments() {
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].phone, ctime(&appointments[i].date));
    }
}

void deleteAppointment() {
    printf("Enter appointment ID to delete: ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < numAppointments; i++) {
        if (i == id) {
            numAppointments--;
            for (int j = i; j < numAppointments; j++) {
                strcpy(appointments[j].name, appointments[j+1].name);
                strcpy(appointments[j].phone, appointments[j+1].phone);
                appointments[j].date = appointments[j+1].date;
            }
            printf("Appointment deleted.\n");
            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}