//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIARY_ENTRIES 1000

struct DiaryEntry {
    char date[20];
    char time[20];
    char content[1000];
};

int main() {
    srand(time(NULL));

    struct DiaryEntry diary[MAX_DIARY_ENTRIES];
    int num_entries = 0;

    int choice;
    do {
        printf("\nDigital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read a random entry\n");
        printf("3. Read all entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_entries >= MAX_DIARY_ENTRIES) {
                    printf("Diary is full.\n");
                } else {
                    printf("Enter date (DD/MM/YYYY): ");
                    scanf("%s", diary[num_entries].date);
                    printf("Enter time (HH:MM:SS): ");
                    scanf("%s", diary[num_entries].time);
                    printf("Enter content:\n");
                    fgets(diary[num_entries].content, 1000, stdin);
                    num_entries++;
                    printf("Entry saved.\n");
                }
                break;
            case 2:
                if (num_entries == 0) {
                    printf("Diary is empty.\n");
                } else {
                    int index = rand() % num_entries;
                    printf("Entry from %s at %s:\n%s\n", diary[index].date, diary[index].time, diary[index].content);
                }
                break;
            case 3:
                if (num_entries == 0) {
                    printf("Diary is empty.\n");
                } else {
                    for (int i = 0; i < num_entries; i++) {
                        printf("Entry from %s at %s:\n%s\n", diary[i].date, diary[i].time, diary[i].content);
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