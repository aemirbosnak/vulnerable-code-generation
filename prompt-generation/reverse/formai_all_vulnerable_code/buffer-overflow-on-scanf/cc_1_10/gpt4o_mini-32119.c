//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESC_LENGTH 256

typedef struct {
    char description[MAX_DESC_LENGTH];
    struct tm dateTime;
} Appointment;

void displayMenu() {
    printf("\n--- Appointment Scheduler ---\n");
    printf("1. Schedule Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void scheduleAppointment(Appointment *appointments, int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Appointment limit reached. Please delete an existing appointment before adding a new one.\n");
        return;
    }

    Appointment newAppointment;
    printf("Enter appointment description: ");
    getchar(); // to consume newline from previous input
    fgets(newAppointment.description, MAX_DESC_LENGTH, stdin);
    newAppointment.description[strcspn(newAppointment.description, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    char date[11];
    scanf("%10s", date);
    printf("Enter appointment time (HH:MM): ");
    char time[6];
    scanf("%5s", time);

    sscanf(date, "%d-%d-%d", &newAppointment.dateTime.tm_year, &newAppointment.dateTime.tm_mon, &newAppointment.dateTime.tm_mday);
    sscanf(time, "%d:%d", &newAppointment.dateTime.tm_hour, &newAppointment.dateTime.tm_min);
    newAppointment.dateTime.tm_year -= 1900; // Adjust year
    newAppointment.dateTime.tm_mon -= 1;     // Adjust month

    appointments[*count] = newAppointment;
    (*count)++;
    printf("Appointment scheduled successfully.\n");
}

void viewAppointments(Appointment *appointments, int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("\n--- Appointments ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s on %04d-%02d-%02d at %02d:%02d\n", 
                i + 1,
                appointments[i].description,
                appointments[i].dateTime.tm_year + 1900,
                appointments[i].dateTime.tm_mon + 1,
                appointments[i].dateTime.tm_mday,
                appointments[i].dateTime.tm_hour,
                appointments[i].dateTime.tm_min);
    }
}

void deleteAppointment(Appointment *appointments, int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    (*count)--; // Decrease count
    printf("Appointment deleted successfully.\n");
}

void saveAppointments(Appointment *appointments, int count) {
    FILE *file = fopen("appointments.txt", "w");
    if (!file) {
        perror("Unable to save appointments");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s|%d-%02d-%02d|%02d:%02d\n", 
                appointments[i].description,
                appointments[i].dateTime.tm_year + 1900,
                appointments[i].dateTime.tm_mon + 1,
                appointments[i].dateTime.tm_mday,
                appointments[i].dateTime.tm_hour,
                appointments[i].dateTime.tm_min);
    }
    
    fclose(file);
    printf("Appointments saved to appointments.txt.\n");
}

void loadAppointments(Appointment *appointments, int *count) {
    FILE *file = fopen("appointments.txt", "r");
    if (!file) {
        return;
    }

    while (*count < MAX_APPOINTMENTS && fscanf(file, "%[^|]|%d-%d-%d|%d:%d\n", 
            appointments[*count].description, 
            &appointments[*count].dateTime.tm_year, 
            &appointments[*count].dateTime.tm_mon, 
            &appointments[*count].dateTime.tm_mday, 
            &appointments[*count].dateTime.tm_hour, 
            &appointments[*count].dateTime.tm_min) == 6) {
        
        appointments[*count].dateTime.tm_year -= 1900; // Adjust year
        appointments[*count].dateTime.tm_mon -= 1; // Adjust month
        (*count)++;
    }
    
    fclose(file);
}

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    loadAppointments(appointments, &count);

    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                scheduleAppointment(appointments, &count);
                break;
            case 2:
                viewAppointments(appointments, count);
                break;
            case 3:
                deleteAppointment(appointments, &count);
                break;
            case 4:
                saveAppointments(appointments, count);
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}