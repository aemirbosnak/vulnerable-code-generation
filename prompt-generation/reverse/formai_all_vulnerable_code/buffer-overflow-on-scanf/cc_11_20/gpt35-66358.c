//FormAI DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
} Contact;

int main() {
    int n = 0, max_n = 10;
    Contact *book = malloc(max_n * sizeof(Contact));

    if (!book) {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(1);
    }

    while (1) {
        char choice;
        printf("Enter choice (a=add, d=delete, s=search, q=quit): ");
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        } else if (choice == 'a') {
            if (n == max_n) {
                max_n *= 2;
                book = realloc(book, max_n * sizeof(Contact));
                if (!book) {
                    fprintf(stderr, "Error: Unable to reallocate memory.\n");
                    exit(1);
                }
            }
            printf("Enter name: ");
            scanf(" %[^\n]", book[n].name);
            printf("Enter phone number: ");
            scanf(" %[^\n]", book[n].phone);
            n++;
        } else if (choice == 'd') {
            char name[50];
            printf("Enter name to delete: ");
            scanf(" %[^\n]", name);

            int i, found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(name, book[i].name) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                for (; i < n-1; i++) {
                    book[i] = book[i+1];
                }
                n--;
                printf("%s was deleted from phone book.\n", name);
            } else {
                printf("%s not found in phone book.\n", name);
            }
        } else if (choice == 's') {
            char name[50];
            printf("Enter name to search: ");
            scanf(" %[^\n]", name);

            int i, found = 0;
            for (i = 0; i < n; i++) {
                if (strcmp(name, book[i].name) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                printf("%s is in the phone book. Phone number: %s\n", name, book[i].phone);
            } else {
                printf("%s not found in phone book.\n", name);
            }
        } else {
            printf("Invalid choice.\n");
        }
    }

    free(book);
    return 0;
}