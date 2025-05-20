//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

// Structure to store appointment details
typedef struct Appointment {
    int day;
    int month;
    int year;
    char time[6];
    char name[50];
} Appointment;

void displayMenu() {
    printf("Appointment Scheduler\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void addAppointment(Appointment *appointments, int *count) {
    printf("Add Appointment\n");
    printf("Enter appointment details:\n");
    printf("Date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &appointments[*count].day, &appointments[*count].month, &appointments[*count].year);
    printf("Time (HH:MM): ");
    scanf("%s", appointments[*count].time);
    printf("Name: ");
    scanf("%s", appointments[*count].name);
    (*count)++;
    printf("Appointment added successfully!\n");
}

void viewAppointments(Appointment *appointments, int count) {
    printf("View Appointments\n");
    if(count == 0) {
        printf("No appointments scheduled\n");
        return;
    }
    printf("Date\t\tTime\tName\n");
    for(int i = 0; i < count; i++) {
        printf("%02d/%02d/%04d\t%s\t%s\n", appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].time, appointments[i].name);
    }
}

void deleteAppointment(Appointment *appointments, int *count) {
    char name[50];
    printf("Delete Appointment\n");
    if(*count == 0) {
        printf("No appointments scheduled\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", name);
    int index = -1;
    for(int i = 0; i < *count; i++) {
        if(strcmp(appointments[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("No appointment found with given name\n");
        return;
    }
    for(int i = index; i < (*count) - 1; i++) {
        appointments[i] = appointments[i+1];
    }
    (*count)--;
    printf("Appointment deleted successfully!\n");
}

int main() {
    Appointment appointments[50];
    int count = 0;
    int choice;
    do {
        displayMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}