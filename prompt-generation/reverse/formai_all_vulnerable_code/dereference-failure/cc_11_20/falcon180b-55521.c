//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    DiaryEntry diaryEntries[MAX_ENTRIES];
    int numEntries = 0;
    char choice;

    if ((diary = fopen(filename, "a")) == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Create new entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Edit entry\n");
        printf("5. Delete entry\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the date (YYYY-MM-DD): ");
                scanf("%s", diaryEntries[numEntries].date);
                printf("Enter your entry: ");
                fgets(diaryEntries[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
                numEntries++;
                break;

            case '2':
                printf("\nDate\tEntry\n");
                for (int i = 0; i < numEntries; i++) {
                    printf("%s\t%s\n", diaryEntries[i].date, diaryEntries[i].entry);
                }
                break;

            case '3':
                printf("Enter the search term: ");
                char searchTerm[50];
                scanf("%s", searchTerm);
                for (int i = 0; i < numEntries; i++) {
                    if (strstr(diaryEntries[i].entry, searchTerm)!= NULL) {
                        printf("%s\t%s\n", diaryEntries[i].date, diaryEntries[i].entry);
                    }
                }
                break;

            case '4':
                printf("Enter the date of the entry you want to edit: ");
                scanf("%s", diaryEntries[numEntries-1].date);
                printf("Enter your new entry: ");
                fgets(diaryEntries[numEntries-1].entry, MAX_ENTRY_LENGTH, stdin);
                break;

            case '5':
                printf("Enter the date of the entry you want to delete: ");
                scanf("%s", diaryEntries[numEntries-1].date);
                numEntries--;
                break;

            case '6':
                printf("Exiting program...\n");
                fclose(diary);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}