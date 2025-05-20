//FormAI DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 10                       // maximum number of diary entries
#define ENTRY_LENGTH 1024                    // maximum length of each entry

struct Entry {                               
    char date[20];                           // date of the entry
    char content[ENTRY_LENGTH];              // content of the entry
};

int main() {
    struct Entry diary[MAX_ENTRIES];         // initialize an array of diary entries
    int num_entries = 0;                     // initialize number of entries as 0
    int choice = 0;                          // initialize choice as 0
    
    printf("Welcome to your Digital Diary!\n");
    
    while (1) {                              // keep looping until exit is chosen
        printf("\nMenu:\n");
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Delete an entry\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);                 // take user input choice
        
        switch (choice) {
            case 1:
                if (num_entries == MAX_ENTRIES) {  // check if max limit is reached
                    printf("Maximum limit of entries reached!\n");
                    break;
                }
                // add new entry with date and content
                printf("Enter today's date (DD/MM/YYYY): ");
                scanf("%s", diary[num_entries].date);
                printf("Enter your content: ");
                getchar();
                fgets(diary[num_entries].content, ENTRY_LENGTH, stdin);
                num_entries++;                        // increment number of entries
                printf("\nEntry added successfully!\n");
                break;
            
            case 2:
                if (num_entries == 0) {           // check if there are no entries
                    printf("No entries found!\n");
                    break;
                } 
                // print all entries with date and content
                printf("\nAll Entries:\n");
                for (int i = 0; i < num_entries; i++) {
                    printf("Entry %d: Date: %s\nContent: %s", i+1, diary[i].date, diary[i].content);
                }
                break;
            
            case 3:
                if (num_entries == 0) {           // check if there are no entries
                    printf("No entries found!\n");
                    break;
                }
                // delete specified entry by shifting all entries after it one position to the left
                int entry_num;
                printf("Enter the entry number to delete: ");
                scanf("%d", &entry_num);
                if (entry_num > num_entries || entry_num <= 0) {  // check if entry exists
                    printf("Invalid entry number!\n");
                    break;
                }
                entry_num--;                      // adjust index for array
                for (int i = entry_num; i < num_entries - 1; i++) {
                    memcpy(&diary[i], &diary[i+1], sizeof(struct Entry));
                }
                num_entries--;                       // decrement number of entries
                printf("\nEntry deleted successfully!\n");
                break;
            
            case 4:
                printf("\nExiting the Digital Diary. Goodbye!\n");
                exit(0);                             // exit the program
                
            default:
                printf("\nInvalid option selected! Please try again.\n");
        }
    }
    return 0;
}