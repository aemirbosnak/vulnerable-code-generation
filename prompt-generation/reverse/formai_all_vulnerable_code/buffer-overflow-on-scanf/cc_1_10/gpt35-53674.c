//FormAI DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_MEMBERS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Member;

Member mailing_list[MAX_MEMBERS];
int num_members = 0;

void add_member() {
    if (num_members >= MAX_MEMBERS) {
        printf("Sorry, the mailing list is full.\n");
        return;
    }

    printf("Enter member name: ");
    fgets(mailing_list[num_members].name, MAX_NAME_LEN, stdin);
    mailing_list[num_members].name[strcspn(mailing_list[num_members].name, "\n")] = '\0';

    printf("Enter member email: ");
    fgets(mailing_list[num_members].email, MAX_EMAIL_LEN, stdin);
    mailing_list[num_members].email[strcspn(mailing_list[num_members].email, "\n")] = '\0';

    num_members++;
    printf("Member added successfully!\n");
}

void remove_member() {
    if (num_members == 0) {
        printf("Sorry, there are no members in the mailing list.\n");
        return;
    }

    char email[MAX_EMAIL_LEN];
    printf("Enter email of member to remove: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    email[strcspn(email, "\n")] = '\0';

    int index_to_remove = -1;
    for (int i = 0; i < num_members; i++) {
        if (strcmp(email, mailing_list[i].email) == 0) {
            index_to_remove = i;
            break;
        }
    }

    if (index_to_remove == -1) {
        printf("Sorry, member with email %s not found.\n", email);
        return;
    }

    for (int i = index_to_remove; i < num_members-1; i++) {
        strcpy(mailing_list[i].name, mailing_list[i+1].name);
        strcpy(mailing_list[i].email, mailing_list[i+1].email);
    }

    num_members--;
    printf("Member with email %s removed successfully!\n", email);
}

void display_members() {
    if (num_members == 0) {
        printf("Sorry, there are no members in the mailing list.\n");
        return;
    }

    printf("Mailing List:\n");
    for (int i = 0; i < num_members; i++) {
        printf("%s <%s>\n", mailing_list[i].name, mailing_list[i].email);
    }
}

int main() {
    int choice;

    while (1) {
        printf("----------------------\n");
        printf("Mailing List Manager\n");
        printf("----------------------\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, quitting.\n");
            return 1;
        }
        while(getchar() != '\n');

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
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}