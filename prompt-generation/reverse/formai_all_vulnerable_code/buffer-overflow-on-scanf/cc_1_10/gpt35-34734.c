//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 15

typedef struct{
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[6]; // HH:MM format
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void printMenu(){
    printf("\tAPPOINTMENT SCHEDULER\n");
    printf("1. Schedule an appointment\n");
    printf("2. View scheduled appointments\n");
    printf("3. Cancel an appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void scheduleAppointment(){
    Appointment newAppointment;
    printf("Enter customer name: ");
    fgets(newAppointment.name, MAX_NAME_LENGTH, stdin);
    printf("Enter appointment date (MM/DD/YYYY): ");
    fgets(newAppointment.date, MAX_DATE_LENGTH, stdin);
    printf("Enter appointment time (HH:MM): ");
    scanf("%s", newAppointment.time);
    getchar(); // clear '\n' character from input buffer
    
    appointments[numAppointments] = newAppointment;
    numAppointments++;
    printf("\nAppointment scheduled successfully!\n\n");  
}

void viewAppointments(){
    if(numAppointments == 0){
        printf("No appointments scheduled.\n\n");
        return;
    }
    
    printf("Scheduled Appointments:\n");
    for(int i=0; i<numAppointments; i++){
        printf("%d. Name: %sDate: %sTime: %s\n", i+1, appointments[i].name, appointments[i].date, appointments[i].time);
    }
    printf("\n");
}

void cancelAppointment(){
    if(numAppointments == 0){
        printf("No appointments scheduled.\n\n");
        return;
    }
    
    printf("Enter the number of the appointment you want to cancel: ");
    int appointmentNumber;
    scanf("%d", &appointmentNumber);
    getchar(); // clear '\n' character from input buffer
    
    if(appointmentNumber < 1 || appointmentNumber > numAppointments){
        printf("Invalid appointment number.\n\n");
        return;
    }
    
    // shift appointments array to left to remove canceled appointment
    for(int i=appointmentNumber-1; i<numAppointments-1; i++){
        appointments[i] = appointments[i+1];
    }
    numAppointments--;
    printf("\nAppointment canceled successfully!\n\n");
}

int main(){
    int choice = 0;
    
    while(choice != 4){
        printMenu();
        scanf("%d", &choice);
        getchar(); // clear '\n' character from input buffer
        
        switch(choice){
            case 1:
                scheduleAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("Exiting appointment scheduler...\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    
    return 0;
}