//FormAI DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_MEMBERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Member;

int num_members = 0;
Member members[MAX_MEMBERS];

void print_menu() {
    printf("\nWelcome to the Mailing List Manager.\n");
    printf("1. Add member\n");
    printf("2. Remove member\n");
    printf("3. Print mailing list\n");
    printf("4. Exit\n");
}

void add_member() {
    if (num_members >= MAX_MEMBERS) {
        printf("Maximum number of members reached.\n");
        return;
    }

    Member new_member;
    printf("Enter member name: ");
    fgets(new_member.name, MAX_NAME_LENGTH, stdin);
    new_member.name[strcspn(new_member.name, "\n")] = '\0'; // remove trailing newline
    printf("Enter member email: ");
    fgets(new_member.email, MAX_EMAIL_LENGTH, stdin);
    new_member.email[strcspn(new_member.email, "\n")] = '\0'; // remove trailing newline

    members[num_members] = new_member;
    num_members++;

    printf("Member added.\n");
}

void remove_member() {
    if (num_members == 0) {
        printf("No members to remove.\n");
        return;
    }

    printf("Enter member email to remove: ");
    char email[MAX_EMAIL_LENGTH];
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0'; // remove trailing newline

    int i;
    for (i = 0; i < num_members; i++) {
        if (strcmp(members[i].email, email) == 0) {
            num_members--;
            members[i] = members[num_members]; // replace removed member with last member in array
            printf("Member removed.\n");
            return;
        }
    }

    printf("Member with email \"%s\" not found.\n", email);
}

void print_mailing_list() {
    if (num_members == 0) {
        printf("No members to print.\n");
        return;
    }

    printf("\nMailing List:\n");
    int i;
    for (i = 0; i < num_members; i++) {
        printf("%s <%s>\n", members[i].name, members[i].email);
    }
}

int main() {
    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // remove trailing newline from previous input

        switch (choice) {
            case 1:
                add_member();
                break;
            case 2:
                remove_member();
                break;
            case 3:
                print_mailing_list();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}