//FormAI DATASET v1.0 Category: Digital Diary ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ENTRIES 1000
#define MAX_STRING_LENGTH 50

typedef struct {
    char date[20];
    char entry[MAX_STRING_LENGTH];
} DiaryEntry;

void add_entry(DiaryEntry* diary, int* count);
void view_entries(DiaryEntry* diary, int count);
void search_entries(DiaryEntry* diary, int count);

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int count = 0;
    int choice;

    while(1) {
        printf("1. Add new entry\n2. View entries\n3. Search entries\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_entry(diary, &count);
                    break;
            case 2: view_entries(diary, count);
                    break;
            case 3: search_entries(diary, count);
                    break;
            case 4: printf("Thanks for using Digital Diary. Goodbye!\n");
                    exit(0);
            default: printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
}

void add_entry(DiaryEntry* diary, int* count) {
    if(*count == MAX_ENTRIES) {
        printf("Digital Diary is full. No more entries can be added.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm* time_ptr = localtime(&t);

    char temp_date[20];
    sprintf(temp_date, "%d/%d/%d", time_ptr->tm_mday, time_ptr->tm_mon+1, time_ptr->tm_year+1900);

    DiaryEntry entry;
    strcpy(entry.date, temp_date);

    printf("Enter your diary entry: ");
    getchar();
    fgets(entry.entry, MAX_STRING_LENGTH, stdin);

    diary[*count] = entry;
    (*count)++;

    printf("Diary entry added successfully!\n");
}

void view_entries(DiaryEntry* diary, int count) {
    if(count == 0) {
        printf("Digital Diary is empty. No entries to show.\n");
        return;
    }

    printf("Date       | Entry\n");
    printf("--------------------\n");

    for(int i=0; i<count; i++) {
        printf("%-10s | %s", diary[i].date, diary[i].entry);
    }
}

void search_entries(DiaryEntry* diary, int count) {
    if(count == 0) {
        printf("Digital Diary is empty. No entries to search.\n");
        return;
    }

    char search_string[MAX_STRING_LENGTH];
    printf("Enter the search string: ");
    getchar();
    fgets(search_string, MAX_STRING_LENGTH, stdin);

    printf("Date       | Entry\n");
    printf("--------------------\n");

    for(int i=0; i<count; i++) {
        if(strstr(diary[i].entry, search_string) != NULL) {
            printf("%-10s | %s", diary[i].date, diary[i].entry);
        }
    }
}