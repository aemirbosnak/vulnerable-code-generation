//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define TITLE_LENGTH 50
#define DATE_LENGTH 20
#define TIME_LENGTH 10

typedef struct {
    char title[TITLE_LENGTH];
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

void display_header() {
    printf("\n=========================================\n");
    printf("      Welcome to the Appointment Scheduler!\n");
    printf("=========================================\n\n");
}

void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Oops! We've reached our appointment limit. Can't add more!\n");
        return;
    }

    printf("Enter appointment title: ");
    fgets(appointments[appointment_count].title, TITLE_LENGTH, stdin);
    appointments[appointment_count].title[strcspn(appointments[appointment_count].title, "\n")] = 0;  // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(appointments[appointment_count].date, DATE_LENGTH, stdin);
    appointments[appointment_count].date[strcspn(appointments[appointment_count].date, "\n")] = 0;  // Remove newline

    printf("Enter appointment time (HH:MM): ");
    fgets(appointments[appointment_count].time, TIME_LENGTH, stdin);
    appointments[appointment_count].time[strcspn(appointments[appointment_count].time, "\n")] = 0;  // Remove newline
    
    appointment_count++;
    printf("🎉 Appointment added successfully! 🎉\n");
}

void view_appointments() {
    printf("\nHere are your appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("%d. [%s] on %s at %s\n", i + 1, appointments[i].title, appointments[i].date, appointments[i].time);
    }
    if (appointment_count == 0) {
        printf("No appointments scheduled. Time to fill your calendar! 🌼\n");
    }
}

void delete_appointment() {
    view_appointments();
    if (appointment_count == 0) return;

    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    getchar(); // Clear the newline character from the input buffer

    if (index < 1 || index > appointment_count) {
        printf("Invalid appointment number! Please try again. 🚫\n");
        return;
    }

    for (int i = index - 1; i < appointment_count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    appointment_count--;
    printf("🗑️ Appointment deleted successfully! 🗑️\n");
}

void menu() {
    int choice;
    do {
        display_header();
        printf("What would you like to do?\n");
        printf("1. Add an appointment\n");
        printf("2. View all appointments\n");
        printf("3. Delete an appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler! 🎉 Goodbye! ✨\n");
                break;
            default:
                printf("Oops! That's not a valid option. Please try again! 🙈\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}