//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500
#define PASSWORD "mysecretpassword"

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void read_entries() {
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        printf("No diary entries found.\n");
        return;
    }

    char line[MAX_ENTRY_LENGTH];
    while (fgets(line, MAX_ENTRY_LENGTH, fp)!= NULL) {
        Entry entry;
        sscanf(line, "%s %s", entry.date, entry.entry);
        strcpy(entries[num_entries].date, entry.date);
        strcpy(entries[num_entries].entry, entry.entry);
        num_entries++;
    }

    fclose(fp);
}

void write_entry(char *date, char *entry) {
    FILE *fp = fopen("diary.txt", "a");
    if (fp == NULL) {
        printf("Error writing diary entry.\n");
        return;
    }

    fprintf(fp, "%s %s\n", date, entry);
    fclose(fp);
}

void main_menu() {
    int choice;

    while (1) {
        printf("Digital Diary\n");
        printf("1. Read entries\n");
        printf("2. Write entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_entries();
                break;
            case 2:
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", entries[num_entries].date);
                printf("Enter entry:\n");
                fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
                write_entry(entries[num_entries].date, entries[num_entries].entry);
                num_entries++;
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    char password[100];

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(password, PASSWORD)!= 0) {
        printf("Incorrect password.\n");
        return 1;
    }

    main_menu();

    return 0;
}