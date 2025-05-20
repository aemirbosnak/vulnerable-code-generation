//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: futuristic
// A unique C Digital Diary example program in a futuristic style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char date[20];
    char content[500];
} DiaryEntry;

void readDiary() {
    DiaryEntry entries[10];
    int numEntries = 0;

    printf("Enter the number of diary entries:\n");
    scanf("%d", &numEntries);

    for (int i = 0; i < numEntries; i++) {
        printf("Entry %d:\n", i + 1);

        printf("Title:\n");
        fgets(entries[i].title, sizeof(entries[i].title), stdin);
        entries[i].title[strcspn(entries[i].title, "\n")] = '\0';

        printf("Date (dd/mm/yyyy):\n");
        fgets(entries[i].date, sizeof(entries[i].date), stdin);
        entries[i].date[strcspn(entries[i].date, "\n")] = '\0';

        printf("Content:\n");
        fgets(entries[i].content, sizeof(entries[i].content), stdin);
        entries[i].content[strcspn(entries[i].content, "\n")] = '\0';

        printf("\n");
    }
}

void writeDiary() {
    DiaryEntry entries[10];
    int numEntries = 0;

    printf("Enter the number of diary entries:\n");
    scanf("%d", &numEntries);

    for (int i = 0; i < numEntries; i++) {
        printf("Entry %d:\n", i + 1);

        printf("Title:\n");
        fgets(entries[i].title, sizeof(entries[i].title), stdin);
        entries[i].title[strcspn(entries[i].title, "\n")] = '\0';

        printf("Date (dd/mm/yyyy):\n");
        fgets(entries[i].date, sizeof(entries[i].date), stdin);
        entries[i].date[strcspn(entries[i].date, "\n")] = '\0';

        printf("Content:\n");
        fgets(entries[i].content, sizeof(entries[i].content), stdin);
        entries[i].content[strcspn(entries[i].content, "\n")] = '\0';

        printf("\n");
    }
}

int main() {
    readDiary();
    writeDiary();
    return 0;
}