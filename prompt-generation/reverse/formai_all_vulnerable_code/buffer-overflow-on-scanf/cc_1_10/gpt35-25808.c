//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

// Structure for storing appointment details
struct Appointment {
    char* patientName;
    char* doctorName;
    char* dateTime;
};

struct Appointment appointmentList[MAX_APPOINTMENTS]; // Global list of appointments
int appointmentCount = 0; // Counter for the number of appointments

// Function to create a new appointment and add it to the list
void createAppointment() {
    char* patientName = malloc(sizeof(char) * 50);
    char* doctorName = malloc(sizeof(char) * 50);
    char* dateTime = malloc(sizeof(char) * 50);

    printf("Enter patient name: ");
    scanf("%s", patientName);

    printf("Enter doctor name: ");
    scanf("%s", doctorName);

    printf("Enter date and time (DD/MM/YYYY HH:MM): ");
    scanf("%s", dateTime);

    // Create new appointment object and add it to list
    struct Appointment newAppointment;
    newAppointment.patientName = patientName;
    newAppointment.doctorName = doctorName;
    newAppointment.dateTime = dateTime;

    appointmentList[appointmentCount++] = newAppointment;

    printf("Appointment created successfully!\n");
}

// Function to display all appointments in the list
void displayAppointments() {
    if (appointmentCount == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }

    printf("%-15s %-15s %-20s\n", "PATIENT NAME", "DOCTOR NAME", "DATE/TIME");

    for (int i = 0; i < appointmentCount; i++) {
        printf("%-15s %-15s %-20s\n", appointmentList[i].patientName,
               appointmentList[i].doctorName, appointmentList[i].dateTime);
    }
}

// Function to search for an appointment by patient name
void searchByPatientName() {
    char* patientName = malloc(sizeof(char) * 50);
    printf("Enter patient name: ");
    scanf("%s", patientName);

    bool found = false;

    for (int i = 0; i < appointmentCount; i++) {
        if (strcmp(appointmentList[i].patientName, patientName) == 0) {
            printf("%-15s %-15s %-20s\n", "PATIENT NAME", "DOCTOR NAME", "DATE/TIME");
            printf("%-15s %-15s %-20s\n", appointmentList[i].patientName,
                   appointmentList[i].doctorName, appointmentList[i].dateTime);

            found = true;
            break;
        }
    }

    if (!found) {
        printf("No appointment found for patient %s.\n", patientName);
    }
}

int main() {
    int option;

    do {
        printf("\n===== APPOINTMENT SCHEDULER =====\n");
        printf("1. Create appointment\n2. Display all appointments\n3. Search by patient name\n4. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                createAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                searchByPatientName();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}