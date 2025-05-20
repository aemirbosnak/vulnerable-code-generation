//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char title[ENTRY_SIZE];
    char content[ENTRY_SIZE];
    time_t timestamp;
} Entry;

Entry diary[MAX_ENTRIES];
int current_entry = 0;

void encode(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ 0x0A;
    }
    output[i] = '\0';
}

void decode(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ 0x0A;
    }
    output[i] = '\0';
}

void add_entry() {
    Entry *entry = &diary[current_entry];
    char title[ENTRY_SIZE], content[ENTRY_SIZE];

    printf("Title: ");
    fgets(title, ENTRY_SIZE, stdin);
    title[strlen(title) - 1] = '\0';

    printf("Content: ");
    fgets(content, ENTRY_SIZE, stdin);
    content[strlen(content) - 1] = '\0';

    encode(title, entry->title);
    encode(content, entry->content);
    entry->timestamp = time(NULL);

    current_entry++;
    if (current_entry == MAX_ENTRIES) {
        printf("Diary is full.\n");
    }
}

void view_entry(int index) {
    Entry *entry = &diary[index];
    char title[ENTRY_SIZE], content[ENTRY_SIZE];

    decode(entry->title, title);
    decode(entry->content, content);

    printf("Title: %s\n", title);
    printf("Content: %s\n", content);
    printf("Timestamp: %s", ctime(&entry->timestamp));
}

int main() {
    int choice;

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Add Entry\n");
        printf("2. View Entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                if (current_entry > 0) {
                    int index;
                    printf("Enter the index of the entry to view: ");
                    scanf("%d", &index);
                    view_entry(index);
                } else {
                    printf("Diary is empty.\n");
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}