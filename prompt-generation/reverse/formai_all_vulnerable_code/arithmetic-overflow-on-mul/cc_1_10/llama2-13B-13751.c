//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PHONE_BOOK_SIZE 1000

struct phone_book {
    char name[50];
    char number[20];
};

int main() {
    struct phone_book phone_book[PHONE_BOOK_SIZE];
    int i, j, k;
    char name[50], number[20];
    char random_name[50];

    // Initialize phone book with random names and numbers
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        srand(time(NULL) * 1000 + i);
        strcpy(phone_book[i].name, "Random Name ");
        sprintf(phone_book[i].number, "%d", i + 1);
    }

    // Print phone book
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].number);
    }

    // Add and search functionality
    while (1) {
        printf("Add new entry: ");
        fgets(name, 50, stdin);
        if (sscanf(name, "%[^ ] %[^\n]", &name, number) == 2) {
            for (i = 0; i < PHONE_BOOK_SIZE; i++) {
                if (strcmp(name, phone_book[i].name) == 0) {
                    printf("Error: Duplicate entry\n");
                    continue;
                }
            }
            strcpy(phone_book[i].name, name);
            strcpy(phone_book[i].number, number);
            i++;
            break;
        }
    }

    printf("Search for: ");
    fgets(name, 50, stdin);
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        if (strcmp(name, phone_book[i].name) == 0) {
            printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].number);
        }
    }

    return 0;
}