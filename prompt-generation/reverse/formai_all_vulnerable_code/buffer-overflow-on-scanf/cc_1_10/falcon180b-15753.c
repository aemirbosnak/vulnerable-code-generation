//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char number[15];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    printf("Enter name: ");
    scanf("%s", phonebook[numEntries].name);
    printf("Enter number: ");
    scanf("%s", phonebook[numEntries].number);
    numEntries++;
}

void viewEntry() {
    int index;
    printf("Enter index: ");
    scanf("%d", &index);
    if(index >= 0 && index < numEntries) {
        printf("Name: %s\nNumber: %s\n", phonebook[index].name, phonebook[index].number);
    } else {
        printf("Invalid index.\n");
    }
}

void deleteEntry() {
    int index;
    printf("Enter index: ");
    scanf("%d", &index);
    if(index >= 0 && index < numEntries) {
        for(int i = index; i < numEntries - 1; i++) {
            strcpy(phonebook[i].name, phonebook[i+1].name);
            strcpy(phonebook[i].number, phonebook[i+1].number);
        }
        numEntries--;
    } else {
        printf("Invalid index.\n");
    }
}

void searchEntry() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int found = 0;
    for(int i = 0; i < numEntries; i++) {
        if(strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            found = 1;
        }
    }
    if(!found) {
        printf("No entry found.\n");
    }
}

int main() {
    printf("Welcome to the Post-Apocalyptic Phone Book!\n");
    while(1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. View entry\n");
        printf("3. Delete entry\n");
        printf("4. Search entry\n");
        printf("5. Exit\n");
        printf("\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                searchEntry();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}