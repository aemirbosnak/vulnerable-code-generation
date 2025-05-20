//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_DESCRIPTION 100

typedef struct {
    char description[MAX_DESCRIPTION];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
} Appointment;

void addAppointment(Appointment *appointments, int *count);
void viewAppointments(Appointment *appointments, int count);
void deleteAppointment(Appointment *appointments, int *count);
void clearBuffer();

int main() {
    Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("Appointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear the input buffer

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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void addAppointment(Appointment *appointments, int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Appointment list is full!\n");
        return;
    }
    
    printf("Enter appointment description: ");
    fgets(appointments[*count].description, MAX_DESCRIPTION, stdin);
    appointments[*count].description[strcspn(appointments[*count].description, "\n")] = 0; // Remove newline character

    printf("Enter appointment date (YYYY-MM-DD): ");
    fgets(appointments[*count].date, 11, stdin);
    appointments[*count].date[strcspn(appointments[*count].date, "\n")] = 0; // Remove newline character

    printf("Enter appointment time (HH:MM): ");
    fgets(appointments[*count].time, 6, stdin);
    appointments[*count].time[strcspn(appointments[*count].time, "\n")] = 0; // Remove newline character
    
    (*count)++;
    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment *appointments, int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment %d: %s on %s at %s\n", 
               i + 1, appointments[i].description, appointments[i].date, appointments[i].time);
    }
    printf("\n");
}

void deleteAppointment(Appointment *appointments, int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    
    int index;
    viewAppointments(appointments, *count);
    
    printf("Enter the appointment number to delete: ");
    scanf("%d", &index);
    clearBuffer();
    
    if (index < 1 || index > *count) {
        printf("Invalid appointment number!\n");
        return;
    }
    
    for (int i = index - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    
    (*count)--;
    printf("Appointment deleted successfully!\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}