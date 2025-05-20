//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct appointment{
    char name[25], id[10], date[15], time[10];
    int priority;
};

struct node{
    struct appointment data;
    struct node *next;
}*head=NULL, *tail=NULL;

int choice;

//function prototypes
void displayMenu();
void createAppointment();
void displayAppointments(struct node *p);
int totalAppointments();
void searchAppointment();
void cancelAppointment();

int main(){
    printf("\t\t***Welcome to Appointment Scheduler***\n");
    printf("********************************************\n\n");

    do{
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: createAppointment(); break;
            case 2: displayAppointments(head); break;
            case 3: searchAppointment(); break;
            case 4: cancelAppointment(); break;
            case 5: printf("\nThank you for using Appointment Scheduler!\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice!=5);

    return 0;
}

//function to display menu
void displayMenu(){
    printf("\n============================================\n");
    printf("1. Create appointment\n");
    printf("2. Display appointments\n");
    printf("3. Search for an appointment\n");
    printf("4. Cancel an appointment\n");
    printf("5. Exit\n");
    printf("============================================\n");
}

//function to create new appointment
void createAppointment(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter patient's name: ");
    scanf("%s", &temp->data.name);
    printf("Enter patient's ID: ");
    scanf("%s", &temp->data.id);
    printf("Enter appointment date (dd/mm/yyyy): ");
    scanf("%s", &temp->data.date);
    printf("Enter appointment time (hh:mm): ");
    scanf("%s", &temp->data.time);
    printf("Enter priority level (1-5, 5 being highest priority): ");
    scanf("%d", &temp->data.priority);

    temp->next=NULL;

    if(head==NULL){
        head=tail=temp;
    }
    else{
        //sort appointments by priority
        if(temp->data.priority > head->data.priority){
            temp->next = head;
            head = temp;
        }
        else{
            struct node *p = head;
            while(p->next!=NULL && temp->data.priority <= p->next->data.priority){
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
            if(temp->next == NULL){
                tail = temp;
            }
        }
    }
    printf("\nAppointment added successfully!\n");
}

//function to display all appointments
void displayAppointments(struct node *p){
    if(p==NULL){
        printf("\nNo appointments found!\n");
    }
    else{
        printf("\n*************************************************\n");
        printf("Patient Name\tID\tDate\t\tTime\tPriority\n");
        printf("*************************************************\n");
        while(p!=NULL){
            printf("%-12s\t%s\t%s\t%s\t%d\n", p->data.name, p->data.id, p->data.date, p->data.time, p->data.priority);
            p = p->next;
        }
    }
}

//function to count total number of appointments
int totalAppointments(){
    int count=0;
    struct node *p = head;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}

//function to search for an appointment
void searchAppointment(){
    if(head==NULL){
        printf("\nNo appointments found!\n");
    }
    else{
        char id[10];
        printf("\nEnter patient's ID: ");
        scanf("%s", &id);

        struct node *p = head;
        while(p!=NULL){
            if(strcmp(p->data.id, id)==0){
                printf("\nAppointment found!\n");
                printf("Patient Name: %s\n", p->data.name);
                printf("Appointment Date: %s\n", p->data.date);
                printf("Appointment Time: %s\n", p->data.time);
                printf("Priority Level: %d\n", p->data.priority);
                break;
            }
            else{
                p = p->next;
            }
        }
        if(p==NULL){
            printf("\nAppointment not found!\n");
        }
    }
}

//function to cancel an appointment
void cancelAppointment(){
    if(head==NULL){
        printf("\nNo appointments found!\n");
    }
    else{
        char id[10];
        printf("\nEnter patient's ID: ");
        scanf("%s", &id);

        if(strcmp(head->data.id, id)==0){
            struct node *temp = head;
            head = head->next;
            free(temp);
            printf("\nAppointment cancelled successfully!\n");
        }
        else{
            struct node *p = head;
            while(p->next!=NULL){
                if(strcmp(p->next->data.id, id)==0){
                    struct node *temp = p->next;
                    if(temp->next == NULL){
                        tail = p;
                    }
                    p->next = temp->next;
                    free(temp);
                    printf("\nAppointment cancelled successfully!\n");
                    break;
                }
                else{
                    p = p->next;
                }
            }
            if(p->next==NULL){
                printf("\nAppointment not found!\n");
            }
        }
    }
}