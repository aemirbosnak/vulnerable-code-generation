//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createDiaryEntry(const char *entry, const char *date);
void readDiaryEntry(const char *date, char *entry);
void writeDiaryEntry(const char *entry, const char *date);

int main() {
    char entry[100];
    char date[20];

    srand(time(NULL));

    printf("Enter a diary entry (max 100 characters): ");
    scanf("%s", entry);

    printf("Enter the date (format: YYYY-MM-DD): ");
    scanf("%s", date);

    createDiaryEntry(entry, date);

    printf("Your diary entry for %s has been created!\n", date);

    return 0;
}

void createDiaryEntry(const char *entry, const char *date) {
    FILE *file = fopen("diary.txt", "a");

    if (file == NULL) {
        printf("Error opening diary file.\n");
        return;
    }

    fprintf(file, "%s - %s\n", date, entry);

    fclose(file);
}

void readDiaryEntry(const char *date, char *entry) {
    FILE *file = fopen("diary.txt", "r");

    if (file == NULL) {
        printf("Error opening diary file.\n");
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "") == 0) {
            break;
        }

        if (sscanf(line, "%s - %s", date, entry) == 2) {
            printf("Your diary entry for %s: %s\n", date, entry);
        }
    }

    fclose(file);
}

void writeDiaryEntry(const char *entry, const char *date) {
    FILE *file = fopen("diary.txt", "a");

    if (file == NULL) {
        printf("Error opening diary file.\n");
        return;
    }

    fprintf(file, "%s - %s\n", date, entry);

    fclose(file);
}