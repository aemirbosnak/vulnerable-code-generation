//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strncpy(entries[num_entries].name, name, MAX_NAME_LEN);
    strncpy(entries[num_entries].number, number, MAX_NUMBER_LEN);
    num_entries++;
}

void print_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid entry index.\n");
        return;
    }

    printf("Name: %s\n", entries[index].name);
    printf("Number: %s\n", entries[index].number);
}

int main() {
    char input[100];
    int choice;
    int index;

    printf("Welcome to the Phone Book!\n");
    printf("Commands:\n");
    printf("1. Add entry\n");
    printf("2. Print entry\n");
    printf("3. Quit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", input);
                printf("Enter number: ");
                scanf("%s", input);
                add_entry(input, input);
                break;
            case 2:
                printf("Enter entry index: ");
                scanf("%d", &index);
                print_entry(index);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}