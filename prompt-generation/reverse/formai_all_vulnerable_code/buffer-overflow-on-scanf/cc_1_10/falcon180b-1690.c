//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    
    do {
        system("clear"); // clear screen
        printf("Welcome to your digital diary!\n");
        printf("1. Write a new entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (num_entries >= MAX_ENTRIES) {
                    printf("Diary is full. Please delete some entries to make room.\n");
                } else {
                    printf("Enter date (YYYY-MM-DD): ");
                    scanf("%s", entries[num_entries].date);
                    printf("Enter entry:\n");
                    fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                    num_entries++;
                    printf("Entry saved.\n");
                }
                break;
            case 2:
                if (num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("Select entry by date (YYYY-MM-DD): ");
                    scanf("%s", filename);
                    diary = fopen(filename, "r");
                    if (diary == NULL) {
                        printf("Entry not found.\n");
                    } else {
                        while (fgets(entries[num_entries].date, 20, diary)!= NULL) {
                            if (strcmp(entries[num_entries].date, filename) == 0) {
                                printf("%s\n%s\n", entries[num_entries].date, entries[num_entries].entry);
                            }
                            num_entries++;
                        }
                        fclose(diary);
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);
    
    return 0;
}