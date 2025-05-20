//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_SIZE 50
#define MAX_NUM_SIZE 20
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUM_SIZE];
} Entry;

int numEntries = 0;
Entry entries[MAX_ENTRIES];

void addEntry() {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUM_SIZE];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter number: ");
    scanf("%s", number);
    strcpy(entries[numEntries].name, name);
    strcpy(entries[numEntries].number, number);
    numEntries++;
    printf("Entry added.\n");
}

void searchEntry() {
    char name[MAX_NAME_SIZE];
    printf("Enter name to search: ");
    scanf("%s", name);
    tolower(name);
    int i;
    for(i=0; i<numEntries; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add Entry\n2. Search Entry\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 3);
    return 0;
}