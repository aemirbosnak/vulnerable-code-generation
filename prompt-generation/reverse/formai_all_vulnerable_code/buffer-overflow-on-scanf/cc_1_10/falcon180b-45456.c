//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    time_t timestamp;
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *fp;
    char filename[20];
    time_t now;
    Entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    printf("Welcome to your digital diary!\n");
    printf("Please enter a filename (without extension): ");
    scanf("%s", filename);

    strcat(filename, ".txt");
    fp = fopen(filename, "a");

    if (fp == NULL) {
        printf("Error: could not create file.\n");
        exit(1);
    }

    time(&now);
    entries[num_entries].timestamp = now;
    printf("Diary created on %s\n\n", ctime(&now));

    while (1) {
        printf("\n");
        printf("1. Write a new entry\n");
        printf("2. View previous entries\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter your entry (up to %d characters): ", MAX_ENTRY_LENGTH - 1);
            fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
            entries[num_entries].entry[strcspn(entries[num_entries].entry, "\n")] = '\0';
            time(&now);
            entries[num_entries].timestamp = now;
            fprintf(fp, "%s - %s\n", ctime(&now), entries[num_entries].entry);
            num_entries++;
        } else if (choice == 2) {
            rewind(fp);
            printf("\nPrevious entries:\n");
            while (fgets(entries[num_entries].entry, MAX_ENTRY_LENGTH, fp)!= NULL) {
                printf("%s", entries[num_entries].entry);
                num_entries++;
            }
        } else if (choice == 3) {
            fclose(fp);
            printf("Diary saved and exited.\n");
            exit(0);
        } else if (choice == 4) {
            printf("Diary exited without saving.\n");
            exit(0);
        }
    }

    return 0;
}