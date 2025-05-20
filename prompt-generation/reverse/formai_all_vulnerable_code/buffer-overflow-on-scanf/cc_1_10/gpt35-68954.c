//FormAI DATASET v1.0 Category: Digital Diary ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

typedef struct diary_entry {
    char date[15];
    char content[1000];
} DiaryEntry;

void add_entry(DiaryEntry diary[], int* count) {
    printf("Enter the date: ");
    scanf("%s", diary[*count].date);
    printf("Enter the content: ");
    scanf("%s", diary[*count].content);
    (*count)++;
}

void view_entries(DiaryEntry diary[], int count) {
    if(count == 0) {
        printf("No entries found in the diary!\n");
        return;
    }
    printf("Date\tContent\n");
    for(int i = 0; i < count; i++) {
        printf("%s\t%s\n", diary[i].date, diary[i].content);
    }
}

void delete_entry(DiaryEntry diary[], int* count) {
    if((*count) == 0) {
        printf("No entries found in the diary!\n");
        return;
    }
    char del_date[15];
    printf("Enter the date of the entry to be deleted: ");
    scanf("%s", del_date);
    for(int i = 0; i < (*count); i++) {
        if(strcmp(diary[i].date, del_date) == 0) {
            for(int j = i; j < (*count)-1; j++) {
                diary[j] = diary[j+1];
            }
            (*count)--;
            printf("Entry deleted!\n");
            return;
        }
    }
    printf("No entry found on that date!\n");
}

void search_entries(DiaryEntry diary[], int count) {
    printf("Enter the keyword to search: ");
    char keyword[50];
    scanf("%s", keyword);
    int found = 0;
    for(int i = 0; i < count; i++) {
        if(strstr(diary[i].content, keyword) != NULL) {
            printf("%s\t%s\n", diary[i].date, diary[i].content);
            found = 1;
        }
    }
    if(found == 0) {
        printf("No entry found containing the keyword!\n");
    }
}

int main() {
    DiaryEntry diary[1000];
    int count = 0;
    printf("****************************************************\n");
    printf("************ Welcome to the Digital Diary ************\n");
    printf("****************************************************\n");
    while(1) {
        printf("\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Delete an entry\n");
        printf("4. Search for an entry\n");
        printf("5. Exit the program\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_entry(diary, &count);
                    break;
            case 2: view_entries(diary, count);
                    break;
            case 3: delete_entry(diary, &count);
                    break;
            case 4: search_entries(diary, count);
                    break;
            case 5: printf("Exiting the program...Goodbye!\n");
                    exit(0);
                    break;
            default: printf("Invalid choice! Please enter again.\n");
        }
    }
    return 0;
}