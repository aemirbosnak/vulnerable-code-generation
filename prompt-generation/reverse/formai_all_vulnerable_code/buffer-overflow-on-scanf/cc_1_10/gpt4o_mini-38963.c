//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 256

typedef struct {
    int id;
    char description[MAX_DESC_LENGTH];
    char date[11];  // format YYYY-MM-DD
    char time[6];   // format HH:MM
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointmentCount = 0;

void addAppointment();
void viewAppointments();
void deleteAppointment();
void displayMenu();
int findAppointmentById(int id);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            while (getchar() != '\n');  // clear invalid input
            continue;
        }
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                printf("Exiting... Bye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\n----- Appointment Scheduler -----\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void addAppointment() {
    if (appointmentCount >= MAX_APPOINTMENTS) {
        printf("Appointment list is full! Cannot add more.\n");
        return;
    }

    Appointment app;
    app.id = appointmentCount + 1; // Incrementing ID 

    printf("Enter description: ");
    getchar(); // clear the newline left by previous input
    fgets(app.description, MAX_DESC_LENGTH, stdin);
    app.description[strcspn(app.description, "\n")] = 0; // remove newline

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%10s", app.date);

    printf("Enter time (HH:MM): ");
    scanf("%5s", app.time);

    appointments[appointmentCount] = app;
    appointmentCount++;
    printf("Appointment added with ID %d.\n", app.id);
}

void viewAppointments() {
    if (appointmentCount == 0) {
        printf("No appointments found.\n");
    } else {
        printf("\n--- Your Appointments ---\n");
        for (int i = 0; i < appointmentCount; i++) {
            printf("ID: %d - Description: %s, Date: %s, Time: %s\n",
                   appointments[i].id,
                   appointments[i].description,
                   appointments[i].date,
                   appointments[i].time);
        }
    }
}

void deleteAppointment() {
    int id;
    printf("Enter the ID of the appointment to delete: ");
    scanf("%d", &id);

    int index = findAppointmentById(id);
    if (index == -1) {
        printf("No appointment found with ID %d.\n", id);
        return;
    }

    for (int i = index; i < appointmentCount - 1; i++) {
        appointments[i] = appointments[i + 1]; // Shift appointments left
    }
    appointmentCount--;
    printf("Appointment with ID %d has been deleted.\n", id);
}

int findAppointmentById(int id) {
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i].id == id)
            return i; // return index
    }
    return -1; // not found
}