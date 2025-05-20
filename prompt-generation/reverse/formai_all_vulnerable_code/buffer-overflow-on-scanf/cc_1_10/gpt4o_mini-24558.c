//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

typedef struct {
    char **lines;
    int count;
} TextBuffer;

// Function prototypes
TextBuffer* create_text_buffer();
void free_text_buffer(TextBuffer *buffer);
void add_line(TextBuffer *buffer, const char *line);
void to_upper(TextBuffer *buffer);
void to_lower(TextBuffer *buffer);
void count_words(TextBuffer *buffer);
void display_menu();
void process_choice(TextBuffer *buffer, int choice);

int main() {
    TextBuffer *buffer = create_text_buffer();
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume trailing newline
        if (choice == 0) {
            break;
        }
        process_choice(buffer, choice);
    }

    free_text_buffer(buffer);
    return 0;
}

TextBuffer* create_text_buffer() {
    TextBuffer *buffer = malloc(sizeof(TextBuffer));
    buffer->lines = malloc(MAX_LINES * sizeof(char *));
    buffer->count = 0;
    return buffer;
}

void free_text_buffer(TextBuffer *buffer) {
    for (int i = 0; i < buffer->count; i++) {
        free(buffer->lines[i]);
    }
    free(buffer->lines);
    free(buffer);
}

void add_line(TextBuffer *buffer, const char *line) {
    if (buffer->count < MAX_LINES) {
        buffer->lines[buffer->count] = malloc(strlen(line) + 1);
        strcpy(buffer->lines[buffer->count], line);
        buffer->count++;
    } else {
        printf("Buffer is full! Cannot add more lines.\n");
    }
}

void to_upper(TextBuffer *buffer) {
    for (int i = 0; i < buffer->count; i++) {
        for (char *p = buffer->lines[i]; *p; p++) {
            *p = toupper((unsigned char)*p);
        }
    }
    printf("All lines converted to uppercase.\n");
}

void to_lower(TextBuffer *buffer) {
    for (int i = 0; i < buffer->count; i++) {
        for (char *p = buffer->lines[i]; *p; p++) {
            *p = tolower((unsigned char)*p);
        }
    }
    printf("All lines converted to lowercase.\n");
}

void count_words(TextBuffer *buffer) {
    int total_words = 0;
    for (int i = 0; i < buffer->count; i++) {
        char *line = buffer->lines[i];
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            total_words++;
            token = strtok(NULL, " \t\n");
        }
    }
    printf("Total word count: %d\n", total_words);
}

void display_menu() {
    printf("\nText Processing Menu:\n");
    printf("1. Add a new line\n");
    printf("2. Convert all lines to uppercase\n");
    printf("3. Convert all lines to lowercase\n");
    printf("4. Count total words\n");
    printf("0. Exit\n");
}

void process_choice(TextBuffer *buffer, int choice) {
    char input[MAX_LINE_LENGTH];
    switch (choice) {
        case 1:
            printf("Enter a line to add: ");
            fgets(input, MAX_LINE_LENGTH, stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline character
            add_line(buffer, input);
            break;
        case 2:
            to_upper(buffer);
            break;
        case 3:
            to_lower(buffer);
            break;
        case 4:
            count_words(buffer);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}