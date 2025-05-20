//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define appointment structure
typedef struct {
    int day;
    int month;
    int year;
    char description[50];
} appointment;

// function prototypes
void display_menu();
void add_appointment(appointment *appointments);
void show_appointments(appointment *appointments);

int main() {
    // create an array of appointments
    appointment appointments[10];

    int choice = 0;
    
    // loop until user chooses to exit
    while (choice != 3) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment(appointments);
                break;
            case 2:
                show_appointments(appointments);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// function to display the menu
void display_menu() {
    printf("Appointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add an Appointment\n");
    printf("2. Show Appointments\n");
    printf("3. Exit\n");
}

// function to add an appointment
void add_appointment(appointment *appointments) {
    int i;
    for (i = 0; i < 10; i++) {
        // check if appointment slot is available
        if (appointments[i].day == 0 && appointments[i].month == 0 && appointments[i].year == 0) {
            printf("Enter appointment date (dd/mm/yyyy): ");
            scanf("%d/%d/%d", &appointments[i].day, &appointments[i].month, &appointments[i].year);
            printf("Enter appointment description: ");
            scanf("%s", appointments[i].description);
            printf("Appointment added.\n");
            return;
        }
    }
    printf("All appointment slots are booked. Please try again later.\n");
}

// function to show all appointments
void show_appointments(appointment *appointments) {
    int i;
    printf("Appointments\n");
    printf("------------\n");
    printf("Date\t\tDescription\n");
    for (i = 0; i < 10; i++) {
        if (appointments[i].day != 0 && appointments[i].month != 0 && appointments[i].year != 0) {
            printf("%d/%d/%d\t%s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].description);
        }
    }
}