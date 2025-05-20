//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
// Appointment Scheduler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for storing appointment information
typedef struct {
    char name[50];
    char date[11];
    char time[6];
} Appointment;

// Function to print appointment information
void printAppointment(Appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Date: %s\n", appointment->date);
    printf("Time: %s\n", appointment->time);
}

// Function to add appointment to the schedule
void addAppointment(Appointment *appointment) {
    FILE *file = fopen("appointments.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(file, "%s %s %s\n", appointment->name, appointment->date, appointment->time);
    fclose(file);
}

// Function to delete appointment from the schedule
void deleteAppointment(Appointment *appointment) {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strcmp(line, appointment->name) == 0) {
            continue;
        }
        fprintf(temp, "%s", line);
    }
    fclose(file);
    fclose(temp);
    remove("appointments.txt");
    rename("temp.txt", "appointments.txt");
}

// Function to search for appointment in the schedule
void searchAppointment(Appointment *appointment) {
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strcmp(line, appointment->name) == 0) {
            printf("Appointment found!\n");
            printAppointment(appointment);
            return;
        }
    }
    printf("Appointment not found!\n");
}

int main() {
    Appointment appointment;
    int choice;
    do {
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. Search appointment\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter appointment information:\n");
                scanf("%s %s %s", appointment.name, appointment.date, appointment.time);
                addAppointment(&appointment);
                break;
            case 2:
                printf("Enter appointment name to delete:\n");
                scanf("%s", appointment.name);
                deleteAppointment(&appointment);
                break;
            case 3:
                printf("Enter appointment name to search:\n");
                scanf("%s", appointment.name);
                searchAppointment(&appointment);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}