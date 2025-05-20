//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: immersive
// Immersive Digital Diary Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to represent a diary entry
struct diary_entry {
    char date[11];
    char time[9];
    char title[50];
    char content[100];
};

// Function to add a new diary entry
void add_diary_entry(struct diary_entry* entry) {
    // Prompt user for date and time
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entry->date);
    printf("Enter time (HH:MM): ");
    scanf("%s", entry->time);

    // Prompt user for title and content
    printf("Enter title: ");
    scanf("%s", entry->title);
    printf("Enter content: ");
    scanf("%s", entry->content);
}

// Function to display a diary entry
void display_diary_entry(struct diary_entry* entry) {
    // Print date and time
    printf("[%s, %s] ", entry->date, entry->time);

    // Print title and content
    printf("%s\n%s\n", entry->title, entry->content);
}

// Function to search for a diary entry by title
void search_diary_entry_by_title(struct diary_entry* entry, char* title) {
    // Loop through all diary entries
    for (int i = 0; i < sizeof(entry) / sizeof(entry[0]); i++) {
        // Check if title matches
        if (strcmp(entry[i].title, title) == 0) {
            // Print the matching diary entry
            display_diary_entry(&entry[i]);
            break;
        }
    }
}

// Function to search for a diary entry by content
void search_diary_entry_by_content(struct diary_entry* entry, char* content) {
    // Loop through all diary entries
    for (int i = 0; i < sizeof(entry) / sizeof(entry[0]); i++) {
        // Check if content matches
        if (strstr(entry[i].content, content) != NULL) {
            // Print the matching diary entry
            display_diary_entry(&entry[i]);
            break;
        }
    }
}

// Main function
int main() {
    // Declare an array of diary entries
    struct diary_entry diary[10];

    // Loop through the array
    for (int i = 0; i < sizeof(diary) / sizeof(diary[0]); i++) {
        // Add a new diary entry
        add_diary_entry(&diary[i]);
    }

    // Search for a diary entry by title
    search_diary_entry_by_title(diary, "My Birthday");

    // Search for a diary entry by content
    search_diary_entry_by_content(diary, "I had a great day");

    return 0;
}