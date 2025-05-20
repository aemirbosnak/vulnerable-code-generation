//FormAI DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "Digital_Diary.txt"

void display_menu() {
    printf("1. Add entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Edit an entry\n");
    printf("5. Delete an entry\n");
    printf("6. Exit\n");
}

void add_entry() {
    char entry[1000], date[20];
    printf("Enter date in YYYY-MM-DD format: ");
    scanf("%s", date);
    printf("Enter diary entry:\n");
    getchar();
    fgets(entry, 1000, stdin);
    FILE *fptr = fopen(FILE_NAME, "a");
    fprintf(fptr, "%s%s\n", date, entry);
    fclose(fptr);
    printf("Entry added successfully!\n");
}

void view_all_entries() {
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL) {
        printf("No entries found!\n");
        return;
    }
    char line[1024];
    while (fgets(line, sizeof(line), fptr)) {
        printf("%s", line);
    }
    fclose(fptr);
}

void search_entry() {
    char query[20];
    printf("Enter date in YYYY-MM-DD format to search for: ");
    scanf("%s", query);
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL) {
        printf("No entries found!\n");
        return;
    }
    char line[1024];
    int found = 0;
    while (fgets(line, sizeof(line), fptr)) {
        if (strstr(line, query) != NULL) {
            printf("%s", line);
            found = 1;
        }
    }
    if (!found) printf("No entries found!\n");
    fclose(fptr);
}

void edit_entry() {
    char date[20], new_entry[1000], temp[1024];
    printf("Enter date in YYYY-MM-DD format to edit: ");
    scanf("%s", date);
    FILE *orig = fopen(FILE_NAME, "r");
    FILE *copy = fopen("temp.txt", "w");
    int found = 0;
    while (fgets(temp, sizeof(temp), orig)) {
        if (strstr(temp, date) != NULL) {
            printf("Enter new entry:\n");
            getchar();
            fgets(new_entry, 1000, stdin);
            fprintf(copy, "%s%s", date, new_entry);
            found = 1;
        }
        else {
            fprintf(copy, "%s", temp);
        }
    }
    if (!found) printf("No entries found!\n");
    fclose(orig);
    fclose(copy);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    printf("Entry edited successfully!\n");
}

void delete_entry() {
    char date[20], temp[1024];
    printf("Enter date in YYYY-MM-DD format to delete: ");
    scanf("%s", date);
    FILE *orig = fopen(FILE_NAME, "r");
    FILE *copy = fopen("temp.txt", "w");
    int found = 0;
    while (fgets(temp, sizeof(temp), orig)) {
        if (strstr(temp, date) != NULL) {
            found = 1;
        }
        else {
            fprintf(copy, "%s", temp);
        }
    }
    if (!found) printf("No entries found!\n");
    else printf("Entry deleted successfully!\n");
    fclose(orig);
    fclose(copy);
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
}

int main() {
    int option;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_entry();
                break;
            case 2:
                view_all_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                edit_entry();
                break;
            case 5:
                delete_entry();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please select from menu!\n");
        }
    }
    return 0;
}