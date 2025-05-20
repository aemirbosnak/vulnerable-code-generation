//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define max number of appointments for the day
#define MAX_APPOINTMENTS 10

// define struct for appointment
typedef struct {
    char name[50];
    char time[10];
} Appointment;

// function to display the menu
void display_menu() {
    printf("1. Add appointment\n");
    printf("2. View appointments\n");
    printf("3. Delete appointment\n");
    printf("4. Exit\n");
}

// function to get user input for menu option
int get_menu_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to add an appointment
void add_appointment(Appointment *appointments, int *num_appointments) {
    // check if appointments list is full
    if (*num_appointments == MAX_APPOINTMENTS) {
        printf("No more appointments can be added for the day.\n");
        return;
    }
    // get input for appointment name and time
    printf("Enter appointment name: ");
    scanf("%s", appointments[*num_appointments].name);
    printf("Enter appointment time (24 hour format e.g. 14:30): ");
    scanf("%s", appointments[*num_appointments].time);
    (*num_appointments)++;
    printf("Appointment added successfully!\n");
}

// function to view all appointments
void view_appointments(Appointment *appointments, int num_appointments) {
    // check if there are any appointments for the day
    if (num_appointments == 0) {
        printf("No appointments for the day.\n");
        return;
    }
    // display all appointments
    printf("Appointments for the day:\n");
    printf("%-20s %-10s\n", "Appointment Name", "Time");
    for (int i = 0; i < num_appointments; i++) {
        printf("%-20s %-10s\n", appointments[i].name, appointments[i].time);
    }
}

// function to delete an appointment
void delete_appointment(Appointment *appointments, int *num_appointments) {
    char name[50];
    // get input for appointment name to be deleted
    printf("Enter appointment name to be deleted: ");
    scanf("%s", name);
    // search for appointment with given name
    int index = -1;
    for (int i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    // if appointment not found
    if (index == -1) {
        printf("Appointment not found.\n");
        return;
    }
    // delete the appointment by shifting all appointments after it to the left
    for (int i = index; i < *num_appointments - 1; i++) {
        strcpy(appointments[i].name, appointments[i + 1].name);
        strcpy(appointments[i].time, appointments[i + 1].time);
    }
    (*num_appointments)--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    // initialize appointments array and number of appointments
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    // display the menu and get user input
    int choice;
    do {
        display_menu();
        choice = get_menu_choice();
        switch (choice) {
            case 1: // add appointment
                add_appointment(appointments, &num_appointments);
                break;
            case 2: // view appointments
                view_appointments(appointments, num_appointments);
                break;
            case 3: // delete appointment
                delete_appointment(appointments, &num_appointments);
                break;
            case 4: // exit program
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}