//FormAI DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure for the mailing list
typedef struct {
    char name[50];
    char email[100];
} MailingList;

// function to add a new member to the mailing list
void addNewMember(MailingList **list, int *memberCount) {
    // allocate memory for new member
    MailingList *newMember = (MailingList*) malloc(sizeof(MailingList));
    if (newMember == NULL) { // if memory allocation failed
        printf("Error: could not allocate memory for new member\n");
        return;
    }
    // ask user for name and email
    printf("Enter name: ");
    scanf("%s", newMember->name);
    printf("Enter email: ");
    scanf("%s", newMember->email);
    // increase member count
    (*memberCount)++;
    // reallocate memory for mailing list
    *list = (MailingList*) realloc(*list, (*memberCount) * sizeof(MailingList));
    if (*list == NULL) { // if memory reallocation failed
        printf("Error: could not reallocate memory for mailing list\n");
        return;
    }
    // add new member to mailing list
    (*list)[(*memberCount) - 1] = *newMember;
    printf("New member added successfully\n");
}

// function to remove a member from the mailing list
void removeMember(MailingList **list, int *memberCount) {
    // ask user for email of member to be removed
    char email[100];
    printf("Enter email of member to be removed: ");
    scanf("%s", email);
    // search for member with given email
    int found = 0;
    int index = 0;
    for (int i = 0; i < *memberCount; i++) {
        if (strcmp((*list)[i].email, email) == 0) {
            found = 1;
            index = i;
            break;
        }
    }
    if (!found) { // if member not found
        printf("Error: member with given email not found\n");
        return;
    }
    // remove member from mailing list
    for (int i = index; i < (*memberCount) - 1; i++) {
        (*list)[i] = (*list)[i + 1];
    }
    (*memberCount)--;
    // reallocate memory for mailing list
    *list = (MailingList*) realloc(*list, (*memberCount) * sizeof(MailingList));
    if (*list == NULL) { // if memory reallocation failed
        printf("Error: could not reallocate memory for mailing list\n");
        return;
    }
    printf("Member removed successfully\n");
}

// function to display the mailing list
void displayMailingList(MailingList *list, int memberCount) {
    if (memberCount == 0) { // if mailing list is empty
        printf("Mailing list is empty\n");
        return;
    }
    printf("Mailing list:\n");
    for (int i = 0; i < memberCount; i++) {
        printf("%d. Name: %s, Email: %s\n", i + 1, list[i].name, list[i].email);
    }
}

int main() {
    MailingList *list = NULL; // initialize mailing list to NULL pointer
    int memberCount = 0; // initialize member count to zero
    int choice;
    do {
        printf("\n\n");
        printf("1. Add new member\n");
        printf("2. Remove a member\n");
        printf("3. Display mailing list\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addNewMember(&list, &memberCount);
                break;
            case 2:
                removeMember(&list, &memberCount);
                break;
            case 3:
                displayMailingList(list, memberCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: invalid choice\n");
                break;
        }
    } while (choice != 4);
    // free memory used by mailing list
    free(list);
    return 0;
}