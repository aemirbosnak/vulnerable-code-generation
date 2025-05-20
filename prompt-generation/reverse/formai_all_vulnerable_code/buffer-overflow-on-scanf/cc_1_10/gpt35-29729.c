//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// Function prototypes
void displayWeek();
void addAppointment();
void viewAppointments();
void cancelAppointment(); 

// Global variables
char daysOfWeek[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday","Friday", "Saturday", "Sunday"};
int appointments[7][8] = {0}; // 7 days in a week and 8 hour slots in a day


int main(){
    char choice;

    printf("Welcome to our Appointment Scheduler Program! \n\n");

    do{
        printf("Please select an option: \n");
        printf("1. Display Week Schedule. \n");
        printf("2. Add Appointment. \n");
        printf("3. View Appointments. \n");
        printf("4. Cancel Appointment. \n");
        printf("5. Exit. \n");

        scanf(" %c", &choice);

        switch(choice){
            case '1':
                displayWeek();
                break;

            case '2':
                addAppointment();
                break;

            case '3':
                viewAppointments();
                break;

            case '4':
                cancelAppointment();
                break;

            case '5':
                printf("Exiting Program. \n");
                return 0;   // End program

            default:
                printf("Invalid selection. Please try again. \n");
                break;
        }
    } while(choice != '5'); // Continue looping until user selects exit option

    return 0;
}

void displayWeek(){
    printf("\nCurrent Week Schedule: \n\n");
    printf("Time         ");
    for(int i = 0; i < 7; i++){
        printf("%s    ", daysOfWeek[i]);
    }
    printf("\n");

    // Display hourly slots
    for(int i = 0; i < 8; i++){
        printf("%d:00 AM     ", i+9); // Start at 9:00 am and increment by hour
        for(int j = 0; j < 7; j++){
            if(appointments[j][i] == 0){
                printf("         ");
            } else {
                printf("X        ");
            }
        }
        printf("\n");
    }
    printf("\n");
}


void addAppointment(){
    int day, time;
    char name[20];

    printf("Please enter the day of the week (1-7, Monday-Sunday): ");
    scanf("%d", &day);
    while(day < 1 || day > 7){
        printf("Invalid day selected. Please try again: ");
        scanf("%d", &day);
    }

    printf("Please enter the hour of the appointment (9-4): ");
    scanf("%d", &time);
    while(time < 9 || time > 16){
        printf("Invalid hour selected. Please try again: ");
        scanf("%d", &time);
    }

    printf("Please enter your name: ");
    scanf("%s", name);

    // Check if appointment slot is already taken
    if(appointments[day-1][time-9] == 0){
        appointments[day-1][time-9] = 1;
        printf("Appointment for %s added at %s %d:00 AM. \n", name, daysOfWeek[day-1], time);
    } else {
        printf("Sorry, the appointment slot at %s %d:00 AM is already taken. \n", daysOfWeek[day-1], time);
    }
}


void viewAppointments(){
    int day;

    printf("Please enter the day of the week (1-7, Monday-Sunday): ");
    scanf("%d", &day);
    while(day < 1 || day > 7){
        printf("Invalid day selected. Please try again: ");
        scanf("%d", &day);
    }

    printf("\nAppointments for %s: \n", daysOfWeek[day-1]);

    // Loop through hourly slots and display names if slot is taken
    for(int i = 0; i < 8; i++){
        if(appointments[day-1][i] == 1){
            printf("%d:00 AM - ", i+9);
            for(int j = i+1; j < 8; j++){
                if(appointments[day-1][j] == 0){
                    printf("%d:00 AM \n", j+9);
                    break;
                }
            }
        }
    }
    printf("\n");
}


void cancelAppointment(){
    int day, time;
    char name[20];

    printf("Please enter the day of the week (1-7, Monday-Sunday): ");
    scanf("%d", &day);
    while(day < 1 || day > 7){
        printf("Invalid day selected. Please try again: ");
        scanf("%d", &day);
    }

    printf("Please enter the hour of the appointment (9-4): ");
    scanf("%d", &time);
    while(time < 9 || time > 16){
        printf("Invalid hour selected. Please try again: ");
        scanf("%d", &time);
    }

    printf("Please enter your name: ");
    scanf("%s", name);

    // Check if appointment slot is already taken by the user
    if(appointments[day-1][time-9] == 1 && strcmp(name, "User")){
        appointments[day-1][time-9] = 0;
        printf("Appointment for %s on %s at %d:00 AM successfully cancelled. \n", name, daysOfWeek[day-1], time);
    } else {
        printf("Sorry, you do not have an appointment on %s at %d:00 AM. \n", daysOfWeek[day-1], time);
    }
}