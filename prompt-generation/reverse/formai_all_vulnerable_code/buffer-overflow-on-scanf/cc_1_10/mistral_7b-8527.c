//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CAT Translator Structures
typedef struct CAT_Rule {
    char *english;
    char *catalan;
} CAT_Rule;

typedef struct CAT_Table {
    int size;
    CAT_Rule *rules;
} CAT_Table;

// Helper Function to find the Catalan word
CAT_Rule *find_rule(CAT_Table *table, char *english) {
    int i;
    for (i = 0; i < table->size; i++) {
        if (strcmp(table->rules[i].english, english) == 0) {
            return &(table->rules[i]);
        }
    }
    return NULL;
}

// Function to translate a word from English to Catalan
void translate(CAT_Table *table, char *english) {
    CAT_Rule *rule = find_rule(table, english);
    if (rule != NULL) {
        printf("%s: %s\n", english, rule->catalan);
    } else {
        printf("%s: Unknown\n", english);
    }
}

// Main Function
int main(int argc, char **argv) {
    // Create a Catalan Translation Table
    CAT_Table table;
    table.size = 5;
    table.rules = (CAT_Rule *)calloc(table.size, sizeof(CAT_Rule));

    // Fill the Catalan Translation Table
    strcpy(table.rules[0].english, "Hello");
    strcpy(table.rules[0].catalan, " Hola ");

    strcpy(table.rules[1].english, "Goodbye");
    strcpy(table.rules[1].catalan, " Adiós ");

    strcpy(table.rules[2].english, "Thank you");
    strcpy(table.rules[2].catalan, " Gràcies ");

    strcpy(table.rules[3].english, "You're welcome");
    strcpy(table.rules[3].catalan, " De totes maneres, estic agradecit ");

    strcpy(table.rules[4].english, "Cat Language Translator");
    strcpy(table.rules[4].catalan, " Traductor de llenguatge de gats ");

    // Get user input and translate
    char input[100];
    while (1) {
        printf("\nEnter a word to translate (type 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        translate(&table, input);
    }

    // Free memory and exit
    free(table.rules);
    return 0;
}