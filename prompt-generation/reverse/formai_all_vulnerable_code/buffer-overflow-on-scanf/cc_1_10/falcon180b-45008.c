//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* entry) {
    strcpy(diary[num_entries].date, date);
    strcpy(diary[num_entries].entry, entry);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    char date[20];
    int choice;
    while (1) {
        printf("Digital Diary\n");
        printf("1. Add Entry\n2. Print Entries\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter Date (YYYY-MM-DD): ");
            scanf("%s", date);
            printf("Enter Entry:\n");
            fgets(input, MAX_ENTRY_LENGTH, stdin);
            input[strcspn(input, "\n")] = '\0';
            add_entry(date, input);
            printf("Entry added.\n");
            break;
        case 2:
            print_entries();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}