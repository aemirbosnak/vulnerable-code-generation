//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

struct entry {
    time_t timestamp;
    char text[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary_file;
    char filename[50] = "diary.txt";
    struct entry diary[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    char text[MAX_ENTRY_LENGTH];

    diary_file = fopen(filename, "r");

    if (diary_file == NULL) {
        printf("Diary file not found.\n");
        exit(1);
    }

    while (fscanf(diary_file, "%s %s", &text, &text)!= EOF) {
        strcpy(diary[num_entries].text, text);
        diary[num_entries].timestamp = time(NULL);
        num_entries++;
    }

    fclose(diary_file);

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. View Entries\n");
        printf("2. Add Entry\n");
        printf("3. Search Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            system("clear");
            printf("\nDiary Entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s - %s\n", ctime(&diary[i].timestamp), diary[i].text);
            }
            break;

        case 2:
            printf("\nEnter your entry: ");
            fgets(text, MAX_ENTRY_LENGTH, stdin);
            strcpy(diary[num_entries].text, text);
            diary[num_entries].timestamp = time(NULL);
            num_entries++;
            break;

        case 3:
            printf("\nEnter the keyword to search: ");
            scanf("%s", text);
            for (int i = 0; i < num_entries; i++) {
                if (strstr(diary[i].text, text)!= NULL) {
                    printf("%s - %s\n", ctime(&diary[i].timestamp), diary[i].text);
                }
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}