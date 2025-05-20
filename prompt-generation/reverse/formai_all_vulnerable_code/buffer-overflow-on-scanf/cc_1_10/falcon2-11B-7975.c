//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15
#define MAX_ENTRIES 100
typedef struct node {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    struct node *next;
} Node;
typedef struct phone_book {
    Node *head;
    Node *tail;
    int num_entries;
} PhoneBook;
PhoneBook phone_book;
void add_entry(char *name, char *number) {
    if (phone_book.num_entries == MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    Node *new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->number, number);
    if (phone_book.head == NULL) {
        phone_book.head = new_node;
        phone_book.tail = new_node;
    } else {
        phone_book.tail->next = new_node;
        phone_book.tail = new_node;
    }
    phone_book.num_entries++;
}
void print_entries() {
    printf("Phone Book:\n");
    Node *current = phone_book.head;
    while (current!= NULL) {
        printf("Name: %s, Number: %s\n", current->name, current->number);
        current = current->next;
    }
}
int main() {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    int choice;
    while (true) {
        printf("Phone Book Menu:\n"
               "1. Add Entry\n"
               "2. Print Entries\n"
               "3. Quit\n"
               "Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(name, number);
                break;
            case 2:
                print_entries();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}