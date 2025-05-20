//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_WORDS 10

const char *cat_words[][2] = {
    {"meow", "greeting"},
    {"purr", "contentment"},
    {"hiss", "danger"},
    {"scratch", "warning"},
    {"yowl", "attention"},
    {"mew", "request"},
    {"whiskers", "curiosity"},
    {"crazy", "joyful"},
    {"nap", "rest"},
    {"feline", "royalty"}
};

void print_welcome_message() {
    printf("=================================\n");
    printf(" Welcome to the Cat Language Translator\n");
    printf("=================================\n");
    printf("Speak to your feline friend with honor!\n");
}

void translate_to_cat_language(const char *input) {
    char *word;
    char *input_copy = strdup(input);
    const char *delim = " ";

    word = strtok(input_copy, delim);
    while (word != NULL) {
        int found = 0;
        for (size_t i = 0; i < sizeof(cat_words) / sizeof(cat_words[0]); i++) {
            if (strcmp(word, cat_words[i][1]) == 0) {
                printf("%s ", cat_words[i][0]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("unknown_word ");
        }
        word = strtok(NULL, delim);
    }
    free(input_copy);
    printf("\n");
}

int count_words(const char *input) {
    int count = 0;
    char *input_copy = strdup(input);
    char *word = strtok(input_copy, " ");
    
    while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    
    free(input_copy);
    return count;
}

void talk_to_your_cat() {
    char input[MAX_LENGTH];
    printf("Speak to thy feline friend: ");
    fgets(input, MAX_LENGTH, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';
    
    int word_count = count_words(input);
    
    if (word_count > 10) {
        printf("Alas! Speak no more than ten words! \n");
    } else {
        translate_to_cat_language(input);
    }
}

int main() {
    print_welcome_message();

    char continue_translating;
    do {
        talk_to_your_cat();
        printf("Would you like to converse with your cat again? (y/n): ");
        scanf(" %c", &continue_translating);
        getchar(); // To consume newline from buffer
    } while (continue_translating == 'y' || continue_translating == 'Y');
    
    printf("Fare thee well, noble cat whisperer!\n");
    return 0;
}