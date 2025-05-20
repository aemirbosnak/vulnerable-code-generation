//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DATE_LENGTH 11      // Format: YYYY-MM-DD
#define TIME_LENGTH 6       // Format: HH:MM
#define FILENAME_LENGTH 256
#define TITLE_LENGTH 50

typedef struct {
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];
    char title[TITLE_LENGTH];
} Appointment;

void loadAppointments(const char *filename, Appointment *appointments, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    while (fscanf(file, "%s %s %s", appointments[*count].date, appointments[*count].time, appointments[*count].title) == 3) {
        (*count)++;
    }

    fclose(file);
}

void saveAppointments(const char *filename, Appointment *appointments, int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s %s\n", appointments[i].date, appointments[i].time, appointments[i].title);
    }

    fclose(file);
}

void addAppointment(const char *filename) {
    Appointment newAppointment;
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newAppointment.date);
    printf("Enter time (HH:MM): ");
    scanf("%s", newAppointment.time);
    printf("Enter appointment title: ");
    scanf(" %[^\n]s", newAppointment.title);  // Read string with spaces

    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    loadAppointments(filename, appointments, &count);

    appointments[count] = newAppointment;
    count++;

    saveAppointments(filename, appointments, count);
    printf("Appointment added successfully!\n");
}

void listAppointments(const char *filename) {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    loadAppointments(filename, appointments, &count);

    printf("Your appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s %s - %s\n", i + 1, appointments[i].date, appointments[i].time, appointments[i].title);
    }
}

void deleteAppointment(const char *filename) {
    int apptNumber;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &apptNumber);
    
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    loadAppointments(filename, appointments, &count);

    if (apptNumber < 1 || apptNumber > count) {
        printf("Invalid appointment number!\n");
        return;
    }

    for (int i = apptNumber - 1; i < count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    count--;

    saveAppointments(filename, appointments, count);
    printf("Appointment deleted successfully!\n");
}

void displayMenu() {
    printf("1. Add Appointment\n");
    printf("2. List Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

int main() {
    char filename[FILENAME_LENGTH];
    printf("Enter your appointments file name: ");
    scanf("%s", filename);

    int choice;
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment(filename);
                break;
            case 2:
                listAppointments(filename);
                break;
            case 3:
                deleteAppointment(filename);
                break;
            case 4:
                printf("Exiting the appointment scheduler.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}