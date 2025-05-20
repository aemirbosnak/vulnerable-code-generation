//FormAI DATASET v1.0 Category: Browser Plugin ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct to hold the user's browsing history
typedef struct history {
    char url[100];
    struct history* next;
} History;

// Function to initialize a new History node
History* new_history(char* url) {
    History* new = (History*)malloc(sizeof(History));
    strcpy(new->url, url);
    new->next = NULL;
    return new;
}

// Function to append a new History node to the end of the list
void append_history(History** head, char* url) {
    History* current = *head;
    if (*head == NULL) {
        *head = new_history(url);
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_history(url);
}

// Function to print the user's browsing history
void print_history(History* head) {
    if (head == NULL) {
        printf("No history available\n");
        return;
    }
    printf("Browsing history:\n");
    History* current = head;
    while (current != NULL) {
        printf("%s\n", current->url);
        current = current->next;
    }
}

// Function to clear the user's browsing history
void clear_history(History** head) {
    if (*head == NULL) {
        return;
    }
    History* current = *head;
    while (current != NULL) {
        *head = current->next;
        free(current);
        current = *head;
    }
}

// Main function
int main() {
    bool running = true;
    History* head = NULL;
    while (running) {
        printf("\nCommands:\n1. Visit a website\n2. Print browsing history\n3. Clear browsing history\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char url[100];
                printf("Enter website URL: ");
                scanf("%s", url);
                append_history(&head, url);
                printf("Visited %s\n", url);
                break;
            }
            case 2: {
                print_history(head);
                break;
            }
            case 3: {
                clear_history(&head);
                printf("Browsing history cleared\n");
                break;
            }
            case 4: {
                clear_history(&head);
                running = false;
                break;
            }
            default: {
                printf("Invalid command\n");
                break;
            }
        }
    }
    return 0;
}