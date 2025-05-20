//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
    int index;
} entry;

void create_index(entry entries[], int num_entries) {
    int i, j;
    entry temp;
    char key[MAX_NAME_LEN];
    for (i = 0; i < num_entries; i++) {
        strcpy(key, entries[i].name);
        j = i - 1;
        while (j >= 0 && strcmp(key, entries[j].name) > 0) {
            temp = entries[j];
            entries[j] = entries[j+1];
            entries[j+1] = temp;
            j--;
        }
    }
}

void search_index(entry entries[], int num_entries, char* search_key) {
    int left = 0;
    int right = num_entries - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (strcmp(entries[mid].name, search_key) == 0) {
            printf("Found %s: %s\n", search_key, entries[mid].value);
            return;
        } else if (strcmp(entries[mid].name, search_key) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Not found: %s\n", search_key);
}

int main() {
    entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char input[MAX_VALUE_LEN];
    while (num_entries < MAX_ENTRIES) {
        printf("Enter name (or 'done' to finish): ");
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        strcpy(entries[num_entries].name, input);
        printf("Enter value: ");
        scanf("%s", entries[num_entries].value);
        num_entries++;
    }
    create_index(entries, num_entries);
    char search_key[MAX_NAME_LEN];
    while (1) {
        printf("Enter search key: ");
        scanf("%s", search_key);
        search_index(entries, num_entries, search_key);
    }
    return 0;
}