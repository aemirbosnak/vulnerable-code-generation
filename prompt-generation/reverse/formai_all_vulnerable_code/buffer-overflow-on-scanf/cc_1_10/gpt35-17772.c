//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPTS 10

typedef struct {
    char date[11];
    char time[6];
    char name[50];
    char phone[15];
} Appointment;

void addAppointment(Appointment [], int *);
void displayAppointments(Appointment [], int);
void deleteAppointment(Appointment [], int *);

int main() {
    Appointment appts[MAX_APPTS];
    int numAppts = 0;
    int choice;

    printf("**** Appointment Scheduler ****\n");

    do {
        printf("\n");
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appts, &numAppts);
                break;
            case 2:
                displayAppointments(appts, numAppts);
                break;
            case 3:
                deleteAppointment(appts, &numAppts);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addAppointment(Appointment appts[], int *numAppts) {
    if (*numAppts == MAX_APPTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    Appointment newAppt;

    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", newAppt.date);

    printf("Enter time (HH:MM): ");
    scanf("%s", newAppt.time);

    printf("Enter name: ");
    scanf(" %[^\n]s", newAppt.name);

    printf("Enter phone (XXX-XXX-XXXX): ");
    scanf("%s", newAppt.phone);

    appts[*numAppts] = newAppt;
    (*numAppts)++;

    printf("Appointment added successfully.\n");
}

void displayAppointments(Appointment appts[], int numAppts) {
    if (numAppts == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("%-15s %-10s %-20s %-15s\n", "Date", "Time", "Name", "Phone");

    for (int i = 0; i < numAppts; i++) {
        printf("%-15s %-10s %-20s %-15s\n", appts[i].date, appts[i].time, appts[i].name, appts[i].phone);
    }
}

void deleteAppointment(Appointment appts[], int *numAppts) {
    if (*numAppts == 0) {
        printf("No appointments found.\n");
        return;
    }

    char searchDate[11];
    char searchTime[6];

    printf("Enter date (MM/DD/YYYY) of appointment to delete: ");
    scanf("%s", searchDate);

    printf("Enter time (HH:MM) of appointment to delete: ");
    scanf("%s", searchTime);

    int apptIndex = -1;

    for (int i = 0; i < *numAppts; i++) {
        if (strcmp(appts[i].date, searchDate) == 0 && strcmp(appts[i].time, searchTime) == 0) {
            apptIndex = i;
            break;
        }
    }

    if (apptIndex == -1) {
        printf("Appointment not found.\n");
        return;
    }

    for (int j = apptIndex; j < (*numAppts - 1); j++) {
        appts[j] = appts[j+1];
    }

    (*numAppts)--;
    printf("Appointment deleted successfully.\n");
}