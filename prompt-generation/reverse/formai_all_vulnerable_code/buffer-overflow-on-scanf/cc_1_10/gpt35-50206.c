//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include<stdio.h>
#include<string.h>

// structure to hold appointment information
struct Appointment {
    char name[50];
    char email[50];
    char date[12];
    char time[6];
};

// function to add a new appointment
void addAppointment(struct Appointment appointments[], int *count) {
    printf("\nEnter the name of the person: ");
    scanf("%s", appointments[*count].name);
    printf("Enter their email address: ");
    scanf("%s", appointments[*count].email);
    printf("Enter the date of the appointment (dd-mm-yyyy): ");
    scanf("%s", appointments[*count].date);
    printf("Enter the time of the appointment (hh:mm): ");
    scanf("%s", appointments[*count].time);
    printf("\nAppointment added successfully!\n");
    (*count)++;
}

// function to display all appointments
void displayAppointments(struct Appointment appointments[], int count) {
    if (count == 0) {
        printf("\nNo appointments to display.\n");
        return;
    }
    printf("\n%-20s %-20s %-12s %-6s\n", "Name", "Email", "Date", "Time");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s %-12s %-6s\n", appointments[i].name, appointments[i].email, appointments[i].date, appointments[i].time);
    }
}

// function to search for appointments by date
void searchAppointments(struct Appointment appointments[], int count) {
    char searchDate[12];
    printf("\nEnter the date to search (dd-mm-yyyy): ");
    scanf("%s", searchDate);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(searchDate, appointments[i].date) == 0) {
            if (!found) {
                printf("\n%-20s %-20s %-12s %-6s\n", "Name", "Email", "Date", "Time");
                found = 1;
            }
            printf("%-20s %-20s %-12s %-6s\n", appointments[i].name, appointments[i].email, appointments[i].date, appointments[i].time);
        }
    }
    if (!found) {
        printf("\nNo appointments found for the given date.\n");
    }
}

int main() {
    struct Appointment appointments[50];
    int count = 0;
    int choice;
    while (1) {
        printf("\n---------- Appointment Scheduler ----------\n");
        printf("1. Add an appointment\n");
        printf("2. Display all appointments\n");
        printf("3. Search for appointments by date\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                displayAppointments(appointments, count);
                break;
            case 3:
                searchAppointments(appointments, count);
                break;
            case 4:
                printf("\nExiting the program...\n");
                return 0;
            default:
                printf("\nInvalid input. Please try again.\n");
        }
    }
    return 0;
}