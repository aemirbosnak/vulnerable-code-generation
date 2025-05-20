#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char entries[MAX_ENTRIES][ENTRY_SIZE];
    int count;
} Diary;

void initDiary(Diary *diary) {
    diary->count = 0;
}

int addEntry(Diary *diary) {
    if (diary->count >= MAX_ENTRIES) return -1;
    printf("Enter your entry: ");
    fscanf(stdin, "%[^\n]%*c", diary->entries[diary->count]);
    diary->count++;
    return 0;
}

void readEntries(Diary *diary) {
    for (int i = 0; i < diary->count; i++) {
        printf("%s\n", diary->entries[i]);
    }
}

int main() {
    Diary myDiary;
    initDiary(&myDiary);
    while (1) {
        printf("\n1. Add Entry\n2. Read Entries\n3. Exit\n");
        int choice;
        scanf("%d%*c", &choice);
        switch (choice) {
            case 1:
                if (addEntry(&myDiary) == -1) {
                    printf("Diary full!\n");
                }
                break;
            case 2:
                readEntries(&myDiary);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
