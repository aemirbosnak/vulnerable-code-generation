//FormAI DATASET v1.0 Category: Digital Diary ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct diary_entry {
    char date[12];
    char time[10];
    char entry[256];
} diary;

void write_diary_entry() {
    printf("\n\nDate (mm/dd/yyyy): ");
    scanf("%s", diary.date);
    printf("Time (hh:mm:ss): ");
    scanf("%s", diary.time);
    printf("Enter your diary entry: ");
    getchar();
    fgets(diary.entry, 256, stdin);

    FILE* fp = fopen("mydiary.txt", "a");
    fprintf(fp, "%s %s\n%s\n", diary.date, diary.time, diary.entry);
    fclose(fp);
    printf("\nDiary Entry Saved Successfully!\n\n");
}

void read_diary_entries() {
    printf("\n\nDiary Entries:\n\n");

    FILE* fp = fopen("mydiary.txt", "r");
    if (fp == NULL) {
        printf("No diary entries yet.\n\n");
        return;
    }

    char c;
    while ((c = getc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);
}

int main() {

    int choice = 0;

    while (choice != 3) {
        printf("\n\n1. Write Diary Entry\n2. Read Diary Entries\n3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                write_diary_entry();
                break;
            case 2:
                read_diary_entries();
                break;
            case 3:
                printf("\nGoodbye!\n\n");
                break;
            default:
                printf("\nInvalid choice. Please try again!\n\n");
                break;
        }
    }

    return 0;
}