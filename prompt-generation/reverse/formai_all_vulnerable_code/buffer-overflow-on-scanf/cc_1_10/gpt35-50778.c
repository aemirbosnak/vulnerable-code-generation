//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment{
    char patientName[30];
    int month, day, year;
    char time[10];
};

struct Appointment appointments[100]; // Maximum 100 appointments

int numOfAppointments = 0; // Current number of appointments

void newAppointment(){
    if(numOfAppointments == 100){ // Check if there is any free appointment slots
        printf("Sorry, can't create new appointment. All appointment slots are booked.\n");
        return;
    }
    struct Appointment newAppointment;
    printf("Enter patient name: ");
    scanf("%29s", &newAppointment.patientName);
    printf("Enter appointment month (1-12): ");
    scanf("%d", &newAppointment.month);
    printf("Enter appointment day (1-31): ");
    scanf("%d", &newAppointment.day);
    printf("Enter appointment year: ");
    scanf("%d", &newAppointment.year);
    printf("Enter appointment time (HH:MM AM/PM): ");
    scanf("%9s", &newAppointment.time);
    appointments[numOfAppointments] = newAppointment;
    numOfAppointments++;
    printf("Appointment created successfully.\n");
}

void listByDate(){
    if(numOfAppointments == 0){ // Check if there is any appointment created
        printf("No appointments to show.\n");
        return;
    }
    printf("Enter date (MM/DD/YYYY): ");
    char dateString[11];
    scanf("%10s", &dateString);
    int month, day, year;
    sscanf(dateString, "%d/%d/%d", &month, &day, &year);
    for(int i = 0; i < numOfAppointments; i++){
        struct Appointment currentAppointment = appointments[i];
        if(currentAppointment.month == month &&
           currentAppointment.day == day &&
           currentAppointment.year == year){
            printf("Patient name: %s\n", currentAppointment.patientName);
            printf("Appointment time: %s\n", currentAppointment.time);
        }
    }
}

void listByPatient(){
    if(numOfAppointments == 0){ // Check if there is any appointment created
        printf("No appointments to show.\n");
        return;
    }
    printf("Enter patient name: ");
    char patientName[30];
    scanf("%29s", &patientName);
    int found = 0; // To check if there is any appointment scheduled for the patient
    for(int i = 0; i < numOfAppointments; i++){
        struct Appointment currentAppointment = appointments[i];
        if(strcmp(currentAppointment.patientName, patientName) == 0){
            printf("Appointment date: %d/%d/%d\n", currentAppointment.month, currentAppointment.day, currentAppointment.year);
            printf("Appointment time: %s\n", currentAppointment.time);
            found = 1;
        }
    }
    if(!found){
        printf("No appointments to show for the patient.\n");
    }
}

void cancelAppointment(){
    if(numOfAppointments == 0){ // Check if there is any appointment created
        printf("No appointments to cancel.\n");
        return;
    }
    printf("Enter patient name: ");
    char patientName[30];
    scanf("%29s", &patientName);
    int found = 0; // To check if the given patient has any appointments
    for(int i = 0; i < numOfAppointments; i++){
        struct Appointment currentAppointment = appointments[i];
        if(strcmp(currentAppointment.patientName, patientName) == 0){
            for(int j = i; j < numOfAppointments - 1; j++){ // shifting elements to left after deleting appointment
                appointments[j] = appointments[j+1];
            }
            numOfAppointments--;
            found = 1; // mark appointment as found to show message based on flag. 
        }
    }
    if(found){
        printf("All appointments for patient %s cancelled.\n", patientName);
    }
    else{
        printf("No appointments found for patient %s.\n", patientName);
    }
}

void displayMenu(){
    printf("Appointment Scheduler\n");
    printf("------------------------\n");
    printf("1. New Appointment\n");
    printf("2. List Appointments by Date\n");
    printf("3. List Appointments by Patient\n");
    printf("4. Cancel Appointment\n");
    printf("5. Exit\n");
}

int main(){
    int userChoice;
    do{
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &userChoice);
        switch(userChoice){
            case 1:
                newAppointment();
                break;
            case 2:
                listByDate();
                break;
            case 3:
                listByPatient();
                break;
            case 4:
                cancelAppointment();
                break;
            case 5:
                exit(0); // Exit the program with success code
            default:
                printf("Invalid choice.\n");
        }
    }while(userChoice != 5);
    return 0;
}