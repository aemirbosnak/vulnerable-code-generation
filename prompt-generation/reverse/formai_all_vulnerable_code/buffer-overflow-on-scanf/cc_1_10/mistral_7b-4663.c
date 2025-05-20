//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

typedef struct Element {
    char value;
    struct Element *next;
} Element;

Element *createNode(char value) {
    Element *newNode = (Element *)malloc(sizeof(Element));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Element **head, char value) {
    Element *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

int dynamicSearch(Element *head, char searchChar) {
    int step = 1, position = 0;
    Element *current = head;

    while (current != NULL) {
        if (current->value == searchChar)
            return position;

        if (step == 1 && current->next == NULL)
            return -1;

        current = current->next;
        position += step;

        if (current->value > searchChar) {
            step *= 2;
            continue;
        }

        step = 1;
    }

    return -1;
}

int main() {
    Element *head = NULL;
    char arr[SIZE], searchChar;
    int i;

    printf("Enter the array elements separated by spaces: ");
    fgets(arr, SIZE, stdin);
    arr[strcspn(arr, "\n")] = '\0';

    for (i = 0; i < strlen(arr); i++) {
        insertAtBeginning(&head, arr[i]);
    }

    printf("Enter the character to search: ");
    scanf("%c", &searchChar);

    int result = dynamicSearch(head, searchChar);

    if (result == -1)
        printf("Character not found.\n");
    else
        printf("Character found at position %d.\n", result);

    return 0;
}