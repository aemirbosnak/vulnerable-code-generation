//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Structures
struct Appointment {
    char date[11];
    char time[6];
    char name[50];
};

int Size = 0; // Number of appointments

// Function to print all the appointments
void PrintAppointments(struct Appointment *appts) {
    printf("\n# All Appointments\n");
    printf("---------------------------------------------------\n");
    printf("S.no\tDate\t\tTime\t\tName\n");
    printf("---------------------------------------------------\n");
    for(int i=0; i<Size; i++) {
        printf("%d.\t%s\t%s\t%s\n", i+1, appts[i].date, appts[i].time, appts[i].name);
    }
    printf("---------------------------------------------------\n\n");
}

// Function to add new appointment
void AddAppointment(struct Appointment *appts) {
    printf("\n# Add Appointment\n");
    printf("Enter the Date (dd-mm-yyyy): ");
    scanf("%s", appts[Size].date);
    printf("Enter the Time (hh:mm): ");
    scanf("%s", appts[Size].time);
    printf("Enter the Name: ");
    getchar();
    fgets(appts[Size].name, 50, stdin);
    Size++; // Increment the number of appointments
    printf("Appointment added successfully.\n");
}

// Function to remove an appointment
void RemoveAppointment(struct Appointment *appts, int index) {
    for(int i=index-1; i<Size-1; i++) {
        appts[i] = appts[i+1]; // Shift the appointments left
    }
    Size--; // Decrement the number of appointments
    printf("Appointment removed successfully.\n");
}

// Main Function
int main() {
    struct Appointment appointments[50]; // Maximum appointments allowed
    int choice, index;
    char d[11], t[6], n[50];
    
    while(1) {
        printf("Select an option:\n");
        printf("1. View all Appointments\n");
        printf("2. Add a new Appointment\n");
        printf("3. Remove an Appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if(choice==1) { // View all Appointments
            PrintAppointments(appointments);
        } else if(choice==2) { // Add a new Appointment
            AddAppointment(appointments);
        } else if(choice==3) { // Remove an Appointment
            PrintAppointments(appointments);
            printf("Enter the S.no of the appointment to be removed: ");
            scanf("%d", &index);
            if(index<1 || index>Size) {
                printf("Invalid appointment number.\n");
            } else {
                RemoveAppointment(appointments, index);
            }
        } else if(choice==4) { // Exit
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }
    }
    
    return 0;
}