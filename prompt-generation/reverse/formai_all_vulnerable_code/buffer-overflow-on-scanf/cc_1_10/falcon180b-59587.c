//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[20];
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    char choice;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    diary = fopen(filename, "r");
    if (diary == NULL) {
        printf("Diary file not found. Creating a new one.\n");
        diary = fopen(filename, "w");
        fprintf(diary, "Welcome to your digital diary!\n");
        fclose(diary);
        diary = fopen(filename, "r");
    }
    else {
        fclose(diary);
    }

    while (1) {
        system("clear");
        printf("Digital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the date (dd/mm/yyyy): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter your entry:\n");
                fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
                num_entries++;
                break;
            case '2':
                printf("\nPrevious entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s: %s\n", entries[i].date, entries[i].text);
                }
                break;
            case '3':
                printf("Exiting...\n");
                fclose(diary);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        diary = fopen(filename, "a");
        fprintf(diary, "%s\n", entries[num_entries-1].text);
        fclose(diary);
    }

    return 0;
}