//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

struct entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
};

int main() {
    FILE *file;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open phonebook file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s\n", entries[num_entries].name, entries[num_entries].number)!= EOF) {
        num_entries++;
    }

    fclose(file);

    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    tolower(search_name);

    int found_entry = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            found_entry = 1;
            break;
        }
    }

    if (!found_entry) {
        printf("No entry found for name: %s\n", search_name);
    }

    return 0;
}