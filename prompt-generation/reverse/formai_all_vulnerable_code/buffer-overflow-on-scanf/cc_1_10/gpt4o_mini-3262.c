//GPT-4o-mini DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to hold appointment details
typedef struct {
    char title[100];
    char date[11]; // Format: YYYY-MM-DD
    char time[6];  // Format: HH:MM
    char description[256];
} Appointment;

// Function declarations
void addAppointment(Appointment *app, int *count);
void viewAppointments(Appointment *app, int count);
void deleteAppointment(Appointment *app, int *count);
void sortAppointments(Appointment *app, int count);
int compareDates(const void *a, const void *b);
void displayMenu();

int main() {
    Appointment appointments[100];
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
                sortAppointments(appointments, count);
                break;
            case 5:
                printf("Exiting the Appointment Scheduler.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Sort Appointments\n");
    printf("5. Exit\n");
}

void addAppointment(Appointment *app, int *count) {
    if (*count >= 100) {
        printf("Cannot add more appointments. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter appointment title: ");
    getchar(); // Consume leftover newline
    fgets(app[*count].title, sizeof(app[*count].title), stdin);
    app[*count].title[strcspn(app[*count].title, "\n")] = 0; // Remove newline

    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%s", app[*count].date);

    printf("Enter appointment time (HH:MM): ");
    scanf("%s", app[*count].time);

    printf("Enter appointment description: ");
    getchar(); // Consume leftover newline
    fgets(app[*count].description, sizeof(app[*count].description), stdin);
    app[*count].description[strcspn(app[*count].description, "\n")] = 0; // Remove newline

    (*count)++;
    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment *app, int count) {
    if (count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    
    printf("\nScheduled Appointments:\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment %d: %s on %s at %s\nDescription: %s\n",
               i + 1, app[i].title, app[i].date, app[i].time, app[i].description);
    }
}

void deleteAppointment(Appointment *app, int *count) {
    if (*count == 0) {
        printf("No appointments to delete.\n");
        return;
    }

    int index;
    printf("Enter appointment number to delete (1 to %d): ", *count);
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid appointment number.\n");
        return;
    }

    for (int i = index - 1; i < *count - 1; i++) {
        app[i] = app[i + 1]; // Shift appointments left
    }
    (*count)--; // Reduce count
    printf("Appointment deleted successfully!\n");
}

void sortAppointments(Appointment *app, int count) {
    if (count == 0) {
        printf("No appointments to sort.\n");
        return;
    }

    qsort(app, count, sizeof(Appointment), compareDates);
    printf("Appointments sorted by date and time successfully!\n");
}

int compareDates(const void *a, const void *b) {
    Appointment *appA = (Appointment *)a;
    Appointment *appB = (Appointment *)b;

    int dateComparison = strcmp(appA->date, appB->date);
    if (dateComparison == 0) {
        return strcmp(appA->time, appB->time); // Compare times if dates are equal
    }
    return dateComparison;
}