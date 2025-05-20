//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 50

struct Appointment {
    int day;
    char month[10];
    int year;
    char time[10];
    char description[50];
};

void printAppointments(struct Appointment appts[], int count);
int findOpening(struct Appointment appts[], int count, int day, char month[], int year, char newTime[]);
void addAppointment(struct Appointment appts[], int* countPtr, int day, char month[], int year, char time[], char description[]);
void removeAppointment(struct Appointment appts[], int* countPtr, int index);
void clearAppointments(struct Appointment appts[], int* countPtr);

void clearBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int appointmentCount = 0;
    char option[5];
    
    char monthName[10];
    printf("Welcome to the Appointment Scheduler\n");
    printf("------------------------------------\n\n");
    
    while (1) {
        
        printf("MENU OPTIONS:\n");
        printf("1) Print all appointments\n");
        printf("2) Add appointment\n");
        printf("3) Remove appointment\n");
        printf("4) Clear all appointments\n");
        printf("5) Exit\n\n");
        
        printf("Enter an option: ");
        scanf("%s", option);
        clearBuffer();
        
        if (strcmp(option, "1") == 0) {
            if (appointmentCount > 0) {
                printAppointments(appointments, appointmentCount);
            } else {
                printf("No appointments scheduled.\n\n");
            }
        } else if (strcmp(option, "2") == 0) {
            int dayValue, yearValue, slotIndex;
            char timeValue[10], descriptionValue[50];
            printf("Enter day: ");
            scanf("%d", &dayValue);
            printf("Enter month: ");
            scanf("%s", monthName);
            printf("Enter year: ");
            scanf("%d", &yearValue);
            printf("Enter time (ex. 3:30pm): ");
            scanf("%s", timeValue);
            clearBuffer();
            printf("Enter description: ");
            fgets(descriptionValue, 50, stdin);
            if (descriptionValue[strlen(descriptionValue) - 1] == '\n') descriptionValue[strlen(descriptionValue) - 1] = '\0';
            slotIndex = findOpening(appointments, appointmentCount, dayValue, monthName, yearValue, timeValue);
            if (slotIndex == -1) {
                printf("Appointment could not be scheduled for that time.\n\n");
            } else {
                addAppointment(appointments, &appointmentCount, dayValue, monthName, yearValue, timeValue, descriptionValue);
                printf("Appointment scheduled.\n\n");
            }
        } else if (strcmp(option, "3") == 0) {
            int index;
            printf("Enter the index of the appointment to remove: ");
            scanf("%d", &index);
            if (index >= 0 && index < appointmentCount) {
                removeAppointment(appointments, &appointmentCount, index);
                printf("Appointment removed.\n\n");
            } else {
                printf("Invalid index entered.\n\n");
            }
        } else if (strcmp(option, "4") == 0) {
            clearAppointments(appointments, &appointmentCount);
            printf("Appointments cleared.\n\n");
        } else if (strcmp(option, "5") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid option entered.\n\n");
        }
    }
    
    return 0;
}

void printAppointments(struct Appointment appts[], int count) {
    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("Appointment %d:\n", i);
        printf("Date: %d %s %d\n", appts[i].day, appts[i].month, appts[i].year);
        printf("Time: %s\n", appts[i].time);
        printf("Description: %s\n", appts[i].description);
        printf("\n");
    }
}

int findOpening(struct Appointment appts[], int count, int day, char month[], int year, char newTime[]) {
    for (int i = 0; i < count; i++) {
        if (appts[i].day == day && strcmp(appts[i].month, month) == 0 && appts[i].year == year) {
            if (strcmp(appts[i].time, newTime) == 0) {
                return -1;
            }
        }
    }
    return count;
}

void addAppointment(struct Appointment appts[], int* countPtr, int day, char month[], int year, char time[], char description[]) {
    appts[*countPtr].day = day;
    strcpy(appts[*countPtr].month, month);
    appts[*countPtr].year = year;
    strcpy(appts[*countPtr].time, time);
    strcpy(appts[*countPtr].description, description);
    (*countPtr)++;
}

void removeAppointment(struct Appointment appts[], int* countPtr, int index) {
    for (int i = index; i < *countPtr - 1; i++) {
        appts[i] = appts[i + 1];
    }
    (*countPtr)--;
}

void clearAppointments(struct Appointment appts[], int* countPtr) {
    *countPtr = 0;
}