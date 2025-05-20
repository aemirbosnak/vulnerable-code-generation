//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define ELEMENT_SIZE 100

typedef struct {
    char name[ELEMENT_SIZE];
} ListElement;

typedef struct {
    ListElement elements[MAX_LIST_SIZE];
    int count;
} List;

void initList(List *list) {
    list->count = 0;
}

int addElement(List *list, char *name) {
    if (list->count >= MAX_LIST_SIZE) {
        return 0;
    }

    strcpy(list->elements[list->count].name, name);
    list->count++;

    return 1;
}

void printList(List list) {
    for (int i = 0; i < list.count; i++) {
        printf("Survivor %d: %s\n", i, list.elements[i].name);
    }
}

int main() {
    List survivors;
    initList(&survivors);

    char name[ELEMENT_SIZE];

    while (1) {
        printf("Enter a survivor name (or 'quit' to exit): ");
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        addElement(&survivors, name);
    }

    printf("\nSurvivor list:\n");
    printList(survivors);

    return 0;
}