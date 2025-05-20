//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 512
#define MAX_KEYWORDS 20
#define MAX_KEYWORD_LENGTH 20

// Function to remove spaces and punctuation from a string
void removeSpacesAndPunctuation(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (isalnum(str[i])) {
            str[j++] = tolower(str[i]);
        }
        i++;
    }
    str[j] = '\0';
}

// Function to compare two strings
int compareStrings(char *str1, char *str2) {
    int i = 0;
    while (str1[i] && str2[i]) {
        if (str1[i]!= str2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check if a string matches any of the keywords
int checkKeywords(char *str, char *keywords[]) {
    int i = 0;
    while (keywords[i]) {
        if (compareStrings(str, keywords[i])) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Function to read keywords from a file
void readKeywords(char *filename, char *keywords[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s", keywords[i])!= EOF) {
        i++;
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <keywords_file>\n", argv[0]);
        exit(1);
    }

    // Read input file
    FILE *input_fp = fopen(argv[1], "r");
    if (!input_fp) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    // Read keywords file
    char *keywords[MAX_KEYWORDS];
    readKeywords(argv[2], keywords);

    // Read input file line by line and check for keywords
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_fp)) {
        removeSpacesAndPunctuation(line);
        int found = 0;
        for (int i = 0; i < MAX_KEYWORDS &&!found; i++) {
            if (checkKeywords(line, keywords[i])) {
                found = 1;
            }
        }
        if (found) {
            printf("Intrusion detected in line: %s\n", line);
        }
    }

    // Close input file
    fclose(input_fp);

    return 0;
}