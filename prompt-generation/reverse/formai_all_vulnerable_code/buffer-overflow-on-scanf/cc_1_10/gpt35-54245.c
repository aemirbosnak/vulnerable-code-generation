//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//structure to hold appointment data
typedef struct{
    char name[50];
    char date[20];
    char time[10];
} Appointment;

//function to display menu options
void displayMenu(){
    printf("----------Appointment Scheduler----------\n");
    printf("1. See all appointments\n");
    printf("2. Schedule a new appointment\n");
    printf("3. Cancel an appointment\n");
    printf("4. Exit\n");
    printf("-----------------------------------------\n");
}

//function to get user input
int getUserInput(){
    int choice;
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

//function to add a new appointment
void scheduleAppointment(Appointment *appt, int *count){
    printf("Please enter the following details:\n");
    printf("Name: ");
    scanf("%s", appt[*count].name);
    printf("Date (DD/MM/YYYY): ");
    scanf("%s", appt[*count].date);
    printf("Time (HH:MM): ");
    scanf("%s", appt[*count].time);
    *count += 1;
}

//function to display all appointments
void displayAppointments(Appointment *appt, int count){
    printf("----------All Appointments----------\n");
    for(int i=0; i<count; i++){
        printf("Appointment #%d:\n", i+1);
        printf("Name: %s\n", appt[i].name);
        printf("Date: %s\n", appt[i].date);
        printf("Time: %s\n", appt[i].time);
    }
    printf("------------------------------------\n");
}

//function to cancel an appointment
void cancelAppointment(Appointment *appt, int *count){
    int apptToCancel;
    printf("Please enter the appointment number to cancel: ");
    scanf("%d", &apptToCancel);
    if(apptToCancel <= *count && apptToCancel > 0){
        for(int i=apptToCancel-1; i<*count-1; i++){
            appt[i] = appt[i+1];
        }
        *count -= 1;
        printf("Appointment #%d has been cancelled.\n", apptToCancel);
    }
    else{
        printf("Invalid appointment number.\n");
    }
}

int main(){
    Appointment appt[100];
    int count = 0;
    int choice;

    do{
        displayMenu();
        choice = getUserInput();

        switch(choice){
            case 1:
                displayAppointments(appt, count);
                break;
            case 2:
                scheduleAppointment(appt, &count);
                break;
            case 3:
                cancelAppointment(appt, &count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice != 4);

    return 0;
}