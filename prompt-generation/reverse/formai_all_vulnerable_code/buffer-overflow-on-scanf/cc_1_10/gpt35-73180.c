//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define struct for Appointment
typedef struct {
    int id;
    char name[50];
    char date[11];
    char time[6];
} Appointment;

// Define function to display menu and get user choice
int menu() {
    int choice;
    printf("==== APPOINTMENT SCHEDULER ====\n");
    printf("1. View Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Edit Appointment\n");
    printf("4. Delete Appointment\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Define function to display all appointments
void viewAppointments(Appointment *appointments, int num_appointments) {
    printf("==== VIEW APPOINTMENTS ====\n");
    printf("ID\tName\t\tDate\t\tTime\n");
    for (int i=0; i<num_appointments; i++) {
        printf("%d\t%s\t%s\t%s\n", appointments[i].id, appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

// Define function to add a new appointment
void addAppointment(Appointment *appointments, int *num_appointments) {
    printf("==== ADD APPOINTMENT ====\n");
    Appointment newAppointment;
    newAppointment.id = *num_appointments + 1;
    printf("Enter Name: ");
    scanf("%s", newAppointment.name);
    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", newAppointment.date);
    printf("Enter Time (HH:MM): ");
    scanf("%s", newAppointment.time);
    appointments[*num_appointments] = newAppointment;
    *num_appointments += 1;
    printf("Appointment added successfully.\n");
}

// Define function to edit an appointment
void editAppointment(Appointment *appointments, int num_appointments) {
    printf("==== EDIT APPOINTMENT ====\n");
    int id;
    printf("Enter ID of Appointment to edit: ");
    scanf("%d", &id);
    for (int i=0; i<num_appointments; i++) {
        if (appointments[i].id == id) {
            printf("Enter Name (Current: %s): ", appointments[i].name);
            scanf("%s", appointments[i].name);
            printf("Enter Date (Current: %s): ", appointments[i].date);
            scanf("%s", appointments[i].date);
            printf("Enter Time (Current: %s): ", appointments[i].time);
            scanf("%s", appointments[i].time);
            printf("Appointment edited successfully.\n");
            return;
        }
    }
    printf("Appointment with ID %d not found.\n", id);
}

// Define function to delete an appointment
void deleteAppointment(Appointment *appointments, int *num_appointments) {
    printf("==== DELETE APPOINTMENT ====\n");
    int id;
    printf("Enter ID of Appointment to delete: ");
    scanf("%d", &id);
    for (int i=0; i<*num_appointments; i++) {
        if (appointments[i].id == id) {
            for (int j=i; j<*num_appointments-1; j++) {
                appointments[j] = appointments[j+1];
            }
            *num_appointments -= 1;
            printf("Appointment deleted successfully.\n");
            return;
        }
    }
    printf("Appointment with ID %d not found.\n", id);
}

// Define function to generate a random appointment
void generateAppointment(Appointment *appointments, int *num_appointments) {
    printf("==== GENERATE APPOINTMENT ====\n");
    char *names[] = {"John", "Mary", "David", "Emily", "Michael"};
    char *dates[] = {"15/09/2021", "16/09/2021", "17/09/2021", "18/09/2021", "19/09/2021"};
    char *times[] = {"10:00", "11:00", "12:00", "13:00", "14:00"};
    int name_idx = rand() % 5;
    int date_idx = rand() % 5;
    int time_idx = rand() % 5;
    Appointment newAppointment;
    newAppointment.id = *num_appointments + 1;
    strcpy(newAppointment.name, names[name_idx]);
    strcpy(newAppointment.date, dates[date_idx]);
    strcpy(newAppointment.time, times[time_idx]);
    appointments[*num_appointments] = newAppointment;
    *num_appointments += 1;
    printf("Appointment generated successfully.\n");
}

int main() {
    // Initialize array to store appointments
    Appointment appointments[100];
    int num_appointments = 0;

    // Seed random number generator
    srand(time(NULL));

    // Display menu and get user choice
    int choice = menu();

    // Process user choice until they choose to exit
    while (choice != 5) {
        switch (choice) {
            case 1:
                viewAppointments(appointments, num_appointments);
                break;
            case 2:
                addAppointment(appointments, &num_appointments);
                break;
            case 3:
                editAppointment(appointments, num_appointments);
                break;
            case 4:
                deleteAppointment(appointments, &num_appointments);
                break;
            case 6:
                generateAppointment(appointments, &num_appointments);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        choice = menu();
    }

    return 0;
}