//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to represent a doctor's appointment
typedef struct {
    char name[30];
    int day;
    int month;
    int year;
    char time[10];
} Appointment;

// function to print an appointment
void printAppointment(Appointment appointment) {
    printf("%s's appointment on %d/%d/%d at %s\n", appointment.name, appointment.day, appointment.month, appointment.year, appointment.time);
}

// function to check if two appointments overlap
int isOverlap(Appointment appointment1, Appointment appointment2) {
    // check if the appointments are on the same day
    if (appointment1.day == appointment2.day && appointment1.month == appointment2.month && appointment1.year == appointment2.year) {
        // check if the appointments have overlapping time intervals
        if ((strcmp(appointment1.time, "10:00 AM - 11:00 AM") == 0 && strcmp(appointment2.time, "10:00 AM - 11:00 AM") == 0) ||
            (strcmp(appointment1.time, "11:00 AM - 12:00 PM") == 0 && strcmp(appointment2.time, "11:00 AM - 12:00 PM") == 0) ||
            (strcmp(appointment1.time, "1:00 PM - 2:00 PM") == 0 && strcmp(appointment2.time, "1:00 PM - 2:00 PM") == 0) ||
            (strcmp(appointment1.time, "2:00 PM - 3:00 PM") == 0 && strcmp(appointment2.time, "2:00 PM - 3:00 PM") == 0)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // create an array to store appointments
    Appointment appointments[10];
    int numAppointments = 0;
    char input[50];

    while (1) {
        // print the current appointments
        printf("Current Appointments:\n");
        for (int i = 0; i < numAppointments; i++) {
            printAppointment(appointments[i]);
        }

        // ask the user for a command
        printf("\nCommands:\n");
        printf("book: book a new appointment\n");
        printf("cancel: cancel an existing appointment\n");
        printf("quit: quit the program\n");
        printf("Enter a command: ");
        fgets(input, 50, stdin);
        
        // remove trailing newline character
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "book") == 0) {
            // ask the user for the appointment details
            printf("\nEnter the patient name: ");
            fgets(input, 50, stdin);
            input[strlen(input) - 1] = '\0';
            strcpy(appointments[numAppointments].name, input);

            printf("Enter the appointment day (1-31): ");
            fgets(input, 50, stdin);
            appointments[numAppointments].day = atoi(input);

            printf("Enter the appointment month (1-12): ");
            fgets(input, 50, stdin);
            appointments[numAppointments].month = atoi(input);

            printf("Enter the appointment year: ");
            fgets(input, 50, stdin);
            appointments[numAppointments].year = atoi(input);

            printf("Enter the appointment time (10:00 AM - 11:00 AM, 11:00 AM - 12:00 PM, 1:00 PM - 2:00 PM, 2:00 PM - 3:00 PM): ");
            fgets(input, 50, stdin);
            input[strlen(input) - 1] = '\0';
            strcpy(appointments[numAppointments].time, input);

            // check if the new appointment overlaps with existing appointments
            int overlap = 0;
            for (int i = 0; i < numAppointments; i++) {
                if (isOverlap(appointments[numAppointments], appointments[i])) {
                    overlap = 1;
                    break;
                }
            }

            if (overlap) {
                printf("Error: Appointment overlaps with an existing appointment.\n");
            } else {
                printf("Appointment booked.\n");
                numAppointments++;
            }
        } else if (strcmp(input, "cancel") == 0) {
            // ask the user for the appointment details to be canceled
            printf("\nEnter the patient name: ");
            fgets(input, 50, stdin);
            input[strlen(input) - 1] = '\0';

            printf("Enter the appointment day (1-31): ");
            fgets(input, 50, stdin);
            int day = atoi(input);

            printf("Enter the appointment month (1-12): ");
            fgets(input, 50, stdin);
            int month = atoi(input);

            printf("Enter the appointment year: ");
            fgets(input, 50, stdin);
            int year = atoi(input);

            printf("Enter the appointment time (10:00 AM - 11:00 AM, 11:00 AM - 12:00 PM, 1:00 PM - 2:00 PM, 2:00 PM - 3:00 PM): ");
            fgets(input, 50, stdin);
            input[strlen(input) - 1] = '\0';

            // find the index of the appointment to be canceled
            int cancelIndex = -1;
            for (int i = 0; i < numAppointments; i++) {
                if (strcmp(appointments[i].name, input) == 0 && appointments[i].day == day && appointments[i].month == month && appointments[i].year == year && strcmp(appointments[i].time, input) == 0) {
                    cancelIndex = i;
                    break;
                }
            }

            if (cancelIndex == -1) {
                printf("Error: Appointment not found.\n");
            } else {
                printf("Appointment canceled.\n");

                // remove the canceled appointment from the array
                for (int i = cancelIndex; i < numAppointments - 1; i++) {
                    appointments[i] = appointments[i+1];
                }
                numAppointments--;
            }
        } else if (strcmp(input, "quit") == 0) {
            // quit the program
            break;
        } else {
            // invalid command
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}