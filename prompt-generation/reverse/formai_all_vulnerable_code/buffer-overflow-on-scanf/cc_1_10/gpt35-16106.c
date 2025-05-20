//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include<stdio.h>
#include<string.h>

// MAX_CAPACITY represents the maximum number of slots available in the scheduler
#define MAX_CAPACITY 10

// Structure to store appointment information
typedef struct {
    int day, month, year;
    int hour, minute;
    char name[50];
} Appointment;

// Function to add a new appointment to the scheduler
void addNewAppointment(Appointment appointments[], int* numAppointments) {
    if (*numAppointments >= MAX_CAPACITY) {
        printf("Scheduler is full. Cannot add appointment.\n");
        return;
    }
    printf("Enter appointment details:\n");
    printf("Day: ");
    scanf("%d", &appointments[*numAppointments].day);
    printf("Month: ");
    scanf("%d", &appointments[*numAppointments].month);
    printf("Year: ");
    scanf("%d", &appointments[*numAppointments].year);
    printf("Hour: ");
    scanf("%d", &appointments[*numAppointments].hour);
    printf("Minute: ");
    scanf("%d", &appointments[*numAppointments].minute);
    printf("Name: ");
    scanf("%s", appointments[*numAppointments].name);
    (*numAppointments)++;
}

// Function to print all appointments in the scheduler
void viewAllAppointments(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Scheduled appointments:\n");
    printf("Date\t\t Time\t\t Name\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d/%d/%d\t %02d:%02d\t %s\n", appointments[i].day, 
            appointments[i].month, appointments[i].year, appointments[i].hour, 
            appointments[i].minute, appointments[i].name);
    }
}

// Function to search for an appointment by name
void searchAppointmentByName(Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    int found = 0;
    printf("Result(s):\n");
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, searchName) == 0) {
            printf("%d/%d/%d\t %02d:%02d\t %s\n", appointments[i].day, 
                appointments[i].month, appointments[i].year, appointments[i].hour, 
                appointments[i].minute, appointments[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No appointment found with name '%s'.\n", searchName);
    }
}

// Main function to run the scheduler
int main() {
    // Array of appointments
    Appointment appointments[MAX_CAPACITY];
    // Number of appointments
    int numAppointments = 0;

    while (1) {
        // Print scheduler menu
        printf("\nAppointment Scheduler\n");
        printf("---------------------\n");
        printf("1. Add new appointment\n");
        printf("2. View all appointments\n");
        printf("3. Search appointment by name\n");
        printf("4. Exit\n");
        printf("Enter option: ");

        int option;
        scanf("%d", &option);

        switch(option) {
            case 1:
                addNewAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAllAppointments(appointments, numAppointments);
                break;
            case 3:
                searchAppointmentByName(appointments, numAppointments);
                break;
            case 4:
                printf("Exiting scheduler. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please enter again.\n");
        }
    }

    return 0;
}