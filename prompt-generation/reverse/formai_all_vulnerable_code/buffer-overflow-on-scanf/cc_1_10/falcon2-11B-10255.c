//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_SIZE 50

struct list_member {
    char name[MAX_NAME_SIZE];
    struct list_member *next;
};

struct list_member *head;

void add_member(const char *name) {
    struct list_member *new_member = malloc(sizeof(struct list_member));
    if (new_member == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return;
    }
    strcpy(new_member->name, name);
    new_member->next = head;
    head = new_member;
}

void remove_member(const char *name) {
    struct list_member *current = head;
    struct list_member *prev = NULL;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev!= NULL) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    fprintf(stderr, "Error: Member not found\n");
}

int main() {
    char name[MAX_NAME_SIZE];
    int choice = 0;
    do {
        printf("Mailing List Manager\n");
        printf("1. Add member\n");
        printf("2. Remove member\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_SIZE, stdin);
                if (strlen(name) == 0) {
                    break;
                }
                add_member(name);
                break;
            case 2:
                printf("Enter name: ");
                fgets(name, MAX_NAME_SIZE, stdin);
                if (strlen(name) == 0) {
                    break;
                }
                remove_member(name);
                break;
            case 3:
                return 0;
            default:
                fprintf(stderr, "Invalid choice\n");
                break;
        }
    } while (1);
    return 0;
}