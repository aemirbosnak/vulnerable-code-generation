//FormAI DATASET v1.0 Category: Mailing list manager ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to hold mailing list data
struct mailingList{
    int id;
    char name[50];
    char email[50];
    struct mailingList *next;
}; 

struct mailingList *head = NULL;

int count = 0; //To maintain the number of records in the linked list

//Function to insert new email data into the linked list
void insertData(int id, char name[], char email[]){
    struct mailingList *newData = (struct mailingList*)malloc(sizeof(struct mailingList));
    newData->id = id;
    strcpy(newData->name, name);
    strcpy(newData->email, email);
    newData->next = NULL;
    
    if(head == NULL){
        head = newData;
    }else{
        struct mailingList *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newData;
    }
    count++;
}

//Function to delete email data from the linked list based on the email id
void deleteData(int id){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    else{
        struct mailingList *temp = head;
        struct mailingList *prev = NULL;
        while(temp != NULL && temp->id != id){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Record not found.\n");
        }else{
            if(prev == NULL){
                head = temp->next;
            }else{
                prev->next = temp->next;
                free(temp);
                count--;
                printf("Record deleted successfully.\n");
            }
        }
    }
}

//Function to display all records in the linked list
void displayData(){
    if(head == NULL){
        printf("No records found.\n");
    }else{
        printf("ID\tName\tEmail\n");
        printf("---------------------------------------------------\n");
        struct mailingList *temp = head;
        while(temp != NULL){
            printf("%d\t%s\t%s\n", temp->id, temp->name, temp->email);
            temp = temp->next;
        }
        printf("---------------------------------------------------\n");
        printf("Total Records: %d\n", count);
    }
}

int main(){
    int option, id;
    char name[50], email[50];
    
    do{
        printf("**********Mailing List Manager**********\n");
        printf("1. Add new record.\n");
        printf("2. Delete a record.\n");
        printf("3. Display all records.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                insertData(count+1, name, email);
                printf("Record added successfully.\n");
                break;
            case 2:
                printf("Enter the ID to delete: ");
                scanf("%d", &id);
                deleteData(id);
                break;
            case 3:
                displayData();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }while(option != 4);
    
    return 0;
}