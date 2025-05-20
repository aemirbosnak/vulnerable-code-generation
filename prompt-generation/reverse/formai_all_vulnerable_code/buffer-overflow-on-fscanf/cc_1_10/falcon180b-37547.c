//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct Entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *fp;
    struct Entry entries[MAX_ENTRIES];
    int numEntries = 0;
    char input[MAX_ENTRY_LENGTH];
    char *token;
    time_t now;

    // Open the diary file
    fp = fopen("diary.txt", "a+");
    if (fp == NULL) {
        printf("Error opening diary file.\n");
        exit(1);
    }

    // Read in the existing entries
    rewind(fp);
    while (fscanf(fp, "%s %s %s\n", entries[numEntries].date, entries[numEntries].time, entries[numEntries].content)!= EOF) {
        numEntries++;
    }

    // Prompt the user for a new entry
    printf("Enter a new diary entry:\n");
    fgets(input, MAX_ENTRY_LENGTH, stdin);

    // Parse the input into date, time, and content
    token = strtok(input, " ");
    strcpy(entries[numEntries].date, token);
    token = strtok(NULL, " ");
    strcpy(entries[numEntries].time, token);
    strcpy(entries[numEntries].content, input + strlen(entries[numEntries].date) + strlen(entries[numEntries].time) + 2);

    // Write the new entry to the file
    fprintf(fp, "%s %s %s\n", entries[numEntries].date, entries[numEntries].time, entries[numEntries].content);

    // Close the file
    fclose(fp);

    // Print the updated diary
    fprintf(stdout, "Diary updated:\n");
    fprintf(stdout, "---------------------------------\n");
    fprintf(stdout, "Date\tTime\tContent\n");
    fprintf(stdout, "---------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        fprintf(stdout, "%s\t%s\t%s\n", entries[i].date, entries[i].time, entries[i].content);
    }
    fprintf(stdout, "---------------------------------\n");

    return 0;
}