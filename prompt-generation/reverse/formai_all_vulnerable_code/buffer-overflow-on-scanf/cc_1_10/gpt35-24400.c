//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct PhoneBook {
    char name[MAX];
    char number[MAX];
};

void addEntry(struct PhoneBook **book, int *size) {
    *size += 1;
    *book = (struct PhoneBook *)realloc(*book, (*size) * sizeof(struct PhoneBook));
    printf("Enter Name: ");
    scanf("%s", (*book)[*size - 1].name);
    printf("Enter Number: ");
    scanf("%s", (*book)[*size - 1].number);
    printf("\nEntry Added!\n\n");
}

void display(struct PhoneBook *book, int size, int i) {
    if (i == size) {
        return;
    }
    printf("Name: %s\n", book[i].name);
    printf("Number: %s\n", book[i].number);
    printf("\n");
    display(book, size, i+1);
}

void search(struct PhoneBook *book, int size, char *name, int i) {
    if (i == size) {
        printf("Entry not found!\n\n");
        return;
    }
    if (strcmp(book[i].name, name) == 0) {
        printf("Name: %s\n", book[i].name);
        printf("Number: %s\n", book[i].number);
        printf("\n");
        return;
    }
    search(book, size, name, i+1);
}

int main() {
    printf("C Phone Book\n\n");
    int size = 0, choice;
    struct PhoneBook *book = NULL;
    do {
        printf("1. Add Entry\n");
        printf("2. Display All Entries\n");
        printf("3. Search for an Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1: addEntry(&book, &size);
                    break;
            case 2: if (size == 0) {
                        printf("No entries found!\n\n");
                    }
                    else {
                        display(book, size, 0);
                    }
                    break;
            case 3: if (size == 0) {
                        printf("No entries found!\n\n");
                    }
                    else {
                        char name[MAX];
                        printf("Enter name to search: ");
                        scanf("%s", name);
                        printf("\n");
                        search(book, size, name, 0);
                    }
                    break;
            case 4: break;
            default: printf("Invalid Choice!\n\n");
                     break;
        }
    } while (choice != 4);
    free(book);
    return 0;
}