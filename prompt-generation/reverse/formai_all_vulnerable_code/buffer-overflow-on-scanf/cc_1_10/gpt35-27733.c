//FormAI DATASET v1.0 Category: Digital Diary ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Defining structure for diary entry
struct Entry{
    int month, day, year;
    char text[500];
};

//Function to get current date
void get_current_date(int *day, int *month, int *year){
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    *day = local->tm_mday;
    *month = local->tm_mon + 1;
    *year = local->tm_year + 1900;
}

//Function to add an entry to the diary
void add_entry(struct Entry *entries, int *num_entries){
    char confirm;
    printf("\nDo you want to add a new entry? (Y/N)\n");
    scanf(" %c", &confirm);
    if(confirm == 'Y' || confirm == 'y'){
        int day, month, year;
        get_current_date(&day, &month, &year);
        entries[*num_entries].day = day;
        entries[*num_entries].month = month;
        entries[*num_entries].year = year;
        printf("\nEnter your text (Max. 500 characters):\n");
        fflush(stdin);
        fgets(entries[*num_entries].text, 500, stdin);
        (*num_entries)++;
        printf("\nEntry added successfully!\n");
    }
}

//Function to view all diary entries
void view_entries(struct Entry *entries, int num_entries){
    printf("\nDiary Entries:\n");
    for(int i=0; i<num_entries; i++){
        printf("\n%d-%d-%d: %s", entries[i].day, entries[i].month, entries[i].year, entries[i].text);
    }
}

//Function to search for a diary entry
void search_entries(struct Entry *entries, int num_entries){
    char keyword[20];
    printf("\nEnter the keyword to search:\n");
    fflush(stdin);
    scanf("%s", keyword);
    int found = 0;
    for(int i=0; i<num_entries; i++){
        if(strstr(entries[i].text, keyword)){
            printf("\n%d-%d-%d: %s", entries[i].day, entries[i].month, entries[i].year, entries[i].text);
            found = 1;
        }
    }
    if(!found){
        printf("\nNo matching entries found.\n");
    }
}

int main(){
    int choice, num_entries = 0, max_entries;
    printf("Welcome to your Digital Diary!\n");
    printf("\nEnter the maximum number of entries:\n");
    scanf("%d", &max_entries);
    struct Entry *entries = (struct Entry*)malloc(max_entries * sizeof(struct Entry));

    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_entry(entries, &num_entries);
                    break;
            case 2: view_entries(entries, num_entries);
                    break;
            case 3: search_entries(entries, num_entries);
                    break;
            case 4: printf("\nGoodbye!\n");
                    break;
            default: printf("\nInvalid choice. Try again.\n");
        }
    }while(choice != 4);

    free(entries);
    return 0;
}