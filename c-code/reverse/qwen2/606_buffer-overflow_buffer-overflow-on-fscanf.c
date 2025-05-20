#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRY_SIZE 256

void write_entry() {
    FILE *file = fopen("diary.txt", "a");
    if (!file) return;
    char entry[MAX_ENTRY_SIZE];
    printf("Enter your entry: ");
    fgets(entry, sizeof(entry), stdin);
    fprintf(file, "%s", entry);
    fclose(file);
}

void read_entries() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) return;
    char entry[MAX_ENTRY_SIZE];
    while (fgets(entry, sizeof(entry), file)) {
        printf("%s", entry);
    }
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("\nDiary Application\n");
        printf("1. Write Entry\n");
        printf("2. Read Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf
        switch (choice) {
            case 1:
                write_entry();
                break;
            case 2:
                read_entries();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
