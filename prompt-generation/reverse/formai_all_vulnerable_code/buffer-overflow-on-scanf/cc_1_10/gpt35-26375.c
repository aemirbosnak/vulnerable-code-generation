//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 100

// Define Cat Language dictionary
const char *CAT_DICT[] = {"meow", "purr", "hiss", "scratch", "claw", "whiskers", "tail", "nap", "curious"};

// Define English Language dictionary
const char *ENG_DICT[] = {"hello", "yes", "no", "please", "thank you", "smile", "wave", "sleep", "interested"};

// Function to translate Cat Language to English
void cat_to_eng(char *input) {
    char *token = strtok(input, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < 9; i++) {
            if (strcmp(CAT_DICT[i], token) == 0) {
                printf("%s ", ENG_DICT[i]);
                found = 1;
                break;
            }
        }
        if (found == 0) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

// Function to translate English to Cat Language
void eng_to_cat(char *input) {
    char *token = strtok(input, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < 9; i++) {
            if (strcmp(ENG_DICT[i], token) == 0) {
                printf("%s ", CAT_DICT[i]);
                found = 1;
                break;
            }
        }
        if (found == 0) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char input[MAX_LENGTH];
    int choice;

    printf("Welcome to the Cat Language Translator!\n");
    printf("What do you want to do?\n");
    printf("1. Translate from Cat Language to English\n");
    printf("2. Translate from English to Cat Language\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        printf("Enter the Cat Language text to translate: ");
        fgets(input, MAX_LENGTH, stdin);
        printf("Translated to English: ");
        cat_to_eng(input);
    } else if (choice == 2) {
        printf("Enter the English text to translate: ");
        fgets(input, MAX_LENGTH, stdin);
        printf("Translated to Cat Language: ");
        eng_to_cat(input);
    } else {
        printf("Invalid choice.");
    }

    return 0;
}