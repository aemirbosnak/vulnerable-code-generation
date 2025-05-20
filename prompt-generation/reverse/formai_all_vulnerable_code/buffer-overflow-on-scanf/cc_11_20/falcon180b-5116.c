//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

struct entry {
    char date[20];
    char time[10];
    char content[500];
};

int main() {
    FILE *fp;
    char filename[50] = "diary.txt";
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    int i;

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_entries >= MAX_ENTRIES) {
                    printf("Error: maximum number of entries reached.\n");
                } else {
                    printf("Enter the date (dd/mm/yyyy): ");
                    scanf("%s", entries[num_entries].date);
                    printf("Enter the time (hh:mm:ss): ");
                    scanf("%s", entries[num_entries].time);
                    printf("Enter the content:\n");
                    fgets(entries[num_entries].content, 500, stdin);
                    entries[num_entries].content[strcspn(entries[num_entries].content, "\n")] = '\0';
                    num_entries++;
                    printf("Entry saved.\n");
                }
                break;
            case '2':
                if (num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("Entries:\n");
                    for (i = 0; i < num_entries; i++) {
                        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
                    }
                }
                break;
            case '3':
                printf("Enter the search keyword: ");
                scanf("%s", entries[num_entries].content);
                printf("Searching...\n");
                for (i = 0; i < num_entries; i++) {
                    if (strstr(entries[i].content, entries[num_entries].content)!= NULL) {
                        printf("%s %s - %s\n", entries[i].date, entries[i].time, entries[i].content);
                    }
                }
                break;
            case '4':
                printf("Exiting...\n");
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}