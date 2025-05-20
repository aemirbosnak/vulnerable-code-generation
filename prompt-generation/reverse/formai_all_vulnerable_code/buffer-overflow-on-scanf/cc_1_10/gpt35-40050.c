//FormAI DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to hold member information
typedef struct member {
    char name[50];
    char email[50];
    struct member *next; //Pointer to the next member in the list
} Member;

//Function to add a new member to the mailing list
void add_member(Member **start, char *name, char *email) {
    Member *new_member = (Member*) malloc(sizeof(Member)); //Allocate memory for new member
    strcpy(new_member->name, name); //Copy name string to new member
    strcpy(new_member->email, email); //Copy email string to new member
    new_member->next = *start; //Set the pointer of the new member to the current start of the list
    *start = new_member; //Set the new member as the new start of the list
}

//Function to remove a member from the mailing list
void remove_member(Member **start, char *email) {
    Member *current = *start;
    Member *previous = NULL;
    //Loop through the list to find the member with the matching email
    while(current != NULL) {
        if(strcmp(current->email, email) == 0) {
            if(previous == NULL) { //If the first member matches the specified email
                *start = current->next; //Set the next member as the new start of the list
            }
            else {
                previous->next = current->next; //Set the pointer of the previous member to the next member
            }
            free(current); //Free memory of the removed member
            printf("Member with email '%s' has been removed from the mailing list.\n", email);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("No member with email '%s' was found in the mailing list.\n", email);
}

//Function to print the mailing list
void print_list(Member *start) {
    if(start == NULL) { //If the mailing list is empty
        printf("The mailing list is empty.\n");
        return;
    }
    printf("====Mailing List:====\n");
    while(start != NULL) {
        printf("Name: %s, Email: %s\n", start->name, start->email); //Print member information
        start = start->next;
    }
    printf("======================\n");
}

int main() {
    Member *start = NULL; //Initialize mailing list as empty
    int choice;
    char name[50], email[50];
    printf("Welcome to the Mailing List Manager Program!\n");
    do {
        printf("\nPlease select an option:\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Print Mailing List\n");
        printf("4. Exit Program\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_member(&start, name, email);
                printf("Member with email '%s' has been added to the mailing list.\n", email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_member(&start, email);
                break;
            case 3:
                print_list(start);
                break;
            case 4:
                printf("Thank you for using the Mailing List Manager Program!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4); //Continue the loop until the user chooses to exit
    return 0;
}