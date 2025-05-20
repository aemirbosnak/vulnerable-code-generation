//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: random
// Example of a unique C Digital Diary program in a random style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store diary entries
typedef struct {
    char title[50];
    char content[100];
    time_t timestamp;
} DiaryEntry;

// Function to add a new diary entry
void addEntry(DiaryEntry* diary) {
    printf("Enter a title for your entry: ");
    fgets(diary->title, 50, stdin);
    printf("Enter the content of your entry: ");
    fgets(diary->content, 100, stdin);
    diary->timestamp = time(NULL);
}

// Function to print all diary entries
void printEntries(DiaryEntry* diary, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("%s\n%s\n", diary[i].title, diary[i].content);
        printf("Added on: %s", ctime(&diary[i].timestamp));
    }
}

int main() {
    DiaryEntry diary[10];
    int numEntries = 0;
    char choice;
    do {
        printf("1. Add a new entry\n");
        printf("2. Print all entries\n");
        printf("3. Quit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                addEntry(&diary[numEntries++]);
                break;
            case '2':
                printEntries(diary, numEntries);
                break;
            case '3':
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != '3');
    return 0;
}