//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *file;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[50];
    char line[MAX_ENTRY_LENGTH];
    time_t now;

    srand(time(NULL));
    now = time(NULL);

    strftime(filename, 50, "diary_%Y%m%d.txt", localtime(&now));
    file = fopen(filename, "a+");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_ENTRY_LENGTH, file)!= NULL) {
        if (num_entries >= MAX_ENTRIES) {
            printf("Error: maximum number of entries reached.\n");
            exit(1);
        }

        struct entry *entry = &entries[num_entries];
        entry->timestamp = strtol(line, NULL, 10);
        strcpy(entry->text, line + strlen(line) - 1);
        num_entries++;
    }

    fclose(file);

    while (1) {
        printf("Digital Diary\n");
        printf("-----------------\n");
        printf("1. Write a new entry\n");
        printf("2. Read existing entries\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter your entry: ");
                fgets(line, MAX_ENTRY_LENGTH, stdin);
                struct tm *tm = localtime(&now);
                fprintf(file, "%d-%02d-%02d %02d:%02d:%02d %s\n",
                        tm->tm_year + 1900,
                        tm->tm_mon + 1,
                        tm->tm_mday,
                        tm->tm_hour,
                        tm->tm_min,
                        tm->tm_sec,
                        line);
                fclose(file);
                printf("Entry saved.\n");
                break;
            }
            case 2: {
                printf("Existing entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s (%s)\n", entries[i].text, ctime(&entries[i].timestamp));
                }
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}