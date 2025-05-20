//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRY_LENGTH 500
#define MAX_ENTRIES 100

typedef struct {
    char date[15];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

int main() {
    int numEntries = 0;
    DiaryEntry diary[MAX_ENTRIES];
    char input[MAX_ENTRY_LENGTH];
    char date[15];
    char entry[MAX_ENTRY_LENGTH];

    printf("Welcome to your digital diary!\n\n");

    while(1) {
        printf("Please enter the date (mm/dd/yyyy): ");
        scanf("%s", date);
        printf("Please enter your entry:\n");
        fgets(input, MAX_ENTRY_LENGTH, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Convert input to lowercase
        for(int i=0; i<strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // Add entry to diary
        strcpy(diary[numEntries].date, date);
        strcpy(diary[numEntries].entry, input);
        numEntries++;

        if(numEntries >= MAX_ENTRIES) {
            printf("You have reached the maximum number of entries.\n");
            break;
        }
    }

    printf("\nYour diary entries:\n");
    for(int i=0; i<numEntries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }

    return 0;
}