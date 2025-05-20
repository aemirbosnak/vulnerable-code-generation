//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
    int appointment_id; // appointment ID
    char patient_name[30]; // patient name
    char doctor_name[30]; // Doctor name
    char appointment_date[12]; // Date of appointment
    char appointment_time[10]; // Time of appointment
}Appointment;

Appointment appointments[50]; 
int no_of_appointments = 0;

// Function to check if the appointment slot is available or not
bool isSlotAvailable(char date[], char time[]){
    for(int i = 0; i < no_of_appointments; i++) {
        if(strcmp(appointments[i].appointment_date, date)==0 && strcmp(appointments[i].appointment_time, time)==0) {
            return false;
        }
    }
    return true;
}

// Function to add the appointment to the array
void addAppointment(Appointment appointment) {
    appointments[no_of_appointments] = appointment;
    no_of_appointments++;
    printf("Appointment added successfully!\n");
}

// Function to display the upcoming appointments
void displayAppointments() {
    printf("Upcoming Appointments:\n");
    printf("----------------------\n");
    for(int i = 0; i < no_of_appointments; i++) {
        printf("Appointment ID: %d\nPatient Name: %s\nDoctor Name: %s\nDate: %s\nTime: %s\n\n", 
            appointments[i].appointment_id, appointments[i].patient_name, appointments[i].doctor_name,
            appointments[i].appointment_date, appointments[i].appointment_time);
    }
}

int main() {
    int option;
    char date[12], time[10];
    Appointment new_appointment;
    printf("Welcome to the Appointment Scheduler!\n");
    while(true) {
        printf("\n\n");
        printf("Select an option:\n");
        printf("1. Add an appointment\n");
        printf("2. Display upcoming appointments\n");
        printf("3. Exit\n");
        printf("Enter your selection (1/2/3): ");
        scanf("%d", &option);
        printf("\n");
        switch(option) {
            case 1:
                printf("Enter patient name: ");
                scanf("%s", new_appointment.patient_name);
                printf("Enter doctor name: ");
                scanf("%s", new_appointment.doctor_name);
                printf("Enter appointment date (DD/MM/YYYY): ");
                scanf("%s", new_appointment.appointment_date);
                printf("Enter appointment time (HH:MM): ");
                scanf("%s", new_appointment.appointment_time);
                new_appointment.appointment_id = no_of_appointments+1;
                if(isSlotAvailable(new_appointment.appointment_date, new_appointment.appointment_time)) {
                    addAppointment(new_appointment);
                } else {
                    printf("Appointment slot not available. Please try again.\n");
                }
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                printf("Thank you for using the Appointment Scheduler!\n");
                exit(0);
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }
    return 0;
}