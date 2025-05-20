//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

void add_appointment(Appointment** head) {
    *head = malloc(sizeof(Appointment));
    (*head)->next = NULL;
    printf("Enter your name: ");
    scanf("%s", (*head)->name);
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", (*head)->date);
    printf("Enter the time (hh:mm): ");
    scanf("%s", (*head)->time);
}

void print_appointments(Appointment* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;
    int choice;

    while (1) {
        printf("1. Add an appointment\n");
        printf("2. Print appointments\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(&head);
                break;
            case 2:
                print_appointments(head);
                break;
            default:
                exit(1);
        }
    }

    return 0;
}