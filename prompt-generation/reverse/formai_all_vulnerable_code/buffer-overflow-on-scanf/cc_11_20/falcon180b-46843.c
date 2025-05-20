//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary_file;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[100];
    time_t current_time;
    int choice;

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter the filename of your diary (without extension): ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    diary_file = fopen(filename, "a+");
    if (diary_file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (1) {
        printf("\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter your new entry:\n");
            fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
            entries[num_entries].timestamp = time(NULL);
            num_entries++;
            if (num_entries >= MAX_ENTRIES) {
                printf("Warning: diary is full.\n");
            }
            break;

        case 2:
            printf("\nPrevious entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s\n", ctime(&entries[i].timestamp));
                printf("%s", entries[i].text);
            }
            break;

        case 3:
            fclose(diary_file);
            diary_file = fopen(filename, "w");
            if (diary_file == NULL) {
                printf("Error: could not open file.\n");
                exit(1);
            }
            for (int i = 0; i < num_entries; i++) {
                fprintf(diary_file, "%s\n", entries[i].text);
            }
            fclose(diary_file);
            printf("Diary saved successfully.\n");
            exit(0);

        case 4:
            fclose(diary_file);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}