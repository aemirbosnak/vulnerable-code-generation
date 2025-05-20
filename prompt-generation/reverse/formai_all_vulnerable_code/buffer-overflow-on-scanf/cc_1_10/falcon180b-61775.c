//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 1000
#define MAX_LINE_SIZE 100
#define MAX_NAME_SIZE 100

struct mailing_list {
    char name[MAX_NAME_SIZE];
    char email[MAX_LINE_SIZE];
};

void add_to_list(struct mailing_list list[], int size, char name[], char email[]) {
    if (size >= MAX_LIST_SIZE) {
        printf("Thou art at thy limit of mailing lists! ");
        return;
    }

    strcpy(list[size].name, name);
    strcpy(list[size].email, email);
    size++;
}

void remove_from_list(struct mailing_list list[], int size, char name[]) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            memmove(list + i, list + i + 1, (size - i - 1) * sizeof(struct mailing_list));
            size--;
            break;
        }
    }
}

void print_list(struct mailing_list list[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Name: %s\nEmail: %s\n", list[i].name, list[i].email);
    }
}

int main() {
    struct mailing_list list[MAX_LIST_SIZE];
    int size = 0;
    char choice;
    char name[MAX_NAME_SIZE];
    char email[MAX_LINE_SIZE];

    while (1) {
        printf("What dost thou wish to do? ");
        printf("A - Add a mailing list\n");
        printf("R - Remove a mailing list\n");
        printf("P - Print the mailing list\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter thy name: ");
                scanf("%s", name);
                printf("Enter thy email: ");
                scanf("%s", email);
                add_to_list(list, size, name, email);
                break;
            case 'R':
                printf("Enter the name of the mailing list thou wish to remove: ");
                scanf("%s", name);
                remove_from_list(list, size, name);
                break;
            case 'P':
                print_list(list, size);
                break;
            case 'Q':
                exit(0);
            default:
                printf("Invalid choice! ");
        }
    }

    return 0;
}