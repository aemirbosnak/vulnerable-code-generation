//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each member of the mailing list
typedef struct{
    char name[50];
    char email[100];
}MailingList;

// Function to add new members to the mailing list
void addToMailingList(MailingList *list, int *size){
    printf("\nEnter name: ");
    scanf("%s", (list + *size)->name);

    printf("\nEnter email: ");
    scanf("%s", (list + *size)->email);

    *size = *size + 1;

    printf("\n%s has been added to the mailing list.\n", (list + (*size-1))->name);
}

// Function to remove a member from the mailing list
void removeFromMailingList(MailingList *list, int *size){
    char target[50];
    int found = 0;

    printf("\nEnter name or email to remove: ");
    scanf("%s", target);

    // Check if the target is in the mailing list
    for(int i=0; i<*size; i++){
        if(strcmp(target, (list + i)->name) == 0 || strcmp(target, (list + i)->email) == 0){
            found = 1;

            // Remove the member from the mailing list
            *size = *size - 1;
            for(int j=i; j<*size; j++){
                strcpy((list + j)->name, (list + j + 1)->name);
                strcpy((list + j)->email, (list + j + 1)->email);
            }
            printf("\n%s has been removed from the mailing list.\n", target);
            break;
        }
    }

    if(!found) printf("\nCould not find %s in the mailing list.\n", target);
}

// Function to display all members in the mailing list
void displayMailingList(MailingList *list, int *size){
    printf("\nMembers in the mailing list:\n");
    for(int i=0; i<*size; i++){
        printf("%s - %s\n", (list + i)->name, (list + i)->email);
    }
}

int main(){
    MailingList *list;
    int size = 0, choice;

    // Allocate memory for mailing list
    list = (MailingList*) malloc(sizeof(MailingList)*100);

    // Prompt user for choices until exit
    do{
        printf("\n-----------Mailing List Manager-----------\n");
        printf("1. Add new member to mailing list.\n");
        printf("2. Remove member from mailing list.\n");
        printf("3. Display all members in mailing list.\n");
        printf("4. Exit.\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addToMailingList(list, &size);
                break;

            case 2:
                removeFromMailingList(list, &size);
                break;

            case 3:
                displayMailingList(list, &size);
                break;

            case 4:
                printf("\nExiting program.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    }while(choice != 4);
    
    // Free allocated memory
    free(list);

    return 0;
}