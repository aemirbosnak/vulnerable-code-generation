//FormAI DATASET v1.0 Category: Digital Diary ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold entry information
struct entry {
    char date[11];
    char time[6];
    char title[50];
    char content[1000];
};

int main() {
    printf("Welcome to Digital Diary!\n");

    // Get current datetime
    time_t current_time = time(NULL);
    struct tm *tm = localtime(&current_time);

    // Set date format
    char date[11];
    sprintf(date, "%.2d/%.2d/%d", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);

    // Set time format
    char time[6];
    sprintf(time, "%.2d:%.2d", tm->tm_hour, tm->tm_min);

    // Initialize diary file
    FILE *diary_file = fopen("diary.txt", "a+");
    if (diary_file == NULL) {
        printf("Error opening diary file!\n");
        return 1;
    }

    // Use a loop to allow the user to enter multiple entries
    char choice = 'y';
    while (choice == 'y') {
        // Get entry information
        struct entry new_entry;
        strcpy(new_entry.date, date);
        strcpy(new_entry.time, time);

        printf("Please enter the title of your entry (maximum 50 characters):\n");
        fgets(new_entry.title, 50, stdin);

        printf("Please enter the content of your entry (maximum 1000 characters):\n");
        fgets(new_entry.content, 1000, stdin);

        // Write entry to diary file
        fprintf(diary_file, "%s %s Title: %sContent: %s\n", new_entry.date, new_entry.time, new_entry.title, new_entry.content);

        printf("Entry added to diary!\n");

        // Ask user if they want to add another entry
        printf("Do you want to add another entry? (y/n)\n");
        scanf("%c", &choice);
        fflush(stdin);
    }

    // Close diary file
    fclose(diary_file);

    return 0;
}