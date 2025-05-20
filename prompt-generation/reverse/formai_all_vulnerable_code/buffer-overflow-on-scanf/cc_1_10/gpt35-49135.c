//FormAI DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_CHARS 500

//Function declarations
void display_menu();
void add_entry(char diary[MAX_ENTRIES][MAX_CHARS], int *num_entries);
void view_entries(char diary[MAX_ENTRIES][MAX_CHARS], int num_entries);
void search_entries(char diary[MAX_ENTRIES][MAX_CHARS], int num_entries);

int main()
{
    char diary[MAX_ENTRIES][MAX_CHARS];
    int num_entries = 0;
    char choice;

    printf("Welcome to your Digital Diary!\n");

    do{
        display_menu();

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch(choice){
            case '1': add_entry(diary, &num_entries);
                      break;
            case '2': view_entries(diary, num_entries);
                      break;
            case '3': search_entries(diary, num_entries);
                      break;
            case '4': printf("Goodbye!\n");
                      break;
            default: printf("Invalid choice. Please try again.\n");
                     break;
        }
    }while(choice != '4');

    return 0;
}

void display_menu(){
    printf("\n1. Add entry\n");
    printf("2. View entries\n");
    printf("3. Search entries\n");
    printf("4. Exit\n");
}

void add_entry(char diary[MAX_ENTRIES][MAX_CHARS], int *num_entries){
    if(*num_entries == MAX_ENTRIES){
        printf("Diary is full. You cannot add any more entries.\n");
        return;
    }

    printf("\nEnter your entry (max %d characters): ", MAX_CHARS);
    scanf(" %[^\n]s", diary[*num_entries]);
    (*num_entries)++;
    printf("Entry added successfully!\n");
}

void view_entries(char diary[MAX_ENTRIES][MAX_CHARS], int num_entries){
    if(num_entries == 0){
        printf("There are no entries to display.\n");
        return;
    }

    printf("\n");
    for(int i=0; i<num_entries; i++){
        printf("%d. %s\n", i+1, diary[i]);
    }
}

void search_entries(char diary[MAX_ENTRIES][MAX_CHARS], int num_entries){
    if(num_entries == 0){
        printf("There are no entries to search.\n");
        return;
    }

    char search_term[MAX_CHARS];
    int counter = 0;

    printf("\nEnter the search term: ");
    scanf(" %[^\n]s", search_term);

    printf("\n");

    for(int i=0; i<num_entries; i++){
        if(strstr(diary[i], search_term) != NULL){
            printf("%d. %s\n", i+1, diary[i]);
            counter++;
        }
    }

    if(counter == 0){
        printf("No match found.\n");
    }
}