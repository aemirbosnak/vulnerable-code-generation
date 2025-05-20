//FormAI DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ENTRIES 100

struct Entry {
    char date[20];
    char title[50];
    char content[500];
};

struct Diary {
    char name[20];
    struct Entry entries[MAX_ENTRIES];
    int count;
};

struct Diary createDiary(char name[20]) {
    struct Diary diary;
    strcpy(diary.name, name);
    diary.count = 0;
    return diary;
}

void addEntry(struct Diary* diary, char date[20], char title[50], char content[500]) {
    struct Entry entry;
    strcpy(entry.date, date);
    strcpy(entry.title, title);
    strcpy(entry.content, content);
    diary->entries[diary->count++] = entry;
}

void printDiaryEntries(struct Diary* diary) {
    for(int i=0; i<diary->count; i++) {
        struct Entry entry = diary->entries[i];
        printf("Date: %s\nTitle: %s\nContent: %s\n", entry.date, entry.title, entry.content);
    }
}

void searchDiaryEntries(struct Diary* diary, char search[20]) {
    for(int i=0; i<diary->count; i++) {
        struct Entry entry = diary->entries[i];
        if(strstr(entry.title, search) != NULL || strstr(entry.content, search) != NULL) {
            printf("Date: %s\nTitle: %s\nContent: %s\n", entry.date, entry.title, entry.content);
        }
    }
}

int main() {
    char diaryName[20];
    printf("Enter name for your diary: ");
    scanf("%s", diaryName);

    struct Diary diary = createDiary(diaryName);

    while(1) {
        printf("\n1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            char date[20], title[50], content[500];
            printf("Enter date (dd/mm/yyyy): ");
            scanf("%s", date);
            printf("Enter title: ");
            fgets(title, 50, stdin);
            printf("Enter content: ");
            fgets(content, 500, stdin);
            addEntry(&diary, date, title, content);
        } else if(choice == 2) {
            if(diary.count == 0) {
                printf("No entries found.\n");
                continue;
            }
            printDiaryEntries(&diary);
        } else if(choice == 3) {
            char search[20];
            printf("Enter search query: ");
            scanf("%s", search);
            searchDiaryEntries(&diary, search);
        } else if(choice == 4) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}