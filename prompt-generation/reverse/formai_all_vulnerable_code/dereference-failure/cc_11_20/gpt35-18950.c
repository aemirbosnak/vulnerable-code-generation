//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

int main() {
    Node *head = NULL, *current = NULL;

    // Read the input file
    char *filename = "input.txt";
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return EXIT_FAILURE;
    }

    // Traverse the file data and create a linked list
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        Node *newNode = malloc(sizeof(Node));
        newNode->data = ch;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        }
        else {
            current->next = newNode;
            current = current->next;
        }
    }

    fclose(file);

    // Traverse the linked list and recover the data
    Node *ptr1 = head, *ptr2 = head;
    int found = 0;

    while (ptr1 != NULL && ptr2 != NULL && found == 0) {
        if (ptr1 == ptr2 && ptr1 != head) {
            found = 1;
            break;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }

    if (found == 0) {
        fprintf(stderr, "Error: Could not recover any data!\n");
        return EXIT_FAILURE;
    }

    // Traverse the linked list from head to ptr1 and print the data
    printf("Recovered Data:\n");

    Node *temp = NULL;
    while (head != ptr1) {
        printf("%c", head->data);
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("\n");

    return EXIT_SUCCESS;
}