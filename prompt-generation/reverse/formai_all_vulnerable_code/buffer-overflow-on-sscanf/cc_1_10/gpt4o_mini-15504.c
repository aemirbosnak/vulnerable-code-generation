//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_TITLE_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct tm date_time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int appointment_count = 0;

// Function to add a new appointment
void add_appointment() {
    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("Oops! You've reached the limit of appointments!\n");
        return;
    }

    Appointment new_appointment;

    printf("What is the title of your appointment? ");
    fgets(new_appointment.title, sizeof(new_appointment.title), stdin);
    new_appointment.title[strcspn(new_appointment.title, "\n")] = 0; // Remove newline

    printf("Could you provide a brief description? ");
    fgets(new_appointment.description, sizeof(new_appointment.description), stdin);
    new_appointment.description[strcspn(new_appointment.description, "\n")] = 0; // Remove newline

    printf("When do you want to schedule it? Please enter date (YYYY-MM-DD): ");
    char date_str[11];
    fgets(date_str, sizeof(date_str), stdin);
    date_str[strcspn(date_str, "\n")] = 0; // Remove newline
    
    printf("And what time? Please enter time (HH:MM): ");
    char time_str[6];
    fgets(time_str, sizeof(time_str), stdin);
    time_str[strcspn(time_str, "\n")] = 0; // Remove newline

    // Combine date and time into a single struct tm
    sscanf(date_str, "%d-%d-%d", &new_appointment.date_time.tm_year, 
                                   &new_appointment.date_time.tm_mon, 
                                   &new_appointment.date_time.tm_mday);
    sscanf(time_str, "%d:%d", &new_appointment.date_time.tm_hour, 
                                 &new_appointment.date_time.tm_min);
    
    new_appointment.date_time.tm_year -= 1900;  // adjust year
    new_appointment.date_time.tm_mon -= 1;      // adjust month
    new_appointment.date_time.tm_isdst = -1;    // let mktime determine if DST is in effect

    appointments[appointment_count++] = new_appointment;
    printf("Your appointment was scheduled successfully!\n");
}

// Function to display all scheduled appointments
void view_appointments() {
    if (appointment_count == 0) {
        printf("Hmm, it seems like you have no appointments scheduled. Why not schedule one now?\n");
        return;
    }

    printf("Here are your scheduled appointments:\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf(" - Title: %s\n", appointments[i].title);
        printf(" - Description: %s\n", appointments[i].description);
        printf(" - Date and Time: %s", asctime(&appointments[i].date_time));
    }
}

// Function to display the menu and handle user input
void display_menu() {
    int choice;

    while (1) {
        printf("\n=== Appointment Scheduler ===\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("What would you like to do? Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character after scanf

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("Thank you for using the Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Hmm, that’s not a valid choice. Please try again!\n");
        }
    }
}

int main() {
    printf("Welcome to the Appointment Scheduler! Ready to organize your time?\n");
    display_menu();
    return 0;
}