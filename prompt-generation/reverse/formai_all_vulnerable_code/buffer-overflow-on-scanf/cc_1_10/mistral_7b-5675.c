//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char name[50];
    char description[200];
    struct Node* next;
} Node;

Node* createNode(char* name, char* description) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->description, description);
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(Node* head) {
    if (head == NULL) {
        return true;
    }
    return false;
}

void addEntry(Node** head, char* name, char* description) {
    Node* newNode = createNode(name, description);

    if (isEmpty(*head)) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayDiary(Node* head) {
    if (isEmpty(head)) {
        printf("Diary is empty.\n");
        return;
    }

    printf("---------------------------------------------------\n");
    printf("| Name             | Description              |\n");
    printf("---------------------------------------------------\n");

    Node* current = head;

    while (current != NULL) {
        printf("| %-50s | %-200s |\n", current->name, current->description);
        current = current->next;
    }

    printf("---------------------------------------------------\n");
}

int main() {
    Node* diaryHead = NULL;

    int choice = 1;
    char name[50], description[200];

    while (choice != 0) {
        printf("\nDigital Diary\n");
        printf("1. Add Entry\n");
        printf("2. Display Diary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Description: ");
                scanf("%s", description);
                addEntry(&diaryHead, name, description);
                break;
            case 2:
                displayDiary(diaryHead);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice. Try again.\n");
        }
    }

    return 0;
}