//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 30

// Define structs
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Date date;
    Time time;
} Appointment;

// Declare global variables
Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

// Function prototypes
void addAppointment();
void deleteAppointment();
void viewAppointments();
void clearScreen();

int main() {
    clearScreen();
    printf("Welcome to the Cyberpunk Appointment Scheduler!\n\n");
    int choice;
    do {
        printf("What would you like to do?\n");
        printf("1. Add an appointment\n");
        printf("2. Delete an appointment\n");
        printf("3. View all appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                deleteAppointment();
                break;
            case 3:
                viewAppointments();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        // Pause for dramatic effect
        sleep(1);
        clearScreen();
    } while (choice != 4);
    return 0;
}

void addAppointment() {
    clearScreen();
    printf("Adding an appointment...\n");
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Sorry, the appointment list is full.\n");
        return;
    }
    Appointment newAppointment;
    printf("Enter the name of the appointment (up to %d characters): ", MAX_NAME_LENGTH);
    scanf("%s", newAppointment.name);
    printf("Enter the date of the appointment (format: DD MM YYYY): ");
    scanf("%d %d %d", &newAppointment.date.day, &newAppointment.date.month, &newAppointment.date.year);
    printf("Enter the time of the appointment (format: HH MM): ");
    scanf("%d %d", &newAppointment.time.hour, &newAppointment.time.minute);
    appointments[numAppointments++] = newAppointment;
    printf("Appointment added successfully!\n");
}

void deleteAppointment() {
    clearScreen();
    printf("Deleting an appointment...\n");
    if (numAppointments == 0) {
        printf("Sorry, there are no appointments to delete.\n");
        return;
    }
    int appointmentIndex;
    printf("Enter the index of the appointment you want to delete (1-%d): ", numAppointments);
    scanf("%d", &appointmentIndex);
    if (appointmentIndex < 1 || appointmentIndex > numAppointments) {
        printf("Invalid index. Please try again.\n");
        return;
    }
    for (int i = appointmentIndex - 1; i < numAppointments - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    numAppointments--;
    printf("Appointment deleted successfully!\n");
}

void viewAppointments() {
    clearScreen();
    printf("Viewing all appointments...\n");
    if (numAppointments == 0) {
        printf("Sorry, there are no appointments to view.\n");
        return;
    }
    printf("Index\tName\t\tDate\t\tTime\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d\t%s\t\t%d/%d/%d\t\t%d:%02d\n", i + 1, appointments[i].name, appointments[i].date.day, appointments[i].date.month, appointments[i].date.year, appointments[i].time.hour, appointments[i].time.minute);
    }
}

void clearScreen() {
    system("clear");
}