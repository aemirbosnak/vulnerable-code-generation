#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char name[100];
    int age;
    struct Record *next;
} Record;

Record *head = NULL;

void add_record(char *name, int age) {
    Record *new_record = (Record *)malloc(sizeof(Record));
    strcpy(new_record->name, name);
    new_record->age = age;
    new_record->next = head;
    head = new_record;
}

void free_list() {
    Record *current = head;
    while (head != NULL) {
        head = head->next;
        free(current);
        current = head;
    }
    head = NULL;
}

void display_list() {
    Record *temp = head;
    printf("Name\tAge\n");
    while (temp != NULL) {
        printf("%s\t%d\n", temp->name, temp->age);
        temp = temp->next;
    }
}

int main() {
    add_record("Alice", 25);
    add_record("Bob", 30);
    add_record("Charlie", 35);

    display_list();

    free_list(); // Free the list here

    printf("Deleting head node\n");
    Record *temp = head;
    head = head->next;
    free(temp); // Use head after it has been freed here

    display_list(); // Should print nothing since the list is empty

    return 0;
}
