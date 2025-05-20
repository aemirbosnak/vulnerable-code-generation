//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    char name[50];
    char phone[15];
    char date[11];
    char time[6];
};

void printMenu();
void addAppointment(struct Appointment appointments[], int *numAppointments);
void viewAppointments(struct Appointment appointments[], int numAppointments);
void searchAppointments(struct Appointment appointments[], int numAppointments);
void updateAppointment(struct Appointment appointments[], int numAppointments);
void deleteAppointment(struct Appointment appointments[], int *numAppointments);

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;
    int choice;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                viewAppointments(appointments, numAppointments);
                break;
            case 3:
                searchAppointments(appointments, numAppointments);
                break;
            case 4:
                updateAppointment(appointments, numAppointments);
                break;
            case 5:
                deleteAppointment(appointments, &numAppointments);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}

void printMenu() {
    printf("\nAppointment Scheduler\n");
    printf("---------------------\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Search Appointments\n");
    printf("4. Update Appointment\n");
    printf("5. Delete Appointment\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addAppointment(struct Appointment appointments[], int *numAppointments) {
    if (*numAppointments >= MAX_APPOINTMENTS) {
        printf("Unable to add appointment. Maximum capacity reached.\n");
    } else {
        printf("\nEnter appointment details:\n");
        printf("Name: ");
        fflush(stdin);
        fgets(appointments[*numAppointments].name, 50, stdin);
        appointments[*numAppointments].name[strcspn(appointments[*numAppointments].name, "\n")] = '\0';
        printf("Phone: ");
        fflush(stdin);
        fgets(appointments[*numAppointments].phone, 15, stdin);
        appointments[*numAppointments].phone[strcspn(appointments[*numAppointments].phone, "\n")] = '\0';
        printf("Date (mm/dd/yyyy): ");
        fflush(stdin);
        fgets(appointments[*numAppointments].date, 11, stdin);
        appointments[*numAppointments].date[strcspn(appointments[*numAppointments].date, "\n")] = '\0';
        printf("Time (hh:mm): ");
        fflush(stdin);
        fgets(appointments[*numAppointments].time, 6, stdin);
        appointments[*numAppointments].time[strcspn(appointments[*numAppointments].time, "\n")] = '\0';
        printf("Appointment added successfully.\n");
        *numAppointments += 1;
    }
}

void viewAppointments(struct Appointment appointments[], int numAppointments) {
    if (numAppointments == 0) {
        printf("No appointments found.\n");
    } else {
        printf("\nAll appointments:\n");
        printf("-----------------\n");
        for (int i = 0; i < numAppointments; i++) {
            printf("Appointment %d:\n", i+1);
            printf("Name: %s\n", appointments[i].name);
            printf("Phone: %s\n", appointments[i].phone);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("\n");
        }
    }
}

void searchAppointments(struct Appointment appointments[], int numAppointments) {
    char searchName[50];
    int found = 0;

    printf("\nEnter the name to search: ");
    fflush(stdin);
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, searchName) == 0) {
            printf("Appointment %d:\n", i+1);
            printf("Name: %s\n", appointments[i].name);
            printf("Phone: %s\n", appointments[i].phone);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No appointments found for %s.\n", searchName);
    }
}

void updateAppointment(struct Appointment appointments[], int numAppointments) {
    char searchName[50];
    int index = -1;

    printf("\nEnter the name of the appointment to update: ");
    fflush(stdin);
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, searchName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No appointments found for %s.\n", searchName);
    } else {
        printf("\nEnter new appointment details:\n");
        printf("Name: ");
        fflush(stdin);
        fgets(appointments[index].name, 50, stdin);
        appointments[index].name[strcspn(appointments[index].name, "\n")] = '\0';
        printf("Phone: ");
        fflush(stdin);
        fgets(appointments[index].phone, 15, stdin);
        appointments[index].phone[strcspn(appointments[index].phone, "\n")] = '\0';
        printf("Date (mm/dd/yyyy): ");
        fflush(stdin);
        fgets(appointments[index].date, 11, stdin);
        appointments[index].date[strcspn(appointments[index].date, "\n")] = '\0';
        printf("Time (hh:mm): ");
        fflush(stdin);
        fgets(appointments[index].time, 6, stdin);
        appointments[index].time[strcspn(appointments[index].time, "\n")] = '\0';
        printf("Appointment updated successfully.\n");
    }
}

void deleteAppointment(struct Appointment appointments[], int *numAppointments) {
    char searchName[50];
    int index = -1;

    printf("\nEnter the name of the appointment to delete: ");
    fflush(stdin);
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < *numAppointments; i++) {
        if (strcmp(appointments[i].name, searchName) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("No appointments found for %s.\n", searchName);
    } else {
        for (int i = index; i < *numAppointments-1; i++) {
            strcpy(appointments[i].name, appointments[i+1].name);
            strcpy(appointments[i].phone, appointments[i+1].phone);
            strcpy(appointments[i].date, appointments[i+1].date);
            strcpy(appointments[i].time, appointments[i+1].time);
        }
        *numAppointments -= 1;
        printf("Appointment deleted successfully.\n");
    }
}