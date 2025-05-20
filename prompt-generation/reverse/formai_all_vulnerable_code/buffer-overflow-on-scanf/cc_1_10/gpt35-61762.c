//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Structure definition for the appointments */
struct appointment {
    char patient_name[50];
    int month;
    int day;
    int year;
    int hour;
    int minute;
};

/* Function prototypes */
void display_menu();
bool is_valid_date(int, int, int);
bool is_valid_time(int, int);
void add_appointment(struct appointment[], int*);
void display_appointments(struct appointment[], int);
void search_appointment(struct appointment[], int);

/* Main function */
int main() {
    int choice, num_appointments = 0;
    struct appointment appointments[100];
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_appointment(appointments, &num_appointments);
                break;
            case 2:
                display_appointments(appointments, num_appointments);
                break;
            case 3:
                search_appointment(appointments, num_appointments);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}

/* Function to display the menu */
void display_menu() {
    printf("*********** Appointment Scheduler ***********\n");
    printf("1. Add appointment\n");
    printf("2. Display appointments\n");
    printf("3. Search appointment\n");
    printf("4. Exit\n");
}

/* Function to check if the provided date is valid */
bool is_valid_date(int month, int day, int year) {
    if(month < 1 || month > 12)
        return false;
    if(day < 1 || day > 31)
        return false;
    if((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) 
        return false;
    if(month == 2) {
        if(day > 29)
            return false;
        if(day == 29 && (year % 400 != 0 && (year % 4 != 0 || year % 100 == 0)))
            return false;
    }
    return true;
}

/* Function to check if the provided time is valid */
bool is_valid_time(int hour, int minute) {
    if(hour < 0 || hour > 23)
        return false;
    if(minute < 0 || minute > 59)
        return false;
    return true;
}

/* Function to add a new appointment */
void add_appointment(struct appointment appointments[], int *num_appointments) {
    char patient_name[50];
    int month, day, year, hour, minute;
    bool valid_input = true;
    
    printf("Enter patient name: ");
    scanf(" %[^\n]", patient_name);
    
    printf("Enter appointment date (in MM/DD/YYYY format): ");
    scanf("%d/%d/%d", &month, &day, &year);
    valid_input &= is_valid_date(month, day, year);
    
    printf("Enter appointment time (in HH:MM 24-hour format): ");
    scanf("%d:%d", &hour, &minute);
    valid_input &= is_valid_time(hour, minute);
    
    if(valid_input) {
        strcpy(appointments[*num_appointments].patient_name, patient_name);
        appointments[*num_appointments].month = month;
        appointments[*num_appointments].day = day;
        appointments[*num_appointments].year = year;
        appointments[*num_appointments].hour = hour;
        appointments[*num_appointments].minute = minute;
        (*num_appointments)++;
        printf("Appointment added successfully!\n");
    }
    else {
        printf("Invalid input. Please try again.\n");
    }
}

/* Function to display all appointments */
void display_appointments(struct appointment appointments[], int num_appointments) {
    if(num_appointments == 0) {
        printf("No appointments found.\n");
        return;
    }
    printf("\n*********** Appointments ***********\n");
    printf("%-20s %-20s %-20s %-20s %-20s\n", "Patient name", "Date", "Time", "Month", "Year");
    for(int i = 0; i < num_appointments; i++) {
        printf("%-20s %02d/%02d/%04d %02d:%02d %10d %10d\n", appointments[i].patient_name, appointments[i].month, appointments[i].day, appointments[i].year, appointments[i].hour, appointments[i].minute, appointments[i].month, appointments[i].year);
    }
    printf("\n");
}

/* Function to search for an appointment */
void search_appointment(struct appointment appointments[], int num_appointments) {
    char patient_name[50];
    bool appointment_found = false;
    
    printf("Enter patient name: ");
    scanf(" %[^\n]", patient_name);
    
    for(int i = 0; i < num_appointments; i++) {
        if(strcmp(appointments[i].patient_name, patient_name) == 0) {
            printf("\n*********** Search result ***********\n");
            printf("Patient name: %s\n", appointments[i].patient_name);
            printf("Date: %02d/%02d/%04d\n", appointments[i].month, appointments[i].day, appointments[i].year);
            printf("Time: %02d:%02d\n", appointments[i].hour, appointments[i].minute);
            printf("\n");
            appointment_found = true;
        }
    }
    
    if(!appointment_found) {
        printf("No appointments found for patient '%s'.\n", patient_name);
    }
}