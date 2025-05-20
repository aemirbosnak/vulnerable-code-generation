//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[100];
    char date[50];
    char time[50];
} Appointment;

int menu();
void clear_input();
void print_appointment(Appointment appointment);
void add_appointment(Appointment appointments[], int* appointment_count);
void print_all_appointments(Appointment appointments[], int appointment_count);
void search_appointment(Appointment appointments[], int appointment_count);

int main() {
    int choice, appointment_count = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    do {
        choice = menu();

        switch (choice)
        {
        case 1:
            add_appointment(appointments, &appointment_count);
            break;

        case 2:
            print_all_appointments(appointments, appointment_count);
            break;

        case 3:
            search_appointment(appointments, appointment_count);
            break;

        case 4:
            printf("Exiting program...\n");
            exit(0);
            break;
        
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    } while (choice != 4);
    return 0;
}

// menu function to display the options
int menu() {
    int choice;
    printf("\n");
    printf("-----Appointment Scheduler Program-----\n");
    printf("1. Add Appointment\n");
    printf("2. Print all Appointments\n");
    printf("3. Search for Appointment\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    clear_input();  // clears any extra input buffer
    
    return choice;
}

// function to clear input buffer
void clear_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// function to print an appointment
void print_appointment(Appointment appointment) {
    printf("Name: %s\n", appointment.name);
    printf("Date: %s\n", appointment.date);
    printf("Time: %s\n", appointment.time);
    printf("\n");
}

// function to add an appointment to the array of appointments
void add_appointment(Appointment appointments[], int* appointment_count) {
    if (*appointment_count == MAX_APPOINTMENTS) {
        printf("Maximum number of appointments reached.\n");
        return;
    }

    char name[100], date[50], time[50];
    printf("Enter name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter date (DD/MM/YYYY): ");
    fgets(date, 50, stdin);
    date[strcspn(date, "\n")] = 0;

    printf("Enter time (HH:mm): ");
    fgets(time, 50, stdin);
    time[strcspn(time, "\n")] = 0;

    // create a new appointment struct and copy the values from the input
    Appointment new_appointment;
    strcpy(new_appointment.name, name);
    strcpy(new_appointment.date, date);
    strcpy(new_appointment.time, time);

    // add the new appointment to the array
    appointments[*appointment_count] = new_appointment;
    *appointment_count += 1;

    printf("Appointment added!\n");
}

// function to print all appointments in the array
void print_all_appointments(Appointment appointments[], int appointment_count) {
    if (appointment_count == 0) {
        printf("No appointments found.\n");
        return;
    }

    for (int i = 0; i < appointment_count; i++) {
        printf("%d.\n", i + 1);
        print_appointment(appointments[i]);
    }
}

// function to search for an appointment by name
void search_appointment(Appointment appointments[], int appointment_count) {
    if (appointment_count == 0) {
        printf("No appointments found.\n");
        return;
    }

    char search_term[100];
    printf("Enter search term: ");
    fgets(search_term, 100, stdin);
    search_term[strcspn(search_term, "\n")] = 0;
    printf("\n");

    int matches = 0;
    for (int i = 0; i < appointment_count; i++) {
        if (strstr(appointments[i].name, search_term) != NULL) {
            matches++;
            printf("%d.\n", matches);
            print_appointment(appointments[i]);
        }
    }

    if (matches == 0) {
        printf("No matching appointments found.\n");
    }
}