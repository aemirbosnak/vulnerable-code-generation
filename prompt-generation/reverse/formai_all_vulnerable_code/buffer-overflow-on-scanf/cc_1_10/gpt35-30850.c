//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mailing_list {
    char name[50];
    char email[50];
    struct mailing_list *next;
};

//Function to add a new member to the list
void add_member(struct mailing_list **head_ref, char *name, char *email) {
    struct mailing_list *new_member = (struct mailing_list*) malloc(sizeof(struct mailing_list));
    strcpy(new_member->name, name);
    strcpy(new_member->email, email);
    new_member->next = *head_ref;
    *head_ref = new_member;
    printf("\nMember added successfully!\n");
}

//Function to remove a member from the list
void remove_member(struct mailing_list **head_ref, char *name) {
    struct mailing_list *temp = *head_ref, *prev;
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head_ref = temp->next; 
        free(temp); 
        printf("\nMember removed successfully!\n");
        return;
    }
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nThe member with name '%s' does not exist in the list!\n", name);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("\nMember removed successfully!\n");
}

//Function to print the entire mailing list
void print_list(struct mailing_list *head) {
    printf("\nName\t\tEmail\n");
    while (head != NULL) {
        printf("%s\t\t%s\n", head->name, head->email);
        head = head->next;
    }
}

int main() { 
    struct mailing_list *head = NULL; 
    char choice, name[50], email[50];
    printf("******* Mailing List Manager *******\n");
    do {
        printf("\nPlease choose an option from the menu:\n\n");
        printf("1. Add a Member\n");
        printf("2. Remove a Member\n");
        printf("3. Print the Mailing List\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice); 
        switch(choice) {
            case '1': 
                printf("\nEnter the name of the member: ");
                scanf("%s", name);
                printf("Enter the email of the member: ");
                scanf("%s", email);
                add_member(&head, name, email);
                break;
            case '2':
                printf("\nEnter the name of the member to be removed: ");
                scanf("%s", name);
                remove_member(&head, name);
                break;
            case '3':
                print_list(head);
                break;
            case '4':
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != '4');
    return 0;
}