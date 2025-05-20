//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ENTRIES 100

typedef struct {
    char title[50];
    char description[200];
    int date;
} Entry;

typedef struct Node {
    Entry entry;
    struct Node* next;
} Node;

Node* head = NULL;
int current_position = -1;

void add_entry(Entry new_entry) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        return;
    }

    new_node->entry = new_entry;
    new_node->next = head;
    head = new_node;
    current_position++;
}

void view_entry(int position) {
    if (position < 0 || position > current_position) {
        printf("Error: Invalid position\n");
        return;
    }

    printf("\nTitle: %s\n", head->entry.title);
    printf("Description: %s\n", head->entry.description);
    printf("Date: %d\n", head->entry.date);

    Node* temp = head;
    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }
    current_position = position;
}

void delete_entry(int position) {
    if (position < 0 || position > current_position) {
        printf("Error: Invalid position\n");
        return;
    }

    if (position == current_position) {
        current_position--;
    }

    Node* temp = head;
    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }

    Node* node_to_delete = temp->next;
    temp->next = node_to_delete->next;

    free(node_to_delete);
    current_position--;
}

void print_menu() {
    printf("\nDigital Diary Menu\n");
    printf("--------------------\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Quit\n");
}

int main() {
    int choice, date;
    char title[50], description[200];

    while (true) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter description: ");
                scanf("%s", description);
                printf("Enter date (YYYYMMDD): ");
                scanf("%d", &date);

                Entry new_entry = {title, description, date};
                add_entry(new_entry);
                printf("Entry added successfully\n");
                break;

            case 2:
                if (current_position < 0) {
                    printf("Error: No entries to view\n");
                    break;
                }

                view_entry(current_position);
                break;

            case 3:
                if (current_position < 0) {
                    printf("Error: No entry to delete\n");
                    break;
                }

                delete_entry(current_position);
                printf("Entry deleted successfully\n");
                break;

            case 4:
                return 0;

            default:
                printf("Error: Invalid choice\n");
                break;
        }
    }

    return 0;
}