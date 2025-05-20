//FormAI DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_MEMBERS 1000

struct member {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
};

struct mailing_list {
    char name[MAX_NAME_LENGTH];
    struct member members[MAX_MEMBERS];
    int num_members;
};

void add_member(struct mailing_list *list) {
    if (list->num_members == MAX_MEMBERS) {
        printf("List is full!\n");
        return;
    }

    struct member *new_member = &list->members[list->num_members];
    printf("Enter email: ");
    scanf("%s", new_member->email);
    printf("Enter name: ");
    scanf("%s", new_member->name);

    list->num_members++;
}

void print_list(struct mailing_list *list) {
    printf("Mailing list: %s\n", list->name);
    printf("--------------------\n");

    for (int i = 0; i < list->num_members; i++) {
        printf("%s <%s>\n", list->members[i].name, list->members[i].email);
    }

    printf("%d members\n", list->num_members);
}

int main() {
    struct mailing_list list;
    list.num_members = 0;

    printf("Enter list name: ");
    scanf("%s", list.name);

    printf("Commands:\n");
    printf("a = add member\n");
    printf("p = print list\n");
    printf("q = quit program\n");

    char command;

    while (1) {
        printf("> ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                add_member(&list);
                break;

            case 'p':
                print_list(&list);
                break;

            case 'q':
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid command!\n");
        }
    }

    return 0;
}