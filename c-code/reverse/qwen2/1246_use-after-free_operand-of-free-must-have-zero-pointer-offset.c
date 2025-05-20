#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 5

typedef struct {
    char entry[256];
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];

void add_entry(int index) {
    if (index >= 0 && index < MAX_ENTRIES) {
        printf("Enter your diary entry: ");
        fgets(entries[index].entry, sizeof(entries[index].entry), stdin);
    } else {
        printf("Invalid index!\n");
    }
}

void print_entries() {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        printf("%d: %s", i, entries[i].entry);
    }
}

int main() {
    int choice, index;
    while (1) {
        printf("\n1. Add Entry\n2. Print Entries\n3. Exit\n");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf
        switch (choice) {
            case 1:
                printf("Enter entry index: ");
                scanf("%d", &index);
                getchar();
                add_entry(index);
                break;
            case 2:
                print_entries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
