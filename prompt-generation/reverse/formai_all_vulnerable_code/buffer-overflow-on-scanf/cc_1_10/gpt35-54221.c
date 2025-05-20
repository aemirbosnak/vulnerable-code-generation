//FormAI DATASET v1.0 Category: Digital Diary ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu();
void newEntry();
void viewEntries(int);
int countEntries(FILE*);
void deleteEntry();
int validateEntryID(int, FILE*);
int isLeapYear(int);
int validateDate(int, int, int);

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    int choice, year, month, day;

    printf("\n\nWelcome to My Digital Diary!\n");
    printf("Please select an option:\n");
    printf("1. Add a new entry\n");
    printf("2. View entries\n");
    printf("3. Delete an entry\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            newEntry();
            break;
        case 2:
            printf("Enter the date you want to view (YYYY MM DD): ");
            scanf("%d %d %d", &year, &month, &day);

            if (validateDate(year, month, day)) {
                viewEntries(year*10000 + month*100 + day);
            } else {
                printf("Invalid date!\n");
                displayMenu();
            }
            break;
        case 3:
            deleteEntry();
            break;
        case 4:
            printf("Goodbye!\n");
            exit(1);
        default:
            printf("Invalid choice!\n");
            displayMenu();
            break;
    }
}

void newEntry() {
    int year, month, day;
    char title[50], content[500];

    printf("Enter the title of the entry: ");
    scanf(" %[^\n]%*c", title);

    printf("Enter the date of the entry (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);

    if (!validateDate(year, month, day)) {
        printf("Invalid date!\n");
        newEntry();
    }

    printf("Enter the content of the entry: ");
    scanf(" %[^\n]%*c", content);

    FILE *fp = fopen("diary.txt", "a");
    if (fp == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }

    fprintf(fp, "%d,%d,%d,%s,%s\n", year, month, day, title, content);
    fclose(fp);

    printf("\nEntry added successfully!\n");
    displayMenu();
}

void viewEntries(int date) {
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        printf("No entries found!\n");
        displayMenu();
    }

    int count = countEntries(fp);

    if (count == 0) {
        printf("No entries found!\n");
        fclose(fp);
        displayMenu();
    }

    rewind(fp);

    int entryCount = 0;
    char line[600];

    printf("Entries for %d:\n", date);

    while (fgets(line, sizeof(line), fp)) {
        int fileDate;
        char title[50], content[500];
        sscanf(line, "%d,%s,%[^\n]", &fileDate, title, content);

        if (fileDate == date) {
            printf("\n--------------------------\n");
            printf("Title: %s\n", title);
            printf("Content: %s\n", content);
            printf("--------------------------\n");
            entryCount++;
        }
    }

    if (entryCount == 0) {
        printf("No entries found for this date!\n");
    }

    fclose(fp);

    displayMenu();
}

int countEntries(FILE *fp) {
    int count = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    return count;
}

void deleteEntry() {
    int year, month, day, id;

    printf("Enter the date of the entry you want to delete (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);

    if (!validateDate(year, month, day)) {
        printf("Invalid date!\n");
        deleteEntry();
    }

    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        printf("No entries found!\n");
        displayMenu();
    }

    int count = countEntries(fp);

    if (count == 0) {
        printf("No entries found!\n");
        fclose(fp);
        displayMenu();
    }

    int validID = 0;
    printf("Enter the ID of the entry you want to delete: ");
    scanf("%d", &id);

    validID = validateEntryID(id, fp);

    if (validID) {
        FILE *temp = fopen("temp.txt", "w");
        if (temp == NULL) {
            printf("Error creating file!\n");
            exit(1);
        }

        rewind(fp);
        char line[600];
        int deleted = 0;

        while (fgets(line, sizeof(line), fp)) {
            int fileDate;
            char title[50], content[500];
            sscanf(line, "%d,%s,%[^\n]", &fileDate, title, content);

            if (fileDate == year*10000 + month*100 + day) {
                id--;
                if (id == 0 && !deleted) {
                    deleted = 1;
                    continue;
                }
            }

            fprintf(temp, "%d,%s,%s\n", fileDate, title, content);
        }

        fclose(fp);
        fclose(temp);

        remove("diary.txt");
        rename("temp.txt", "diary.txt");

        printf("\nEntry deleted successfully!\n");
    } else {
        printf("Invalid ID!\n");
    }

    displayMenu();
}

int validateEntryID(int id, FILE *fp) {
    rewind(fp);
    int count = 0, validID = 0;

    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    rewind(fp);
    char line[600];

    while (fgets(line, sizeof(line), fp)) {
        int fileDate;
        char title[50], content[500];
        sscanf(line, "%d,%s,%[^\n]", &fileDate, title, content);

        validID = 0;

        if (id == count) {
            validID = 1;
            break;
        }

        count--;
    }

    return validID;
}

int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int validateDate(int year, int month, int day) {
    if (year < 1900 || year > 2099) {
        return 0;
    }

    if (month < 1 || month > 12) {
        return 0;
    }

    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            if (day < 1 || day > 30) {
                return 0;
            }
            break;
        case 2:
            if (isLeapYear(year)) {
                if (day < 1 || day > 29) {
                    return 0;
                }
            } else {
                if (day < 1 || day > 28) {
                    return 0;
                }
            }
            break;
        default:
            if (day < 1 || day > 31) {
                return 0;
            }
            break;
    }

    return 1;
}