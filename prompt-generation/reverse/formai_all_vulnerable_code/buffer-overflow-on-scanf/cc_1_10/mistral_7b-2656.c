//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE 100

typedef struct {
    char title[50];
    char description[50];
    char date[11];
} Entry;

void saveEntry(int index, Entry* entry);
Entry loadEntry(int index);
void printMenu();

Entry entries[MAX_ENTRIES];
int currentEntry = 0;

int main() {
    int choice;

    while(1) {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(currentEntry < MAX_ENTRIES) {
                    printf("Enter Title: ");
                    scanf("%s", entries[currentEntry].title);
                    printf("Enter Description: ");
                    scanf("%s", entries[currentEntry].description);
                    printf("Enter Date (dd-mm-yy): ");
                    scanf("%s", entries[currentEntry].date);
                    saveEntry(currentEntry, &entries[currentEntry]);
                    currentEntry++;
                } else {
                    printf("Diary is full!\n");
                }
                break;
            case 2:
                if(currentEntry > 0) {
                    Entry entry = loadEntry(currentEntry - 1);
                    printf("Title: %s\n", entry.title);
                    printf("Description: %s\n", entry.description);
                    printf("Date: %s\n", entry.date);
                } else {
                    printf("No entries yet!\n");
                }
                break;
            case 3:
                printf("Exiting Diary...\n");
                exit(0);
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}

void printMenu() {
    printf("\nRetro Digital Diary\n");
    printf("---------------------\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Exit\n");
}

void saveEntry(int index, Entry* entry) {
    FILE* fp = fopen("diary.dat", "ab");
    if(fp == NULL) {
        printf("Error saving entry!\n");
        exit(1);
    }

    fwrite(entry, sizeof(Entry), 1, fp);
    fclose(fp);
}

Entry loadEntry(int index) {
    FILE* fp = fopen("diary.dat", "rb");

    if(fp == NULL) {
        printf("Error loading entry!\n");
        exit(1);
    }

    fseek(fp, index * sizeof(Entry), SEEK_SET);
    Entry entry;
    fread(&entry, sizeof(Entry), 1, fp);

    fclose(fp);
    return entry;
}