//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DESCRIPTION_SIZE 100
#define FILE_NAME "appointments.txt"

typedef struct {
    int id;
    char description[DESCRIPTION_SIZE];
} Appointment;

void addAppointment(Appointment *appointments, int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }
    printf("Enter appointment description: ");
    getchar(); // To consume leftover newline character
    fgets(appointments[*count].description, DESCRIPTION_SIZE, stdin);
    appointments[*count].description[strcspn(appointments[*count].description, "\n")] = 0; // Remove newline
    appointments[*count].id = *count + 1; // ID starts from 1
    (*count)++;
    printf("Appointment added!\n");
}

void viewAppointments(Appointment *appointments, int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Scheduled Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Description: %s\n", appointments[i].id, appointments[i].description);
    }
}

void deleteAppointment(Appointment *appointments, int *count) {
    int id, found = 0;
    printf("Enter appointment ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *count; i++) {
        if (appointments[i].id == id) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                appointments[j] = appointments[j + 1]; // Shift appointments
            }
            (*count)--;
            printf("Appointment ID %d deleted!\n", id);
            break;
        }
    }
    
    if (!found) {
        printf("Appointment with ID %d not found!\n", id);
    }
}

void saveAppointments(Appointment *appointments, int count) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Unable to save appointments!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s\n", appointments[i].id, appointments[i].description);
    }
    fclose(file);
    printf("Appointments saved to %s\n", FILE_NAME);
}

void loadAppointments(Appointment *appointments, int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No previous appointments found. Starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%d,%99[^\n]\n", &appointments[*count].id, appointments[*count].description) == 2) {
        (*count)++;
    }
    fclose(file);
    printf("Appointments loaded from %s\n", FILE_NAME);
}

void displayMenu() {
    printf("\nAppointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Save Appointments\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    loadAppointments(appointments, &count);
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                viewAppointments(appointments, count);
                break;
            case 3:
                deleteAppointment(appointments, &count);
                break;
            case 4:
                saveAppointments(appointments, count);
                break;
            case 5:
                saveAppointments(appointments, count);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}