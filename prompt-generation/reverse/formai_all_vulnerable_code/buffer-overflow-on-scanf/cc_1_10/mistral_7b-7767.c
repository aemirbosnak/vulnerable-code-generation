//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char c;
    struct node *next;
} node;

node *reverseList(node *head) {
    node *current = head;
    node *prev = NULL;

    while (current != NULL) {
        node *nextTemp = current->next;
        current->next = prev;
        prev = current;
        current = nextTemp;
    }

    return prev;
}

void printList(node *head) {
    node *current = head;

    while (current != NULL) {
        printf("%c", current->c);
        current = current->next;
    }
}

int main() {
    FILE *file;
    char filename[100];
    size_t size;
    char *buffer;

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    buffer = (char *) calloc(size + 1, sizeof(char));

    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    fread(buffer, size, 1, file);
    fclose(file);

    node *head = NULL;
    node *temp = NULL;

    for (int i = 0; i < size; i++) {
        temp = (node *) malloc(sizeof(node));
        temp->c = buffer[i];
        temp->next = head;
        head = temp;
    }

    node *reversedHead = reverseList(head);
    printList(reversedHead);

    printf("\nSize of the file: %ld bytes\n", size);

    node *current = reversedHead;

    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }

    free(buffer);

    return 0;
}