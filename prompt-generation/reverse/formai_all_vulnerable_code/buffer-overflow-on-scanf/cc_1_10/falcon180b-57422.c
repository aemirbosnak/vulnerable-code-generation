//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Entry;

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    char search_name[MAX_NAME_LEN];
    int search_result;

    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error opening file. Creating new phonebook...\n");
        fclose(file);
        file = fopen("phonebook.txt", "w");
        fprintf(file, "Name\tNumber\n");
        fclose(file);
    } else {
        while (fscanf(file, "%s\t%s", entries[num_entries].name, entries[num_entries].number)!= EOF) {
            num_entries++;
        }
        fclose(file);
    }

    while (1) {
        printf("\nPhonebook:\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%s\t%s\n", entries[i].name, entries[i].number);
        }

        printf("\nOptions:\n");
        printf("A - Add entry\n");
        printf("S - Search entry\n");
        printf("Q - Quit\n");

        scanf(" %c", &choice);

        switch (choice) {
        case 'A':
            printf("Enter name: ");
            scanf("%s", entries[num_entries].name);
            printf("Enter number: ");
            scanf("%s", entries[num_entries].number);
            num_entries++;
            break;

        case 'S':
            printf("Enter name to search: ");
            scanf("%s", search_name);
            search_result = searchPhonebook(entries, num_entries, search_name);
            if (search_result == -1) {
                printf("Entry not found.\n");
            } else {
                printf("Found entry:\n");
                printf("%s\t%s\n", entries[search_result].name, entries[search_result].number);
            }
            break;

        case 'Q':
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

int searchPhonebook(Entry entries[], int num_entries, char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}