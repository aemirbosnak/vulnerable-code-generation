//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char email[50];
    struct Node* next;
};

void insert_node(struct Node** head, char* email) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

int search_node(struct Node* head, char* email) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->email, email) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void delete_node(struct Node** head, char* email) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL && strcmp(temp->email, email) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%s not present in the list.\n", email);
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void clear_list(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }
}

int main() {
    struct Node* head = NULL;
    int choice;
    do {
        printf("\n\n");
        printf("1. Add email\n");
        printf("2. View mailing list\n");
        printf("3. Search email\n");
        printf("4. Delete email\n");
        printf("5. Clear mailing list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char email[50];
                printf("Enter email: ");
                scanf("%s", email);
                insert_node(&head, email);
                printf("%s added to the list!\n", email);
                break;
            }
            case 2: {
                printf("Mailing List:\n");
                display_list(head);
                break;
            }
            case 3: {
                char email[50];
                printf("Enter email to search: ");
                scanf("%s", email);
                int result = search_node(head, email);
                if (result) {
                    printf("%s is present in the list.\n", email);
                } else {
                    printf("%s is not present in the list.\n", email);
                }
                break;
            }
            case 4: {
                char email[50];
                printf("Enter email to delete: ");
                scanf("%s", email);
                delete_node(&head, email);
                break;
            }
            case 5: {
                clear_list(&head);
                printf("Mailing list cleared!\n");
                break;
            }
            case 6: {
                printf("Exiting program...\n");
                break;
            }
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    } while (choice != 6);
    return 0;
}