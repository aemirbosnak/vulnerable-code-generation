//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct appointment {
    char name[50];
    char reason[100];
    time_t date;
    struct appointment* next;
};

struct appointment* head = NULL;

void add_appointment() {
    struct appointment* new_appointment = (struct appointment*)malloc(sizeof(struct appointment));
    printf("Enter name of patient: ");
    scanf("%s", new_appointment->name);
    printf("Enter reason for appointment: ");
    scanf("%s", new_appointment->reason);
    printf("Enter date of appointment (YYYY-MM-DD): ");
    scanf("%s", new_appointment->date);
    new_appointment->date = strptime(new_appointment->date, "%Y-%m-%d", NULL);
    new_appointment->next = NULL;

    if (head == NULL) {
        head = new_appointment;
    } else {
        struct appointment* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_appointment;
    }
    printf("Appointment added successfully!\n");
}

void view_appointments() {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
    } else {
        struct appointment* temp = head;
        printf("Appointments:\n");
        while (temp!= NULL) {
            printf("Name: %s\nReason: %s\nDate: %s\n", temp->name, temp->reason, ctime(&temp->date));
            temp = temp->next;
        }
    }
}

void delete_appointment() {
    char name[50];
    printf("Enter name of patient to delete appointment: ");
    scanf("%s", name);

    struct appointment* temp = head;
    struct appointment* prev = NULL;

    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Appointment deleted successfully!\n");
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void search_appointment() {
    char name[50];
    printf("Enter name of patient to search appointment: ");
    scanf("%s", name);

    struct appointment* temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Name: %s\nReason: %s\nDate: %s\n", temp->name, temp->reason, ctime(&temp->date));
            break;
        }
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Search appointment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                search_appointment();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}