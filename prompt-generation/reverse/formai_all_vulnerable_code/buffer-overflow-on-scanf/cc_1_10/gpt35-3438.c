//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declare struct for appointment
struct appointment {
    char date[20];
    char time[20];
    char name[50];
    char venue[50];
};

// declare struct for node
struct node {
    struct appointment a;
    struct node *next;
};

// declare global variable for list
struct node *head = NULL;

// function to add an appointment to list
void add_appointment() {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the appointment date (DD/MM/YYYY): ");
    scanf("%s", temp->a.date);
    printf("Enter the appointment time (HH:MM): ");
    scanf("%s", temp->a.time);
    printf("Enter the name of the person: ");
    scanf("%s", temp->a.name);
    printf("Enter the venue for the appointment: ");
    scanf("%s", temp->a.venue);
    temp->next = head;
    head = temp;
    printf("Appointment added successfully!\n");
}

// function to print all appointments
void print_appointments() {
    struct node *temp = head;
    int count = 1;
    while (temp != NULL) {
        printf("\nAppointment #%d:\n", count++);
        printf("Date: %s\n", temp->a.date);
        printf("Time: %s\n", temp->a.time);
        printf("Name: %s\n", temp->a.name);
        printf("Venue: %s\n", temp->a.venue);
        temp = temp->next;
    }
    printf("\n");
}

// function to search for an appointment
void search_appointment() {
    char date[20], time[20];
    printf("Enter the appointment date (DD/MM/YYYY): ");
    scanf("%s", date);
    printf("Enter the appointment time (HH:MM): ");
    scanf("%s", time);
    struct node *temp = head;
    int flag = 0;
    while (temp != NULL) {
        if (strcmp(temp->a.date, date) == 0 && strcmp(temp->a.time, time) == 0) {
            printf("\nAppointment found:\n");
            printf("Date: %s\n", temp->a.date);
            printf("Time: %s\n", temp->a.time);
            printf("Name: %s\n", temp->a.name);
            printf("Venue: %s\n", temp->a.venue);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (!flag) {
        printf("\nAppointment not found!\n");
    }
}

// main function
int main() {
    int choice;
    while (1) {
        printf("------ Appointment Scheduler ------\n");
        printf("1. Add Appointment\n");
        printf("2. Print All Appointments\n");
        printf("3. Search for Appointment\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_appointment(); break;
            case 2: print_appointments(); break;
            case 3: search_appointment(); break;
            case 4: exit(0); break;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}