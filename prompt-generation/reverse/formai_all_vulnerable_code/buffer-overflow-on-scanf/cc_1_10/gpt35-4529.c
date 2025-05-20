//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Appointment structure
struct Appointment {
    int date;
    int month;
    int year;
    char time[6];
    char name[30];
    char phone[15];
    char email[30];
};

// Function to display appointments
void displayAppointments(struct Appointment appointments[], int n) {
    printf("\n--- Appointments ---\n");
    for (int i=0; i<n; i++) {
        printf("Appointment %d:\n", i+1);
        printf("  Date: %d/%d/%d\n", appointments[i].date, appointments[i].month, appointments[i].year);
        printf("  Time: %s\n", appointments[i].time);
        printf("  Name: %s\n", appointments[i].name);
        printf("  Phone: %s\n", appointments[i].phone);
        printf("  Email: %s\n", appointments[i].email);
    }
}

// Function to add appointment
void addAppointment(struct Appointment appointments[], int* n) {
    printf("\n--- Add Appointment ---\n");
    printf("Enter Date (DD): ");
    scanf("%d", &appointments[*n].date);
    printf("Enter Month (MM): ");
    scanf("%d", &appointments[*n].month);
    printf("Enter Year (YYYY): ");
    scanf("%d", &appointments[*n].year);
    printf("Enter Time (HH:MM): ");
    scanf("%s", appointments[*n].time);
    printf("Enter Name: ");
    scanf("%s", appointments[*n].name);
    printf("Enter Phone Number: ");
    scanf("%s", appointments[*n].phone);
    printf("Enter Email: ");
    scanf("%s", appointments[*n].email);
    (*n)++;
    printf("Appointment added successfully!\n");
}

// Function to cancel appointment
void cancelAppointment(struct Appointment appointments[], int* n) {
    printf("\n--- Cancel Appointment ---\n");
    printf("Enter Appointment Number: ");
    int appointmentNum;
    scanf("%d", &appointmentNum);
    if (appointmentNum > 0 && appointmentNum <= *n) {
        for (int i=appointmentNum-1; i<*n-1; i++) {
            appointments[i] = appointments[i+1];
        }
        (*n)--;
        printf("Appointment cancelled successfully!\n");
    }
    else {
        printf("Invalid Appointment Number!\n");
    }
}

// Main function
int main() {
    struct Appointment appointments[100]; // Array to store appointments
    int n = 0; // Number of appointments

    while (true) {
        printf("\n--- Appointment Scheduler Menu ---\n");
        printf("1. Display Appointments\n");
        printf("2. Add Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayAppointments(appointments, n);
                break;
            case 2:
                addAppointment(appointments, &n);
                break;
            case 3:
                cancelAppointment(appointments, &n);
                break;
            case 4:
                printf("Exiting Appointment Scheduler...");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}