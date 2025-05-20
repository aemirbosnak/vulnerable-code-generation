//FormAI DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define the maximum number of characters for the diary entry
#define MAX_ENTRY_LENGTH 1000

// function to get the current time and date
char *getCurrentTimeAndDate() {
    time_t now;
    time(&now);
    return ctime(&now);
}

int main() {

    FILE *fp;
    char entry[MAX_ENTRY_LENGTH];
    char fileName[20];
    char *currentTimeAndDate;

    printf("Welcome to your digital diary!\n\n");

    // get the filename for the diary entry
    printf("Please enter a filename for your diary entry: ");
    scanf("%s", fileName);

    // create a new file with the given filename
    fp = fopen(fileName, "w");

    if(fp == NULL) {
        printf("Error: unable to create file %s\n", fileName);
        exit(1);
    }

    // get the diary entry text from the user
    printf("\nPlease enter your diary entry below:\n");

    // clear the input buffer
    fflush(stdin);

    // read the diary entry
    fgets(entry, MAX_ENTRY_LENGTH, stdin);

    // add a time and date stamp to the diary entry
    currentTimeAndDate = getCurrentTimeAndDate();

    // remove the newline character from the end of the diary entry
    entry[strcspn(entry, "\n")] = 0;

    // write the diary entry to the file
    fprintf(fp, "[%s] %s\n", currentTimeAndDate, entry);

    // close the file
    fclose(fp);

    printf("\nYour diary entry was successfully saved to %s\n", fileName);

    return 0;
}