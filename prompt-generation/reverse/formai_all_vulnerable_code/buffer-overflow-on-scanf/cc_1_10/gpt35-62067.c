//FormAI DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct DiaryEntry {
    int day, month, year;
    char title[50];
    char entry[200];
};

void display_menu();
void write_entry(FILE *file);
void read_entry(FILE *file);
void delete_entry(FILE *file);

int main() {
    FILE *file;
    char filename[20];
    int choice;

    printf("Welcome to your digital diary!\n");
    printf("Please enter the filename you'd like to use: ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    file = fopen(filename, "a+");

    if (file == NULL) {
        printf("Error accessing file.\n");
        exit(1);
    }

    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                write_entry(file);
                break;
            case 2:
                read_entry(file);
                break;
            case 3:
                delete_entry(file);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    fclose(file);
    return 0;
}

void display_menu() {
    printf("\n\nMenu:\n");
    printf("1. Write an entry\n");
    printf("2. Read all entries\n");
    printf("3. Delete an entry\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

void write_entry(FILE *file) {
    struct DiaryEntry entry;
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);

    printf("\nEnter the title of your entry: ");
    scanf("%s", entry.title);
    printf("Enter the text of your entry (up to 200 characters): ");
    scanf("\n%[^\n]", entry.entry);

    entry.day = current_time->tm_mday;
    entry.month = current_time->tm_mon + 1;
    entry.year = current_time->tm_year + 1900;

    fprintf(file, "%d/%d/%d\n%s\n%s\n", entry.day, entry.month, entry.year, entry.title, entry.entry);
    printf("Entry saved!\n");
}

void read_entry(FILE *file) {
    struct DiaryEntry entry;

    rewind(file);
    fgets(entry.title, 50, file);

    if (entry.title[0] == '\n') {
        printf("No entries yet!\n");
        return;
    }

    printf("\n\nYour entries:\n\n");
    while (!feof(file)) {
        fscanf(file, "%d/%d/%d\n", &entry.day, &entry.month, &entry.year);
        printf("%d/%d/%d - %s\n", entry.day, entry.month, entry.year, entry.title);
        fgets(entry.entry, 200, file);
        printf("%s\n", entry.entry);
        fgets(entry.title, 50, file);
    }
    rewind(file);
}

void delete_entry(FILE *file) {
    struct DiaryEntry entry;
    char title[50];
    int found = 0;

    printf("Enter the title of the entry you'd like to delete: ");
    scanf("%s", title);

    while (!feof(file)) {
        fscanf(file, "%d/%d/%d\n", &entry.day, &entry.month, &entry.year);
        fgets(entry.title, 50, file);
        fgets(entry.entry, 200, file);
        if (strcmp(title, entry.title) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Are you sure you'd like to delete this entry?\n");
        printf("%d/%d/%d - %s\n", entry.day, entry.month, entry.year, entry.title);
        printf("%s\n", entry.entry);
        printf("1. Yes\n2. No\n");
        scanf("%d", &found);
        if (found == 1) {
            fseek(file, -strlen(entry.title)-strlen(entry.entry)-13, SEEK_CUR);
            fprintf(file, "");
            printf("Entry deleted!\n");
        } else {
            printf("Entry not deleted.\n");
        }
    } else {
        printf("Entry not found.\n");
    }

    rewind(file);
}