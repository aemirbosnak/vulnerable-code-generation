//FormAI DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold mailing list details
struct MailingList {
    char name[30];
    char address[50];
    char email[50];
};

// Function to add new entry to mailing list
void addEntry(struct MailingList *list, int index) {
    getchar(); // Consume newline character
    printf("\nEnter name: ");
    fgets(list[index].name, 30, stdin);
    printf("Enter address: ");
    fgets(list[index].address, 50, stdin);
    printf("Enter email: ");
    fgets(list[index].email, 50, stdin);
}

// Function to display all entries in mailing list
void displayList(struct MailingList *list, int size) {
    printf("\n------- Mailing List -------\n");
    for(int i=0; i<size; i++) {
        printf("Index[%d]: %s %s %s", i+1, list[i].name, list[i].address, list[i].email);
    }
    printf("-----------------------------\n\n");
}

int main() {
    int size = 10;
    struct MailingList list[size]; // Create mailing list of size 10
    int choice = 0, index = 0;

    while(choice != 3) {
        printf("1. Add new entry\n");
        printf("2. Display mailing list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(index < size) {
                    addEntry(list, index);
                    index++;
                }
                else {
                    printf("\nMailing list is full.\n");
                }
                break;

            case 2:
                if(index > 0) {
                    displayList(list, index);
                }
                else {
                    printf("\nMailing list is empty.\n");
                }
                break;

            case 3:
                printf("\nExiting program.\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}