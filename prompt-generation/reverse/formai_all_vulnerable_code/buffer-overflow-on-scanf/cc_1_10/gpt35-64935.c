//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct appointment {
    char patientName[50];
    char doctorName[50];
    char reason[100];
    int date;
    int time;
    bool status;
} Appointment;

void printMenu() {
    printf("========================================\n");
    printf("             APPOINTMENT SYSTEM          \n");
    printf("========================================\n");
    printf("| 1. Add Appointment                    |\n");
    printf("| 2. Update Appointment                 |\n");
    printf("| 3. View Appointment                   |\n");
    printf("| 4. Cancel Appointment                 |\n");
    printf("| 5. Exit                               |\n");
    printf("========================================\n");
}

void clearBuffer() {
    fflush(stdin);
}

void addAppointment(Appointment *appointments, int *numOfAppointments) {
    Appointment newAppointment;
    printf("Enter Patient Name: ");
    fgets(newAppointment.patientName, 50, stdin);
    strtok(newAppointment.patientName, "\n");
    printf("Enter Doctor Name: ");
    fgets(newAppointment.doctorName, 50, stdin);
    strtok(newAppointment.doctorName, "\n");
    printf("Enter Reason for the appointment: ");
    fgets(newAppointment.reason, 100, stdin);
    strtok(newAppointment.reason, "\n");
    printf("Enter Date (DDMMYYYY): ");
    scanf("%d", &newAppointment.date);
    printf("Enter Time (HHMM): ");
    scanf("%d", &newAppointment.time);
    newAppointment.status = true;
    appointments[*numOfAppointments] = newAppointment;
    *numOfAppointments += 1;
    clearBuffer();
    printf("Appointment added!\n\n");
}

void updateAppointment(Appointment *appointments, int numOfAppointments) {
    int appointmentId;
    printf("Enter appointment ID: ");
    scanf("%d", &appointmentId);
    if (appointmentId >= 0 && appointmentId < numOfAppointments && appointments[appointmentId].status) {
        char option;
        printf("Enter new Patient Name (press ENTER to skip): ");
        clearBuffer();
        fgets(appointments[appointmentId].patientName, 50, stdin);
        strtok(appointments[appointmentId].patientName, "\n");
        printf("Enter new Doctor Name (press ENTER to skip): ");
        fgets(appointments[appointmentId].doctorName, 50, stdin);
        strtok(appointments[appointmentId].doctorName, "\n");
        printf("Enter new Reason for the appointment (press ENTER to skip): ");
        fgets(appointments[appointmentId].reason, 100, stdin);
        strtok(appointments[appointmentId].reason, "\n");
        printf("Enter new Date (DDMMYYYY) (press 0 to skip): ");
        scanf("%d", &appointments[appointmentId].date);
        printf("Enter new Time (HHMM) (press 0 to skip): ");
        scanf("%d", &appointments[appointmentId].time);
        printf("Enter new Status (Y/N) (press F to skip): ");
        clearBuffer();
        scanf("%c", &option);
        if (option == 'Y') {
            appointments[appointmentId].status = true;
        } else if (option == 'N') {
            appointments[appointmentId].status = false;
        }
        clearBuffer();
        printf("Appointment updated!\n\n");
    } else {
        printf("Invalid appointment ID!\n\n");
    }
}

void viewAppointment(Appointment *appointments, int numOfAppointments) {
    bool isAppointmentsExist = false;
    printf("========================================\n");
    printf("           NOW SHOWING APPOINTMENTS      \n");
    printf("========================================\n");
    printf("| %-3s | %-20s | %-20s | %-20s | %-10s | %-10s | %-6s |\n", "ID", "Patient Name", "Doctor Name", "Reason", "Date", "Time", "Status");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < numOfAppointments; i++) {
        if (appointments[i].status) {
            printf("| %-3d | %-20s | %-20s | %-20s | %-10d | %-10d | %-6s |\n", i, appointments[i].patientName, appointments[i].doctorName, appointments[i].reason, appointments[i].date, appointments[i].time, appointments[i].status ? "Yes" : "No");
            isAppointmentsExist = true;
        }
    }
    if (!isAppointmentsExist) {
        printf("No appointments found!\n");
    }
    printf("\n");
}

void cancelAppointment(Appointment *appointments, int numOfAppointments) {
    int appointmentId;
    printf("Enter appointment ID: ");
    scanf("%d", &appointmentId);
    if (appointmentId >= 0 && appointmentId < numOfAppointments && appointments[appointmentId].status) {
        appointments[appointmentId].status = false;
        printf("Appointment canceled!\n\n");
    } else {
        printf("Invalid appointment ID!\n\n");
    }
}

int main() {
    Appointment appointments[100];
    int numOfAppointments = 0;
    int option;
    do {
        printMenu();
        printf("Enter an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addAppointment(appointments, &numOfAppointments);
                break;
            case 2:
                updateAppointment(appointments, numOfAppointments);
                break;
            case 3:
                viewAppointment(appointments, numOfAppointments);
                break;
            case 4:
                cancelAppointment(appointments, numOfAppointments);
                break;
            case 5:
                printf("Thank you for using the appointment system!\n");
                break;
            default:
                printf("Invalid option chosen, Please choose an available option from the menu!\n\n");
                break;
        }
    } while (option != 5);
    return 0;
}