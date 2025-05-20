//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_ART_SIZE 500

// Function prototypes
void displayMenu();
void getInput(char *input);
void generateAsciiArt(const char *input, char (*art)[MAX_ART_SIZE], int *artSize);
void printAsciiArt(const char (*art)[MAX_ART_SIZE], int artSize);
void saveToFile(const char *filename, const char (*art)[MAX_ART_SIZE], int artSize);

int main() {
    char input[MAX_INPUT_SIZE];
    char art[MAX_ART_SIZE][MAX_ART_SIZE];
    int artSize = 0;
    char filename[MAX_INPUT_SIZE];
    
    displayMenu();
    getInput(input);
    generateAsciiArt(input, art, &artSize);
    
    printAsciiArt(art, artSize);
    
    printf("Do you want to save the ASCII art to a file? (yes/no): ");
    char option[MAX_INPUT_SIZE];
    scanf("%s", option);
    
    if (strcmp(option, "yes") == 0) {
        printf("Enter filename: ");
        scanf("%s", filename);
        saveToFile(filename, art, artSize);
        printf("ASCII art saved to %s\n", filename);
    }

    return 0;
}

void displayMenu() {
    printf("Welcome to Text to ASCII Art Generator\n");
    printf("---------------------------------------\n");
}

void getInput(char *input) {
    printf("Enter the text you want to convert to ASCII art: ");
    scanf(" %[^\n]", input);  // reads a line of text including spaces
}

void generateAsciiArt(const char *input, char (*art)[MAX_ART_SIZE], int *artSize) {
    int len = strlen(input);
    *artSize = len * 2;  // Each character generates 2 lines for simplicity

    for (int i = 0; i < len; i++) {
        char ch = input[i];

        // Generating a simple ASCII representation
        snprintf(art[i * 2], MAX_ART_SIZE, "  _%c_  ", ch); // top line
        snprintf(art[i * 2 + 1], MAX_ART_SIZE, " |%c|  ", ch); // bottom line
    }
}

void printAsciiArt(const char (*art)[MAX_ART_SIZE], int artSize) {
    printf("\nGenerated ASCII Art:\n");
    for (int i = 0; i < artSize; i++) {
        printf("%s\n", art[i]);
    }
}

void saveToFile(const char *filename, const char (*art)[MAX_ART_SIZE], int artSize) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < artSize; i++) {
        fprintf(file, "%s\n", art[i]);
    }
    
    fclose(file);
}