//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to display the menu
void displayMenu() {
    printf("\nAppointment Scheduler Menu:\n");
    printf("1. Add an appointment\n");
    printf("2. View appointments\n");
    printf("3. Delete an appointment\n");
    printf("4. Exit\n");
}

// Function to add an appointment
void addAppointment() {
    char name[50];
    char date[20];
    char time[20];
    printf("\nEnter the name of the person: ");
    scanf("%s", name);
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", date);
    printf("Enter the time (HH:MM): ");
    scanf("%s", time);
    printf("\nAppointment added successfully!\n");
}

// Function to view appointments
void viewAppointments() {
    FILE *fp;
    char ch;
    fp = fopen("appointments.txt", "r");
    if (fp == NULL) {
        printf("\nNo appointments found.\n");
    } else {
        while ((ch = fgetc(fp))!= EOF) {
            printf("%c", ch);
        }
        fclose(fp);
    }
}

// Function to delete an appointment
void deleteAppointment() {
    char name[50];
    printf("\nEnter the name of the person: ");
    scanf("%s", name);
    FILE *fp;
    fp = fopen("appointments.txt", "r+");
    rewind(fp);
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            fprintf(fp, "%s\n", name);
        }
    }
    fclose(fp);
    printf("\nAppointment deleted successfully!\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}