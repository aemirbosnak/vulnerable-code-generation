//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: excited
// Embrace the digital era with your very own digital diary!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Customize your diary with your own unique name!
#define DIARY_NAME "My Digital Masterpiece"

// Let's have some fun with colors!
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

// The heart of your diary – the entries!
typedef struct {
    char *date;
    char *entry;
} DiaryEntry;

// An array to hold all your precious entries
DiaryEntry entries[100];

// The grand entrance to your digital diary – the welcome screen
void welcome() {
    printf(YELLOW "**~*~ Welcome to %s ~*~**\n" RESET, DIARY_NAME);
    printf(GREEN "Your digital companion for capturing life's precious moments\n" RESET);
    printf("\n");
}

// Add a new entry to your diary – let the words flow!
void addEntry() {
    char date[20];
    char entry[1000];

    printf(MAGENTA "Enter the date (e.g., 2023-03-08): " RESET);
    scanf("%s", date);

    printf(CYAN "Pour your heart out, write your entry here: \n" RESET);
    scanf("\n%[^\n]", entry); // Capture everything until the user presses enter

    DiaryEntry newEntry = { .date = strdup(date), .entry = strdup(entry) };

    entries[0] = newEntry; // Let's keep it simple and store the latest entry first
}

// Display all the entries you've lovingly penned down
void displayEntries() {
    if (entries[0].date == NULL) {
        printf(RED "Your diary is still empty, write something to fill it up!\n" RESET);
        return;
    }

    for (int i = 0; entries[i].date != NULL; i++) {
        printf("%sEntry %d%s\n", BLUE, i + 1, RESET);
        printf("Date: %s\n", entries[i].date);
        printf("Entry: %s\n", entries[i].entry);
        printf("\n");
    }
}

int main() {
    // Let the digital diary adventure begin!
    welcome();

    int choice = 0;
    while (choice != 3) {
        printf(GREEN "\nChoose an option:\n" RESET);
        printf("1. Add a new entry\n");
        printf("2. Display all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                displayEntries();
                break;
            case 3:
                printf(YELLOW "Thank you for trusting me with your memories! Until next time!~" RESET);
                break;
            default:
                printf(RED "Invalid choice, try again!\n" RESET);
        }
    }

    return 0;
}