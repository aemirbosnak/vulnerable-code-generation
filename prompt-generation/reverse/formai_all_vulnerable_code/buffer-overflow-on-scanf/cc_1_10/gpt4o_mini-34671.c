//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define DATE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[DATE_LENGTH];
    char time[10];
} Appointment;

void addAppointment(Appointment appointments[], int *count);
void viewAppointments(Appointment appointments[], int count);
void deleteAppointment(Appointment appointments[], int *count);
void findAppointment(Appointment appointments[], int count);
void displayMenu();

int main() {
    Appointment appointments[MAX_APPOINTMENTS] = {0};
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
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
                findAppointment(appointments, count);
                break;
            case 5:
                printf("Exiting the Appointment Scheduler. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n---- Appointment Scheduler ----\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Find Appointment\n");
    printf("5. Exit\n");
}

void addAppointment(Appointment appointments[], int *count) {
    if (*count >= MAX_APPOINTMENTS) {
        printf("Cannot add more appointments. Limit reached!\n");
        return;
    }
    printf("Enter the patient's name: ");
    scanf(" %[^\n]%*c", appointments[*count].name);
    printf("Enter the appointment date (YYYY-MM-DD): ");
    scanf(" %[^\n]%*c", appointments[*count].date);
    printf("Enter the appointment time (HH:MM): ");
    scanf(" %[^\n]%*c", appointments[*count].time);
    (*count)++;
    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("\n--- Appointments ---\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].name);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("----------------------\n");
    }
}

void deleteAppointment(Appointment appointments[], int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }
    int num;
    printf("Enter the appointment number to delete (1 to %d): ", *count);
    scanf("%d", &num);
    if (num < 1 || num > *count) {
        printf("Invalid appointment number!\n");
        return;
    }
    for (int i = num - 1; i < *count - 1; i++) {
        appointments[i] = appointments[i + 1];
    }
    (*count)--;
    printf("Appointment deleted successfully!\n");
}

void findAppointment(Appointment appointments[], int count) {
    if (count == 0) {
        printf("No appointments to search.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter the patient's name to find: ");
    scanf(" %[^\n]%*c", name);
    int found = 0;
    
    printf("\nSearching for appointments for %s...\n", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("Appointment found!\n");
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No appointments found for %s.\n", name);
    }
}