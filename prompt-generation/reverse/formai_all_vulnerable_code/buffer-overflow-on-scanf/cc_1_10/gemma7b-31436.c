//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SIZE 4

typedef struct Page {
    char **data;
    struct Page *next;
} Page;

void insertPage(Page **head, char **data) {
    Page *newNode = malloc(sizeof(Page));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
        *head = newNode;
    }
}

void readEbook(Page **head) {
    char **data = NULL;
    int pageNumber = 0;

    printf("Enter page number: ");
    scanf("%d", &pageNumber);

    data = (*head)->data[pageNumber - 1];

    if (data) {
        printf("Page content: \n");
        printf("%s\n", data);
    } else {
        printf("Page not found.\n");
    }
}

int main() {
    Page **head = NULL;

    // Insert some pages
    insertPage(head, "Hello, world!");
    insertPage(head, "This is the second page.");
    insertPage(head, "The third page content.");

    readEbook(head);

    return 0;
}