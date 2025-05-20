//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define MAX_WORDS 100

void transform_to_uppercase(char *text) {
    for (int i = 0; text[i]; i++) {
        text[i] = toupper(text[i]);
    }
}

void reverse_text(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len / 2; i++) {
        char temp = text[i];
        text[i] = text[len - i - 1];
        text[len - i - 1] = temp;
    }
}

void print_words(const char *text) {
    char *word;
    char *copy = strdup(text);
    char *delimiter = " \n\t";
    word = strtok(copy, delimiter);
    
    printf("Words in the input text:\n");
    while (word != NULL) {
        printf("%s\n", word);
        word = strtok(NULL, delimiter);
    }
    
    free(copy);
}

int count_chars(const char *text) {
    return strlen(text);
}

int count_words(const char *text) {
    int count = 0;
    char *copy = strdup(text);
    char *word = strtok(copy, " \n\t");
    
    while (word != NULL) {
        count++;
        word = strtok(NULL, " \n\t");
    }
    
    free(copy);
    return count;
}

void print_menu() {
    printf("\nShape-Shifting Text Processor\n");
    printf("1. Transform to Uppercase\n");
    printf("2. Reverse Text\n");
    printf("3. Print Words Line by Line\n");
    printf("4. Character Count\n");
    printf("5. Word Count\n");
    printf("6. Exit\n");
}

int main() {
    char input_text[MAX_INPUT_SIZE];
    int choice;

    printf("Enter your text (max %d characters):\n", MAX_INPUT_SIZE);
    fgets(input_text, MAX_INPUT_SIZE, stdin);
    
    while (1) {
        print_menu();
        printf("Please choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                transform_to_uppercase(input_text);
                printf("Transformed Text: %s\n", input_text);
                break;
            case 2:
                reverse_text(input_text);
                printf("Reversed Text: %s\n", input_text);
                break;
            case 3:
                print_words(input_text);
                break;
            case 4:
                printf("Character Count: %d\n", count_chars(input_text));
                break;
            case 5:
                printf("Word Count: %d\n", count_words(input_text));
                break;
            case 6:
                printf("Exiting the Shape-Shifting Text Processor. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    return 0;
}