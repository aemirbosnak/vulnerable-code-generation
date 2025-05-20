//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Appointment structure
typedef struct {
    char date[11];
    char time[6];
    char purpose[101];
} Appointment;

// Node structure for linked list
typedef struct node {
    Appointment appt;
    struct node *next;
} Node;

// Global variables
Node *head = NULL;
Node *tail = NULL;

// Function declarations
void displayMenu();
void addAppointment();
void viewAppointments();
void deleteAppointment();
Node *createNewNode(Appointment appt);
void insertAtEnd(Appointment appt);
void deleteNode(Node *nodeToDelete);
bool isDateValid(char *date);
bool isTimeValid(char *time);

int main() {
    int choice;
    displayMenu();
    scanf("%d", &choice);
    while (choice != 4) {
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                viewAppointments();
                break;
            case 3:
                deleteAppointment();
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
        displayMenu();
        scanf("%d", &choice);
    }
    printf("Exiting program.\n");
    return 0;
}

// Displays menu of options
void displayMenu() {
    printf("1. Add Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Delete Appointment\n");
    printf("4. Exit\n");
    printf("Enter Choice: ");
}

// Adds a new appointment to the linked list
void addAppointment() {
    Appointment appt;
    printf("Enter date of appointment (MM/DD/YYYY): ");
    scanf("%s", appt.date);
    if (!isDateValid(appt.date)) {
        printf("Invalid date format. Please enter date in MM/DD/YYYY format.\n");
        return;
    }
    printf("Enter time of appointment (HH:MM): ");
    scanf("%s", appt.time);
    if (!isTimeValid(appt.time)) {
        printf("Invalid time format. Please enter time in HH:MM format.\n");
        return;
    }
    printf("Enter purpose of appointment: ");
    getchar(); // flush input buffer
    fgets(appt.purpose, 101, stdin);
    insertAtEnd(appt);
    printf("Appointment added successfully.\n");
}

// Views all appointments currently in the linked list
void viewAppointments() {
    if (head == NULL) {
        printf("No appointments to display.\n");
    } else {
        Node *temp = head;
        while (temp != NULL) {
            printf("Date: %s\tTime: %s\tPurpose: %s", temp->appt.date, temp->appt.time, temp->appt.purpose);
            temp = temp->next;
        }
    }
}

// Deletes an appointment from the linked list
void deleteAppointment() {
    if (head == NULL) {
        printf("No appointments to delete.\n");
        return;
    }
    char dateToDelete[11];
    printf("Enter date of appointment to delete (MM/DD/YYYY): ");
    scanf("%s", dateToDelete);
    if (!isDateValid(dateToDelete)) {
        printf("Invalid date format. Please enter date in MM/DD/YYYY format.\n");
        return;
    }
    char timeToDelete[6];
    printf("Enter time of appointment to delete (HH:MM): ");
    scanf("%s", timeToDelete);
    if (!isTimeValid(timeToDelete)) {
        printf("Invalid time format. Please enter time in HH:MM format.\n");
        return;
    }
    Node *temp = head;
    bool found = false;
    while (temp != NULL) {
        if ((strcmp(temp->appt.date, dateToDelete) == 0) && (strcmp(temp->appt.time, timeToDelete) == 0)) {
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (found) {
        deleteNode(temp);
        printf("Appointment deleted successfully.\n");
    } else {
        printf("Appointment not found.\n");
    }
}

// Creates a new node with the given appointment
Node *createNewNode(Appointment appt) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->appt = appt;
    newNode->next = NULL;
    return newNode;
}

// Inserts a new node at the end of the linked list with the given appointment
void insertAtEnd(Appointment appt) {
    Node *newNode = createNewNode(appt);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Deletes the given node from the linked list
void deleteNode(Node *nodeToDelete) {
    if (nodeToDelete == head) {
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
        }
    } else {
        Node *temp = head;
        while (temp->next != nodeToDelete) {
            temp = temp->next;
        }
        temp->next = nodeToDelete->next;
        if (nodeToDelete == tail) {
            tail = temp;
        }
    }
    free(nodeToDelete);
}

// Validates a date string in MM/DD/YYYY format
bool isDateValid(char *date) {
    if (strlen(date) != 10) {
        return false;
    }
    char month[3];
    strncpy(month, date, 2);
    month[2] = '\0';
    int mm = atoi(month);
    char day[3];
    strncpy(day, date + 3, 2);
    day[2] = '\0';
    int dd = atoi(day);
    char year[5];
    strncpy(year, date + 6, 4);
    year[4] = '\0';
    int yyyy = atoi(year);
    if (mm < 1 || mm > 12 || dd < 1 || dd > 31 || yyyy < 1900) {
        return false;
    }
    if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd == 31) {
        return false;
    }
    if (mm == 2 && (dd > 29 || (dd == 29 && yyyy % 4 != 0))) {
        return false;
    }
    return true;
}

// Validates a time string in HH:MM format
bool isTimeValid(char *time) {
    if (strlen(time) != 5) {
        return false;
    }
    char hour[3];
    strncpy(hour, time, 2);
    hour[2] = '\0';
    int hh = atoi(hour);
    char minute[3];
    strncpy(minute, time + 3, 2);
    minute[2] = '\0';
    int mm = atoi(minute);
    if (hh < 0 || hh > 23 || mm < 0 || mm > 59) {
        return false;
    }
    return true;
}