//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Define array of C Cat words
const char* c_cat_words[] = {"meow", "purr", "hiss", "scratch", "pounce"};

// Define array of English translations
const char* english_words[] = {"Hello", "Yes", "No", "What are you doing?", "Stop that"};

// Define function to translate C Cat to English
void c_cat_to_english(char* c_cat_string) {
    int i;
    for(i = 0; i < 5; i++) {
        if(strcmp(c_cat_string, c_cat_words[i]) == 0) {
            printf("%s\n", english_words[i]);
            return;
        }
    }
    printf("I do not understand.\n");
}

// Define function to translate English to C Cat
void english_to_c_cat(char* english_string) {
    int i;
    for(i = 0; i < 5; i++) {
        if(strcmp(english_string, english_words[i]) == 0) {
            printf("%s\n", c_cat_words[i]);
            return;
        }
    }
    printf("I do not understand.\n");
}

int main() {
    char input_string[100];
    char* user_choice = "";
    while(1) {
        printf("Enter '1' to translate from C Cat to English, '2' to translate from English to C Cat, or 'quit' to exit: ");
        scanf("%s", user_choice);
        if(strcmp(user_choice, "1") == 0) {
            printf("Enter a C Cat phrase: ");
            scanf("%s", input_string);
            c_cat_to_english(input_string);
        } else if(strcmp(user_choice, "2") == 0) {
            printf("Enter an English phrase: ");
            getchar(); // consume newline character
            fgets(input_string, sizeof(input_string), stdin);
            input_string[strlen(input_string) - 1] = '\0'; // replace newline character with null terminator
            english_to_c_cat(input_string);
        } else if(strcmp(user_choice, "quit") == 0) {
            break;
        } else {
            printf("Invalid input.\n");
        }
    }
    return 0;
}