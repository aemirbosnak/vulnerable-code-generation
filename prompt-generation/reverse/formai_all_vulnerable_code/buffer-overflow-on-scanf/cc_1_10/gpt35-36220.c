//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct diary_entry {
    char date[11];
    char entry[500];
};

struct diary {
    char owner[50];
    int num_entries;
    struct diary_entry* entries;
};

void add_entry(struct diary* book) {
    printf("\nEnter the date for the entry (MM/DD/YYYY): ");
    scanf("%s", book->entries[book->num_entries].date);
    printf("\nEnter your diary entry for this date: ");
    scanf(" %[^\n]", book->entries[book->num_entries].entry);
    book->num_entries++;
    printf("\nEntry added successfully!\n");
}

void view_entry(struct diary* book) {
    if(book->num_entries == 0) {
        printf("\nNo entries found!\n");
        return;
    }
    printf("\nYour diary entries:\n");
    for(int i=0; i<book->num_entries; i++) {
        printf("\nDate: %s \nEntry: %s\n", book->entries[i].date, book->entries[i].entry);
    }
}

int main() {
    struct diary book;
    book.num_entries = 0;
    book.entries = (struct diary_entry*) malloc(sizeof(struct diary_entry));
    printf("\nWelcome to your digital diary!\nPlease enter your name: ");
    scanf("%s", book.owner);
    while(1) {
        printf("\nEnter '1' to add entry, '2' to view entries, '3' to exit: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_entry(&book);
                    break;
            case 2: view_entry(&book);
                    break;
            case 3: printf("\nExiting program...Goodbye %s!\n", book.owner);
                    exit(0);
                    break;
            default: printf("\nInvalid choice! Please select again.\n");
        }
    }
    free(book.entries);
    return 0;
}