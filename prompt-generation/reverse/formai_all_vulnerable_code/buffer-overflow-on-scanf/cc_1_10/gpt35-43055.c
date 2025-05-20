//FormAI DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct MailingList {
    char name[50];
    char email[50];
};

void addToList(struct MailingList *list, int *size);
void getList(struct MailingList *list, int size);
void searchList(struct MailingList *list, int size);

int main() {
    struct MailingList list[MAX_SIZE];
    int size = 0;
    int choice;

    while(1) {
        printf("Select an option:\n");
        printf("1. Add to list\n");
        printf("2. Get list\n");
        printf("3. Search list\n");
        printf("4. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addToList(list, &size);
                break;
            case 2:
                getList(list, size);
                break;
            case 3:
                searchList(list, size);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }

        printf("\n");
    }   

    return 0;
}

void addToList(struct MailingList *list, int *size) {
    char name[50], email[50];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);

    strcpy(list[*size].name, name);
    strcpy(list[*size].email, email);

    *size += 1;
    printf("Added to list successfully!\n");
}

void getList(struct MailingList *list, int size) {
    if(size == 0) {
        printf("The list is empty!\n");
        return;
    }

    printf("Name\t\tEmail\n");
    printf("====\t\t=====\n");

    for(int i = 0; i < size; i++) {
        printf("%s\t\t%s\n", list[i].name, list[i].email);
    }
}

void searchList(struct MailingList *list, int size) {
    if(size == 0) {
        printf("The list is empty!\n");
        return;
    }

    char search[50];
    int found = 0;

    printf("Enter name or email to search: ");
    scanf("%s", search);

    printf("Results:\n");
    printf("Name\t\tEmail\n");
    printf("====\t\t=====\n");

    for(int i = 0; i < size; i++) {
        if(strcmp(list[i].name, search) == 0 || strcmp(list[i].email, search) == 0) {
            printf("%s\t\t%s\n", list[i].name, list[i].email);
            found = 1;
        }
    }

    if(!found) {
        printf("No results found.\n");
    }
}