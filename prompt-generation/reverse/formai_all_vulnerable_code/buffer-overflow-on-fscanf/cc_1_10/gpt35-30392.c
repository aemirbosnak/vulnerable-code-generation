//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

// Define the structures used for storing the translation rules and input/output strings
typedef struct {
    char alien_char;
    char human_str[10];
} TranslationRule;

typedef struct {
    char alien_str[100];
    char human_str[100];
} TranslationInput;

// Function declarations
void load_translation_rules(TranslationRule[], int);
void translate_input_strings(TranslationInput[], int, TranslationRule[], int);
void print_translation_outputs(TranslationInput[], int);

int main() {
    // Define the number of translation rules and input strings, and allocate space for them
    int num_rules = 5;
    int num_inputs = 3;
    TranslationRule rules[num_rules];
    TranslationInput inputs[num_inputs];
    
    // Load the translation rules from a file
    load_translation_rules(rules, num_rules);
    
    // Get input strings from the user and store them
    printf("Enter %d alien strings, one per line:\n", num_inputs);
    for (int i = 0; i < num_inputs; i++) {
        printf("Input %d: ", i+1);
        fgets(inputs[i].alien_str, 100, stdin);
        inputs[i].alien_str[strcspn(inputs[i].alien_str, "\n")] = '\0'; // Remove the newline character
    }
    
    // Translate the input strings into human-readable form
    translate_input_strings(inputs, num_inputs, rules, num_rules);
    
    // Print the translated output strings
    print_translation_outputs(inputs, num_inputs); 
    
    return 0;
}

// Function to load translation rules from a file
void load_translation_rules(TranslationRule rules[], int num_rules) {
    FILE *fp;
    fp = fopen("translation_rules.txt", "r");
    
    for (int i = 0; i < num_rules; i++) {
        fscanf(fp, "%c %s\n", &rules[i].alien_char, rules[i].human_str);
    }
    
    fclose(fp);
}

// Function to translate input strings into human-readable form
void translate_input_strings(TranslationInput inputs[], int num_inputs, TranslationRule rules[], int num_rules) {
    for (int i = 0; i < num_inputs; i++) {
        int len = strlen(inputs[i].alien_str);
        for (int j = 0; j < len; j++) {
            for (int k =0; k < num_rules; k++) {
                if (inputs[i].alien_str[j] == rules[k].alien_char) {
                    strncat(inputs[i].human_str, rules[k].human_str, strlen(rules[k].human_str));
                }
            }
        }
    }
}

// Function to print the translated output strings
void print_translation_outputs(TranslationInput inputs[], int num_inputs) {
    printf("\nTranslation outputs:\n");
    for (int i = 0; i < num_inputs; i++) {
        printf("%s\n", inputs[i].human_str);
    }
}