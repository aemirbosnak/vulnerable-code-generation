//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

struct entry {
    time_t timestamp;
    char message[256];
};

int main() {
    FILE *diary;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;
    char filename[32];
    time_t now;

    printf("Welcome to your digital diary!\n");
    printf("Please enter a name for your diary (up to 31 characters): ");
    scanf("%31s", filename);

    diary = fopen(filename, "r");
    if (diary == NULL) {
        printf("Diary not found. Creating new diary.\n");
        diary = fopen(filename, "w");
        if (diary == NULL) {
            printf("Error creating diary.\n");
            return 1;
        }
        fprintf(diary, "Digital Diary\n");
        fprintf(diary, "--------------------\n");
    } else {
        rewind(diary);
        while (fscanf(diary, "%s", entries[num_entries].message)!= EOF) {
            num_entries++;
        }
        fclose(diary);
        diary = fopen(filename, "a");
        if (diary == NULL) {
            printf("Error opening diary.\n");
            return 1;
        }
    }

    while (1) {
        printf("\n");
        printf("1. Write a new entry\n");
        printf("2. Read previous entries\n");
        printf("3. Save and exit\n");
        printf("4. Exit without saving\n");
        printf("Please enter your choice: ");
        scanf("%d", &now);

        switch (now) {
        case 1:
            printf("Enter your message (up to 255 characters): ");
            fgets(entries[num_entries].message, 256, stdin);
            entries[num_entries].timestamp = time(NULL);
            fprintf(diary, "%s\n", entries[num_entries].message);
            num_entries++;
            break;

        case 2:
            rewind(diary);
            printf("--------------------\n");
            printf("Digital Diary\n");
            printf("--------------------\n");
            for (int i = 0; i < num_entries; i++) {
                fprintf(stdout, "%s\n", entries[i].message);
            }
            break;

        case 3:
            fclose(diary);
            printf("Diary saved.\n");
            return 0;

        case 4:
            fclose(diary);
            printf("Diary not saved.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}