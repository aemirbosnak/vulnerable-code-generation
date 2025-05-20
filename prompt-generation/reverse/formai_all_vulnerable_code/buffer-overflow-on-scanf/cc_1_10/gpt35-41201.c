//FormAI DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void write_diary_entry();
void read_diary_entries();

int main()
{
    int choice;
    srand(time(NULL));

    do {
        printf("Welcome to your Digital Diary!\n");
        printf("1. Write a diary entry\n");
        printf("2. Read diary entries\n");
        printf("3. Exit\n");
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 3);

    return 0;
}

void write_diary_entry()
{
    char title[50];
    char entry[1000];
    char filename[100];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    printf("Enter title for diary entry: ");
    scanf("%s", title);

    sprintf(filename, "%s_%04d-%02d-%02d_%02d-%02d-%02d.txt", title, tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    FILE *fp = fopen(filename, "w");

    printf("Enter diary entry: ");
    scanf("%s", entry);

    fprintf(fp, "%s\n", entry);

    fclose(fp);

    printf("Saved diary entry as %s\n", filename);
}

void read_diary_entries()
{
    int i, count = 0;
    char **entries;

    printf("Reading diary entries...\n");

    for (i = 0; i < 10; i++) {
        char filename[100];
        sprintf(filename, "entry_%02d.txt", i);

        FILE *fp = fopen(filename, "r");

        if (fp) {
            count++;
            entries = (char **)realloc(entries, count * sizeof(char *));
            entries[count - 1] = (char *)malloc(1000 * sizeof(char));
            fscanf(fp, "%s", entries[count - 1]);

            fclose(fp);
        }
    }

    if (count == 0) {
        printf("No diary entries found.\n");
    } else {
        printf("%d diary entries found.\n", count);

        for (i = 0; i < count; i++) {
            printf("%d. %s\n", i + 1, entries[i]);
        }
    }
}