//Falcon-180B DATASET v1.0 Category: File handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Function to read the file and return its content as a string
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char* buffer = malloc(MAX_LINE_SIZE);
    char* content = malloc(MAX_LINE_SIZE);
    content[0] = '\0';

    // Read the file line by line and concatenate the lines
    while (fgets(buffer, MAX_LINE_SIZE, file)!= NULL) {
        strcat(content, buffer);
    }

    fclose(file);
    return content;
}

// Function to write the content to a file
void write_file(const char* filename, const char* content) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file %s for writing\n", filename);
        exit(1);
    }

    fprintf(file, "%s", content);

    fclose(file);
}

// Function to replace all occurrences of a substring with another substring
char* replace_substring(const char* content, const char* old_substring, const char* new_substring) {
    char* modified_content = malloc(strlen(content) + 1);
    strcpy(modified_content, content);

    char* current_position = strstr(modified_content, old_substring);
    while (current_position!= NULL) {
        strcpy(current_position, new_substring);
        current_position += strlen(new_substring);
        current_position = strstr(current_position, old_substring);
    }

    return modified_content;
}

// Function to count the number of words in a string
int count_words(const char* content) {
    int count = 0;
    char* current_position = strtok(content, " ");
    while (current_position!= NULL) {
        count++;
        current_position = strtok(NULL, " ");
    }

    return count;
}

int main() {
    char* file_content = read_file("post_apocalyptic_story.txt");

    // Replace all occurrences of the word "zombie" with "walker"
    char* modified_content = replace_substring(file_content, "zombie", "walker");

    // Write the modified content to a new file
    write_file("modified_story.txt", modified_content);

    // Count the number of words in the modified content
    int word_count = count_words(modified_content);

    printf("The modified story contains %d words.\n", word_count);

    free(file_content);
    free(modified_content);

    return 0;
}