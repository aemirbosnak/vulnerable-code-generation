//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone_book_entry {
    char *name;
    char *number;
} phone_book_entry;

phone_book_entry *create_entry(char *name, char *number) {
    phone_book_entry *entry = malloc(sizeof(phone_book_entry));
    entry->name = strdup(name);
    entry->number = strdup(number);
    return entry;
}

void print_entry(phone_book_entry *entry) {
    printf("%s: %s\n", entry->name, entry->number);
}

int main(int argc, char **argv) {
    phone_book_entry *book[100];
    int num_entries = 0;

    while (1) {
        char input[100];
        printf("Enter a command (add, find, print, quit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char name[100];
            char number[100];
            printf("Enter a name: ");
            scanf("%s", name);
            printf("Enter a number: ");
            scanf("%s", number);
            book[num_entries] = create_entry(name, number);
            num_entries++;
        } else if (strcmp(input, "find") == 0) {
            char name[100];
            printf("Enter a name to find: ");
            scanf("%s", name);
            int found = 0;
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(book[i]->name, name) == 0) {
                    print_entry(book[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("No entry found for %s\n", name);
            }
        } else if (strcmp(input, "print") == 0) {
            for (int i = 0; i < num_entries; i++) {
                print_entry(book[i]);
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    for (int i = 0; i < num_entries; i++) {
        free(book[i]->name);
        free(book[i]->number);
        free(book[i]);
    }

    return 0;
}