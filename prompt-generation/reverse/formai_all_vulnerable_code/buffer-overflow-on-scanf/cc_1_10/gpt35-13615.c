//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 50

struct Appointment {
    char date[MAX_LEN];
    char time[MAX_LEN];
    char name[MAX_LEN];
    char reason[MAX_LEN];
};

struct Node {
    struct Appointment appt;
    struct Node* next;
};

void addAppointment(struct Node** head_ref, struct Appointment appt) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->appt = appt;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("\nAppointment added successfully!\n");
}

void displayAppointments(struct Node* node) {
    printf("Date\t\tTime\tName\tReason\n");
    while (node != NULL) {
        printf("%s\t%s\t%s\t%s\n", node->appt.date, node->appt.time, node->appt.name, node->appt.reason);
        node = node->next;
    }
}

void deleteAppointment(struct Node** head_ref, char* name) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && strcmp(temp->appt.name, name) == 0) {
        *head_ref = temp->next;
        free(temp);
        printf("\nAppointment deleted successfully!\n");
        return;
    }

    while (temp != NULL && strcmp(temp->appt.name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nAppointment not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\nAppointment deleted successfully!\n");
}

int main() {
    struct Node* head = NULL;
    int choice;
    struct Appointment appt;

    while(1) {
        printf("\n1. Add Appointment\n2. Display Appointments\n");
        printf("3. Delete Appointment\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter appointment details:\n");
                printf("Date: ");
                scanf("%s", appt.date);
                printf("Time: ");
                scanf("%s", appt.time);
                printf("Name: ");
                scanf("%s", appt.name);
                printf("Reason: ");
                scanf("%s", appt.reason);
                addAppointment(&head, appt);
                break;

            case 2:
                displayAppointments(head);
                break;

            case 3:
                printf("\nEnter the name of the appointment to be deleted: ");
                char name[MAX_LEN];
                scanf("%s", name);
                deleteAppointment(&head, name);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}