//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME 50
#define MAX_NUMBER 15

struct entry {
    char name[MAX_NAME];
    char number[MAX_NUMBER];
};

int main() {
    FILE *fp;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    fp = fopen("phonebook.txt", "r");
    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while(fscanf(fp, "%s %s\n", entries[num_entries].name, entries[num_entries].number)!= EOF) {
        num_entries++;
    }

    fclose(fp);

    char search_name[MAX_NAME];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    tolower(search_name);

    int found = 0;
    for(int i=0; i<num_entries; i++) {
        if(strcmp(entries[i].name, search_name) == 0) {
            printf("%s\n", entries[i].number);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Name not found.\n");
    }

    return 0;
}