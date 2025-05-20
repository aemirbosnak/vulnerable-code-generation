//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[30];
    char date[15];
    char time[10];
};

struct Node {
    struct Appointment data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAppointment(struct Appointment appointment) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = appointment;
    node->next = NULL;

    if(head == NULL) {
        head = node;
        return;
    }

    struct Node *current = head;
    while(current->next != NULL)
        current = current->next;
    current->next = node;
}

void deleteAppointment(char name[]) {
    if(head == NULL)
        return;

    struct Node *temp = head;

    if(strcmp(head->data.name, name) == 0) {
        head = head->next;
        free(temp);
        return;
    }

    while(temp->next != NULL && strcmp(temp->next->data.name, name) != 0)
        temp = temp->next;

    if(temp->next == NULL)
        return;

    struct Node *delete = temp->next;
    temp->next = delete->next;
    free(delete);   
}

int countAppointments() {
    int count = 0;
    struct Node *temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayAppointments() {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%s\t%s\t%s\n", temp->data.name, temp->data.date, temp->data.time);
        temp = temp->next;
    }
}

int main() {
    int choice;
    char name[30], date[15], time[10];
    struct Appointment appointment;

    do {
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. View appointments\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter date: ");
                scanf("%s", date);
                printf("Enter time: ");
                scanf("%s", time);
                strcpy(appointment.name, name);
                strcpy(appointment.date, date);
                strcpy(appointment.time, time);
                insertAppointment(appointment);
                printf("Appointment added successfully!\n");
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                deleteAppointment(name);
                printf("Appointment deleted successfully!\n");
                break;
            case 3:
                if(countAppointments() == 0) {
                    printf("No appointments found!\n");
                    break;
                }
                printf("Name\tDate\tTime\n");
                displayAppointments();
                break;
            case 4:
                printf("Thank you for using the Appointment Scheduler!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}