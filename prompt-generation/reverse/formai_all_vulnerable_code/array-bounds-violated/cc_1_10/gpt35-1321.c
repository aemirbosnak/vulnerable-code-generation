//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Constants
#define MAX_HIGHLIGHTS 10
#define MAX_TITLE_LENGTH 50
#define MAX_ELEMENT_LENGTH 50

// Structs
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char element[MAX_ELEMENT_LENGTH];
} Highlight;

// Global Variables
Highlight highlights[MAX_HIGHLIGHTS] = {0};
int numHighlights = 0;

// Function Prototypes
void saveHighlight(char* title, char* element);
void printHighlights();
void removeHighlight(int index);

int main() {
    char input[100];
    char title[MAX_TITLE_LENGTH];
    char element[MAX_ELEMENT_LENGTH];

    printf("Welcome to the Highlighter Plugin!\n");
    printf("Type 'help' for a list of commands.\n");

    while(1) {
        printf("\nEnter a command: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character
        input[strlen(input)-1] = '\0';

        // Parse command
        if(strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("  highlight <title> <element>\n");
            printf("  show_highlights\n");
            printf("  remove_highlight <index>\n");
            printf("  exit\n");
        }
        else if(strcmp(input, "exit") == 0) {
            printf("Exiting Highlighter Plugin...\n");
            break;
        }
        else {
            char* token = strtok(input, " ");

            if(strcmp(token, "highlight") == 0) {
                // Parse the title and element
                token = strtok(NULL, " ");
                strcpy(title, token);

                token = strtok(NULL, " ");
                strcpy(element, token);

                saveHighlight(title, element);
            }
            else if(strcmp(token, "show_highlights") == 0) {
                printHighlights();
            }
            else if(strcmp(token, "remove_highlight") == 0) {
                token = strtok(NULL, " ");
                int index = atoi(token);

                removeHighlight(index);
            }
            else {
                printf("Unknown command. Type 'help' for a list of available commands.\n");
            }
        }
    }

    return 0;
}

/**
 * Saves a new highlight with the given title and element.
 */
void saveHighlight(char* title, char* element) {
    if(numHighlights >= MAX_HIGHLIGHTS) {
        printf("Unable to save highlight. Maximum number of highlights has been reached.\n");
        return;
    }

    // Create new highlight
    Highlight newHighlight;
    strcpy(newHighlight.title, title);
    strcpy(newHighlight.element, element);

    // Add highlight to array
    highlights[numHighlights++] = newHighlight;

    printf("Highlight saved.\n");
}

/**
 * Prints out all saved highlights.
 */
void printHighlights() {
    if(numHighlights == 0) {
        printf("There are no saved highlights.\n");
        return;
    }

    printf("Saved Highlights:\n");
    for(int i = 0; i < numHighlights; i++) {
        printf("%d. %s: %s\n", i+1, highlights[i].title, highlights[i].element);
    }
}

/**
 * Removes a highlight at the given index.
 */
void removeHighlight(int index) {
    if(index < 1 || index > numHighlights) {
        printf("Invalid index. Please enter an index between 1 and %d.\n", numHighlights);
        return;
    }

    // Remove highlight from array
    for(int i = index-1; i < numHighlights-1; i++) {
        highlights[i] = highlights[i+1];
    }
    numHighlights--;

    printf("Highlight removed.\n");
}