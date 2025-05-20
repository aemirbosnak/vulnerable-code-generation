//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Member {
    char name[50];
    char email[50];
    struct Member* next;
} Member;

Member* head = NULL;

void add_member() {
    Member* new_member = (Member*)malloc(sizeof(Member));
    if (new_member == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter member name: ");
    scanf("%s", new_member->name);
    printf("Enter member email: ");
    scanf("%s", new_member->email);
    new_member->next = head;
    head = new_member;
    printf("Member %s added successfully!\n", new_member->name);
}

void remove_member() {
    char email[50];
    printf("Enter the email of the member to remove: ");
    scanf("%s", email);

    Member* current = head;
    Member* previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("No member found with email: %s\n", email);
        return;
    }
    
    if (previous == NULL) {
        head = current->next; // Member to be deleted is the first member
    } else {
        previous->next = current->next; // Bypass the member to be deleted
    }
    free(current);
    printf("Member with email %s removed successfully!\n", email);
}

void display_members() {
    if (head == NULL) {
        printf("No members in the mailing list.\n");
        return;
    }

    Member* current = head;
    printf("Mailing List Members:\n");
    while (current != NULL) {
        printf("Name: %s, Email: %s\n", current->name, current->email);
        current = current->next;
    }
}

void free_members() {
    Member* current = head;
    Member* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    int choice;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_member();
                break;
            case 2:
                remove_member();
                break;
            case 3:
                display_members();
                break;
            case 4:
                free_members();
                printf("Exiting program. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}