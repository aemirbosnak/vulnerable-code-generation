//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    int day;
    int month;
    int year;
    int time;
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void addAppointment() {
    if (numAppointments == MAX_APPOINTMENTS) {
        printf("Sorry, the appointment book is full.\n");
        return;
    }
    
    Appointment appointment;
    
    printf("Enter your name: ");
    scanf("%s", appointment.name);
    
    printf("Enter your phone number: ");
    scanf("%s", appointment.phone);
    
    printf("Enter your email address: ");
    scanf("%s", appointment.email);
    
    printf("Enter the day of your appointment (1-31): ");
    scanf("%d", &appointment.day);
    
    printf("Enter the month of your appointment (1-12): ");
    scanf("%d", &appointment.month);
    
    printf("Enter the year of your appointment: ");
    scanf("%d", &appointment.year);
    
    printf("Enter the time of your appointment (in 24-hour format): ");
    scanf("%d", &appointment.time);
    
    appointments[numAppointments] = appointment;
    numAppointments++;
    
    printf("Appointment added.\n");
}

void listAppointments() {
    if (numAppointments == 0) {
        printf("There are no appointments scheduled.\n");
        return;
    }
    
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s, %s, %s, %d/%d/%d, %d:00\n", 
            appointments[i].name, 
            appointments[i].phone, 
            appointments[i].email, 
            appointments[i].day, 
            appointments[i].month, 
            appointments[i].year, 
            appointments[i].time);
    }
}

void searchAppointments() {
    char name[50];
    
    printf("Enter the name of the person you are looking for: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("%s, %s, %s, %d/%d/%d, %d:00\n", 
                appointments[i].name, 
                appointments[i].phone, 
                appointments[i].email, 
                appointments[i].day, 
                appointments[i].month, 
                appointments[i].year, 
                appointments[i].time);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No appointments found for that name.\n");
    }
}

void deleteAppointment() {
    char name[50];
    
    printf("Enter the name of the person whose appointment you want to delete: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            for (int j = i + 1; j < numAppointments; j++) {
                appointments[j - 1] = appointments[j];
            }
            numAppointments--;
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No appointments found for that name.\n");
    } else {
        printf("Appointment deleted.\n");
    }
}

int main() {
    int choice;
    
    do {
        printf("1. Add appointment\n");
        printf("2. List appointments\n");
        printf("3. Search appointments\n");
        printf("4. Delete appointment\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                listAppointments();
                break;
            case 3:
                searchAppointments();
                break;
            case 4:
                deleteAppointment();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    
    return 0;
}