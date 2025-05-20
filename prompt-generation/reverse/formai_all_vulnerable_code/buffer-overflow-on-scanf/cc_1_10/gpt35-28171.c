//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
/* A Unique C Appointment Scheduler Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store appointment details
struct appointment {
    char name[50];
    char date[20];
    char time[10];
};

// Function to print menu and get user input
int menu() {
    int choice;
    printf("\n");
    printf("Welcome to the Appointment Scheduler Program!\n");
    printf("1. Add an Appointment\n");
    printf("2. Remove an Appointment\n");
    printf("3. View Appointments\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add an appointment
void add_appointment(struct appointment *appointments, int *count) {
    printf("Add Appointment:\n");
    printf("Enter name: ");
    scanf("%s", appointments[*count].name);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", appointments[*count].date);
    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", appointments[*count].time);
    (*count)++;
}

// Function to remove an appointment
void remove_appointment(struct appointment *appointments, int *count) {
    printf("Remove Appointment:\n");
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);
    bool found = false;
    for (int i = 0; i < *count; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            found = true;
            for (int j = i; j < *count - 1; j++) {
                strcpy(appointments[j].name, appointments[j+1].name);
                strcpy(appointments[j].date, appointments[j+1].date);
                strcpy(appointments[j].time, appointments[j+1].time);
            }
            (*count)--;
            printf("Appointment %s on %s at %s removed successfully.\n", name, appointments[i].date, appointments[i].time);
            break;
        }
    }
    if (!found) {
        printf("Appointment not found.\n");
    }
}

// Function to view appointments
void view_appointments(struct appointment *appointments, int *count) {
    printf("View Appointments:\n");
    if (*count == 0) {
        printf("No appointments scheduled.\n");
    } else {
        for (int i = 0; i < *count; i++) {
            printf("%d.\n", i+1);
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
        }
    }
}

// Main function
int main() {
    int choice;
    struct appointment appointments[50];
    int count = 0;
    while (true) {
        choice = menu();
        switch(choice) {
            case 1:
                add_appointment(appointments, &count);
                break;
            case 2:
                remove_appointment(appointments, &count);
                break;
            case 3:
                view_appointments(appointments, &count);
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler Program!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}