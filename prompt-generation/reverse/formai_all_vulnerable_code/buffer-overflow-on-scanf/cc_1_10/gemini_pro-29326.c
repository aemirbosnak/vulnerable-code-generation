//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Create a new diary entry
int new_entry(char *title, char *content) {
    // Open the diary file
    FILE *fp = fopen("diary.txt", "a");
    if (fp == NULL) {
        return -1;
    }

    // Get the current time
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    // Write the entry to the file
    fprintf(fp, "%s %s %04d-%02d-%02d %02d:%02d:%02d\n", title, content, tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    // Close the file
    fclose(fp);

    return 0;
}

// List all diary entries
int list_entries() {
    // Open the diary file
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    // Read each line of the file
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Print the line
        printf("%s", line);
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Search for a diary entry
int search_entry(char *query) {
    // Open the diary file
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    // Read each line of the file
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Check if the line contains the query
        if (strstr(line, query)) {
            // Print the line
            printf("%s", line);
        }
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Delete a diary entry
int delete_entry(int entry_number) {
    // Open the diary file
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    // Read each line of the file
    char line[1024];
    int line_number = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Check if the line is the entry to be deleted
        if (line_number == entry_number) {
            // Skip the line
            continue;
        }

        // Write the line to the temporary file
        FILE *tmp = fopen("tmp.txt", "a");
        fprintf(tmp, "%s", line);
        fclose(tmp);

        // Increment the line number
        line_number++;
    }

    // Close the diary file
    fclose(fp);

    // Delete the original diary file
    remove("diary.txt");

    // Rename the temporary file to the diary file
    rename("tmp.txt", "diary.txt");

    return 0;
}

// Main function
int main() {
    // Get the user's input
    char input[1024];
    printf("Enter a command (new, list, search, delete, quit): ");
    scanf("%s", input);

    // Execute the command
    if (strcmp(input, "new") == 0) {
        // Get the title and content of the new entry
        char title[1024];
        char content[1024];
        printf("Enter the title of the new entry: ");
        scanf(" %[^\n]", title);
        printf("Enter the content of the new entry: ");
        scanf(" %[^\n]", content);

        // Create the new entry
        new_entry(title, content);

        // Print a success message
        printf("New entry created.\n");
    } else if (strcmp(input, "list") == 0) {
        // List all diary entries
        list_entries();
    } else if (strcmp(input, "search") == 0) {
        // Get the search query
        char query[1024];
        printf("Enter the search query: ");
        scanf(" %[^\n]", query);

        // Search for the entry
        search_entry(query);
    } else if (strcmp(input, "delete") == 0) {
        // Get the entry number to be deleted
        int entry_number;
        printf("Enter the entry number to be deleted: ");
        scanf("%d", &entry_number);

        // Delete the entry
        delete_entry(entry_number);

        // Print a success message
        printf("Entry deleted.\n");
    } else if (strcmp(input, "quit") == 0) {
        // Quit the program
        return 0;
    } else {
        // Print an error message
        printf("Invalid command.\n");
    }

    // Get the next command
    main();

    return 0;
}