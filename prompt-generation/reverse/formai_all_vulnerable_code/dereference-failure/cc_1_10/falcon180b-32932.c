//Falcon-180B DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    struct person *next;
} person;

void add_person(person **head, char *name, int age) {
    person *new_person = (person *)malloc(sizeof(person));
    if (new_person == NULL) {
        printf("Memory error\n");
        return;
    }
    new_person->name = (char *)malloc(strlen(name) + 1);
    if (new_person->name == NULL) {
        printf("Memory error\n");
        return;
    }
    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->next = *head;
    *head = new_person;
}

void print_list(person *head) {
    while (head!= NULL) {
        printf("%s is %d years old\n", head->name, head->age);
        head = head->next;
    }
}

int main() {
    person *head = NULL;
    add_person(&head, "Alice", 25);
    add_person(&head, "Bob", 30);
    add_person(&head, "Charlie", 20);
    print_list(head);
    person *current = head;
    while (current!= NULL) {
        if (strcmp(current->name, "Bob") == 0) {
            printf("Found Bob\n");
            current = current->next;
        } else {
            person *temp = current;
            current = current->next;
            free(temp->name);
            free(temp);
        }
    }
    return 0;
}