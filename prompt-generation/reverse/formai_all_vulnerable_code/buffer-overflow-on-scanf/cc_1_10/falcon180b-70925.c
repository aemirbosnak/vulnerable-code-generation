//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry;

int main() {
    FILE *fp;
    diary_entry diary[MAX_ENTRIES];
    int num_entries = 0;
    char choice;
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    strftime(diary[num_entries].date, 20, "%Y-%m-%d", tm_now);
    printf("Welcome to your digital diary!\n");
    printf("What would you like to do?\n");
    printf("1. Write a new entry\n");
    printf("2. Read previous entries\n");
    printf("3. Exit\n");
    scanf("%c", &choice);

    while (choice!= '3') {
        switch (choice) {
            case '1':
                printf("Enter your entry:\n");
                fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                strcat(diary[num_entries].entry, "\n");
                num_entries++;
                break;
            case '2':
                printf("Previous entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%s: %s", diary[i].date, diary[i].entry);
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\nWhat would you like to do?\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Exit\n");
        scanf("%c", &choice);
    }

    fp = fopen("diary.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%s: %s", diary[i].date, diary[i].entry);
    }
    fclose(fp);

    printf("Thank you for using your digital diary.\n");
    return 0;
}