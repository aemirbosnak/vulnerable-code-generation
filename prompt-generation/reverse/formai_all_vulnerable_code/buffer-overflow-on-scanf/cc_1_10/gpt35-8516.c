//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 10

struct Appointment {
    char name[50];
    int year, month, day, hour, minute;
};

void displayMenu();
void viewAppointments(struct Appointment appointments[MAX], int len);
void addAppointment(struct Appointment appointments[MAX], int len);
void deleteAppointment(struct Appointment appointments[MAX], int* len);

int main()
{
    struct Appointment appointments[MAX];
    int len = 0, choice, i;
    bool running = true;
    
    while (running) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                viewAppointments(appointments, len);
                break;
            case 2:
                addAppointment(appointments, len);
                len++;
                break;
            case 3:
                deleteAppointment(appointments, &len);
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler! Goodbye.\n\n");
                running = false;
                break;
            default:
                printf("Invalid choice, please try again\n\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("Appointment Scheduler Menu\n");
    printf("1. View Appointments\n");
    printf("2. Add Appointment\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
}

void viewAppointments(struct Appointment appointments[MAX], int len) {
    if (len == 0) {
        printf("There are no appointments\n\n");
    } else {
        printf("Appointments:\n");
        for (int i = 0; i < len; i++) {
            printf("%s - %d/%d/%d at %02d:%02d\n", appointments[i].name, appointments[i].month, appointments[i].day, appointments[i].year, appointments[i].hour, appointments[i].minute);
        }
        printf("\n");
    }
}

void addAppointment(struct Appointment appointments[MAX], int len) {
    char tempName[50];
    int tempYear, tempMonth, tempDay, tempHour, tempMinute;
    
    printf("Enter the name of the appointment: ");
    scanf("%s", tempName);
    strcpy(appointments[len].name, tempName);
    
    printf("Enter year (yyyy): ");
    scanf("%d", &tempYear);
    appointments[len].year = tempYear;
    
    printf("Enter month (1-12): ");
    scanf("%d", &tempMonth);
    appointments[len].month = tempMonth;
    
    printf("Enter day (1-31): ");
    scanf("%d", &tempDay);
    appointments[len].day = tempDay;
    
    printf("Enter hour (0-23): ");
    scanf("%d", &tempHour);
    appointments[len].hour = tempHour;
    
    printf("Enter minute (0-59): ");
    scanf("%d", &tempMinute);
    appointments[len].minute = tempMinute;
    
    printf("Appointment added!\n\n");
}

void deleteAppointment(struct Appointment appointments[MAX], int* len) {
    int index;
    char tempName[50];
    bool found = false;
    
    if (*len == 0) {
        printf("There are no appointments to delete\n\n");
    } else {
        printf("Enter the name of the appointment to delete: ");
        scanf("%s", tempName);
        
        for (int i = 0; i < *len; i++) {
            if (strcmp(tempName, appointments[i].name) == 0) {
                index = i;
                found = true;
            }
        }
        
        if (found) {
            for (int i = index; i < *len - 1; i++) {
                appointments[i] = appointments[i+1];
            }
            (*len)--;
            printf("Appointment deleted!\n\n");
        } else {
            printf("Appointment not found.\n\n");
        }
    }
}