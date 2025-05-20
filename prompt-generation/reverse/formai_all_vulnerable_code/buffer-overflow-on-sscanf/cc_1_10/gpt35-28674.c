//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if the input string is a valid date
bool isDateValid(char* string){
    int day, month, year;
    if(sscanf(string, "%d/%d/%d", &day, &month, &year) != 3)
        return false;
    if(month < 1 || month > 12)
        return false;
    if(day < 1 || day > 31)
        return false;
    if((month == 4 || month == 6 || month == 9 || month == 11) && (day == 31))
        return false;
    if(month == 2){
        if(day > 29)
            return false;
        if(day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
            return false;
    }
    return true;
}

// Function to check if the input string is a valid time
bool isTimeValid(char* string){
    int hours, minutes;
    if(sscanf(string, "%d:%d", &hours, &minutes) != 2)
        return false;
    if(hours < 0 || hours > 23)
        return false;
    if(minutes < 0 || minutes > 59)
        return false;
    return true;
}

// Function to check if the input string is a valid name
bool isNameValid(char* string){
    for(int i=0; i<strlen(string); i++){
        if(!isalpha(string[i]) && string[i] != ' ')
            return false;
    }
    return true;
}

// Struct for an appointment
typedef struct Appointment{
    char date[11];
    char time[6];
    char name[50];
} Appointment;

int main(){
    int numAppointments = 0;
    int maxAppointments = 10;
    Appointment* appointments = (Appointment*)malloc(maxAppointments * sizeof(Appointment));
    printf("Welcome to the appointment scheduler!\n");
    while(true){
        printf("Select an option:\n");
        printf("[1] Add Appointment\n");
        printf("[2] View Appointments\n");
        printf("[3] Exit\n");
        int choice;
        scanf("%d", &choice);
        if(choice == 1){
            printf("Enter date (dd/mm/yyyy): ");
            char date[11];
            scanf("%s", date);
            fflush(stdin);
            if(!isDateValid(date)){
                printf("Invalid date format!\n");
                continue;
            }
            printf("Enter time (hh:mm): ");
            char time[6];
            scanf("%s", time);
            fflush(stdin);
            if(!isTimeValid(time)){
                printf("Invalid time format!\n");
                continue;
            }
            printf("Enter name: ");
            char name[50];
            scanf("%[^\n]", name);
            fflush(stdin);
            if(!isNameValid(name)){
                printf("Invalid name format!\n");
                continue;
            }
            if(numAppointments == maxAppointments){
                maxAppointments *= 2;
                appointments = (Appointment*)realloc(appointments, maxAppointments * sizeof(Appointment));
            }
            strcpy(appointments[numAppointments].date, date);
            strcpy(appointments[numAppointments].time, time);
            strcpy(appointments[numAppointments].name, name);
            printf("Appointment added!\n");
            numAppointments++;
        }
        else if(choice == 2){
            if(numAppointments == 0){
                printf("No appointments scheduled.\n");
                continue;
            }
            printf("Date\t\tTime\t\tName\n");
            for(int i=0; i<numAppointments; i++){
                printf("%s\t%s\t%s\n", appointments[i].date, appointments[i].time, appointments[i].name);
            }
        }
        else if(choice == 3){
            printf("Exiting program. Goodbye!\n");
            break;
        }
        else{
            printf("Invalid choice. Please try again.\n");
        }
    }
    free(appointments);
    return 0;
}