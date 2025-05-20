//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node structure for the linked-list of appointments
struct Appointment{
    char* name;
    char* date;
    char* time;
    struct Appointment* next;
};

// Function prototypes
void addAppointment(struct Appointment** head_ref, char* name, char* date, char* time);
void printAppointments(struct Appointment* head);
void deleteAppointment(struct Appointment** head_ref, char* name, char* date, char* time);

int main(){
    // Initialize the linked-list of appointments
    struct Appointment* head = NULL;
    
    // Menu for the user to choose an action
    int choice = 0;
    while(choice != 4){
        printf("\nAppointment Scheduler\n");
        printf("1. Add an appointment\n");
        printf("2. View all appointments\n");
        printf("3. Delete an appointment\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Add an appointment
        if(choice == 1){
            char name[50];
            char date[20];
            char time[20];

            printf("Enter the name of the appointment: ");
            scanf("%s", &name);
            printf("Enter the date of the appointment: ");
            scanf("%s", &date);
            printf("Enter the time of the appointment: ");
            scanf("%s", &time);

            addAppointment(&head, name, date, time);
        }

        // View all appointments
        else if(choice == 2){
            printAppointments(head);
        }

        // Delete an appointment
        else if(choice == 3){
            char name[50];
            char date[20];
            char time[20];

            printf("Enter the name of the appointment to be deleted: ");
            scanf("%s", &name);
            printf("Enter the date of the appointment to be deleted: ");
            scanf("%s", &date);
            printf("Enter the time of the appointment to be deleted: ");
            scanf("%s", &time);

            deleteAppointment(&head, name, date, time);
        }

        // Quit the program
        else if(choice == 4){
            printf("Exiting Appointment Scheduler...\n");
        }

        // Invalid choice
        else{
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new appointment to the linked-list
void addAppointment(struct Appointment** head_ref, char* name, char* date, char* time){
    // Allocate memory for the new node
    struct Appointment* new_appt = (struct Appointment*)malloc(sizeof(struct Appointment));

    // Copy the appointment information to the new node
    new_appt->name = (char*)malloc(strlen(name)+1);
    strcpy(new_appt->name, name);
    new_appt->date = (char*)malloc(strlen(date)+1);
    strcpy(new_appt->date, date);
    new_appt->time = (char*)malloc(strlen(time)+1);
    strcpy(new_appt->time, time);

    // Set the next pointer of the new node to the current head node
    new_appt->next = (*head_ref);

    // Set the head node to the new node
    (*head_ref) = new_appt;

    printf("Appointment added successfully.\n");
}

// Function to print all the appointments in the linked-list
void printAppointments(struct Appointment* head){
    if(head == NULL){
        printf("No appointments found.\n");
        return;
    }
    
    // Traverse the linked-list and print the appointment information
    struct Appointment* temp = head;
    printf("\nAppointments:\n");
    while(temp != NULL){
        printf("Name: %s\n", temp->name);
        printf("Date: %s\n", temp->date);
        printf("Time: %s\n", temp->time);
        temp = temp->next;
    }
}

// Function to delete an appointment from the linked-list
void deleteAppointment(struct Appointment** head_ref, char* name, char* date, char* time){
    if(*head_ref == NULL){
        printf("No appointments found.\n");
        return;
    }

    // Find the appointment to be deleted
    struct Appointment* prev = NULL;
    struct Appointment* curr = *head_ref;
    while(curr != NULL && (strcmp(curr->name, name) != 0 || strcmp(curr->date, date) != 0 || strcmp(curr->time, time) != 0)){
        prev = curr;
        curr = curr->next;
    }

    // Appointment not found
    if(curr == NULL){
        printf("Appointment not found.\n");
        return;
    }

    // Appointment found and is the head node
    if(prev == NULL){
        *head_ref = curr->next;
        free(curr->name);
        free(curr->date);
        free(curr->time);
        free(curr);
        printf("Appointment deleted successfully.\n");
        return;
    }

    // Appointment found and is not the head node
    prev->next = curr->next;
    free(curr->name);
    free(curr->date);
    free(curr->time);
    free(curr);
    printf("Appointment deleted successfully.\n");
}