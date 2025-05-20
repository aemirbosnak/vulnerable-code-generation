//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* name, char* number) {
    strcpy(entries[numEntries].name, name);
    strcpy(entries[numEntries].number, number);
    numEntries++;
}

void searchEntry(char* name) {
    int i;
    for(i = 0; i < numEntries; i++) {
        if(strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
    int len;

    do {
        system("clear");
        printf("Phone Book\n");
        printf("1. Add Entry\n2. Search Entry\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Number: ");
                scanf("%s", number);
                addEntry(name, number);
                printf("\nEntry added!\n");
                break;
            case 2:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                searchEntry(name);
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}