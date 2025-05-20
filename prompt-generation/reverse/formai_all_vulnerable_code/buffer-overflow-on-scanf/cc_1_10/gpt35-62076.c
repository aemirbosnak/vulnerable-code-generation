//FormAI DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

struct diary_entry{
    char date[20];
    char* content;
}entries[MAX_ENTRIES];

int num_entries=0;

void add_entry(){
    if(num_entries == MAX_ENTRIES){
        printf("Sorry, the diary is full!");
        return;
    }
    char date[20];
    printf("Enter Date (dd-mm-yyyy): ");
    scanf("%s", date);
    
    for(int i=0;i<num_entries;i++){
        if(strcmp(date, entries[i].date) == 0){
            printf("Entry for this date already exists. Do you want to overwrite it? (Y/N)");
            char response;
            scanf(" %c", &response);
            if(response == 'Y'){
                free(entries[i].content);
                printf("Enter Content:\n");
                char content[500];
                scanf(" %[^\n]s", content);
                entries[i].content = (char*)malloc(strlen(content)+1);
                strcpy(entries[i].content, content);
                printf("Entry successfully overwritten!");
            }
            else{
                printf("Entry not added.");
            }
            return;
        }
    }
    printf("Enter Content:\n");
    char content[500];
    scanf(" %[^\n]s", content);
    strcpy(entries[num_entries].date, date);
    entries[num_entries].content = (char*)malloc(strlen(content)+1);
    strcpy(entries[num_entries].content, content);
    num_entries++;
    printf("Entry added successfully!");
}

void view_entry(){
    char date[20];
    printf("Enter Date (dd-mm-yyyy): ");
    scanf("%s", date);
    int found=0;
    for(int i=0;i<num_entries;i++){
        if(strcmp(date, entries[i].date) == 0){
            printf("Entry found for %s\nContent:\n%s", date, entries[i].content);
            found=1;
        }
    }
    if(!found){
        printf("No entry found for %s", date);
    }
}

void menu(){
    printf("\n\nDIARY MENU\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Exit\n");
}

int main(){
    int choice;
    do{
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: add_entry(); break;
            case 2: view_entry(); break;
            case 3: exit(0);
            default: printf("Invalid Choice");
        }
    }while(1);
    return 0;
}