//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char date[11];  // Format: YYYY-MM-DD
    char time[6];   // Format: HH:MM
    char notes[100];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void clearScreen() {
    printf("\033[H\033[J");
}

void displayAppointments() {
    clearScreen();
    printf("Current Appointments:\n");
    printf("---------------------\n");
    if (appointment_count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Notes: %s\n", appointments[i].notes);
        printf("---------------------\n");
    }
}

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Maximum limit reached.\n");
        return;
    }
    Appointment new_appointment;
    
    printf("Enter the name of the person: ");
    scanf(" %[^\n]", new_appointment.name);
    
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    
    printf("Enter the time (HH:MM): ");
    scanf("%s", new_appointment.time);
    
    printf("Enter notes (optional): ");
    scanf(" %[^\n]", new_appointment.notes);
    
    appointments[appointment_count] = new_appointment;
    appointment_count++;
    
    printf("Appointment added successfully!\n");
}

void deleteAppointment() {
    int index;
    displayAppointments();

    if (appointment_count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("Appointment deleted successfully!\n");
}

void findAppointment() {
    char name[50];
    printf("Enter name to search for appointments: ");
    scanf(" %[^\n]", name);
    
    int found = 0;
    for (int i = 0; i < appointment_count; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("Appointment %d:\n", i + 1);
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("Notes: %s\n", appointments[i].notes);
            printf("---------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No appointments found for %s.\n", name);
    }
}

void showMenu() {
    clearScreen();
    printf("Appointment Scheduler\n");
    printf("----------------------\n");
    printf("1. Add Appointment\n");
    printf("2. Delete Appointment\n");
    printf("3. View Appointments\n");
    printf("4. Find Appointment by Name\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                deleteAppointment();
                break;
            case 3:
                displayAppointments();
                printf("Press Enter to continue...");
                getchar(); // consume leftover newline
                getchar(); // wait for user to press Enter
                break;
            case 4:
                findAppointment();
                printf("Press Enter to continue...");
                getchar(); // consume leftover newline
                getchar(); // wait for user to press Enter
                break;
            case 5:
                printf("Exiting the scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}