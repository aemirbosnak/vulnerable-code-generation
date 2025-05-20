//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display menu options
void menu() {
    printf("\n*******************************\n");
    printf("********** MENU OPTIONS ********\n");
    printf("*******************************\n");
    printf("[1] Add a new appointment\n");
    printf("[2] View all appointments\n");
    printf("[3] View specific appointment\n");
    printf("[4] Edit an appointment\n");
    printf("[5] Delete an appointment\n");
    printf("[6] Exit\n");
}

// Define a struct to store appointments
struct Appointment {
    char name[30];
    char date[15];
    char time[10];
    char location[50];
    char description[100];
};

// Function to add a new appointment
void addAppointment(struct Appointment *appointments, int *count) {
    printf("\nEnter appointment details:\n");
    printf("Name: ");
    scanf("%s", appointments[*count].name);
    printf("Date (DD/MM/YYYY): ");
    scanf("%s", appointments[*count].date);
    printf("Time (24hr format, ex: 14:30): ");
    scanf("%s", appointments[*count].time);
    printf("Location: ");
    scanf("%s", appointments[*count].location);
    printf("Description: ");
    scanf("%s", appointments[*count].description);
    (*count)++;
    printf("\nAppointment added successfully!\n");
}

// Function to view all appointments
void viewAppointments(struct Appointment *appointments, int count) {
    if (count == 0) {
        printf("\nNo appointments found.\n");
    } else {
        printf("\nAll appointments:\n");
        printf("------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("Appointment #%d\n", i+1);
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("Location: %s\n", appointments[i].location);
            printf("Description: %s\n", appointments[i].description);
            printf("------------------------------\n");
        }
    }
}

// Function to view a specific appointment
void viewAppointment(struct Appointment *appointments, int count) {
    char name[30];
    printf("\nEnter name of appointment to view: ");
    scanf("%s", name);
    int flag = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            printf("\nAppointment found!\n");
            printf("Name: %s\n", appointments[i].name);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("Location: %s\n", appointments[i].location);
            printf("Description: %s\n", appointments[i].description);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("\nAppointment not found.\n");
    }
}

// Function to edit an appointment
void editAppointment(struct Appointment *appointments, int count) {
    char name[30];
    printf("\nEnter name of appointment to edit: ");
    scanf("%s", name);
    int flag = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            printf("\nAppointment found!\n");
            printf("Enter new details:\n");
            printf("Name: ");
            scanf("%s", appointments[i].name);
            printf("Date (DD/MM/YYYY): ");
            scanf("%s", appointments[i].date);
            printf("Time (24hr format, ex: 14:30): ");
            scanf("%s", appointments[i].time);
            printf("Location: ");
            scanf("%s", appointments[i].location);
            printf("Description: ");
            scanf("%s", appointments[i].description);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("\nAppointment not found.\n");
    } else {
        printf("\nAppointment updated successfully!\n");
    }
}

// Function to delete an appointment
void deleteAppointment(struct Appointment *appointments, int *count) {
    char name[30];
    printf("\nEnter name of appointment to delete: ");
    scanf("%s", name);
    int flag = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(name, appointments[i].name) == 0) {
            printf("\nAppointment found!\n");
            for (int j = i; j < *count - 1; j++) {
                appointments[j] = appointments[j+1];
            }
            (*count)--;
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("\nAppointment not found.\n");
    } else {
        printf("\nAppointment deleted successfully!\n");
    }
}

int main() {
    struct Appointment appointments[100];
    int count = 0;
    int choice;
    do {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment(appointments, &count);
                break;
            case 2:
                viewAppointments(appointments, count);
                break;
            case 3:
                viewAppointment(appointments, count);
                break;
            case 4:
                editAppointment(appointments, count);
                break;
            case 5:
                deleteAppointment(appointments, &count);
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}