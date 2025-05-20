//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIST_SIZE 100

typedef struct {
    char name[50];
    char email[50];
} ListElement;

ListElement list[MAX_LIST_SIZE];
int list_size = 0;

void add_to_list(char *name, char *email) {
    if (list_size >= MAX_LIST_SIZE) {
        printf("Mailing list is full!\n");
        return;
    }
    strcpy(list[list_size].name, name);
    strcpy(list[list_size].email, email);
    list_size++;
}

void remove_from_list(int index) {
    if (index < 0 || index >= list_size) {
        printf("Invalid index!\n");
        return;
    }
    memmove(&list[index], &list[index + 1], (list_size - index - 1) * sizeof(ListElement));
    list_size--;
}

void print_list() {
    int i;
    for (i = 0; i < list_size; i++) {
        printf("%s: %s\n", list[i].name, list[i].email);
    }
}

int main() {
    char name[50], email[50];
    int choice, index;

    while (1) {
        printf("\n1. Add to list\n2. Remove from list\n3. Print list\n4. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_to_list(name, email);
                break;
            case 2:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                remove_from_list(index);
                break;
            case 3:
                print_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}