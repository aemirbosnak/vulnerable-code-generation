//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    int day;
    int month;
    int year;
    char patientName[50];
    char doctorName[50];
    char clinicName[50];
    char time[10];
};

struct Appointment appointments[100];
int appointmentCount = 0;

void addAppointment() {
    printf("Please enter the appointment details:\n");
    printf("Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appointments[appointmentCount].day, &appointments[appointmentCount].month, &appointments[appointmentCount].year);
    printf("Patient name: ");
    scanf("%s", appointments[appointmentCount].patientName);
    printf("Doctor name: ");
    scanf("%s", appointments[appointmentCount].doctorName);
    printf("Clinic name: ");
    scanf("%s", appointments[appointmentCount].clinicName);
    printf("Time (hh:mm): ");
    scanf("%s", appointments[appointmentCount].time);
    appointmentCount++;
    printf("\nAppointment has been added successfully!\n\n");
}

void viewAppointments() {
    if(appointmentCount == 0) {
        printf("There are no appointments scheduled.\n\n");
        return;
    }

    printf("Here are the scheduled appointments:\n");
    printf("----------------------------------\n");
    for(int i=0; i<appointmentCount; i++) {
        printf("%d/%d/%d, %s, %s, %s, at %s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].patientName, appointments[i].doctorName, appointments[i].clinicName, appointments[i].time);
    }
    printf("\n");
}

int main() {
    int choice;
    while(1) {
        printf("Welcome to the Appointment Scheduler!\n");
        printf("-------------------------------------\n");
        printf("1. Add new appointment\n");
        printf("2. View scheduled appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                printf("Thank you for using the Appointment Scheduler!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n\n");
        }
    }

    return 0;
}