//FormAI DATASET v1.0 Category: Text processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void print_menu();
void capitalize(char *input);
void count_words(char *input);

int main() {
    char input[1000];
    int choice;

    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);
    printf("\n");

    do {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                capitalize(input);
                break;
            case 2:
                count_words(input);
                break;
            case 3:
                printf("Exiting program...\n\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while(choice != 3);

    return 0;
}

// Function to print the main menu
void print_menu() {
    printf("Menu:\n");
    printf("1. Capitalize text\n");
    printf("2. Count words\n");
    printf("3. Exit program\n");
    printf("Enter a choice: ");
}

// Function to capitalize each word in the input string
void capitalize(char *input) {
    char *token;
    char output[1000];
    int i = 0;

    token = strtok(input, " ");

    while(token != NULL) {
        token[0] = toupper(token[0]);
        strcpy(&output[i], token);
        i += strlen(token);
        output[i++] = ' ';
        token = strtok(NULL, " ");
    }

    output[i] = '\0';

    printf("Capitalized text: %s\n\n", output);
}

// Function to count the number of words in the input string
void count_words(char *input) {
    int word_count = 0;
    char *token;

    token = strtok(input, " ");

    while(token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }

    printf("Number of words: %d\n\n", word_count);
}