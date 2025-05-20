//FormAI DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct mailingList {
    char name[MAX];
    char email[MAX];
    int age;
};

struct mailingList list[MAX];
int count = 0;

void addToList() {
    if (count < MAX) {
        printf("Enter name: ");
        fgets(list[count].name, MAX, stdin);
        printf("Enter email: ");
        fgets(list[count].email, MAX, stdin);
        printf("Enter age: ");
        scanf("%d", &list[count].age);
        getchar(); //clear the buffer
        printf("Successfully added to the list!\n");
        count++;
    } else {
        printf("Mailing list is full!\n");
    }
}

void printList() {
    printf("----- Mailing List -----\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %sEmail: %sAge: %d\n", list[i].name, list[i].email, list[i].age);
    }
}

void mainMenu() {
    printf("\n------- Mailing List Manager -------\n");
    printf("1. Add Person to the List\n");
    printf("2. Print Entire Mailing List\n");
    printf("3. Exit Program\n");
    printf("Select an option: ");
}

int main(void) {
    int choice;

    do {
        mainMenu();
        scanf("%d", &choice);
        getchar(); //clear the buffer

        switch (choice) {
            case 1:
                addToList();
                break;
            case 2:
                printList();
                break;
            case 3:
                printf("\nThank you for using Mailing List Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}