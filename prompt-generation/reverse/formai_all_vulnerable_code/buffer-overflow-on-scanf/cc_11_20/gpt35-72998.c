//FormAI DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email[100];
    struct node *next;
} Node;

int main() {
    int choice;
    Node *head = NULL;
    Node *tail = NULL;
    Node *temp;
    char email[100];

    printf("Mailing List Manager\n");
    printf("--------------------\n");

    do {
        printf("\n1. Add email\n2. View all emails\n3. Delete email\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter email: ");
                scanf("%s", email);

                temp = (Node *)malloc(sizeof(Node));
                strcpy(temp->email, email);
                temp->next = NULL;

                if (head == NULL) {
                    head = temp;
                    tail = temp;
                } else {
                    tail->next = temp;
                    tail = temp;
                }

                printf("\nEmail added successfully.\n");
                break;

            case 2:
                if (head == NULL) {
                    printf("\nNo emails found.\n");
                } else {
                    printf("\nAll emails:\n");

                    temp = head;
                    while (temp != NULL) {
                        printf("%s\n", temp->email);
                        temp = temp->next;
                    }
                }
                break;

            case 3:
                if (head == NULL) {
                    printf("\nNo emails found.\n");
                } else {
                    printf("\nEnter email to delete: ");
                    scanf("%s", email);

                    if (strcmp(head->email, email) == 0) {
                        temp = head;
                        head = head->next;
                        free(temp);
                        printf("\nEmail deleted successfully.\n");
                    } else {
                        Node *prev = head;
                        temp = head->next;

                        while (temp != NULL) {
                            if (strcmp(temp->email, email) == 0) {
                                prev->next = temp->next;
                                free(temp);
                                printf("\nEmail deleted successfully.\n");
                                break;
                            } else {
                                prev = temp;
                                temp = temp->next;
                            }
                        }

                        if (temp == NULL) {
                            printf("\nEmail not found.\n");
                        }
                    }
                }
                break;

            case 4:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    temp = head;
    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }

    return 0;
}