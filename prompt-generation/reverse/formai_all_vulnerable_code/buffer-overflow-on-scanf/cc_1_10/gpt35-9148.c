//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

#define MAX_APPOINTMENTS 10

/* Surrealistic C Appointment Scheduler Example Program */

typedef struct {
    char date[30];
    char time[30];
    char customer_name[30];
    char service[30];
} Appointment;

int num_appointments = 0;
Appointment appointments[MAX_APPOINTMENTS];

void addAppointment() {
    if(num_appointments >= MAX_APPOINTMENTS) {
        printf("Sorry, we are not accepting any more appointments at this time. Please try again later.\n");
        return;
    }

    printf("Enter appointment date (dd/mm/yyyy): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter appointment time (hh:mm): ");
    scanf("%s",appointments[num_appointments].time);

    printf("Enter customer name: ");
    scanf("%s", appointments[num_appointments].customer_name);

    printf("Enter service: ");
    scanf("%s", appointments[num_appointments].service);

    num_appointments++;

    printf("\nAppointment scheduled for %s at %s with %s for %s.\n", 
           appointments[num_appointments-1].date, 
           appointments[num_appointments-1].time, 
           appointments[num_appointments-1].customer_name, 
           appointments[num_appointments-1].service);
}

void viewAppointments() {
    if(num_appointments == 0) {
        printf("\nYou have no appointments scheduled at this time.\n");
        return;
    }
    
    printf("|---------------------------------------------------------------------------------------------------------|\n");
    printf("| %-13s | %-10s | %-20s | %-20s |\n", "Date", "Time", "Customer Name", "Service");
    printf("|--------------|------------|-----------------------|-----------------------|\n");

    for(int i=0; i<num_appointments; i++) {
        printf("| %-13s | %-10s | %-20s | %-20s |\n", appointments[i].date, appointments[i].time, appointments[i].customer_name, appointments[i].service);
    }
    printf("|---------------------------------------------------------------------------------------------------------|\n");
}

void cancelAppointment() {
    if(num_appointments == 0) {
        printf("\nYou have no appointments scheduled at this time.\n");
        return;
    }
    
    char date[30];
    char time[30];
    printf("Enter appointment date you would like to cancel (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter appointment time you would like to cancel (hh:mm): ");
    scanf("%s", time);

    for(int i=0; i<num_appointments; i++) {
        if(strcmp(appointments[i].date, date) == 0 && strcmp(appointments[i].time, time) == 0) {
            printf("\nAppointment scheduled for %s at %s with %s for %s has been cancelled.\n", appointments[i].date, appointments[i].time, appointments[i].customer_name, appointments[i].service);
            for(int j=i+1; j<num_appointments; j++) {
                appointments[j-1] = appointments[j];
            }
            num_appointments--;
            return;
        }
    }

    printf("\nSorry, we could not find an appointment with that date and time.\n");
}

void menu() {
    printf("\n1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    printf("\t\tWelcome to the Surrealist Appointment Scheduler!\n");
    printf("\t\t==============================================\n");

    do{
        menu();

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
                cancelAppointment();
                break;
            case 4:
                printf("\nThank you for using the Surrealist Appointment Scheduler. Goodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}