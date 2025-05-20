//FormAI DATASET v1.0 Category: Digital Diary ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ENTRIES 50
#define MAX_LENGTH 100

struct Entry{
    char date[20];
    char time[20];
    char description[MAX_LENGTH];
};

struct Diary{
    struct Entry entries[MAX_ENTRIES];
    int num_entries;
};

void add_entry(struct Diary* diary, char* description){
    if(diary->num_entries == MAX_ENTRIES){
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    struct Entry new_entry;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(new_entry.date, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    sprintf(new_entry.time, "%02d:%02d", tm.tm_hour, tm.tm_min);
    strcpy(new_entry.description, description);

    diary->entries[diary->num_entries++] = new_entry;
    printf("New entry added successfully.\n");
}

void list_entries(struct Diary diary){
    if(diary.num_entries == 0){
        printf("No entries found in diary.\n");
        return;
    }

    printf("Date        Time   Description\n");
    printf("-----------------------------------\n");
    for(int i=0; i<diary.num_entries; i++){
        printf("%s  %s  %s\n", diary.entries[i].date, diary.entries[i].time, diary.entries[i].description);
    }
}

int main(){
    struct Diary my_diary = { {}, 0 };
    while(1){
        printf("\n\n");
        printf("1. Add new entry\n");
        printf("2. List all entries\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        int choice = 0;
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                char description[MAX_LENGTH];
                printf("Enter description: ");
                scanf(" %[^\n]s", description);
                add_entry(&my_diary, description);
                break;
            }
            case 2:{
                list_entries(my_diary);
                break;
            }
            case 3:{
                printf("Exiting program. Goodbye!\n");
                exit(0);
            }
            default:{
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
            }
        }
    }
    return 0;
}