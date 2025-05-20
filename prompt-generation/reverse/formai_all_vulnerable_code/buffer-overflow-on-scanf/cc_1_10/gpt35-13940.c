//FormAI DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Diary {
    char date[20];
    char entry[200];
} Diary;

void save_entry(Diary *diary, int count) {
    FILE *fp;
    time_t t;
    struct tm *tm;

    fp = fopen("diary.txt", "a");
    if (fp == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }

    // Get the current date and time
    t = time(NULL);
    tm = localtime(&t);

    // Save the entry
    fprintf(fp, "%d/%d/%d: %s\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, diary[count].entry);

    fclose(fp);
}

void display_entries(Diary *diary, int count) {
    FILE *fp;
    char line[201];
    int i;

    fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file for reading.\n");
        return;
    }

    // Print all the entries
    for (i = 0; i < count; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].entry);
    }

    printf("\nPrevious entries:\n");
    while (fgets(line, 201, fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

int main() {
    Diary diary[50];
    int option, count = 0;

    do {
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Exit\n\n");

        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter today's entry:\n");
                scanf(" %[^\n]", diary[count].entry);
                save_entry(diary, count);
                count++;
                break;

            case 2:
                display_entries(diary, count);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 3);

    return 0;
}