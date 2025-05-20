//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPTS 20

// Define appt struct
typedef struct {
    char name[30];
    char date[11];
    char time[6];
} Appointment;

// Function prototypes
void get_appt_info(Appointment *appt);
void print_appt_list(Appointment *appt_list, int num_appts);
void add_appt(Appointment *appt_list, int *num_appts);
void delete_appt(Appointment *appt_list, int *num_appts, char *name);
void search_appt(Appointment *appt_list, int num_appts, char *name);

int main() {

    // Declare variables
    int num_appts = 0;
    Appointment appt_list[MAX_APPTS];
    char option;

    do {
        // Display menu
        printf("\n\n C Appointment Scheduler \n");
        printf("------------------------------\n");
        printf("1. Add Appointment\n");
        printf("2. Delete Appointment\n");
        printf("3. Search Appointment\n");
        printf("4. View All Appointments\n");
        printf("5. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice (1-5): ");

        // Get user input
        fflush(stdin);
        option = getchar();

        // Process user input
        switch(option) {
            case '1':
                add_appt(appt_list, &num_appts);
                break;
            case '2':
                if (num_appts > 0) {
                    char name[30];
                    printf("\nEnter the name of the appointment you want to delete: ");
                    fflush(stdin);
                    gets(name);
                    delete_appt(appt_list, &num_appts, name);
                } else {
                    printf("\nThere are no appointments to delete.\n");
                }
                break;
            case '3':
                if (num_appts > 0) {
                    char name[30];
                    printf("\nEnter the name of the appointment you want to search for: ");
                    fflush(stdin);
                    gets(name);
                    search_appt(appt_list, num_appts, name);
                } else {
                    printf("\nThere are no appointments to search for.\n");
                }
                break;
            case '4':
                if (num_appts > 0) {
                    print_appt_list(appt_list, num_appts);
                } else {
                    printf("\nThere are no appointments to display.\n");
                }
                break;
            case '5':
                printf("\nExiting the Appointment Scheduler.\n");
                break;
            default:
                printf("\nInvalid selection, please try again.\n");
                break;
        }

    } while (option != '5');

    return 0;
}

// Function to get appointment information from user
void get_appt_info(Appointment *appt) {
    printf("\nEnter the name of the appointment: ");
    fflush(stdin);
    gets(appt->name);
    printf("Enter the date of the appointment (MM/DD/YYYY): ");
    fflush(stdin);
    gets(appt->date);
    printf("Enter the time of the appointment (HH:MM): ");
    fflush(stdin);
    gets(appt->time);
}

// Function to print list of appointments
void print_appt_list(Appointment *appt_list, int num_appts) {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("%d. %s on %s at %s\n", i+1, appt_list[i].name, appt_list[i].date, appt_list[i].time);
    }
}

// Function to add appointment
void add_appt(Appointment *appt_list, int *num_appts) {
    if (*num_appts < MAX_APPTS) {
        Appointment new_appt;
        get_appt_info(&new_appt);
        appt_list[*num_appts] = new_appt;
        printf("\nAppointment added successfully.\n");
        (*num_appts)++;
    } else {
        printf("\nSorry, you have reached the maximum number of appointments.\n");
    }
}

// Function to delete appointment
void delete_appt(Appointment *appt_list, int *num_appts, char *name) {
    int index = -1;
    for (int i = 0; i < *num_appts; i++) {
        if (strcmp(appt_list[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < (*num_appts - 1); i++) {
            appt_list[i] = appt_list[i+1];
        }
        (*num_appts)--;
        printf("\nAppointment deleted successfully.\n");
    } else {
        printf("\nUnable to find appointment.\n");
    }
}

// Function to search for appointment
void search_appt(Appointment *appt_list, int num_appts, char *name) {
    int found = 0;
    printf("\nAppointments with name \"%s\":\n", name);
    for (int i = 0; i < num_appts; i++) {
        if (strcmp(appt_list[i].name, name) == 0) {
            printf("%d. %s on %s at %s\n", i+1, appt_list[i].name, appt_list[i].date, appt_list[i].time);
            found = 1;
        }
    }
    if (!found) {
        printf("\nUnable to find appointments with name \"%s\".\n", name);
    }
}