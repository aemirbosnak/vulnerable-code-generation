//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    FILE *diary_file;
    char filename[50] = "diary.txt";
    char choice;
    char content[MAX_ENTRY_LENGTH];
    int i, j;
    time_t now;

    diary_file = fopen(filename, "a");

    if (diary_file == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("Digital Diary\n");
        printf("A - Add entry\n");
        printf("R - Read entries\n");
        printf("S - Search entries\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter your entry:\n");
                fgets(content, MAX_ENTRY_LENGTH, stdin);
                strtok(content, "\n");
                content[strcspn(content, "\n")] = '\0';
                gettimeofday(&now, NULL);
                strftime(entries[num_entries].date, 20, "%Y-%m-%d", localtime(&now));
                strftime(entries[num_entries].time, 20, "%H:%M:%S", localtime(&now));
                strcpy(entries[num_entries].content, content);
                num_entries++;
                break;

            case 'R':
                printf("\nEntries:\n");
                for (i = 0; i < num_entries; i++) {
                    printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].content);
                }
                break;

            case 'S':
                printf("Enter search keyword: ");
                scanf("%s", content);
                for (i = 0; i < num_entries; i++) {
                    if (strstr(entries[i].content, content)!= NULL) {
                        printf("%s %s\n%s\n", entries[i].date, entries[i].time, entries[i].content);
                    }
                }
                break;

            case 'Q':
                fclose(diary_file);
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}