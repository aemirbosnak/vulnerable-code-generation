//FormAI DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node_tag{
    char email[30];
    struct node_tag *next;
}NODE;

NODE *head = NULL;
NODE *tail = NULL;

void addEmail(){
    NODE *newNode;
    newNode = (NODE *) malloc(sizeof(NODE));
    if(newNode == NULL){
        printf("\nUnable to add email address.");
        return;
    }

    printf("\nEnter the email address: ");
    scanf("%s", newNode -> email);
    newNode -> next = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> next = newNode;
        tail = newNode;
    }
    printf("\nEmail added successfully!");
}

void displayList(){
    NODE *temp;
    temp = head;
    if(temp == NULL){
        printf("\nThe mailing list is empty.");
    }
    else{
        printf("\nMailing List\n------------\n");
        while(temp != NULL){
            printf("%s\n",temp -> email);
            temp = temp -> next;
        }
    }
}

void searchList(){
    NODE *temp;
    char searchEmail[30];
    int found = 0; 
    temp = head;
    printf("\nEnter the email address to be searched: ");
    scanf("%s", searchEmail);
    if(temp == NULL){
        printf("\nThe mailing list is empty.");
    }
    else{
        while(temp != NULL){
            if(strcmp(temp -> email, searchEmail) == 0){
                printf("\nEmail address is found in the list.");
                found = 1;
                break;
            }
            temp = temp -> next;
        }
        if (found == 0)
            printf("\nEmail address is not found in the list.");
    }
}

void deleteEmail(){
    NODE *temp, *prev;
    char searchEmail[30];
    temp = head;
    printf("\nEnter the email address to be deleted: ");
    scanf("%s", searchEmail);
    if(temp == NULL){
        printf("\nThe mailing list is empty.");
    }
    else{
        prev = head;
        while(temp != NULL){
            if(strcmp(temp -> email, searchEmail) == 0){
                if(temp == head){
                    head = temp -> next;
                    free(temp);
                }
                else if(temp == tail){
                    prev -> next = NULL;
                    tail = prev;
                    free(temp);
                }
                else{
                    prev -> next = temp -> next;
                    free(temp);
                }
                printf("\nEmail address is deleted from the mailing list.");
                return;
            }
            else{
                prev = temp;
                temp = temp -> next;
            }
        }
        printf("\nEmail address is not found in the mailing list.");
    }
}
int main(){
    int choice;
    do{
        printf("\nSelect an option\n----------------\n");
        printf("1. Add an email address\n");
        printf("2. Display the mailing list\n");
        printf("3. Search for an email address\n");
        printf("4. Delete an email address\n");
        printf("5. Exit\n");
        printf("----------------\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                addEmail();
                break;
            case 2:
                displayList();
                break;
            case 3:
                searchList();
                break;
            case 4:
                deleteEmail();
                break;
            case 5:
                printf("\nExiting mailing list manager...");
                exit(0);
                break;
            default:
                printf("\nInvalid option. Please select again.\n");
        }
    }while(1);
    return 0;
}