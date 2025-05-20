#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRY_LENGTH 256

void add_entry() {
    FILE *file = fopen("diary.txt", "a");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your diary entry: ");
    fgets(entry, sizeof(entry), stdin);
    fprintf(file, "%s", entry);
    fclose(file);
}

void read_entries() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    char entry[MAX_ENTRY_LENGTH];
    while (fgets(entry, sizeof(entry), file)) {
        printf("%s", entry);
    }
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("\nDigital Diary\n1. Add Entry\n2. Read Entries\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                read_entries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
