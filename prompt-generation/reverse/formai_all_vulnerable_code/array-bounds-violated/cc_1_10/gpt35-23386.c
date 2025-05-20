//FormAI DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

char master_pw[MAX_LENGTH];
struct pw_node {
    char domain[MAX_LENGTH];
    char username[MAX_LENGTH];
    char pw[MAX_LENGTH];
    struct pw_node *next;
};
struct pw_node *pw_list = NULL;

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void get_master_pw() {
    printf("Enter a master password: ");
    fgets(master_pw, MAX_LENGTH, stdin);
    master_pw[strlen(master_pw) - 1] = 0;
}

void add_pw() {
    struct pw_node *new_pw = malloc(sizeof(struct pw_node));
    printf("Enter the domain: ");
    fgets(new_pw->domain, MAX_LENGTH, stdin);
    new_pw->domain[strlen(new_pw->domain) - 1] = 0;
    printf("Enter the username: ");
    fgets(new_pw->username, MAX_LENGTH, stdin);
    new_pw->username[strlen(new_pw->username) - 1] = 0;
    printf("Enter the password: ");
    fgets(new_pw->pw, MAX_LENGTH, stdin);
    new_pw->pw[strlen(new_pw->pw) - 1] = 0;
    new_pw->next = pw_list;
    pw_list = new_pw;
}

void list_pw() {
    printf("Stored Passwords:\n");
    printf("-----------------\n");
    for (struct pw_node *p = pw_list; p != NULL; p = p->next) {
        printf("%s:%s:%s\n", p->domain, p->username, p->pw);
    }
}

void search_pw() {
    printf("Enter the domain to search: ");
    char search[MAX_LENGTH];
    fgets(search, MAX_LENGTH, stdin);
    search[strlen(search) - 1] = 0;
    for (struct pw_node *p = pw_list; p != NULL; p = p->next) {
        if (strcmp(p->domain, search) == 0) {
            printf("%s:%s:%s\n", p->domain, p->username, p->pw);
            return;
        }
    }
    printf("No password found for domain %s\n", search);
}

void delete_pw() {
    printf("Enter the domain to delete: ");
    char search[MAX_LENGTH];
    fgets(search, MAX_LENGTH, stdin);
    search[strlen(search) - 1] = 0;
    if (strcmp(pw_list->domain, search) == 0) {
        struct pw_node *tmp = pw_list;
        pw_list = pw_list->next;
        free(tmp);
        printf("Password for domain %s deleted!\n", search);
        return;
    }
    struct pw_node *p;
    for (p = pw_list; p->next != NULL; p = p->next) {
        if (strcmp(p->next->domain, search) == 0) {
            struct pw_node *tmp = p->next;
            p->next = p->next->next;
            free(tmp);
            printf("Password for domain %s deleted!\n", search);
            return;
        }
    }
    printf("No password found for domain %s\n", search);
}

int main() {
    get_master_pw();
    printf("Password Manager\n");
    printf("----------------\n");
    while (1) {
        printf("Enter a command (add, list, search, delete, quit): ");
        char cmd[MAX_LENGTH];
        fgets(cmd, MAX_LENGTH, stdin);
        cmd[strlen(cmd) - 1] = 0;
        if (strcmp(cmd, "add") == 0) {
            add_pw();
        } else if (strcmp(cmd, "list") == 0) {
            list_pw();
        } else if (strcmp(cmd, "search") == 0) {
            search_pw();
        } else if (strcmp(cmd, "delete") == 0) {
            delete_pw();
        } else if (strcmp(cmd, "quit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid command, try again.\n");
        }
    }
}