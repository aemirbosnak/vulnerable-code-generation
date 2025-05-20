//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary_file = NULL;
    struct entry entries[MAX_ENTRIES] = {{0}};
    int num_entries = 0;
    char filename[20];
    time_t current_time;
    int choice;

    srand(time(NULL));
    current_time = time(NULL);

    printf("Welcome to the Digital Diary!\n");
    printf("Enter your name: ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    diary_file = fopen(filename, "a");
    if (diary_file == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }

    while (1) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Write a new entry\n");
        printf("2. Read an entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Maximum number of entries reached.\n");
            } else {
                printf("Enter your entry:\n");
                fflush(stdin);
                fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
                entries[num_entries].timestamp = current_time;
                num_entries++;
                fprintf(diary_file, "%s\n", entries[num_entries - 1].text);
                printf("Entry saved.\n");
            }
            break;

        case 2:
            printf("Select an entry to read:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%d. %s\n", i + 1, ctime(&entries[i].timestamp));
            }
            scanf("%d", &choice);

            if (choice >= 1 && choice <= num_entries) {
                printf("\n%s\n", entries[choice - 1].text);
            } else {
                printf("Invalid choice.\n");
            }
            break;

        case 3:
            printf("Goodbye!\n");
            fclose(diary_file);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}