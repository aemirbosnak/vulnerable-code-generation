//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include<stdio.h>
#include<string.h>

/*Defining the maximum limit of the digital diary*/
#define MAX_ENTRIES 100

/*A structure defining the format of the diary entry*/
struct diary_entry {
    char date[11];
    char title[100];
    char content[1000];
};

/*Function to add an entry to the digital diary*/
void add_entry(struct diary_entry diary[], int *entry_count) {
    /*Checking if the maximum limit of entries has been reached or not*/
    if(*entry_count == MAX_ENTRIES) {
        printf("Digital Diary is full. Delete some entries to add new entries.\n");
        return;
    }

    struct diary_entry entry;
    printf("Enter the date of the entry in dd-mm-yyyy format: ");
    scanf("%s", entry.date);
    printf("Enter the title of the entry: ");
    getchar();
    fgets(entry.title, 100, stdin);
    printf("Enter the content of the entry: ");
    fgets(entry.content, 1000, stdin);
    /*Adding the entry to the digital diary*/
    diary[*entry_count] = entry;
    *entry_count += 1;
    printf("Your entry has been added.\n");
}

/*Function to view all the entries in the digital diary*/
void view_entries(struct diary_entry diary[], int entry_count) {
    /*Checking if any entries exist in the diary or not*/
    if(entry_count == 0) {
        printf("No entries to display.\n");
        return;
    }
    int i;
    printf("All entries in Digital Diary:\n");
    for(i=0; i<entry_count; i++) {
        printf("Date: %s\nTitle: %sContent: %s\n", diary[i].date, diary[i].title, diary[i].content);
    }
}

/*Function to search for a particular entry based on date*/
void search_entry(struct diary_entry diary[], int entry_count) {
    if(entry_count == 0) {
        printf("No entries to search for.\n");
        return;
    }
    char search_date[11];
    printf("Enter the date to search in dd-mm-yyyy format: ");
    scanf("%s", search_date);
    int i, found=0;
    for(i=0; i<entry_count; i++) {
        if(strcmp(diary[i].date, search_date) == 0) {
            printf("Entry Found:\nDate: %s\nTitle: %sContent: %s\n", diary[i].date, diary[i].title, diary[i].content);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("No entries found for the given date.\n");
    }
}

/*Function to delete an entry from the digital diary based on date*/
void delete_entry(struct diary_entry diary[], int *entry_count) {
    if(*entry_count == 0) {
        printf("No entries to delete.\n");
        return;
    }
    char delete_date[11];
    printf("Enter the date to delete in dd-mm-yyyy format: ");
    scanf("%s", delete_date);
    int i, found=0;
    for(i=0; i<*entry_count; i++) {
        if(strcmp(diary[i].date, delete_date) == 0) {
            /*Deleting the entry by shifting all the entries after it one position up*/
            for(int j=i; j<*entry_count-1; j++) {
                diary[j] = diary[j+1];
            }
            *entry_count -= 1;
            found = 1;
            printf("Entry deleted.\n");
            break;
        }
    }
    if(!found) {
        printf("No entries found for the given date.\n");
    }
}

int main() {
    int option, entry_count=0;
    struct diary_entry diary[MAX_ENTRIES];
    printf("Welcome to Digital Diary!\n");

    while(1) {
        printf("\nPlease select an option:\n1. Add an Entry\n2. View All Entries\n3. Search for an Entry\n4. Delete an Entry\n5. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_entry(diary, &entry_count);
                break;

            case 2:
                view_entries(diary, entry_count);
                break;

            case 3:
                search_entry(diary, entry_count);
                break;

            case 4:
                delete_entry(diary, &entry_count);
                break;

            case 5:
                printf("Thank you for using Digital Diary!\n");
                return 0;

            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }
    return 0;
}