//FormAI DATASET v1.0 Category: Digital Diary ; Style: irregular
// Unique C Digital Diary Program
// Created by Chatbot
// Date: 01/01/2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Declare variables
    char filename[128], entry[256], response;
    time_t now;
    struct tm *current_time;
    FILE *fp;

    // Get current time
    time(&now);
    current_time = localtime(&now);

    printf("Welcome to your digital diary!\n");
    printf("Please enter a filename for your diary: ");
    scanf("%s", filename);

    // Check if file exists
    fp = fopen(filename, "r");
    if (fp != NULL) {
        printf("A file with that name already exists!\n");
        fclose(fp);
        return 0;
    }

    // Create file and write header
    fp = fopen(filename, "w");
    fprintf(fp, "Digital Diary\n");
    fprintf(fp, "%02d/%02d/%04d\n", current_time->tm_mon + 1, current_time->tm_mday, current_time->tm_year + 1900);

    // Ask user for entries
    do {
        printf("Please enter an entry for your diary: ");
        scanf(" %[^\n]", entry);
        fprintf(fp, "%s\n", entry);
        printf("Do you want to add another entry? (y/n): ");
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');

    // Close file and print confirmation message
    fclose(fp);
    printf("Your diary has been saved!\n");

    return 0;
}