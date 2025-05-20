//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[11];
    char entry[1024];
} Entry;

int main() {
    FILE *file;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t now;

    file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Diary file not found. Creating new file...\n");
        file = fopen("diary.txt", "w");
        fprintf(file, "Digital Diary\n");
        fprintf(file, "------------------------\n");
    } else {
        fseek(file, 0, SEEK_END);
        num_entries = ftell(file) / sizeof(Entry);
        rewind(file);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("------------------------\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter your entry:\n");
                fgets(entries[num_entries].entry, sizeof(entries[num_entries].entry), stdin);
                time(&now);
                strftime(entries[num_entries].date, sizeof(entries[num_entries].date), "%Y-%m-%d %H:%M:%S", localtime(&now));
                num_entries++;
                break;

            case '2':
                if (num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("\nPrevious entries:\n");
                    for (int i = 0; i < num_entries; i++) {
                        printf("%s: %s\n", entries[i].date, entries[i].entry);
                    }
                }
                break;

            case '3':
                rewind(file);
                for (int i = 0; i < num_entries; i++) {
                    fprintf(file, "%s: %s\n", entries[i].date, entries[i].entry);
                }
                printf("Entries saved.\n");
                break;

            case '4':
                printf("Exiting without saving...\n");
                break;

            default:
                printf("Invalid option.\n");
        }

        if (choice == '3' || choice == '4') {
            break;
        }
    }

    fclose(file);
    return 0;
}