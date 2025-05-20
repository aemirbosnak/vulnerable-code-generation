//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct appointment{
    char name[20];
    int day;
    int month;
    int year;
    char time[10];
};

struct node{
    struct appointment data;
    struct node *next;
};

typedef struct node NODE;
NODE *head = NULL;

void addAppointment(){
    NODE *new_node = (NODE*) malloc(sizeof(NODE));
    printf("\nEnter the details of the appointment:\n");
    printf("Name: ");
    scanf("%s", new_node->data.name);
    printf("Date (dd mm yyyy): ");
    scanf("%d %d %d", &new_node->data.day, &new_node->data.month, &new_node->data.year);
    printf("Time (hh:mm): ");
    scanf("%s", new_node->data.time);
    new_node->next = head;
    head = new_node;
    printf("\nAppointment added successfully!\n\n");
}

void displayAppointments(){
    NODE *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("\nNo appointments scheduled!\n\n");
        return;
    }
    printf("\nList of appointments:\n");
    while(ptr != NULL){
        printf("\nName: %s", ptr->data.name);
        printf("\nDate: %d/%d/%d", ptr->data.day, ptr->data.month, ptr->data.year);
        printf("\nTime: %s\n", ptr->data.time);
        ptr = ptr->next;
    }
    printf("\n");
}

void deleteAppointment(char name[]){
    NODE *temp, *prev;
    temp = head;
    prev = NULL;
    while(temp != NULL){
        if(strcmp(name, temp->data.name) == 0){
            if(prev == NULL){
                head = temp->next;
                free(temp);
            }
            else{
                prev->next = temp->next;
                free(temp);
            }
            printf("\nAppointment deleted successfully!\n\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nAppointment not found!\n\n");
}

int main(){
    int choice;
    char name[20];
    printf("\nWelcome to the Appointment Scheduler\n");
    while(1){
        printf("\nSelect an option:\n1. Add appointment\n2. Display appointments\n3. Delete appointment\n0. Exit\n\n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                addAppointment();
                break;
            case 2:
                displayAppointments();
                break;
            case 3:
                printf("\nEnter the name of the appointment to delete: ");
                scanf("%s", name);
                deleteAppointment(name);
                break;
            case 0:
                printf("\nThank you for using the Appointment Scheduler!\n\n");
                exit(0);
            default:
                printf("\nInvalid option!\n\n");
                break;
        }
    }
    return 0;
}