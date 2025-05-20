//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 500
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

diary_entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *entry) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    printf("Digital Diary\n");
    printf("=============\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to your digital diary!\n");

    while (1) {
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", date);

        printf("Enter your entry:\n");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);
        entry[strcspn(entry, "\n")] = '\0';

        add_entry(date, entry);

        printf("\nYour entry has been saved.\n");

        char choice;
        printf("Do you want to:\n1. Add another entry\n2. Print your diary\n3. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                break;
            case '2':
                print_entries();
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}