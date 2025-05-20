//FormAI DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct diary_entry {
    char date[11];
    char content[1000];
    struct diary_entry* next;
};

struct diary_entry* create_entry(char date[11], char content[1000]) {
    struct diary_entry* new_entry = (struct diary_entry*) malloc(sizeof(struct diary_entry));
    if (new_entry == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    strcpy(new_entry->date, date);
    strcpy(new_entry->content, content);
    new_entry->next = NULL;
    return new_entry;
}

void write_entry(struct diary_entry** head_ptr, struct diary_entry** tail_ptr, char date[11], char content[1000]) {
    struct diary_entry* new_entry = create_entry(date, content);
    if (*head_ptr == NULL) {
        *head_ptr = new_entry;
        *tail_ptr = new_entry;
    } else {
        (*tail_ptr)->next = new_entry;
        *tail_ptr = new_entry;
    }
    printf("Diary entry successfully added!\n");
}

void read_entry(struct diary_entry* head) {
    if (head == NULL) {
        printf("Your diary is empty!\n");
    } else {
        printf("Here are your diary entries:\n");
        while (head != NULL) {
            printf("Date: %s\nContent: %s\n", head->date, head->content);
            head = head->next;
        }
    }
}

void delete_entry(struct diary_entry** head_ptr, char date[11]) {
    if (*head_ptr == NULL) {
        printf("Your diary is empty!\n");
    } else {
        struct diary_entry* current = *head_ptr;
        struct diary_entry* prev = NULL;
        while (current != NULL) {
            if (strcmp(current->date, date) == 0) {
                if (prev == NULL) {
                    *head_ptr = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                printf("Diary entry successfully deleted!\n");
                return;
            }
            prev = current;
            current = current->next;
        }
        printf("Could not find diary entry with that date!\n");
    }
}

int main() {
    struct diary_entry* head = NULL;
    struct diary_entry* tail = NULL;
    char command;
    char date[11];
    char content[1000];
    while (1) {
        printf("\nCommands:\n1 - Write diary entry\n2 - Read diary\n3 - Delete diary entry\nQ - Quit program\n");
        printf("Enter command: ");
        scanf(" %c", &command);
        switch (command) {
            case '1':
                printf("Enter date (MM/DD/YYYY): ");
                scanf("%s", date);
                printf("Enter content: ");
                scanf(" %[^\n]s", content);
                write_entry(&head, &tail, date, content);
                break;
            case '2':
                read_entry(head);
                break;
            case '3':
                printf("Enter date of diary entry to delete (MM/DD/YYYY): ");
                scanf("%s", date);
                delete_entry(&head, date);
                break;
            case 'Q':
            case 'q':
                printf("Quitting program...\n");
                while (head != NULL) {
                    struct diary_entry* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid command!\n");
                break;
        }
    }
}