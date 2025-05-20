//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_LENGTH];
};

int main() {
    FILE *diary;
    diary = fopen("diary.txt", "a+");
    if (diary == NULL) {
        printf("Error opening diary file.\n");
        return 1;
    }

    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char choice;
    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("> ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Diary is full.\n");
                } else {
                    printf("Write your entry:\n");
                    fgets(entries[num_entries].text, MAX_LENGTH, stdin);
                    entries[num_entries].timestamp = time(NULL);
                    num_entries++;
                    fprintf(diary, "%s\n", entries[num_entries-1].text);
                    printf("Entry saved.\n");
                }
                break;

            case '2':
                rewind(diary);
                printf("Diary entries:\n");
                while (fgets(entries[num_entries].text, MAX_LENGTH, diary)!= NULL) {
                    printf("%s", entries[num_entries].text);
                    num_entries++;
                }
                break;

            case '3':
                printf("Search for:\n");
                fgets(entries[num_entries].text, MAX_LENGTH, stdin);
                rewind(diary);
                while (fgets(entries[num_entries].text, MAX_LENGTH, diary)!= NULL) {
                    if (strstr(entries[num_entries].text, entries[num_entries-1].text)!= NULL) {
                        printf("%s", entries[num_entries].text);
                    }
                    num_entries++;
                }
                break;

            case '4':
                fclose(diary);
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}