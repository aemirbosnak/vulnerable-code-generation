//FormAI DATASET v1.0 Category: Data recovery tool ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_LENGTH 1000

typedef struct Node {
    char data[MAX_DATA_LENGTH];
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void initializeList(LinkedList* list) {
    list->head = NULL;
}

void insertNode(LinkedList* list, char* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node != NULL) {
        strcpy(node->data, data);
        node->next = list->head;
        list->head = node;
    }
}

void printList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    LinkedList list;
    initializeList(&list);

    printf("Welcome to Retro Data Recovery Tool!\n\n");

    int num_files;
    printf("How many files would you like to recover? ");
    scanf("%d", &num_files);

    for (int i = 1; i <= num_files; i++) {
        char filename[MAX_DATA_LENGTH];
        printf("Enter filename for file %d: ", i);
        scanf("%s", filename);

        char* data = (char*)malloc(MAX_DATA_LENGTH * sizeof(char));
        if (data != NULL) {
            printf("Enter data for %s (max length %d): ", filename, MAX_DATA_LENGTH);
            scanf("%s", data);
            insertNode(&list, data);
            free(data);
        }
    }

    printf("\nRecovered Files:\n");
    printList(&list);

    printf("\nThank you for using Retro Data Recovery Tool!\n");

    return 0;
}