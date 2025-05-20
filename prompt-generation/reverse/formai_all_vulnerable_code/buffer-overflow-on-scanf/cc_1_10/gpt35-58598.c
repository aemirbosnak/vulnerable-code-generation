//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 12
#define MAX_DATE_LENGTH 11
#define MAX_TIME_LENGTH 6

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void printMenu();
void addAppointment();
void viewAppointments();
void searchAppointments();
void deleteAppointment();

int main() {
    int choice = 0;
    printf("Welcome to Appointment Scheduler!\n\n");
    do {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                searchAppointments();
                break;
            case 4:
                deleteAppointment();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);
    return 0;
}

void printMenu() {
    printf("Please choose an option:\n");
    printf("1. Add appointment\n");
    printf("2. View appointments\n");
    printf("3. Search appointments\n");
    printf("4. Delete appointment\n");
    printf("5. Exit\n");
    printf("Choice: ");
}

void addAppointment() {
    printf("\nAdding new appointment:\n");
    if(numAppointments == MAX_APPOINTMENTS) {
        printf("Appointment scheduler is full. Cannot add new appointments.\n");
        return;
    }
    Appointment newAppointment;
    
    printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH-1);
    scanf("%s", newAppointment.name);
    getchar(); // clears input buffer
    printf("Enter phone number (up to %d characters): ", MAX_PHONE_LENGTH-1);
    fgets(newAppointment.phone, MAX_PHONE_LENGTH, stdin);
    printf("Enter date in mm/dd/yyyy format: ");
    scanf("%s", newAppointment.date);
    printf("Enter time in 24 hour format (e.g. 13:30): ");
    scanf("%s", newAppointment.time);
    
    appointments[numAppointments++] = newAppointment;
    printf("Appointment added!\n\n");
}

void viewAppointments() {
    printf("\nViewing appointments:\n");
    if(numAppointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }
    for(int i=0; i<numAppointments; i++) {
        Appointment a = appointments[i];
        printf("Appointment %d:\n", i+1);
        printf("Name: %s\n", a.name);
        printf("Phone: %s", a.phone);
        printf("Date: %s\n", a.date);
        printf("Time: %s\n\n", a.time);
    }
}

void searchAppointments() {
    printf("\nSearching for appointments:\n");
    if(numAppointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }
    printf("Enter search term (name or phone number): ");
    char searchTerm[MAX_PHONE_LENGTH];
    char termUpper[MAX_PHONE_LENGTH];
    scanf("%s", searchTerm);
    for(int i=0; i<strlen(searchTerm); i++) {
        termUpper[i] = toupper(searchTerm[i]);
    }
    printf("\nSearch results:\n");
    for(int i=0, found=0; i<numAppointments; i++) {
        Appointment a = appointments[i];
        char nameUpper[MAX_NAME_LENGTH];
        for(int j=0; j<strlen(a.name); j++) {
            nameUpper[j] = toupper(a.name[j]);
        }
        if(strstr(nameUpper, termUpper) != NULL || strstr(a.phone, searchTerm) != NULL) {
            found = 1;
            printf("Appointment %d:\n", i+1);
            printf("Name: %s\n", a.name);
            printf("Phone: %s", a.phone);
            printf("Date: %s\n", a.date);
            printf("Time: %s\n\n", a.time);
        }
        if(i == numAppointments-1 && !found) {
            printf("No appointments found.\n\n");
        }
    }
}

void deleteAppointment() {
    printf("\nDeleting appointment:\n");
    if(numAppointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }
    viewAppointments();
    int appointmentToDelete = 0;
    printf("Enter appointment number to delete: ");
    scanf("%d", &appointmentToDelete);
    if(appointmentToDelete < 1 || appointmentToDelete > numAppointments) {
        printf("Invalid appointment number.\n\n");
        return;
    }
    for(int i=appointmentToDelete-1; i<numAppointments-1; i++) {
        appointments[i] = appointments[i+1];
    }
    numAppointments--;
    printf("Appointment deleted.\n\n");
}