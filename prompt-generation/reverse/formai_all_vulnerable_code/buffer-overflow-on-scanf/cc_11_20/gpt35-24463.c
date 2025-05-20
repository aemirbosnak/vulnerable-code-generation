//FormAI DATASET v1.0 Category: Digital Diary ; Style: genious
#include <stdio.h> 
#define ENTRY_LIMIT 365 // Maximum number of entries in a year

int main() { 
    printf("Welcome to My Digital Diary!\n");

    // Initialize diary entries 
    char entries[ENTRY_LIMIT][100]; 
    int num_entries = 0; 

    while(1) {
        printf("What would you like to do today?\n");
        printf("1. Add an entry\n");
        printf("2. Read all entries\n");
        printf("3. Search for a specific entry\n");
        printf("4. Exit\n");

        int choice; 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 

        if(choice == 1) {
            printf("\nEnter your diary entry (Max 100 characters):\n"); 
            char entry[100]; 
            scanf("%s", entry);

            if(num_entries == ENTRY_LIMIT) {
                printf("\nThe diary is full. You cannot add more entries.\n");
            } else {
                strcpy(entries[num_entries], entry); 
                num_entries++; 
                printf("\nEntry added successfully.\n"); 
            }

        } else if(choice == 2) {
            if(num_entries == 0) {
                printf("\nNo entries found.\n"); 
            } else {
                printf("\nAll entries:\n"); 
                for(int i = 0; i < num_entries; i++) {
                    printf("%d. %s\n", i+1, entries[i]); 
                }
            }

        } else if(choice == 3) {
            printf("\nEnter the search keyword:\n"); 
            char search_key[100]; 
            scanf("%s", search_key); 

            int entry_found = 0; 
            for(int i = 0; i < num_entries; i++) {
                if(strstr(entries[i], search_key)) {
                    entry_found = 1;
                    printf("%d. %s\n", i+1, entries[i]); 
                }
            }
            if(!entry_found) {
                printf("\nNo entries found for the given keyword.\n"); 
            }

        } else if(choice == 4) {
            printf("\nThank you for using My Digital Diary! Goodbye.\n");
            break; 

        } else {
            printf("\nInvalid choice. Please enter a valid choice.\n"); 
        }

    }

    return 0; 
}