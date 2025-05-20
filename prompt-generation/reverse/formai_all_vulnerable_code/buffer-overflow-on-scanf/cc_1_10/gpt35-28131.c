//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
// C Appointment Scheduler Program in Ada Lovelace Style

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_APPTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20
#define MAX_TIME_LENGTH 20

// Structure to hold information for an appointment
typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} appointment;

// Function prototypes
int get_selection();
void display_menu();
void add_appointment(appointment[], int*);
void delete_appointment(appointment[], int*);
void display_appointments(appointment[], int);

int main() {
    int selection;
    int num_appointments = 0;
    appointment appointments[MAX_APPTS];

    // Display menu and get user input until they choose to quit
    do {
        display_menu();
        selection = get_selection();
        switch(selection) {
            case 1: // Add appointment
                add_appointment(appointments, &num_appointments);
                break;
            case 2: // Delete appointment
                delete_appointment(appointments, &num_appointments);
                break;
            case 3: // Display appointments
                display_appointments(appointments, num_appointments);
                break;
            case 4: // Quit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    } while(selection != 4);

    return 0;
}

// Function to display the menu options
void display_menu() {
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add Appointment\n");
    printf("2. Delete Appointment\n");
    printf("3. Display Appointments\n");
    printf("4. Quit\n");
}

// Function to get user selection
int get_selection() {
    int selection;
    printf("Enter selection: ");
    scanf("%d", &selection);
    return selection;
}

// Function to add an appointment
void add_appointment(appointment appts[], int *num_appts) {
    if (*num_appts < MAX_APPTS) {
        printf("Enter name: ");
        scanf("%s", appts[*num_appts].name);
        printf("Enter date (MM/DD/YYYY): ");
        scanf("%s", appts[*num_appts].date);
        printf("Enter time (HH:MM AM/PM): ");
        scanf("%s", appts[*num_appts].time);
        (*num_appts)++;
    }
    else {
        printf("Error: maximum number of appointments reached.\n");
    }
}

// Function to delete an appointment
void delete_appointment(appointment appts[], int *num_appts) {
    char name[MAX_NAME_LENGTH];
    int i, index = -1;
    printf("Enter name to delete: ");
    scanf("%s", name);

    // Search for the appointment with the given name
    for (i = 0; i < *num_appts; i++) {
        if (strcmp(appts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Shift all appointments after the one to delete to the left
        for (i = index; i < (*num_appts)-1; i++) {
            strcpy(appts[i].name, appts[i+1].name);
            strcpy(appts[i].date, appts[i+1].date);
            strcpy(appts[i].time, appts[i+1].time);
        }
        (*num_appts)--;
        printf("Appointment for %s on %s at %s deleted.\n", name, appts[index].date, appts[index].time);
    }
    else {
        printf("Error: appointment not found.\n");
    }
}

// Function to display all appointments
void display_appointments(appointment appts[], int num_appts) {
    int i;
    printf("Appointments:\n");
    for (i = 0; i < num_appts; i++) {
        printf("%s on %s at %s\n", appts[i].name, appts[i].date, appts[i].time);
    }
}