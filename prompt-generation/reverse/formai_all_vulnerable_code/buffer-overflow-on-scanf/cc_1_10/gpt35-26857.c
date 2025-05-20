//FormAI DATASET v1.0 Category: Banking Record System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BankRecord{
    char name[50];
    int accountNumber;
    float balance;
    struct BankRecord *next;
}BankRecord;

// function prototype declarations
void create(BankRecord **head, BankRecord **tail);
void insert(BankRecord **head, BankRecord **tail, char *name, int accountNumber, float balance);
void delete(BankRecord **head, BankRecord **tail, int accountNumber);
void display(BankRecord *head);
void search(BankRecord *head, int accountNumber);

int main(){
    BankRecord *head = NULL, *tail = NULL;
    int choice, accountNumber;
    char name[50];
    float balance;

    do{
        printf("\n1. Create Bank Record");
        printf("\n2. Insert Bank Record");
        printf("\n3. Delete Bank Record");
        printf("\n4. Display Bank Records");
        printf("\n5. Search Bank Record");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: create(&head, &tail);
                    break;
            case 2: printf("\nEnter name, account number and balance: ");
                    scanf("%s %d %f", name, &accountNumber, &balance);
                    insert(&head, &tail, name, accountNumber, balance);
                    break;
            case 3: printf("\nEnter account number to delete: ");
                    scanf("%d", &accountNumber);
                    delete(&head, &tail, accountNumber);
                    break;
            case 4: display(head);
                    break;
            case 5: printf("\nEnter account number to search: ");
                    scanf("%d", &accountNumber);
                    search(head, accountNumber);
                    break;
            case 6: printf("\nGoodbye!");
                    break;
            default: printf("\nInvalid choice! Try again.");
        }
    }while(choice!=6);

    return 0;
}

// function to create an empty record
void create(BankRecord **head, BankRecord **tail){
    *head = NULL;
    *tail = NULL;
    printf("\nEmpty Bank Record created!");
}

// function to insert a new record
void insert(BankRecord **head, BankRecord **tail, char *name, int accountNumber, float balance){
    BankRecord *temp = (BankRecord *)malloc(sizeof(BankRecord));
    strcpy(temp->name, name);
    temp->accountNumber = accountNumber;
    temp->balance = balance;
    temp->next = NULL;

    if(*head==NULL){
        *head = temp;
        *tail = temp;
    }
    else{
        (*tail)->next = temp;
        *tail = temp;
    }

    printf("\nRecord inserted successfully.");
}

// function to delete a record
void delete(BankRecord **head, BankRecord **tail, int accountNumber){
    BankRecord *temp = *head, *prev = NULL;

    if(temp!=NULL && temp->accountNumber==accountNumber){
        if(*head==*tail) *tail = NULL;
        *head = temp->next;
        free(temp);
        printf("\nRecord deleted successfully.");
        return;
    }
    while(temp!=NULL && temp->accountNumber!=accountNumber){
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL){
        printf("\nRecord not found!");
        return;
    }
    prev->next = temp->next;
    if(temp==*tail) *tail = prev;
    free(temp);
    printf("\nRecord deleted successfully.");
}

// function to display all records
void display(BankRecord *head){
    if(head==NULL){
        printf("\nEmpty Bank Record!");
        return;
    }
    BankRecord *temp = head;
    printf("\nBank Record details:");
    while(temp!=NULL){
        printf("\nName: %s", temp->name);
        printf("\nAccount Number: %d", temp->accountNumber);
        printf("\nBalance: $%.2f", temp->balance);
        temp = temp->next;
    }
}

// function to search a record by account number
void search(BankRecord *head, int accountNumber){
    BankRecord *temp = head;

    while(temp!=NULL && temp->accountNumber!=accountNumber){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("\nRecord not found!");
        return;
    }
    printf("\nName: %s", temp->name);
    printf("\nAccount Number: %d", temp->accountNumber);
    printf("\nBalance: $%.2f", temp->balance);
}