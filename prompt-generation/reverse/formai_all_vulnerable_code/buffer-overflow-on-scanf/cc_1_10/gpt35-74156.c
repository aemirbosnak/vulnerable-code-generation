//FormAI DATASET v1.0 Category: Database Indexing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_AGE 3
#define MAX_INDEX 26

typedef struct {
    char name[MAX_NAME];
    int age;
} Person;

typedef struct node {
    Person person;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} Index;

Index indexTable[MAX_INDEX];

void addPersonNode(Index *index, Person person) {
    Node *node = malloc(sizeof(Node));
    if (node != NULL) {
        node->person = person;
        node->next = index->head;
        index->head = node;
        index->count++;
    }
}

void printIndex(Index *index) {
    Node *current = index->head;
    while (current != NULL) {
        printf("Name: %s, Age: %d\n", current->person.name, current->person.age);
        current = current->next;
    }
}

int getIndex(char *name) {
    return name[0] - 'a';
}

int main() {
    char name[MAX_NAME];
    int age;
    int index;
    Person person;

    while (1) {
        printf("Enter name (or exit to quit): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // remove newline character
        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);
        getchar(); // remove newline character

        person.age = age;
        strcpy(person.name, name);

        index = getIndex(name);
        addPersonNode(&indexTable[index], person);
    }

    for (int i = 0; i < MAX_INDEX; i++) {
        printf("Index %c\n", i + 'a');
        printIndex(&indexTable[i]);
        printf("\n");
    }

    return 0;
}