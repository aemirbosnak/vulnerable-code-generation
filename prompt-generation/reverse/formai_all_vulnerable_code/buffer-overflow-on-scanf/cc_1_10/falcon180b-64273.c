//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

struct entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
    time_t timestamp;
};

void add_entry(struct entry *book, int count, char *name, char *number) {
    strcpy(book[count].name, name);
    strcpy(book[count].number, number);
    book[count].timestamp = time(NULL);
    printf("Entry added:\nName: %s\nNumber: %s\n", book[count].name, book[count].number);
}

void search_entry(struct entry *book, int count, char *name) {
    int i;
    for(i=0; i<count; i++) {
        if(strcmp(book[i].name, name) == 0) {
            printf("Entry found:\nName: %s\nNumber: %s\n", book[i].name, book[i].number);
            printf("Timestamp: %s\n", ctime(&book[i].timestamp));
        }
    }
}

int main() {
    struct entry book[MAX_ENTRIES];
    int count = 0;
    char name[MAX_NAME_LEN], number[MAX_NUMBER_LEN];
    char choice;
    
    printf("Welcome to the Phone Book!\n");
    do {
        printf("\nPress:\n");
        printf("1 - Add entry\n");
        printf("2 - Search entry\n");
        printf("3 - Exit\n");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("Enter name: ");
                scanf(" %[^\n]", name);
                printf("Enter number: ");
                scanf(" %[^\n]", number);
                add_entry(book, count, name, number);
                count++;
                break;
            case '2':
                printf("Enter name to search: ");
                scanf(" %[^\n]", name);
                search_entry(book, count, name);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '3');

    return 0;
}