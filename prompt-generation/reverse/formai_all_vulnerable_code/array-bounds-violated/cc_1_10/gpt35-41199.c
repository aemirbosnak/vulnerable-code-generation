//FormAI DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailingList {
    char name[50];
    char email[50];
    struct mailingList *next;
};

struct mailingList *head = NULL;

struct mailingList *createNode(char *name, char *email) {
    struct mailingList *node = (struct mailingList *) malloc(sizeof(struct mailingList));
    strcpy(node->name, name);
    strcpy(node->email, email);
    node->next = NULL;
    return node;
}

void addNode(char *name, char *email) {
    if (head == NULL) {
        head = createNode(name, email);
        printf("%s <%s> has been added to the mailing list.\n", name, email);
    } else {
        struct mailingList *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(name, email);
        printf("%s <%s> has been added to the mailing list.\n", name, email);
    }
}

void deleteNode(char *email) {
    if (head == NULL) {
        printf("There are no email addresses in the mailing list.\n");
    } else {
        struct mailingList *temp = head;
        struct mailingList *prev = NULL;
        while (temp != NULL) {
            if (strcmp(temp->email, email) == 0) {
                if (prev == NULL) {
                    head = temp->next;
                    printf("%s <%s> has been removed from the mailing list.\n", temp->name, temp->email);
                    free(temp);
                    return;
                } else {
                    prev->next = temp->next;
                    printf("%s <%s> has been removed from the mailing list.\n", temp->name, temp->email);
                    free(temp);
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        }
        printf("%s is not in the mailing list.\n", email);
    }
}

void printMailingList() {
    if (head == NULL) {
        printf("There are no email addresses in the mailing list.\n");
    } else {
        struct mailingList *temp = head;
        printf("Mailing List:\n");
        while (temp != NULL) {
            printf("%s <%s>\n", temp->name, temp->email);
            temp = temp->next;
        }
    }
}

int main(int argc, char *argv[]) {
    char input[50];
    while (1) {
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "print") == 0) {
            printMailingList();
        } else if (strstr(input, "add") != NULL) {
            char *name = strtok(input + 4, "<");
            char *email = strtok(NULL, ">");
            addNode(name, email);
        } else if (strstr(input, "delete") != NULL) {
            char *email = input + 7;
            deleteNode(email);
        } else if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}