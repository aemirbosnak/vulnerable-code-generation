//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary_file;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    diary_file = fopen("diary.txt", "a");
    if (diary_file == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("Digital Diary\n");
        printf("--------------------\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter your entry:\n");
            fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
            entries[num_entries].timestamp = time(NULL);
            num_entries++;
            if (num_entries >= MAX_ENTRIES) {
                printf("Diary is full. Please delete some entries.\n");
            } else {
                fprintf(diary_file, "%s - %s\n", ctime(&entries[num_entries-1].timestamp), entries[num_entries-1].text);
            }
            break;
        case '2':
            rewind(diary_file);
            while (fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, diary_file)!= NULL) {
                printf("%s - %s\n", ctime(&entries[num_entries].timestamp), entries[num_entries].text);
                num_entries++;
            }
            break;
        case '3':
            fclose(diary_file);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}