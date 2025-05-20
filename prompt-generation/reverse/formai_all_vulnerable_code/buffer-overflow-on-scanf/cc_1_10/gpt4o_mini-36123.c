//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 50

typedef struct {
    char name[50];
    char date[11];    // Format: YYYY-MM-DD
    char time[6];     // Format: HH:MM
} Appointment;

void displayMenu();
void addAppointment(Appointment *appointments, int *count);
void viewAppointments(Appointment *appointments, int count);
void clearAppointments(Appointment *appointments, int *count);
void sortAppointments(Appointment *appointments, int count);
int compare(const void *a, const void *b);

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    printf("~~~~~ Welcome to the Artistic Appointment Scheduler ~~~~~\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                viewAppointments(appointments, count);
                break;
            case 3:
                clearAppointments(appointments, &count);
                break;
            case 4:
                sortAppointments(appointments, count);
                printf("Appointments sorted successfully!\n");
                break;
            case 5:
                printf("Thank you for using the Artistic Appointment Scheduler!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n");
    printf("--------------------\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Clear Appointments\n");
    printf("4. Sort Appointments\n");
    printf("5. Exit\n");
    printf("--------------------\n");
}

void addAppointment(Appointment *appointments, int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full. Cannot add more appointments.\n");
        return;
    }

    printf("Enter name of the appointment: ");
    scanf(" %[^\n]", appointments[*count].name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[*count].date);
    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[*count].time);
    (*count)++;

    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment *appointments, int count) {
    if (count == 0) {
        printf("No appointments to display.\n");
        return;
    }

    printf("\n~~~~~ List of Appointments ~~~~~\n");
    for (int i = 0; i < count; i++) {
        printf("[%d] %s on %s at %s\n", i + 1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void clearAppointments(Appointment *appointments, int *count) {
    *count = 0;  // Clears the appointment list
    printf("All appointments cleared successfully!\n");
}

void sortAppointments(Appointment *appointments, int count) {
    qsort(appointments, count, sizeof(Appointment), compare);
}

int compare(const void *a, const void *b) {
    Appointment *appt1 = (Appointment *)a;
    Appointment *appt2 = (Appointment *)b;
    
    int dateComparison = strcmp(appt1->date, appt2->date);
    if (dateComparison == 0) {
        return strcmp(appt1->time, appt2->time);
    }
    return dateComparison;
}