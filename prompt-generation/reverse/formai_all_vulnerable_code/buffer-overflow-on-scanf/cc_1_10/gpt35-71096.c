//FormAI DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100 // maximum number of entries 

// structure to hold diary entry information
typedef struct entry {
    char date[20];
    char title[50];
    char content[1000];
} entry_t;

// function prototypes
void print_menu();
void add_entry(entry_t diary[], int *count);
void view_entry(entry_t diary[], int count);
void search_entry(entry_t diary[], int count);
void save_entries(entry_t diary[], int count);
void load_entries(entry_t diary[], int *count);

int main()
{
    entry_t diary[MAX_ENTRIES]; // array to hold diary entries
    int count = 0; // count of current entries
    int choice; // menu choice

    // load existing entries from file
    load_entries(diary, &count);

    // display menu and get user choice
    do {
        print_menu();
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                add_entry(diary, &count); // add new entry
                break;
            case 2:
                view_entry(diary, count); // view existing entry
                break;
            case 3:
                search_entry(diary, count); // search for entries
                break;
            case 4:
                save_entries(diary, count); // save all entries to file
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

// function to display menu options
void print_menu() {
    printf("1. Add new entry\n");
    printf("2. View existing entry\n");
    printf("3. Search for entry\n");
    printf("4. Save all entries to file\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// function to add new entry
void add_entry(entry_t diary[], int *count) {
    // check if diary is full
    if(*count == MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }

    // get current date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[*count].date, "%02d/%02d/%04d %02d:%02d:%02d",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    // get title and content from user input
    fflush(stdin);
    printf("Enter title (maximum 50 characters): ");
    fgets(diary[*count].title, 50, stdin);
    diary[*count].title[strlen(diary[*count].title) - 1] = '\0'; // remove newline character
    printf("Enter content (maximum 1000 characters): ");
    fgets(diary[*count].content, 1000, stdin);
    diary[*count].content[strlen(diary[*count].content) - 1] = '\0'; // remove newline character

    // increment count of entries
    (*count)++;

    printf("New entry added successfully.\n");
}

// function to view existing entry
void view_entry(entry_t diary[], int count) {
    // check if diary is empty
    if(count == 0) {
        printf("Diary is empty. No entries to view.\n");
        return;
    }

    // get index of entry to view from user input
    int index;
    printf("Enter index of entry to view (between 1 and %d): ", count);
    scanf("%d", &index);
    printf("\n");

    // check if index is valid
    if(index < 1 || index > count) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    // display entry information
    printf("Date: %s\n", diary[index - 1].date);
    printf("Title: %s\n", diary[index - 1].title);
    printf("Content: %s\n", diary[index - 1].content);
}

// function to search for entries
void search_entry(entry_t diary[], int count) {
    // check if diary is empty
    if(count == 0) {
        printf("Diary is empty. No entries to search.\n");
        return;
    }

    // get search term from user input
    char term[50];
    printf("Enter search term: ");
    fflush(stdin);
    fgets(term, 50, stdin);
    term[strlen(term) - 1] = '\0'; // remove newline character

    // search for entries that contain search term
    printf("\nSearch results:\n");
    for(int i = 0; i < count; i++) {
        if(strstr(diary[i].title, term) || strstr(diary[i].content, term)) {
            printf("Index: %d | Date: %s | Title: %s\n", i+1, diary[i].date, diary[i].title);
        }
    }
}

// function to save all entries to file
void save_entries(entry_t diary[], int count) {
    // open file for writing
    FILE *fp;
    fp = fopen("diary.txt", "w");
    if(fp == NULL) {
        printf("Error. Cannot open file.\n");
        return;
    }

    // write all entries to file
    for(int i = 0; i < count; i++) {
        fprintf(fp, "Index: %d | Date: %s | Title: %s | Content: %s\n",
                i+1, diary[i].date, diary[i].title, diary[i].content);
    }

    fclose(fp);

    printf("All entries saved successfully.\n");
}

// function to load existing entries from file
void load_entries(entry_t diary[], int *count) {
    // open file for reading
    FILE *fp;
    fp = fopen("diary.txt", "r");
    if(fp == NULL) {
        printf("No existing entries.\n");
        return;
    }

    char line[1100];

    // read each line and split into entry information
    while(fgets(line, 1100, fp) != NULL && *count < MAX_ENTRIES) {
        char *token = strtok(line, " |");
        int index = atoi(&token[7]); // get index from string

        // get date from string
        token = strtok(NULL, " |");
        strcpy(diary[index-1].date, &token[6]);

        // get title from string
        token = strtok(NULL, " |");
        strcpy(diary[index-1].title, &token[7]);

        // get content from string
        token = strtok(NULL, " |");
        strcpy(diary[index-1].content, &token[10]);

        (*count)++;
    }

    fclose(fp);

    printf("%d existing entries loaded from file.\n\n", *count);
}