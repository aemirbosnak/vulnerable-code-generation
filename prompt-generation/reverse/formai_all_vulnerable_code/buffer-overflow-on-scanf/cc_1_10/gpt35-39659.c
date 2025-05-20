//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_NUM_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char phoneNum[MAX_NUM_LEN];
} phoneBookEntry;

void addEntry(phoneBookEntry *pb, int *count) {
    printf("Name: ");
    scanf("%s", pb[*count].name);
    printf("Phone Number: ");
    scanf("%s", pb[*count].phoneNum);
    (*count)++;
}

void searchEntry(phoneBookEntry *pb, int count) {
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);
    
    for(int i = 0; i < count; i++) {
        if(strcmp(pb[i].name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", pb[i].name, pb[i].phoneNum);
            return;
        }
    }
    printf("Entry not found.\n");
}

void printAllEntries(phoneBookEntry *pb, int count) {
    for(int i = 0; i < count; i++) {
        printf("Name: %s\nPhone Number: %s\n", pb[i].name, pb[i].phoneNum);
    }
}

int main() {
    phoneBookEntry pb[100];
    int count = 0;
    int choice;
    
    while(1) {
        printf("\n");
        printf("Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Print all Entries\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addEntry(pb, &count);
                break;
            case 2:
                searchEntry(pb, count);
                break;
            case 3:
                printAllEntries(pb, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}