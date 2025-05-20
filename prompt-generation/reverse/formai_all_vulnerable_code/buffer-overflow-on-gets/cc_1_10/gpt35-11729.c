//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node //Represent the node of the doubly linked list.
{
    char name[50];
    char time[10];
    char email[50];
    char contact[15];
    char date[15];
    struct Node* prev;
    struct Node* next;
}*head, *tail;

void InsertAtEnd(char name[], char time[], char email[], char contact[], char date[])
{
    int flag = 0;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->name, name);
    strcpy(newnode->time, time);
    strcpy(newnode->email, email);
    strcpy(newnode->contact, contact);
    strcpy(newnode->date, date);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        struct Node* temp = head;
        while (temp != NULL)
        {
            if (strcmp(temp->date, date) == 0 && strcmp(temp->time, time) == 0)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 1)
        {
            printf("\nThis slot is already booked for another appointment. Please try again.\n");
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}

void DeleteAppointment(char name[], char date[])
{
    int flag = 0;
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0 && strcmp(temp->date, date) == 0)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 1)
    {
        if (temp == head && temp == tail)
        {
            head = tail = NULL;
        }
        else if (temp == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else if (temp == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        free(temp);
        printf("\nThe appointment for %s has been cancelled on %s.\n", name, date);
    }
    else
    {
        printf("\nNo such appointment found for %s on %s.\n", name, date);
    }
}

void DisplayAppointment(char date[])
{
    struct Node* temp = head;
    int count = 0;
    printf("\n------------------- Appointments on %s -------------------------\n", date);
    while (temp != NULL)
    {
        if (strcmp(temp->date, date) == 0)
        {
            count++;
            printf("\nName: %s \t Time: %s \t Email: %s \t Contact: %s\n", temp->name, temp->time, temp->email, temp->contact);
        }
        temp = temp->next;
    }
    if (count == 0)
    {
        printf("\nNo appointments found for the given date.\n");
    }
}

int main()
{
    int choice;
    head = tail = NULL;
    printf("\n------------ Welcome to the Appointment Scheduling System --------------\n");
    do
    {
        printf("\n1. Book an Appointment\n2. Cancel an Appointment\n3. Display Appointments\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
        {
            char name[50], time[10], email[50], contact[15], date[15];
            printf("\nEnter your name: ");
            gets(name);
            printf("Enter your email: ");
            gets(email);
            printf("Enter your contact number: ");
            gets(contact);
            printf("Enter the appointment date (dd/mm/yyyy): ");
            gets(date);
            printf("Enter the appointment time (hh:mm AM/PM): ");
            gets(time);
            InsertAtEnd(name, time, email, contact, date);
            break;
        }
        case 2:
        {
            char name[50], date[15];
            printf("\nEnter the name of the patient: ");
            gets(name);
            printf("Enter the appointment date (dd/mm/yyyy): ");
            gets(date);
            DeleteAppointment(name, date);
            break;
        }
        case 3:
        {
            char date[15];
            printf("\nEnter the appointment date (dd/mm/yyyy): ");
            gets(date);
            DisplayAppointment(date);
            break;
        }
        case 4:
        {
            printf("\nThank you for using the Appointment Scheduling System!\n");
            break;
        }
        default:
            printf("\nInvalid choice! Try again.\n");
            break;
        }
    } while (choice != 4);
    return 0;
}