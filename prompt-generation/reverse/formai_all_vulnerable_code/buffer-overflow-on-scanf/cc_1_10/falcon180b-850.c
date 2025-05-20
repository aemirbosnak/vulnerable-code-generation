//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 100

struct entry {
    time_t timestamp;
    char message[MAX_ENTRY_LENGTH];
};

int main(void) {
    FILE *fptr;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[MAX_ENTRY_LENGTH];
    char input[MAX_ENTRY_LENGTH];

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter a filename: ");
    scanf("%s", filename);

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("File not found. Creating new file.\n");
        fptr = fopen(filename, "w");
    }

    while (fgets(input, MAX_ENTRY_LENGTH, fptr)!= NULL) {
        if (num_entries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached. Exiting.\n");
            fclose(fptr);
            return 1;
        }

        struct tm* tm = localtime(&entries[num_entries].timestamp);
        strftime(entries[num_entries].message, MAX_ENTRY_LENGTH, "%Y-%m-%d %H:%M:%S", tm);
        num_entries++;
    }

    fclose(fptr);

    while (1) {
        printf("Please enter an activity (e.g. running, swimming, cycling): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        time_t now = time(NULL);
        struct tm* tm = localtime(&now);
        strftime(entries[num_entries].message, MAX_ENTRY_LENGTH, "%Y-%m-%d %H:%M:%S", tm);
        strcat(entries[num_entries].message, " ");
        strcat(entries[num_entries].message, input);

        num_entries++;

        if (num_entries >= MAX_ENTRIES) {
            printf("Maximum number of entries reached. Exiting.\n");
            break;
        }
    }

    fptr = fopen(filename, "w");
    for (int i = 0; i < num_entries; i++) {
        fprintf(fptr, "%s\n", entries[i].message);
    }

    fclose(fptr);

    return 0;
}