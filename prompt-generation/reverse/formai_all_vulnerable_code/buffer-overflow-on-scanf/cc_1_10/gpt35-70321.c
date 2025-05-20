//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
/*
This program is an appointment scheduler that allows users to schedule, view, and cancel appointments in a calendar. 
The program is written in Ada Lovelace-style programming, using comments to explain each step of the code. 

Author: Ada Lovelace
Date: October 14, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define constants for maximum appointment length, and maximum number of appointments
#define MAX_LEN 50
#define MAX_APPOINTMENTS 10

// Define struct for an appointment
typedef struct {
    char date[MAX_LEN];
    char time[MAX_LEN];
    char name[MAX_LEN];
} Appointment;

// Define struct for a list of appointments
typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} AppointmentList;

/*
This function adds an appointment to the calendar
*/
void add_appointment(AppointmentList* list, char* date, char* time, char* name) {
    if (list->num_appointments < MAX_APPOINTMENTS) {
        Appointment* apt = &list->appointments[list->num_appointments++];
        strcpy(apt->date, date);
        strcpy(apt->time, time);
        strcpy(apt->name, name);
        printf("Appointment added on %s at %s for %s\n", date, time, name);
    } else {
        printf("Calendar is full!\n");
    }
}

/*
This function cancels an appointment from the calendar
*/
void cancel_appointment(AppointmentList* list, char* date, char* time, char* name) {
    bool found = false;
    for (int i = 0; i < list->num_appointments; i++) {
        Appointment* apt = &list->appointments[i];
        if (strcmp(apt->date, date) == 0 && strcmp(apt->time, time) == 0 && strcmp(apt->name, name) == 0) {
            for (int j = i; j < list->num_appointments - 1; j++) {
                list->appointments[j] = list->appointments[j + 1];
            }
            list->num_appointments--;
            found = true;
            break;
        }
    }
    if (found) {
        printf("Appointment on %s at %s for %s cancelled\n", date, time, name);
    } else {
        printf("Appointment not found\n");
    }
}

/*
This function displays all appointments in the calendar
*/
void display_appointments(AppointmentList* list) {
    printf("Calendar:\n");
    for (int i = 0; i < list->num_appointments; i++) {
        Appointment* apt = &list->appointments[i];
        printf("Date: %s Time: %s Name: %s\n", apt->date, apt->time, apt->name);
    }
}

/*
This function prints the menu options for the user
*/
void print_menu() {
    printf("\nMenu:\n");
    printf("1. Add Appointment\n");
    printf("2. Cancel Appointment\n");
    printf("3. Display Appointments\n");
    printf("4. Quit\n");
}

/*
This is the main function that runs the program
*/
int main() {
    AppointmentList list = {0};
    int choice = 0;
    char date[MAX_LEN], time[MAX_LEN], name[MAX_LEN];
    while (choice != 4) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%s", date);
                printf("Enter time (HH:MM AM/PM): ");
                scanf("%s", time);
                printf("Enter name: ");
                scanf("%s", name);
                add_appointment(&list, date, time, name);
                break;
            case 2:
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%s", date);
                printf("Enter time (HH:MM AM/PM): ");
                scanf("%s", time);
                printf("Enter name: ");
                scanf("%s", name);
                cancel_appointment(&list, date, time, name);
                break;
            case 3:
                display_appointments(&list);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}