//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

void print_menu() {
    printf("\n--- Text Processing Tool ---\n");
    printf("1. Add a line of text\n");
    printf("2. Display all lines\n");
    printf("3. Search a term in the text\n");
    printf("4. Replace a term in the text\n");
    printf("5. Save to file\n");
    printf("6. Load from file\n");
    printf("7. Exit\n");
    printf("---------------------------\n");
    printf("Choose an option: ");
}

void add_line(char lines[MAX_LINES][MAX_LENGTH], int *line_count) {
    if (*line_count >= MAX_LINES) {
        printf("Maximum line limit reached!\n");
        return;
    }
    
    printf("Enter the line of text: ");
    getchar(); // Clear the newline character from input buffer
    fgets(lines[*line_count], MAX_LENGTH, stdin);
    
    // Remove newline character, if present
    lines[*line_count][strcspn(lines[*line_count], "\n")] = 0;
    (*line_count)++;
    printf("Line added successfully.\n");
}

void display_lines(char lines[MAX_LINES][MAX_LENGTH], int line_count) {
    printf("\n--- Displaying Lines ---\n");
    for (int i = 0; i < line_count; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

void search_term(char lines[MAX_LINES][MAX_LENGTH], int line_count) {
    char term[MAX_LENGTH];
    printf("Enter term to search: ");
    getchar(); // Clear the newline character from input buffer
    fgets(term, MAX_LENGTH, stdin);
    term[strcspn(term, "\n")] = 0; // Remove newline character

    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < line_count; i++) {
        if (strstr(lines[i], term) != NULL) {
            printf("Found in line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No match found for '%s'.\n", term);
    }
}

void replace_term(char lines[MAX_LINES][MAX_LENGTH], int line_count) {
    char old_term[MAX_LENGTH], new_term[MAX_LENGTH];
    printf("Enter term to replace: ");
    getchar(); // Clear the newline character
    fgets(old_term, MAX_LENGTH, stdin);
    old_term[strcspn(old_term, "\n")] = 0; // Remove newline

    printf("Enter new term: ");
    fgets(new_term, MAX_LENGTH, stdin);
    new_term[strcspn(new_term, "\n")] = 0; // Remove newline

    int replaced = 0;
    for (int i = 0; i < line_count; i++) {
        if (strstr(lines[i], old_term) != NULL) {
            char temp[MAX_LENGTH];
            strcpy(temp, lines[i]);
            
            char *pos = strstr(temp, old_term);
            while (pos) {
                char buffer[MAX_LENGTH];
                *pos = '\0';
                sprintf(buffer, "%s%s%s", temp, new_term, pos + strlen(old_term));
                strcpy(lines[i], buffer);
                pos = strstr(lines[i], old_term);
            }
            printf("Replaced in line %d: %s\n", i + 1, lines[i]);
            replaced++;
        }
    }
    if (replaced == 0) {
        printf("No occurrences of '%s' found for replacement.\n", old_term);
    }
}

void save_to_file(char lines[MAX_LINES][MAX_LENGTH], int line_count) {
    FILE *file;
    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < line_count; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);
    printf("Lines saved to output.txt successfully.\n");
}

void load_from_file(char lines[MAX_LINES][MAX_LENGTH], int *line_count) {
    FILE *file;
    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (*line_count < MAX_LINES && fgets(lines[*line_count], MAX_LENGTH, file) != NULL) {
        lines[*line_count][strcspn(lines[*line_count], "\n")] = 0; // Remove newline
        (*line_count)++;
    }
    fclose(file);
    printf("Lines loaded from output.txt successfully.\n");
}

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    int line_count = 0;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_line(lines, &line_count);
                break;
            case 2:
                display_lines(lines, line_count);
                break;
            case 3:
                search_term(lines, line_count);
                break;
            case 4:
                replace_term(lines, line_count);
                break;
            case 5:
                save_to_file(lines, line_count);
                break;
            case 6:
                load_from_file(lines, &line_count);
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}