//FormAI DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Entry {
    char date[11];
    char time[6];
    char event[51];
};

void print_menu() {
    printf("\n1. New entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void new_entry(FILE *fp) {
    struct Entry e;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("\nEnter the event: ");
    fgets(e.event, 51, stdin);
    e.event[strcspn(e.event, "\n")] = 0; // Remove trailing newline character
    sprintf(e.date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    sprintf(e.time, "%02d:%02d", tm.tm_hour, tm.tm_min);
    fwrite(&e, sizeof(struct Entry), 1, fp);
    printf("\nEntry added successfully!\n");
}

void view_entries(FILE *fp) {
    struct Entry e;
    int count = 0;

    printf("\nAll Entries:\n\n");

    while (fread(&e, sizeof(struct Entry), 1, fp) != 0) {
        printf("%d. %s %s - %s\n", ++count, e.date, e.time, e.event);
    }

    if (count == 0) {
        printf("\nNo entries found.\n");
    } else {
        printf("\nTotal %d entries found.\n", count);
    }
}

void search_entries(FILE *fp) {
    struct Entry e;
    char date[11];
    int count = 0;

    printf("\nEnter the date to search (dd/mm/yyyy): ");
    fgets(date, 11, stdin);
    date[strcspn(date, "\n")] = 0; // Remove trailing newline character

    printf("\nSearch Results:\n\n");

    while (fread(&e, sizeof(struct Entry), 1, fp) != 0) {
        if (strcmp(e.date, date) == 0) {
            printf("%d. %s %s - %s\n", ++count, e.date, e.time, e.event);
        }
    }

    if (count == 0) {
        printf("\nNo entries found for the given date.\n");
    } else {
        printf("\nTotal %d entries found.\n", count);
    }
}

int main() {
    FILE *fp;
    int option;

    fp = fopen("diary.dat", "ab+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (1) {
        print_menu();
        scanf("%d", &option);
        getchar(); // Remove newline character from input buffer

        switch (option) {
            case 1:
                new_entry(fp);
                break;
            case 2:
                view_entries(fp);
                break;
            case 3:
                search_entries(fp);
                break;
            case 4:
                printf("\nExiting...\n");
                fclose(fp);
                exit(0);
            default:
                printf("\nInvalid option.\n");
        }
    }

    return 0;
}