//FormAI DATASET v1.0 Category: Digital Diary ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_TITLE_LEN 50
#define MAX_BODY_LEN 500

// Structure for storing Diary Entry information
typedef struct {
    char title[MAX_TITLE_LEN];
    char body[MAX_BODY_LEN];
    time_t created_time;
} DiaryEntry;

// Function to get current time in string format such as "2022-05-25 16:30:59"
char* current_time_string() {
    time_t current_time = time(NULL);
    char* time_string = ctime(&current_time);
    time_string[strlen(time_string)-1] = '\0'; // Remove newline character
    return time_string;
}

// Function to print a single diary entry
void print_entry(int index, DiaryEntry entry) {
    printf("\n---- Entry #%d, created at %s ----\n", index, current_time_string());
    printf("Title: %s\n", entry.title);
    printf("Body: %s\n", entry.body);
}

// Function to print all diary entries
void print_entries(DiaryEntry* diary, int num_entries) {
    int i;
    for (i=0; i<num_entries; i++) {
        print_entry(i+1, diary[i]);
    }
}

int main(void)
{
    // Initialize empty diary array
    DiaryEntry diary[MAX_ENTRIES];
    int num_entries = 0;

    char option = '0';
    while (option != '3') {
        // Print menu options
        printf("\n---- Digital Diary ----\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                // Add diary entry
                if (num_entries < MAX_ENTRIES) {
                    // Get user input for title and body
                    char title[MAX_TITLE_LEN];
                    char body[MAX_BODY_LEN];
                    printf("\nEnter title (max %d characters): ", MAX_TITLE_LEN-1);
                    scanf(" %[^\n]%*c", title);
                    printf("Enter body (max %d characters): ", MAX_BODY_LEN-1);
                    scanf(" %[^\n]%*c", body);
                    
                    // Create new diary entry and add to diary array
                    DiaryEntry new_entry;
                    strcpy(new_entry.title, title);
                    strcpy(new_entry.body, body);
                    new_entry.created_time = time(NULL);
                    diary[num_entries++] = new_entry;
                    
                    printf("\nEntry added!\n");
                } else {
                    printf("\nDiary is full.\n");
                }
                break;
            case '2':
                // View all diary entries
                if (num_entries == 0) {
                    printf("\nNo entries found.\n");
                } else {
                    print_entries(diary, num_entries);
                }
                break;
            case '3':
                // Exit the program
                printf("\nGoodbye!\n");
                break;
            default:
                // Invalid option
                printf("\nInvalid option. Please choose again.\n");
        }
    }

    return 0;
}