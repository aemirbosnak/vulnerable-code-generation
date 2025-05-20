//FormAI DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 1024

void print_instructions() {
    printf("Welcome to Digital Diary!\n");
    printf("This program allows you to write and save notes in a text file.\n");
    printf("Commands:\n");
    printf("\t- 'new' to create a new note\n");
    printf("\t- 'read' to read existing notes\n");
    printf("\t- 'exit' to exit the program\n");
}

void create_new_note() {
    char filename[50], title[100], content[MAX_LINES * MAX_LINE_LENGTH];

    getchar(); // Consume previous newline character
    printf("Enter note title: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline character from input

    printf("Enter note content (up to %d lines, press Ctrl+D to stop):\n", MAX_LINES);
    char line[MAX_LINE_LENGTH];
    content[0] = '\0'; // Initialize string with empty string
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        strcat(content, line); // Append line to content string
    }

    // Generate unique filename based on current timestamp
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(filename, "%02d-%02d-%04d_%02d-%02d-%02d.txt", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Write note to file
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }
    fprintf(fp, "%s\n%s", title, content);
    fclose(fp);

    printf("\nNote saved to file %s\n\n", filename);
}

void read_notes() {
    system("cat *.txt");
    printf("\n\n");
}

int main() {
    char command[10];

    print_instructions();

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "new") == 0) {
            create_new_note();
        } else if (strcmp(command, "read") == 0) {
            read_notes();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}