//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PATIENTS 50              //MAX number of patients can be scheduled
#define PATIENT_NAME_SIZE 30         //MAX length of patient name
#define DOCTOR_NAME_SIZE 30          //MAX length of doctor name
#define APPOINTMENT_TIME_SIZE 10     //MAX length of appointment time
#define MENU_OPTIONS_COUNT 4         //MAX number of options in the menu

//Structure to store patient details
struct Patient {
    char name[PATIENT_NAME_SIZE];
    char appointmentTime[APPOINTMENT_TIME_SIZE];
    char doctorName[DOCTOR_NAME_SIZE];
};

//Function to display Main Menu
void displayMainMenu() {
    printf("\n\n========= Appointment Scheduler =========\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

//Function to add new appointment
void scheduleAppointment(struct Patient *patients, int *count) {
    if(*count >= MAX_PATIENTS) {
        printf("No more appointments can be scheduled!\n");
        return;
    }

    printf("\nEnter Patient Name: ");
    scanf("%s", patients[*count].name);

    printf("Enter Doctor Name: ");
    scanf("%s", patients[*count].doctorName);

    printf("Enter Appointment Time (hh:mm): ");
    scanf("%s", patients[*count].appointmentTime);

    (*count)++;
    printf("\nAppointment Scheduled Successfully!\n");
}

//Function to display formatted appointment details
void displayAppointmentDetails(struct Patient patient) {
    printf("\nPatient Name: %s", patient.name);
    printf("\nDoctor Name: %s", patient.doctorName);
    printf("\nAppointment Time: %s", patient.appointmentTime);
}

//Function to display all appointments
void viewAppointments(struct Patient *patients, int count) {
    if(count == 0) {
        printf("\nNo appointments scheduled\n");
        return;
    }

    printf("\nAll Appointments:\n");
    for(int i=0; i<count; i++) {
        printf("\nAppointment #%d: ", i+1);
        displayAppointmentDetails(patients[i]);
    }
}

//Function to cancel appointment
void cancelAppointment(struct Patient *patients, int *count) {
    if(*count == 0) {
        printf("\nNo appointments scheduled to cancel!\n");
        return;
    }

    char appointmentTime[APPOINTMENT_TIME_SIZE];
    printf("\nEnter Appointment Time to cancel (hh:mm): ");
    scanf("%s", appointmentTime);

    for(int i=0; i<*count; i++) {
        if(strcmp(patients[i].appointmentTime, appointmentTime) == 0) {
            for(int j=i; j<*count-1; j++) {
                patients[j] = patients[j+1];
            }
            (*count)--;
            printf("\nAppointment Cancelled Successfully!\n");
            return;
        }
    }

    printf("\nNo appointments found to cancel!\n");
}

//Main Function
int main() {
    struct Patient patients[MAX_PATIENTS];
    int count=0, choice=0;

    do {
        displayMainMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: scheduleAppointment(patients, &count); break;
            case 2: viewAppointments(patients, count); break;
            case 3: cancelAppointment(patients, &count); break;
            case 4: printf("\nThank you for using the Appointment Scheduler!\n"); break;
            default: printf("\nPlease enter valid choice\n"); break;
        }
    } while(choice != MENU_OPTIONS_COUNT);

    return 0;
}