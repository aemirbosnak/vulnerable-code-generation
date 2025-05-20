//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char number[15];
} entry_t;

void add_entry(entry_t entries[], int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);
    printf("Enter number: ");
    scanf("%s", entries[count].number);
    count++;
}

void search_entry(entry_t entries[], int count, char* query) {
    int i;
    for(i = 0; i < count; i++) {
        if(strcmp(entries[i].name, query) == 0 || strcmp(entries[i].number, query) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

void delete_entry(entry_t entries[], int count, char* query) {
    int i;
    for(i = 0; i < count; i++) {
        if(strcmp(entries[i].name, query) == 0 || strcmp(entries[i].number, query) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(entry_t) * (count - i - 1));
            count--;
            break;
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;

    while(1) {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(count >= MAX_ENTRIES) {
                    printf("Maximum entries reached.\n");
                    break;
                }
                add_entry(entries, count);
                count++;
                break;
            case 2:
                printf("Enter query: ");
                char query[50];
                scanf("%s", query);
                search_entry(entries, count, query);
                break;
            case 3:
                printf("Enter query: ");
                char query2[50];
                scanf("%s", query2);
                delete_entry(entries, count, query2);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}