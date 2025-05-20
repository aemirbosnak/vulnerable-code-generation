//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 500

struct entry {
    time_t timestamp;
    char content[MAX_ENTRY_LENGTH];
};

int main() {
    FILE *diary;
    char filename[50] = "diary.txt";
    char ch;
    int count = 0;
    struct entry entries[MAX_ENTRIES];

    diary = fopen(filename, "r");

    if (diary == NULL) {
        printf("Diary file not found. Creating a new one...\n");
        diary = fopen(filename, "w");
        fprintf(diary, "Welcome to your digital diary!\n");
        fclose(diary);
        diary = fopen(filename, "r");
    }

    while ((ch = fgetc(diary))!= EOF) {
        if (ch == '\n') {
            entries[count].content[strcspn(entries[count].content, "\n")] = '\0';
            entries[count].timestamp = time(NULL);
            count++;
        } else {
            strncat(entries[count].content, &ch, 1);
        }
    }

    fclose(diary);

    while (1) {
        system("clear");
        printf("Digital Diary\n");
        printf("--------------------\n");

        for (int i = 0; i < count; i++) {
            printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].content);
        }

        printf("\n");
        printf("1. Write a new entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("--------------------\n");

        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter your new entry:\n");
                fflush(stdin);
                fgets(entries[count].content, MAX_ENTRY_LENGTH, stdin);
                entries[count].timestamp = time(NULL);
                count++;
                break;
            case 2:
                system("clear");
                printf("Digital Diary\n");
                printf("--------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%s - %s\n", ctime(&entries[i].timestamp), entries[i].content);
                }
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                fclose(diary);
                remove(filename);
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}