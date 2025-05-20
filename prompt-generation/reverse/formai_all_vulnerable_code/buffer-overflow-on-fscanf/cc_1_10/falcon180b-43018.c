//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_NAME 50
#define MAX_NUMBER 15

struct entry {
    char name[MAX_NAME];
    char number[MAX_NUMBER];
};

int main() {
    FILE *file;
    int count = 0;
    struct entry entries[MAX_ENTRIES];

    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error opening phonebook.txt\n");
        exit(1);
    }

    while (fscanf(file, "%s %s\n", entries[count].name, entries[count].number)!= EOF) {
        count++;
        if (count >= MAX_ENTRIES) {
            printf("Phonebook is full\n");
            exit(1);
        }
    }

    fclose(file);

    while (1) {
        printf("Enter name to search: ");
        scanf(" %[^\n]", entries[count].name);
        entries[count].name[strcspn(entries[count].name, "\n")] = '\0';
        tolower(entries[count].name);

        printf("Enter number to add: ");
        scanf(" %[^\n]", entries[count].number);
        entries[count].number[strcspn(entries[count].number, "\n")] = '\0';

        file = fopen("phonebook.txt", "a");
        fprintf(file, "%s %s\n", entries[count].name, entries[count].number);
        fclose(file);

        count++;
        if (count >= MAX_ENTRIES) {
            printf("Phonebook is full\n");
            exit(1);
        }
    }

    return 0;
}