//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: synchronous
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
    FILE *diary_file;
    char filename[20]; // "dd-mm-yyyy.txt"
    time_t now;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    do {
        printf("Digital Diary\n");
        printf("1. Create new entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the date (dd-mm-yyyy): ");
            scanf("%s", filename);

            diary_file = fopen(filename, "a");
            if (diary_file == NULL) {
                printf("Error opening file.\n");
                break;
            }

            printf("Enter your entry:\n");
            fgets(entries[num_entries].text, MAX_ENTRY_LENGTH, stdin);
            entries[num_entries].timestamp = time(NULL);
            num_entries++;

            fclose(diary_file);
            printf("Entry saved successfully.\n");
            break;

        case 2:
            printf("Loading entries...\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
            }
            break;

        case 3:
            printf("Enter the keyword to search: ");
            char keyword[MAX_ENTRY_LENGTH];
            scanf("%s", keyword);

            for (int i = 0; i < num_entries; i++) {
                if (strstr(entries[i].text, keyword)!= NULL) {
                    printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
                }
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}