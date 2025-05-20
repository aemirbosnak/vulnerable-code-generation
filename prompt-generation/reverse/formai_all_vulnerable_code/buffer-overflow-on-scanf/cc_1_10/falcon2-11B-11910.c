//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct list {
    char *name;
    struct list *next;
};

struct list *head = NULL;

int main(int argc, char **argv) {
    struct list *current = head;
    char name[50];

    while (1) {
        printf("Enter the name of a new list member: ");
        scanf("%s", name);

        if (!strcmp(name, "quit")) {
            break;
        }

        struct list *new_member = malloc(sizeof(struct list));
        if (!new_member) {
            printf("Error allocating memory.\n");
            continue;
        }

        new_member->name = strdup(name);
        new_member->next = NULL;

        if (!head) {
            head = new_member;
        } else {
            current->next = new_member;
        }

        current = new_member;
    }

    if (head) {
        struct list *current = head;
        while (current) {
            printf("%s\n", current->name);
            current = current->next;
        }
    }

    return 0;
}