//FormAI DATASET v1.0 Category: Digital Diary ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Struct for each entry of the diary
struct DiaryEntry{
    int year;
    int month;
    int day;
    char title[50];
    char content[500];
};

typedef struct DiaryEntry DiaryEntry;

int total_entries = 0; //Total number of entries in the diary
DiaryEntry* entries; //Dynamic array of diary entries

//Function to add a new entry to the diary
void add_entry(){
    DiaryEntry new_entry;
    printf("Enter the title: ");
    getchar();
    fgets(new_entry.title, 50, stdin);
    printf("Enter the content: ");
    fgets(new_entry.content, 500, stdin);
    time_t current_time;
    struct tm* time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    new_entry.year = time_info->tm_year + 1900;
    new_entry.month = time_info->tm_mon + 1;
    new_entry.day = time_info->tm_mday;
    total_entries++;
    entries = (DiaryEntry*)realloc(entries, sizeof(DiaryEntry)*total_entries);
    entries[total_entries - 1] = new_entry;
    printf("\nEntry added successfully!\n\n");
}

//Function to view all the entries in the diary
void view_entries(){
    if(total_entries == 0){
        printf("\nNo entries found!\n\n");
        return;
    }
    printf("\nDIARY ENTRIES:\n\n");
    for(int i=0; i<total_entries; i++){
        printf("%d/%02d/%02d %s\n", entries[i].year, entries[i].month, entries[i].day, entries[i].title);
    }
    printf("\nEnter the number of the entry to view its content: ");
    int choice;
    scanf("%d", &choice);
    if(choice<1 || choice>total_entries){
        printf("\nInvalid choice!\n\n");
        return;
    }
    printf("\n%s\n\n", entries[choice-1].content);
}

//Function to search for entries based on the search term
void search_entries(){
    if(total_entries == 0){
        printf("\nNo entries found!\n\n");
        return;
    }
    printf("\nEnter the search term: ");
    char term[50];
    getchar();
    fgets(term, 50, stdin);
    printf("\nSEARCH RESULTS:\n\n");
    for(int i=0; i<total_entries; i++){
        if(strstr(entries[i].title, term) || strstr(entries[i].content, term)){
            printf("%d/%02d/%02d %s\n", entries[i].year, entries[i].month, entries[i].day, entries[i].title);
        }
    }
    printf("\nEnter the number of the entry to view its content: ");
    int choice;
    scanf("%d", &choice);
    if(choice<1 || choice>total_entries){
        printf("\nInvalid choice!\n\n");
        return;
    }
    printf("\n%s\n\n", entries[choice-1].content);
}

//Function to delete an entry from the diary
void delete_entry(){
    if(total_entries == 0){
        printf("\nNo entries found!\n\n");
        return;
    }
    printf("\nEnter the number of the entry to delete: ");
    int choice;
    scanf("%d", &choice);
    if(choice<1 || choice>total_entries){
        printf("\nInvalid choice!\n\n");
        return;
    }
    for(int i=choice-1; i<total_entries-1; i++){
        entries[i] = entries[i+1];
    }
    total_entries--;
    entries = (DiaryEntry*)realloc(entries, sizeof(DiaryEntry)*total_entries);
    printf("\nEntry deleted successfully!\n\n");
}

int main(){
    entries = (DiaryEntry*)malloc(sizeof(DiaryEntry));
    int option;
    do{
        printf("1. Add new entry\n2. View entries\n3. Search entries\n4. Delete entry\n5. Exit\n");
        scanf("%d", &option);
        switch(option){
            case 1: add_entry();
                    break;
            case 2: view_entries();
                    break;
            case 3: search_entries();
                    break;
            case 4: delete_entry();
                    break;
            case 5: break;
            default: printf("\nInvalid option!\n\n");
                     break;
        }
    }while(option!=5);
    free(entries);
    return 0;
}