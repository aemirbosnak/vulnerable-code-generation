//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct appointment{ // creating a structure to hold appointment data
    char name[50];
    char date[12];
    char time[12];
}Appointment;

void addAppointment(Appointment **appointments, int *numAppointments); // function to add appointment
void viewAppointments(Appointment *appointments, int numAppointments); // function to view appointments
void exitProgram(); // function to exit program

int main(){
    Appointment *appointments = NULL; // initializing a pointer to store appointment data
    int menuChoice = 0, numAppointments = 0; // initializing variables to store user input
    do {
        printf("\n\n\t\t*****Appointment Scheduler*****\n\n");
        printf("\t\t1. Add Appointment\n");
        printf("\t\t2. View Appointments\n");
        printf("\t\t3. Exit\n\n");
        printf("\t\tEnter your choice (1-3): ");
        scanf("%d", &menuChoice);
        switch(menuChoice){ // using switch statement to call appropriate function based on user input
            case 1:
                addAppointment(&appointments, &numAppointments); // passing a pointer to pointer to allow reallocation of memory as needed
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                exitProgram();
            default:
                printf("\n\t\tInvalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    } while (menuChoice != 3); // repeating the menu until user chooses to exit
    free(appointments); // freeing memory
    return 0;
}

void addAppointment(Appointment **appointments, int *numAppointments){
    *numAppointments = *numAppointments + 1; // incrementing the number of appointments
    *appointments = realloc(*appointments, *numAppointments * sizeof(Appointment)); // reallocating memory to allow for addition of new appointment
    printf("\n\t\tAppointment %d\n", *numAppointments);
    printf("\n\t\tEnter name: ");
    scanf("%s", (*appointments + *numAppointments - 1)->name);
    printf("\n\t\tEnter date (DD/MM/YYYY): ");
    scanf("%s", (*appointments + *numAppointments - 1)->date);
    printf("\n\t\tEnter time (HH:MM AM/PM): ");
    scanf("%s", (*appointments + *numAppointments - 1)->time);
    printf("\n\t\tAppointment added successfully!\n");
}

void viewAppointments(Appointment *appointments, int numAppointments){
    if(numAppointments == 0){
        printf("\n\t\tYou have no appointments scheduled.\n");
        return;
    }
    printf("\n\t\tYour Appointments\n");
    printf("\t\t---------------------------------------\n");
    printf("\t\t%-20s | %-12s | %-12s\n", "Name", "Date", "Time");
    printf("\t\t---------------------------------------\n");
    for(int i=0; i<numAppointments; i++){
        printf("\t\t%-20s | %-12s | %-12s\n", (appointments + i)->name, (appointments + i)->date, (appointments + i)->time);
    }
}

void exitProgram(){
    printf("\n\n\t\tThank you for using the Appointment Scheduler!\n");
    exit(0); // exiting the program
}