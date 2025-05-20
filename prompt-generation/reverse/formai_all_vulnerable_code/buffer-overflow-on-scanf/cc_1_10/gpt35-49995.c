//FormAI DATASET v1.0 Category: Mailing list manager ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining a struct for the contacts
struct contact{
    char name[30];
    char email[50];
    struct contact* next;
};

//Function to add a new contact to the mailing list
void addContact(struct contact** head_ref){

    struct contact* new_contact = (struct contact*) malloc(sizeof(struct contact));
    printf("Enter name of the contact: ");
    scanf("%s",new_contact->name);
    printf("Enter email of the contact: ");
    scanf("%s",new_contact->email);

    new_contact->next = (*head_ref);
    (*head_ref) = new_contact;
}

//Function to search for a contact in the mailing list
void searchContact(struct contact* head,char* email){

    struct contact* current_contact = head;
    while(current_contact!=NULL){
        if(strcmp(current_contact->email,email)==0){
            printf("Contact found!\n");
            printf("Name: %s\n",current_contact->name);
            printf("Email: %s\n",current_contact->email);
            return;
        }
        current_contact = current_contact->next;
    }
    printf("Contact not found!\n");

}

//Function to delete a contact from the mailing list
void deleteContact(struct contact** head_ref,char* email){

    struct contact* current_contact = (*head_ref);
    struct contact* prev_contact = NULL;

    //If head node itself holds the email to be deleted
    if(current_contact!=NULL && strcmp(current_contact->email,email)==0){
        (*head_ref) = current_contact->next;
        free(current_contact);
        printf("Contact deleted successfully!\n");
        return;
    }

    //Search for the email to be deleted and keep track of previous node
    while(current_contact!=NULL && strcmp(current_contact->email,email)!=0){
        prev_contact = current_contact;
        current_contact = current_contact->next;
    }

    //If contact was not found
    if(current_contact==NULL){
        printf("Contact not found!\n");
        return;
    }

    //Unlink the node from the list
    prev_contact->next = current_contact->next;
    free(current_contact);
    printf("Contact deleted successfully!\n");
}

//Function to print all contacts in the mailing list
void printContacts(struct contact* head){

    printf("List of all contacts:\n");
    struct contact* current_contact = head;
    while(current_contact!=NULL){
        printf("Name: %s\n",current_contact->name);
        printf("Email: %s\n\n",current_contact->email);
        current_contact = current_contact->next;
    }

}

//Main Function
int main(){

    struct contact* head = NULL;

    while(1){

        printf("\nMenu: \n1. Add contact\n2. Search for contact\n3. Delete contact\n4. Print all contacts\n5. Exit\n");
        printf("\nEnter your choice (1-5): ");
        int choice;
        scanf("%d",&choice);

        switch(choice){
            case 1: //Add contact
                addContact(&head);
                break;
            case 2: //Search for contact
                printf("Enter email of the contact to be searched: ");
                char email_to_search[50];
                scanf("%s",email_to_search);
                searchContact(head,email_to_search);
                break;
            case 3: //Delete contact
                printf("Enter email of the contact to be deleted: ");
                char email_to_delete[50];
                scanf("%s",email_to_delete);
                deleteContact(&head,email_to_delete);
                break;
            case 4: //Print all contacts
                printContacts(head);
                break;
            case 5: //Exit
                printf("Exiting..\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;

}