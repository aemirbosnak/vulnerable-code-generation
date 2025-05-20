//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

// Function to add a diary entry
void add_entry(const char *title, const char *content) {
    if (entry_count < MAX_ENTRIES) {
        strncpy(diary[entry_count].title, title, MAX_TITLE_LENGTH);
        strncpy(diary[entry_count].content, content, MAX_CONTENT_LENGTH);
        entry_count++;
        printf("Oh, sweet entry penned with care!\n");
    } else {
        printf("The diary cannot hold more of thy thoughts, Romeo.\n");
    }
}

// Function to display all entries
void display_entries() {
    if (entry_count == 0) {
        printf("The pages of this diary are as bare as Juliet’s heart before thee.\n");
        return;
    }
    
    printf("Entries of the Heart:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("\nEntry %d: %s\n", i + 1, diary[i].title);
        printf("%s\n", diary[i].content);
    }
}

// Function to search entries by title
void search_entry(const char *search_title) {
    int found = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strstr(diary[i].title, search_title) != NULL) {
            printf("\nFound Entry %d: %s\n", i + 1, diary[i].title);
            printf("%s\n", diary[i].content);
            found = 1;
        }
    }
    if (!found) {
        printf("Alas! No entry with the title that tugs at thy heartstrings.\n");
    }
}

// Function to save entries to a file
void save_entries(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("The ink hath run dry, unable to write to the parchment.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "Entry %d: %s\n%s\n\n", i + 1, diary[i].title, diary[i].content);
    }
    fclose(file);
    printf("The hearts' musings hath been inscribed upon the parchment.\n");
}

// Function to load entries from a file
void load_entries(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("The parchment is as empty as my soul without thee, dear Juliet.\n");
        return;
    }

    char line[MAX_TITLE_LENGTH + MAX_CONTENT_LENGTH + 100];
    while (fgets(line, sizeof(line), file) != NULL && entry_count < MAX_ENTRIES) {
        char title[MAX_TITLE_LENGTH];
        char content[MAX_CONTENT_LENGTH];

        sscanf(line, "Entry %*d: %[^\n]\n", title);
        fgets(content, sizeof(content), file);

        add_entry(title, content);
    }
    fclose(file);
    printf("The faded memories have returned like a summer's day.\n");
}

int main() {
    int option;
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    char filename[100];

    printf("Welcome to the Diary of Love, where every entry echoes the hearts' quandaries.\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a diary entry\n");
        printf("2. Display all entries\n");
        printf("3. Search for an entry by title\n");
        printf("4. Save entries to a file\n");
        printf("5. Load entries from a file\n");
        printf("6. Exit\n");
        printf("Thy choice: ");
        
        if (scanf("%d", &option) != 1) {
            printf("Alas! Thou must enter a valid number.\n");
            while(getchar() != '\n'); // Clearing the input buffer
            continue;
        }
        
        getchar(); // To consume the newline character after the number input

        switch (option) {
            case 1:
                printf("Enter the title of thy entry: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character

                printf("Enter the content of thy entry: ");
                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = 0; // Remove newline character

                add_entry(title, content);
                break;
            case 2:
                display_entries();
                break;
            case 3:
                printf("Enter the title to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character

                search_entry(title);
                break;
            case 4:
                printf("Enter filename to save: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character

                save_entries(filename);
                break;
            case 5:
                printf("Enter filename to load from: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character

                load_entries(filename);
                break;
            case 6:
                printf("An exit hath come, but remember, love is eternal.\n");
                exit(0);
            default:
                printf("Such a choice doth vex the heart, choose wisely again!\n");
        }
    }

    return 0;
}