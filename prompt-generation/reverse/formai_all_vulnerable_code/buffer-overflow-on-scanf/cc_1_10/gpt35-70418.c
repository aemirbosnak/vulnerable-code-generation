//FormAI DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ENTRY_SIZE 1000
#define MAX_ENTRIES 50

// Declare global variables
char* diary[MAX_ENTRIES];
int entry_count = 0;

int check_for_trigger_words(char* entry) {
    // Define paranoid trigger words
    char trigger_words[5][15] = {"hack", "spy", "blackmail", "conspiracy", "sabotage"};
    
    for (int i=0; i<5; i++) {
        if (strstr(entry, trigger_words[i]) != NULL) {
            return 1; // Trigger word found
        }
    }
    return 0; // No trigger words found
}

void write_to_diary(char* entry) {
    // Check for trigger words
    if (check_for_trigger_words(entry)) {
        printf("\nWARNING: Your entry contains paranoid trigger words.\n");
        printf("Please reconsider before continuing.\n\n");
        return;
    }
    
    // Limit the diary to maximum 50 entries
    if (entry_count == MAX_ENTRIES) {
        printf("\nDIARY FULL: Maximum entries reached. Please delete existing entries to continue writing.\n\n");
        return;
    }
    
    // Allocate memory for the entry
    diary[entry_count] = (char*) malloc(MAX_ENTRY_SIZE * sizeof(char));
    
    // Copy the entry to the diary
    strcpy(diary[entry_count], entry);
    
    entry_count++;
    printf("\nENTRY ADDED: Your entry has been successfully added to the diary.\n\n");
    return;
}

void print_diary() {
    if (entry_count == 0) {
        printf("\nDIARY EMPTY: No entries found in the diary.\n\n");
        return;
    }
    
    printf("\nDIARY ENTRIES:\n");
    
    for (int i=0; i<entry_count; i++) {
        printf("%d: %s\n", i+1, diary[i]);
    }
    
    printf("\n");
    return;
}

void delete_entry(int entry_number) {
    if (entry_number <= 0 || entry_number > entry_count) {
        printf("\nINVALID INPUT: Entry number out of bounds.\n\n");
        return;
    }
    
    // Free the memory allocated for the entry
    free(diary[entry_number-1]);
    
    // Shift the entries to fill the empty space
    for (int i=entry_number-1; i<entry_count-1; i++) {
        diary[i] = diary[i+1];
    }
    
    entry_count--;
    printf("\nENTRY DELETED: Your entry has been successfully deleted from the diary.\n\n");
    return;
}

int main() {
    int option;
    char entry[MAX_ENTRY_SIZE];
    
    printf("WELCOME TO YOUR DIGITAL DIARY\n\n");
    
    while(1) {
        printf("Menu Options:\n");
        printf("1. Write new entry\n");
        printf("2. View diary entries\n");
        printf("3. Delete entry\n");
        printf("4. Quit\n\n");
        printf("Please enter your choice (1/2/3/4): ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\nWRITE NEW ENTRY: Please enter your entry below.\n");
                printf("Note: This app is designed to detect and warn you of paranoid trigger words.\n\n");
                getchar(); // Clearing input buffer 
                fgets(entry, MAX_ENTRY_SIZE, stdin);
                write_to_diary(entry);
                break;
            case 2:
                print_diary();
                break;
            case 3:
                printf("\nDELETE ENTRY: Please enter the number of the entry you want to delete.\n");
                printf("Note: Entry numbers start from 1.\n\n");
                scanf("%d", &option);
                delete_entry(option);
                break;
            case 4:
                printf("\nQUITTING DIARY: Thank you for trusting us with your thoughts.\n\n");
                exit(0);
            default:
                printf("\nINVALID CHOICE: Please select a valid option.\n\n");
                break;
        }
    }
    return 0;
}