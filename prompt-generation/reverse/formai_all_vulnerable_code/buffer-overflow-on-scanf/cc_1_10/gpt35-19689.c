//FormAI DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct diary_entry {
    char date[11];
    char time[6];
    char title[100];
    char content[500];
};

void add_entry(struct diary_entry* diary, int* diary_size) {
    struct diary_entry new_entry;
    time_t raw_time;
    struct tm* current_time;
    
    time(&raw_time);
    current_time = localtime(&raw_time);
    
    strftime(new_entry.date, 11, "%d-%m-%Y", current_time);
    strftime(new_entry.time, 6, "%H:%M", current_time);
    
    printf("Enter title: ");
    fgets(new_entry.title, 100, stdin);
    new_entry.title[strcspn(new_entry.title, "\n")] = 0;
    
    printf("Enter content: ");
    fgets(new_entry.content, 500, stdin);
    new_entry.content[strcspn(new_entry.content, "\n")] = 0;
    
    diary[*diary_size] = new_entry;
    *diary_size += 1;
    
    printf("Entry added!\n");
}

void display_all_entries(struct diary_entry* diary, int diary_size) {
    if (diary_size == 0) {
        printf("No entries found!\n");
        return;
    }
    
    printf("Date        Time    Title\n");
    printf("------------------------\n");
    
    for (int i = 0; i < diary_size; i++) {
        printf("%s %s  %s\n", diary[i].date, diary[i].time, diary[i].title);
    }
}

void display_entry(struct diary_entry* diary, int diary_size) {
    if (diary_size == 0) {
        printf("No entries found!\n");
        return;
    }
    
    char search_key[100];
    printf("Enter title to search: ");
    fgets(search_key, 100, stdin);
    search_key[strcspn(search_key, "\n")] = 0;
    
    for (int i = 0; i < diary_size; i++) {
        if (strcmp(diary[i].title, search_key) == 0) {
            printf("Date: %s\nTime: %s\nTitle: %s\nContent: %s\n", diary[i].date, diary[i].time, diary[i].title, diary[i].content);
            return;
        }
    }
    
    printf("Entry not found!\n");
}

void delete_entry(struct diary_entry* diary, int* diary_size) {
    if (*diary_size == 0) {
        printf("No entries found!\n");
        return;
    }
    
    char search_key[100];
    printf("Enter title to delete: ");
    fgets(search_key, 100, stdin);
    search_key[strcspn(search_key, "\n")] = 0;
    
    int delete_index = -1;
    for (int i = 0; i < *diary_size; i++) {
        if (strcmp(diary[i].title, search_key) == 0) {
            delete_index = i;
            break;
        }
    }
    
    if (delete_index == -1) {
        printf("Entry not found!\n");
        return;
    }
    
    for (int i = delete_index; i < *diary_size - 1; i++) {
        diary[i] = diary[i+1];
    }
    
    *diary_size -= 1;
    
    printf("Entry deleted!\n");
}

int main() {
    struct diary_entry diary[1000];
    int diary_size = 0;
    int option;
    
    printf("Welcome to your digital diary!\n");
    
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Search for entry\n");
        printf("4. Delete entry\n");
        printf("5. Exit\n");
        
        scanf("%d", &option);
        getchar();
        
        switch (option) {
            case 1:
                add_entry(diary, &diary_size);
                break;
            case 2:
                display_all_entries(diary, diary_size);
                break;
            case 3:
                display_entry(diary, diary_size);
                break;
            case 4:
                delete_entry(diary, &diary_size);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    }
    
    return 0;
}