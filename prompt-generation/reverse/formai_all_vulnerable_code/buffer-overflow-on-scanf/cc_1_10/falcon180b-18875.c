//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char *date;
    char *title;
    char *content;
};

struct entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *date, char *title, char *content) {
    struct entry *new_entry = &entries[num_entries];
    new_entry->date = strdup(date);
    new_entry->title = strdup(title);
    new_entry->content = strdup(content);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\nDate: %s\nTitle: %s\nContent:\n%s\n\n", i+1, entries[i].date, entries[i].title, entries[i].content);
    }
}

int main() {
    char buffer[MAX_ENTRY_LENGTH];
    char *date = NULL;
    char *title = NULL;
    char *content = NULL;
    int content_length = 0;
    int title_length = 0;

    printf("Welcome to Digital Diary!\n");
    while (1) {
        printf("Enter a date (YYYY-MM-DD): ");
        scanf("%s", buffer);
        date = strdup(buffer);

        printf("Enter a title: ");
        fgets(buffer, MAX_ENTRY_LENGTH, stdin);
        title = strdup(buffer);
        title_length = strlen(title);
        while (isspace(title[title_length-1])) {
            title[--title_length] = '\0';
        }

        printf("Enter content:\n");
        content = NULL;
        content_length = 0;
        while (fgets(buffer, MAX_ENTRY_LENGTH, stdin)!= NULL) {
            content_length += strlen(buffer);
            content = realloc(content, content_length+1);
            strcat(content, buffer);
        }

        add_entry(date, title, content);
        printf("\nEntry added.\n");

        free(date);
        free(title);
        free(content);
    }

    return 0;
}