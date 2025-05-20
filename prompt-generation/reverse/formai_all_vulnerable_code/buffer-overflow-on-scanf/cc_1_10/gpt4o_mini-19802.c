//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100
#define DATE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
    char date[DATE_LENGTH]; // Format: YYYY-MM-DD
    int hour; // Hour in 24-hour format
    int minute; // Minutes
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void addAppointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full! Can't add more appointments.\n");
        return;
    }
    
    Appointment new_appointment;
    
    printf("Enter your name: ");
    scanf("%s", new_appointment.name);
    
    printf("Enter appointment description: ");
    getchar(); // clear newline from buffer
    fgets(new_appointment.description, DESC_LENGTH, stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = '\0'; // Remove newline
    
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", new_appointment.date);
    
    printf("Enter appointment time (HH MM): ");
    scanf("%d %d", &new_appointment.hour, &new_appointment.minute);
    
    appointments[appointment_count++] = new_appointment;
    printf("Appointment added successfully!\n");
}

void viewAppointments() {
    if (appointment_count == 0) {
        printf("No appointments scheduled yet.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < appointment_count; ++i) {
        printf("%d. %s - %s on %s at %02d:%02d\n", 
            i + 1, 
            appointments[i].name, 
            appointments[i].description, 
            appointments[i].date, 
            appointments[i].hour, 
            appointments[i].minute);
    }
}

void cancelAppointment() {
    int index;
    
    printf("Enter the appointment number to cancel: ");
    scanf("%d", &index);
    
    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number!\n");
        return;
    }
    
    for (int i = index - 1; i < appointment_count - 1; ++i) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    
    printf("Appointment cancelled successfully!\n");
}

void displayMenu() {
    printf("\n**** Welcome to the Appointment Scheduler! ****\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Cancel Appointment\n");
    printf("4. Exit\n");
    printf("***********************************************\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}