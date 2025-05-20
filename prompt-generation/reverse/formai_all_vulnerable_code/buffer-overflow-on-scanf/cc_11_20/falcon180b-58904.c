//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    time_t timestamp;
    char content[1000];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    char filename[100];

    printf("Welcome to the Digital Diary of Romeo and Juliet!\n");
    printf("Please enter a filename for your diary (without extension): ");
    scanf("%s", filename);
    strcat(filename, ".txt");

    diary = fopen(filename, "a");
    if (diary == NULL) {
        printf("Error: could not open diary file.\n");
        exit(1);
    }

    while (1) {
        printf("\n");
        printf("1. Write a diary entry\n");
        printf("2. Read a diary entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Diary is full.\n");
            } else {
                printf("Enter your diary entry:\n");
                fgets(entries[num_entries].content, 1000, stdin);
                entries[num_entries].timestamp = time(NULL);
                num_entries++;
                fprintf(diary, "%s - %s\n", ctime(&entries[num_entries - 1].timestamp), entries[num_entries - 1].content);
                printf("Entry saved.\n");
            }
            break;

        case 2:
            if (num_entries == 0) {
                printf("Diary is empty.\n");
            } else {
                printf("Choose an entry to read:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("%d. %s\n", i + 1, ctime(&entries[i].timestamp));
                }
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice >= 1 && choice <= num_entries) {
                    printf("%s\n", entries[choice - 1].content);
                } else {
                    printf("Invalid choice.\n");
                }
            }
            break;

        case 3:
            printf("Exiting...\n");
            fclose(diary);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}