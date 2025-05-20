//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define struct to store diary entry
struct diary_entry {
    char date[20];
    char topic[50];
    char text[100];
};

// Define array to store diary entries
struct diary_entry diary[5];

// Function to read and write diary entries
void read_diary() {
    // Open diary file in read-write mode
    FILE *file = fopen("diary.txt", "r+");

    // Check if file exists
    if (!file) {
        printf("Error: Diary file does not exist.\n");
        return;
    }

    // Read diary entries from file
    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s %s %s", diary[i].date, diary[i].topic, diary[i].text);
    }

    // Close file
    fclose(file);
}

// Function to add new diary entry
void add_entry() {
    // Open diary file in write-only mode
    FILE *file = fopen("diary.txt", "a+");

    // Check if file exists
    if (!file) {
        printf("Error: Diary file does not exist.\n");
        return;
    }

    // Get current date and time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    char *current_date =asctime(current_time);

    // Ask user for topic and text
    printf("Enter topic: ");
    fgets(diary[5].topic, 50, stdin);
    printf("Enter text: ");
    fgets(diary[5].text, 100, stdin);

    // Write diary entry to file
    fprintf(file, "%s %s %s\n", current_date, diary[5].topic, diary[5].text);

    // Close file
    fclose(file);
}

int main() {
    // Call read_diary function to read existing diary entries
    read_diary();

    // Print diary entries
    for (int i = 0; i < 5; i++) {
        printf("%d. %s %s\n", i + 1, diary[i].date, diary[i].topic);
    }

    // Call add_entry function to add new diary entry
    add_entry();

    return 0;
}