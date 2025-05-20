//FormAI DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARACTERS 100
#define MAX_EMAILS 1000

struct node {
    char email[MAX_CHARACTERS];
    struct node *next;
};

struct node *head = NULL;

void add_email() {
    char new_email[MAX_CHARACTERS];
    printf("Enter the email address: ");
    scanf("%s", new_email);
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->email, new_email);
    new_node->next = head;
    head = new_node;
    printf("Email added successfully!\n");
}

void remove_email() {
    if (head == NULL) {
        printf("The mailing list is empty!\n");
        return;
    }
    char email_to_remove[MAX_CHARACTERS];
    printf("Enter the email address to remove: ");
    scanf("%s", email_to_remove);
    struct node *current_node = head;
    struct node *previous_node = NULL;
    while (current_node != NULL) {
        if (strcmp(current_node->email, email_to_remove) == 0) {
            if (previous_node == NULL) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            printf("Email removed successfully!\n");
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    printf("The email address is not in the mailing list.\n");
}

void print_mailing_list() {
    if (head == NULL) {
        printf("The mailing list is empty!\n");
        return;
    }
    printf("Mailing list:\n");
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%s\n", current_node->email);
        current_node = current_node->next;
    }
}

void send_emails() {
    if (head == NULL) {
        printf("The mailing list is empty!\n");
        return;
    }
    char message[MAX_CHARACTERS];
    printf("Enter the message to send: ");
    scanf(" %[^\n]s", message);
    printf("Sending message to %d emails...\n", size());
    struct node *current_node = head;
    while (current_node != NULL) {
        printf("%s: %s\n", current_node->email, message);
        current_node = current_node->next;
    }
    printf("All emails sent!\n");
}

void filter_emails() {
    if (head == NULL) {
        printf("The mailing list is empty!\n");
        return;
    }
    char keyword[MAX_CHARACTERS];
    printf("Enter the keyword to filter by: ");
    scanf("%s", keyword);
    struct node *current_node = head;
    while (current_node != NULL) {
        if (strstr(current_node->email, keyword) != NULL) {
            printf("%s\n", current_node->email);
        }
        current_node = current_node->next;
    }
}

void cleanup() {
    struct node *current_node = head;
    while (current_node != NULL) {
        struct node *temp_node = current_node->next;
        free(current_node);
        current_node = temp_node;
    }
}

int size() {
    int count = 0;
    struct node *current_node = head;
    while (current_node != NULL) {
        count++;
        current_node = current_node->next;
    }
    return count;
}

int main() {
    int choice;
    while (1) {
        printf("\nMailing List Manager:\n");
        printf("1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print mailing list\n");
        printf("4. Send emails\n");
        printf("5. Filter emails\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_email(); break;
            case 2: remove_email(); break;
            case 3: print_mailing_list(); break;
            case 4: send_emails(); break;
            case 5: filter_emails(); break;
            case 6: cleanup(); return 0;
            default: printf("Invalid choice\n"); break;
        }
    }
}