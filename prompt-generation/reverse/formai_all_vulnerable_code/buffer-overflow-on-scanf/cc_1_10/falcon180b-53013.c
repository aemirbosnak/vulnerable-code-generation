//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100
#define MAX_ENTRIES 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

typedef struct {
    time_t timestamp;
    char entry[MAX_WORDS * MAX_WORD_LENGTH];
} DiaryEntry;

int main() {
    FILE *diaryFile;
    char filename[MAX_WORD_LENGTH];
    char buffer[MAX_WORD_LENGTH];
    int choice;
    time_t currentTime;
    time(&currentTime);
    srand(currentTime);

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter a filename (without extension): ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    diaryFile = fopen(filename, "a+");
    if (diaryFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Write a new entry\n");
        printf("2. View previous entries\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your entry:\n");
                fgets(buffer, MAX_WORD_LENGTH, stdin);
                fprintf(diaryFile, "%s\n", buffer);
                printf("Entry saved.\n");
                break;
            case 2:
                rewind(diaryFile);
                while (fgets(buffer, MAX_WORD_LENGTH, diaryFile)!= NULL) {
                    printf("%s", buffer);
                }
                break;
            case 3:
                fclose(diaryFile);
                exit(0);
            case 4:
                fclose(diaryFile);
                exit(1);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}