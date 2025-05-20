//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    time_t timestamp;
    char text[1000];
};

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;
    char text[1000];
    time_t now;

    diary = fopen(filename, "a+");
    if (diary == NULL) {
        printf("Error opening diary file.\n");
        return 1;
    }

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Write an entry\n");
        printf("2. Read entries\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your text:\n");
                fgets(text, sizeof(text), stdin);
                time(&now);
                entries[num_entries].timestamp = now;
                strcpy(entries[num_entries].text, text);
                num_entries++;
                if (num_entries >= MAX_ENTRIES) {
                    printf("Diary is full. Please delete some entries.\n");
                } else {
                    printf("Entry saved.\n");
                }
                break;
            case 2:
                if (num_entries == 0) {
                    printf("Diary is empty.\n");
                } else {
                    printf("\nDiary Entries:\n");
                    for (int i = 0; i < num_entries; i++) {
                        printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
                    }
                }
                break;
            case 3:
                rewind(diary);
                for (int i = 0; i < num_entries; i++) {
                    fprintf(diary, "%s - %s\n", ctime(&entries[i].timestamp), entries[i].text);
                }
                fclose(diary);
                printf("Diary saved and exited.\n");
                return 0;
            case 4:
                printf("Diary exited without saving.\n");
                fclose(diary);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}