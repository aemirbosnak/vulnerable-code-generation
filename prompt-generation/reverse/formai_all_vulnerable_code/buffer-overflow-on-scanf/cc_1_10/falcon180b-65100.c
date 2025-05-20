//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char text[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char input[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry:\n");
    fgets(input, MAX_ENTRY_LENGTH, stdin);
    int length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
        length--;
    }
    strcpy(entries[num_entries].text, input);
    entries[num_entries].timestamp = time(NULL);
    num_entries++;
    printf("Entry added.\n");
}

void view_entries() {
    printf("Your diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", ctime(&entries[i].timestamp));
        printf("%s\n\n", entries[i].text);
    }
}

void search_entries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter a keyword to search for:\n");
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);
    int length = strlen(keyword);
    if (length > 0 && keyword[length - 1] == '\n') {
        keyword[length - 1] = '\0';
        length--;
    }
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].text, keyword)) {
            printf("%s\n", ctime(&entries[i].timestamp));
            printf("%s\n\n", entries[i].text);
        }
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to your digital diary!\n\n");
    while (1) {
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            view_entries();
            break;
        case 3:
            search_entries();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}