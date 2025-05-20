//FormAI DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct Entry {
    char date[12];
    char text[256];
} Entry;

int main() {
    Entry diary[MAX_ENTRIES];
    int num_entries = 0;

    // Load existing entries from file
    FILE *file;
    file = fopen("diary.txt", "r");
    if (file != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            char *token = strtok(line, ",");
            strcpy(diary[num_entries].date, token);
            token = strtok(NULL, "\n");
            strcpy(diary[num_entries].text, token);
            num_entries++;
        }
        fclose(file);
    }

    // Prompt user for action
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry.\n");
        printf("2. View existing entries.\n");
        printf("3. Exit program.\n");
        char input[2];
        fgets(input, sizeof(input), stdin);
        int action = atoi(input);
        if (action == 1) {
            Entry new_entry;
            printf("\nEnter the date (MM/DD/YYYY): ");
            fgets(new_entry.date, sizeof(new_entry.date), stdin);
            printf("Enter the entry text: ");
            fgets(new_entry.text, sizeof(new_entry.text), stdin);
            if (num_entries < MAX_ENTRIES) {
                diary[num_entries] = new_entry;
                num_entries++;
                printf("\nEntry added successfully.");
            } else {
                printf("\nError: Maximum number of entries exceeded.");
            }
        } else if (action == 2) {
            if (num_entries == 0) {
                printf("\nNo entries found.");
            } else {
                printf("\nHere are your existing entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%d. ", i+1);
                    printf("%s, ", diary[i].date);
                    printf("%s", diary[i].text);
                }
            }
        } else if (action == 3) {
            // Save entries to file before exiting
            file = fopen("diary.txt", "w");
            for (int i = 0; i < num_entries; i++) {
                fprintf(file, "%s,%s", diary[i].date, diary[i].text);
            }
            fclose(file);
            printf("\nGoodbye.");
            exit(0);
        } else {
            printf("\nInvalid input.");
        }
    }
    return 0;
}