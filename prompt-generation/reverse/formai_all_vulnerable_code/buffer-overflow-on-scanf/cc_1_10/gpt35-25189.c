//FormAI DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50 // Maximum length of email address
#define MAX_NAME_LENGTH 20 // Maximum length of name
#define MAX_MEMBERS 1000 // Maximum number of members in the list

struct member {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct mailing_list {
    int num_members;
    struct member members[MAX_MEMBERS];
};

void add_member(struct mailing_list* list) {
    if (list->num_members == MAX_MEMBERS) { // List is full
        printf("Error: Mailing list is full.");
        return;
    }

    struct member new_member;

    printf("Enter member name: ");
    scanf("%s", new_member.name);

    printf("Enter member email address: ");
    scanf("%s", new_member.email);

    list->members[list->num_members++] = new_member;

    printf("Member added successfully.\n");
}

void remove_member(struct mailing_list* list) {
    printf("Enter email address of member to remove: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);

    int removed = 0;
    for (int i = 0; i < list->num_members; i++) {
        if (strcmp(list->members[i].email, email) == 0) { // Email matches
            for (int j = i; j < list->num_members - 1; j++) {
                list->members[j] = list->members[j + 1]; // Shift members down
            }
            list->num_members--;
            removed = 1;
            break;
        }
    }

    if (removed) {
        printf("Member removed successfully.\n");
    }
    else {
        printf("Error: Member not found.\n");
    }
}

void print_members(struct mailing_list* list) {
    printf("Mailing List Members:\n");
    for (int i = 0; i < list->num_members; i++) {
        printf("%s <%s>\n", list->members[i].name, list->members[i].email);
    }
}

int main() {
    struct mailing_list list = { 0 };

    printf("--- Post-Apocalyptic Mailing List Manager ---\n");

    int choice = -1;
    while (choice != 0) {
        printf("\nPlease choose an option:\n");
        printf("1. Add member\n");
        printf("2. Remove member\n");
        printf("3. Print members\n");
        printf("0. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_member(&list);
            break;
        case 2:
            remove_member(&list);
            break;
        case 3:
            print_members(&list);
            break;
        case 0:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}