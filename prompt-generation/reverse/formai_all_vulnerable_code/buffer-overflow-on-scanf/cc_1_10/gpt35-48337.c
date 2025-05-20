//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char name[50];
    int age;
    char phone[20];
    char date[20];
    char time[20];
    struct node* next;
};

struct node* head = NULL;

// function to print menu
void print_menu() {
    printf("\n");
    printf("C APPOINTMENT SCHEDULER\n");
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");
}

// function to add appointment
void add_appointment() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter patient name: ");
    scanf("%s", new_node->name);
    printf("Enter patient age: ");
    scanf("%d", &(new_node->age));
    printf("Enter phone number (ex: 123-456-7890): ");
    scanf("%s", new_node->phone);
    printf("Enter appointment date (ex: mm/dd/yyyy): ");
    scanf("%s", new_node->date);
    printf("Enter appointment time (ex: hh:mm): ");
    scanf("%s", new_node->time);
    new_node->next = head;
    head = new_node;
    printf("Appointment added successfully!\n");
}

// function to view appointments
void view_appointments() {
    if (head == NULL) {
        printf("\nNo appointments available.\n");
        return;
    }
    struct node* curr = head;
    printf("\n");
    printf("APPOINTMENTS\n");
    printf("------------\n");
    printf("NAME\t\tAGE\tPHONE\t\tDATE\t\tTIME\n");
    while (curr != NULL) {
        printf("%-12s\t%d\t%s\t%s\t%s\n", curr->name, curr->age, curr->phone, curr->date, curr->time);
        curr = curr->next;
    }
}

int main() {
    printf("Welcome to C Appointment Scheduler!\n");
    int choice;
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);
    return 0;
}