//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 30
#define MAX_LINE_LEN 256

// Function to get a random number between min and max
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to get a random line from a file
char* get_random_line(FILE* file) {
    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Get a random number between 0 and the size of the file
    int random_offset = get_random_number(0, file_size - 1);

    // Seek to the random offset
    fseek(file, random_offset, SEEK_SET);

    // Read the line
    char* line = malloc(MAX_LINE_LEN);
    fgets(line, MAX_LINE_LEN, file);

    // Remove the newline character from the end of the line
    line[strlen(line) - 1] = '\0';

    // Return the line
    return line;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Open the fortune file
    FILE* fortune_file = fopen("fortunes.txt", "r");
    if (fortune_file == NULL) {
        printf("Error opening fortune file\n");
        return 1;
    }

    // Get the user's name
    char name[MAX_NAME_LEN];
    printf("What is your name? ");
    scanf("%s", name);

    // Get a random fortune
    char* fortune = get_random_line(fortune_file);

    // Print the fortune
    printf("\nHello, %s. Your fortune is:\n\n%s\n\n", name, fortune);

    // Close the fortune file
    fclose(fortune_file);

    return 0;
}