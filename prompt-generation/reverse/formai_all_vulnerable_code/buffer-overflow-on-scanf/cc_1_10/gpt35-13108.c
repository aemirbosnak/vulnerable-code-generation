//FormAI DATASET v1.0 Category: Mailing list manager ; Style: careful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Structure for storing the information of mailing list subscriber 
struct Subscriber{
    char name[100];
    char email[100];
    int age;
    struct Subscriber* next;
};

//Function to add new subscriber to the mailing list
struct Subscriber* addSubscriber(struct Subscriber* head, char name[], char email[], int age){
    //Dynamic allocation of memory for new subscriber node
    struct Subscriber* newSubscriber = (struct Subscriber*)malloc(sizeof(struct Subscriber));
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);
    newSubscriber->age = age;
    newSubscriber->next = NULL;

    if(head == NULL){
        head = newSubscriber;
    }
    else{
        struct Subscriber* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newSubscriber;
    }
    return head;
}

//Function to search for a subscriber based on their email
void searchSubscriber(struct Subscriber* head, char email[]){
    struct Subscriber* ptr = head;
    while(ptr != NULL){
        if(strcmp(ptr->email, email) == 0){
            printf("\nSubscriber Found:");
            printf("\nName: %s",ptr->name);
            printf("\nEmail: %s",ptr->email);
            printf("\nAge: %d\n",ptr->age);
            return;
        }
        else{
            ptr = ptr->next;
        }
    }
    printf("\nSubscriber Not Found!\n");
}

//Function to delete a subscriber from the mailing list
struct Subscriber* deleteSubscriber(struct Subscriber* head, char email[]){
    if(head == NULL){
        printf("\nMailing list is empty!\n");
        return head;
    }
    struct Subscriber* ptr = head;
    struct Subscriber* prev = NULL;
    while(ptr != NULL){
        if(strcmp(ptr->email, email) == 0){
            if(ptr == head){
                head = head->next;
            }
            else{
                prev->next = ptr->next;
            }
            free(ptr);
            printf("\nSubscriber with email %s has been deleted from the mailing list.\n", email);
            return head;
        }
        else{
            prev = ptr;
            ptr = ptr->next;
        }
    }
    printf("\nSubscriber with email %s not found!\n", email);
    return head;
}

//Function to display all subscribers in the mailing list
void displayMailingList(struct Subscriber* head){
    if(head == NULL){
        printf("\nMailing list is empty!\n");
        return;
    }
    printf("\nMailing List:\n");
    struct Subscriber* ptr = head;
    while(ptr != NULL){
        printf("\nName: %s",ptr->name);
        printf("\nEmail: %s",ptr->email);
        printf("\nAge: %d\n",ptr->age);
        ptr = ptr->next;
    }
    return;
}

int main(){
    struct Subscriber* head = NULL;
    int choice,age;
    char name[100], email[100], searchEmail[100];
    while(1){
        printf("\n-------MAILING LIST MANAGER--------\n");
        printf("\n1. Add Subscriber\n2. Search Subscriber\n3. Delete Subscriber\n4. Display Mailing List\n5. Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter Subscriber name: ");
                scanf("%s",name);
                printf("\nEnter Subscriber email: ");
                scanf("%s",email);
                printf("\nEnter Subscriber age: ");
                scanf("%d",&age);
                head = addSubscriber(head, name, email, age);
                printf("\nSubscriber added to mailing list successfully!\n");
                break;
            case 2:
                printf("\nEnter email of the Subscriber you want to search for: ");
                scanf("%s",searchEmail);
                searchSubscriber(head, searchEmail);
                break;
            case 3:
                printf("\nEnter email of the Subscriber you want to delete: ");
                scanf("%s",searchEmail);
                head = deleteSubscriber(head, searchEmail);
                break;
            case 4:
                displayMailingList(head);
                break;
            case 5:
                printf("\nThank you for using the mailing list manager!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}