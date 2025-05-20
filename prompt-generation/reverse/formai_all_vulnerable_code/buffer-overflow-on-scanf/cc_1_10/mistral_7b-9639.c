//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

Subscriber list[MAX_LIST_SIZE];
int list_size = 0;

void add_subscriber(char *name, char *email) {
    if (list_size >= MAX_LIST_SIZE) {
        printf("Mailing list is full.\n");
        return;
    }
    strcpy(list[list_size].name, name);
    strcpy(list[list_size].email, email);
    list_size++;
}

void remove_subscriber(int index) {
    if (index < 0 || index >= list_size) {
        printf("Invalid index.\n");
        return;
    }
    memmove(&list[index], &list[index + 1], sizeof(Subscriber) * (list_size - index - 1));
    list_size--;
}

void print_list() {
    for (int i = 0; i < list_size; i++) {
        printf("%d. %s <%s>\n", i + 1, list[i].name, list[i].email);
    }
}

void main() {
    char command[10];
    int index;
    char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Print list\n");
        printf("4. Quit\n");
        printf("Enter command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_subscriber(name, email);
                break;
            case '2':
                printf("Enter index: ");
                scanf("%d", &index);
                remove_subscriber(index - 1);
                break;
            case '3':
                print_list();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }
}