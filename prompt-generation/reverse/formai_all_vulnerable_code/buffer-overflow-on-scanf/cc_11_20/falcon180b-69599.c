//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 200

struct entry {
    time_t timestamp;
    char text[ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char choice;

    diary = fopen(filename, "r");
    if (diary == NULL) {
        printf("No diary found. Creating a new one.\n");
        fclose(diary);
        diary = fopen(filename, "w");
        if (diary == NULL) {
            printf("Error creating diary.\n");
            return 1;
        }
        fprintf(diary, "Welcome to your digital diary!\n\n");
        fclose(diary);
    } else {
        fclose(diary);
    }

    while (1) {
        printf("Select an option:\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Save and exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter your entry:\n");
                fgets(entries[num_entries].text, ENTRY_LENGTH, stdin);
                entries[num_entries].timestamp = time(NULL);
                num_entries++;
                break;
            case '2':
                if (num_entries == 0) {
                    printf("No entries found.\n");
                } else {
                    printf("Previous entries:\n");
                    for (int i = 0; i < num_entries; i++) {
                        printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
                    }
                }
                break;
            case '3':
                diary = fopen(filename, "w");
                if (diary == NULL) {
                    printf("Error saving diary.\n");
                    return 1;
                }
                for (int i = 0; i < num_entries; i++) {
                    fprintf(diary, "%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
                }
                fprintf(diary, "\nGoodbye, dear diary.\n");
                fclose(diary);
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}