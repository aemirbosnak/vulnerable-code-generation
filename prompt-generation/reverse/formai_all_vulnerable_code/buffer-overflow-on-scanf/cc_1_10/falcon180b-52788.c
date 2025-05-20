//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50] = "diary.txt";
    char choice;

    diary = fopen(filename, "a+");

    if (diary == NULL) {
        printf("Error: Could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        printf("Choose an option: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (num_entries >= MAX_ENTRIES) {
                printf("Error: Maximum number of entries reached.\n");
            } else {
                printf("Enter your entry: ");
                fflush(stdin);
                fgets(entries[num_entries].text, ENTRY_LENGTH, stdin);
                entries[num_entries].timestamp = time(NULL);
                num_entries++;
                printf("Entry saved.\n");
            }
            break;

        case '2':
            if (num_entries == 0) {
                printf("No entries found.\n");
            } else {
                printf("Your entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s - %s", ctime(&entries[i].timestamp), entries[i].text);
                }
            }
            break;

        case '3':
            fclose(diary);
            exit(0);

        case '4':
            printf("Exiting without saving...\n");
            fclose(diary);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}