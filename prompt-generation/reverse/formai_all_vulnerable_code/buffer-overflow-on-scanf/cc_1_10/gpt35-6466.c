//FormAI DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for a mailing list member
typedef struct MailingListMember {
    char* name;
    char* email;
    struct MailingListMember* next;
} MailingListMember;

// Function to create a new mailing list member
MailingListMember* createMember(char* name, char* email) {
    MailingListMember* newMember = (MailingListMember*)malloc(sizeof(MailingListMember));
    newMember->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(newMember->name, name);
    newMember->email = (char*)malloc((strlen(email) + 1) * sizeof(char));
    strcpy(newMember->email, email);
    newMember->next = NULL;
    return newMember;
}

// Function to add a new member to the mailing list
void addMember(MailingListMember** list, char* name, char* email) {
    MailingListMember* newMember = createMember(name, email);
    if (*list == NULL) {
        *list = newMember;
    } else {
        MailingListMember* current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newMember;
    }
}

// Function to remove a member from the mailing list
void removeMember(MailingListMember** list, char* email) {
    if (*list == NULL) {
        return;
    }
    if (strcmp((*list)->email, email) == 0) {
        MailingListMember* temp = *list;
        *list = (*list)->next;
        free(temp->name);
        free(temp->email);
        free(temp);
        return;
    }
    MailingListMember* current = *list;
    while (current->next != NULL && strcmp(current->next->email, email) != 0) {
        current = current->next;
    }
    if (current->next == NULL) {
        return;
    }
    MailingListMember* temp = current->next;
    current->next = temp->next;
    free(temp->name);
    free(temp->email);
    free(temp);
}

// Function to print all members of the mailing list
void printList(MailingListMember* list) {
    while (list != NULL) {
        printf("%s <%s>\n", list->name, list->email);
        list = list->next;
    }
}

int main() {
    MailingListMember* list = NULL;
    int choice = 0;
    while (choice != 4) {
        printf("1: Add member\n2: Remove member\n3: Print list\n4: Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char name[50];
                char email[50];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addMember(&list, name, email);
                break;
            }
            case 2: {
                char email[50];
                printf("Enter email: ");
                scanf("%s", email);
                removeMember(&list, email);
                break;
            }
            case 3: {
                printList(list);
                break;
            }
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}