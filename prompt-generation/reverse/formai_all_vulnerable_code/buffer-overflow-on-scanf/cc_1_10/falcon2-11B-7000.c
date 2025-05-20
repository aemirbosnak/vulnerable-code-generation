//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

// Function to write to a text file
void writeToFile(char *filename, char *content) {
    FILE *fptr = fopen(filename, "a");
    if (fptr == NULL) {
        printf("Error opening file\n");
    } else {
        fprintf(fptr, "%s\n", content);
        fclose(fptr);
    }
}

// Function to get current date and time
void getDateAndTime() {
    time_t now;
    time(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d %B %Y %X", localtime(&now));
    printf("Current date and time: %s\n", buffer);
}

int main() {
    // Set up the diary file
    char diaryFileName[50] = "diary.txt";
    FILE *fptr = fopen(diaryFileName, "a");
    if (fptr == NULL) {
        printf("Error opening file\n");
    } else {
        fclose(fptr);
    }

    // Get current date and time
    getDateAndTime();

    // Ask user for diary entry
    char diaryEntry[80];
    printf("Enter your diary entry: ");
    scanf("%s", diaryEntry);

    // Write diary entry to file
    writeToFile(diaryFileName, diaryEntry);

    // Get user's name
    char name[50];
    printf("What is your name? ");
    scanf("%s", name);

    // Write name to file
    writeToFile(diaryFileName, name);

    printf("Your diary entry has been recorded! %s\n", diaryEntry);

    return 0;
}