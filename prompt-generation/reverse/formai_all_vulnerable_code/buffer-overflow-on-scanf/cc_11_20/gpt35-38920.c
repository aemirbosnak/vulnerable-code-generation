//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_APPOINTMENTS 10 // Maximum number of appointments that can be scheduled

// Struct to store the appointment details
struct Appointment {
    char date[15];
    char time[10];
    char name[30];
};

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS]; // Array to store the appointments
    int numAppointments = 0; // Variable to keep track of the number of appointments scheduled
    bool continueProgram = true; // Variable to control the flow of the program

    printf("Welcome to the Appointment Scheduler!\n");

    while(continueProgram) {
        printf("Please choose an option:\n");
        printf("1. Schedule appointment\n");
        printf("2. View appointments\n");
        printf("3. Cancel appointment\n");
        printf("4. Exit program\n");
        printf("Enter option number: ");

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter appointment date (dd/mm/yyyy): ");
                scanf("%s", appointments[numAppointments].date);

                printf("Enter appointment time (hh:mm): ");
                scanf("%s", appointments[numAppointments].time);

                printf("Enter your name: ");
                scanf("%s", appointments[numAppointments].name);

                printf("Appointment scheduled successfully!\n\n");

                numAppointments++;
                break;
            case 2:
                printf("\nList of Appointments:\n\n");
                printf("%-15s %-10s %-30s\n", "Date", "Time", "Name");
                for(int i = 0; i < numAppointments; i++) {
                    printf("%-15s %-10s %-30s\n", appointments[i].date, appointments[i].time, appointments[i].name);
                }
                printf("\n");
                break;
            case 3:
                printf("\nEnter appointment date (dd/mm/yyyy): ");
                char date[15];
                scanf("%s", date);

                printf("Enter appointment time (hh:mm): ");
                char time[10];
                scanf("%s", time);

                bool appointmentFound = false;
                for(int i = 0; i < numAppointments; i++) {
                    if(strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
                        appointmentFound = true;
                        printf("Appointment found! Cancelling..\n\n");

                        // Shift all the appointments after the cancelled one by one position left
                        for(int j = i; j < numAppointments - 1; j++) {
                            appointments[j] = appointments[j + 1];
                        }

                        numAppointments--;
                        break;
                    }
                }

                if(!appointmentFound) {
                    printf("No appointment found for the given date and time.\n\n");
                }
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                continueProgram = false;
                break;
            default:
                printf("\nInvalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}