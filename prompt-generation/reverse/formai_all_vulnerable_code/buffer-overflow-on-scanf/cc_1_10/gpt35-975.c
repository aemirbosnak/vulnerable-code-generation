//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct for appointment node
struct Appointment {
    char date[11];
    char time[6];
    char name[256];
    char phonenumber[11];
    struct Appointment* next;
};

// Add new appointment node to list
void addAppointment(struct Appointment** head_ref, char* date, char* time, char* name, char* phonenumber) {
    struct Appointment* new_appointment = (struct Appointment*) malloc(sizeof(struct Appointment));
    strcpy(new_appointment->date, date);
    strcpy(new_appointment->time, time);
    strcpy(new_appointment->name, name);
    strcpy(new_appointment->phonenumber, phonenumber);
    
    // If head is NULL, add node as first node
    if (*head_ref == NULL) {
        *head_ref = new_appointment;
        new_appointment->next = NULL;
        return;
    }
    
    // If new appointment is before the head node
    if (strcmp(new_appointment->date, (*head_ref)->date) < 0) {
        new_appointment->next = *head_ref;
        *head_ref = new_appointment;
        return;
    }
    
    // Loop through list to find where to insert new appointment node
    struct Appointment* current = *head_ref;
    while(current->next != NULL && strcmp(new_appointment->date, current->next->date) > 0) {
        current = current->next;
    }
    // If there are no appointments on the same day or earlier, add to end of list
    if (current->next == NULL) {
        current->next = new_appointment;
        new_appointment->next = NULL;
    }
    // If appointment is on the same day, compare times to see where to insert
    else if (strcmp(new_appointment->date, current->next->date) == 0) {
        // If new appointment is at an earlier time, insert before current->next
        if (strcmp(new_appointment->time, current->next->time) < 0) {
            new_appointment->next = current->next;
            current->next = new_appointment;
        }
        // If new appointment is at the same or later time, keep loop going to find correct location
        else {
            new_appointment->next = current->next->next;
            current->next->next = new_appointment;
        }
    }
    // If appointment is on a later day, insert before day in list
    else {
        new_appointment->next = current->next;
        current->next = new_appointment;
    }
    return;
}

// Remove appointment node from list
void removeAppointment(struct Appointment** head_ref, char* date, char* time) {
    struct Appointment* temp = *head_ref;
    struct Appointment* prev = NULL;
    
    // If head node matches date and time
    if (temp != NULL && strcmp(temp->date, date) == 0 && strcmp(temp->time, time) == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    // Loop through rest of list to find appointment with matching date and time
    while (temp != NULL && (strcmp(temp->date, date) != 0 || strcmp(temp->time, time) != 0)) {
        prev = temp;
        temp = temp->next;
    }
    
    // If appointment with matching date and time was found, remove it from the list
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
        return;
    }
    // If appointment not found, print error message
    else {
        printf("Appointment not found.\n");
        return;
    }
}

// Print list of appointments for specific date
void printAppointmentsByDate(struct Appointment* head, char* date) {
    int count = 0;
    struct Appointment* current = head;
    
    // Loop through list to find any appointments on inputted date
    while(current != NULL) {
        if (strcmp(current->date, date) == 0) {
            printf("\nDate: %s\n", current->date);
            printf("Time: %s\n", current->time);
            printf("Name: %s\n", current->name);
            printf("Phone number: %s\n", current->phonenumber);
            count++;
        }
        current = current->next;
    }
    // If there were no appointments on inputted date, print message
    if (count == 0) {
        printf("No appointments for that date.\n");
    }
}

int main() {
    struct Appointment* head = NULL;
    int choice;
    char date[11];
    char time[6];
    char name[256];
    char phonenumber[11];
    
    printf("\nWelcome to the appointment scheduler!\n\n");
    
    while(1) {
        printf("Enter 1 to add an appointment\n");
        printf("Enter 2 to remove an appointment\n");
        printf("Enter 3 to view appointments for a specific date\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter date (MM/DD/YYYY): ");
                scanf("%s", date);
                printf("Enter time (HH:MM): ");
                scanf("%s", time);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number (XXXXXXXXXX): ");
                scanf("%s", phonenumber);
                
                addAppointment(&head, date, time, name, phonenumber);
                printf("\nAppointment added!\n\n");
                break;
                
            case 2:
                printf("\nEnter date (MM/DD/YYYY): ");
                scanf("%s", date);
                printf("Enter time (HH:MM): ");
                scanf("%s", time);
                
                removeAppointment(&head, date, time);
                break;
                
            case 3:
                printf("\nEnter date (MM/DD/YYYY): ");
                scanf("%s", date);
                
                printAppointmentsByDate(head, date);
                break;
                
            case 0:
                printf("\nThank you for using the appointment scheduler!\n");
                exit(0);
                
            default:
                printf("\nInvalid input, please try again.\n\n");
        }
    }
    return 0;
}