//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int word_count(char *str) {
    int count = 0;
    char *token;

    token = strtok(str, " \t\r\n\f\v");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " \t\r\n\f\v");
    }

    return count;
}

// Function to count characters in a string
int char_count(char *str) {
    int count = 0;

    while (*str!= '\0') {
        count++;
        str++;
    }

    return count;
}

// Function to count lines in a string
int line_count(char *str) {
    int count = 0;
    char *token;

    token = strtok(str, "\n");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, "\n");
    }

    return count;
}

// Function to count sentences in a string
int sentence_count(char *str) {
    int count = 0;
    char *token;

    token = strtok(str, ".?!");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, ".?!");
    }

    return count;
}

int main() {
    char input[1000];
    int choice;

    printf("Welcome to the Word Count Tool!\n");
    printf("Enter your text (up to 1000 characters):\n");
    fgets(input, sizeof(input), stdin);

    printf("Choose an option:\n");
    printf("1. Word Count\n");
    printf("2. Character Count\n");
    printf("3. Line Count\n");
    printf("4. Sentence Count\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Word Count: %d\n", word_count(input));
            break;
        case 2:
            printf("Character Count: %d\n", char_count(input));
            break;
        case 3:
            printf("Line Count: %d\n", line_count(input));
            break;
        case 4:
            printf("Sentence Count: %d\n", sentence_count(input));
            break;
        default:
            printf("Invalid option!\n");
            break;
    }

    return 0;
}