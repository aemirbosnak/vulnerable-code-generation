//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_SIZE];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char date_str[20];
    time_t now = time(NULL);
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", localtime(&now));

    char input_buffer[MAX_ENTRY_SIZE];
    printf("Enter your entry for %s:\n", date_str);
    fgets(input_buffer, MAX_ENTRY_SIZE, stdin);
    
    input_buffer[strcspn(input_buffer, "\n")] = '\0';
    strcpy(entries[num_entries].date, date_str);
    strcpy(entries[num_entries].entry, input_buffer);

    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n%s\n", entries[i].date, entries[i].entry);
    }
}

void search_entries() {
    char search_date[20];
    printf("Enter the date to search (YYYY-MM-DD): ");
    scanf("%s", search_date);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].date, search_date) == 0) {
            printf("%s\n%s\n", entries[i].date, entries[i].entry);
        }
    }
}

int main() {
    setbuf(stdout, NULL);

    while (1) {
        printf("1. Add entry\n2. Print entries\n3. Search entries\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                print_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}