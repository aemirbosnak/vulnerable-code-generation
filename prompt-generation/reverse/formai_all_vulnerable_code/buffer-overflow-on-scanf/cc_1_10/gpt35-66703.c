//FormAI DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to convert all characters in a string to uppercase
void toUpper(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

// Function to count the number of occurrences of a character in a string
int countChar(char *str, char c) {
    int count = 0;
    while (*str) {
        if (*str == c) {
            count++;
        }
        str++;
    }
    return count;
}

// Function to trim leading and trailing whitespace from a string
void trim(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    while (*start && isspace(*start)) {
        start++;
    }
    while (end > start && isspace(*end)) {
        end--;
    }
    *(end+1) = '\0';
    memmove(str, start, end-start+1);
}

// Example usage: read in a file and count the number of occurrences of a character
int main() {
    FILE *fp;
    char filename[50];
    char c;
    char line[100];
    int count = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the character to count: ");
    scanf(" %c", &c);

    while (fgets(line, sizeof(line), fp)) {
        // Convert the line to uppercase
        toUpper(line);
        // Trim leading and trailing whitespace
        trim(line);
        // Count the number of occurrences of the character
        count += countChar(line, c);
    }

    printf("The character '%c' occurs %d times in the file %s.\n", c, count, filename);

    fclose(fp);

    return 0;
}