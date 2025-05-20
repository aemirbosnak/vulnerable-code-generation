//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 256

typedef struct {
    char *word;
    char *translation;
} WordTranslation;

int main() {
    // Define the alien language dictionary.
    WordTranslation dictionary[] = {
        {"hello", "ola"},
        {"world", "mundo"},
        {"goodbye", "adeus"},
        {"thank you", "obrigado"},
        {"you're welcome", "de nada"},
        {"yes", "sim"},
        {"no", "não"},
        {"maybe", "talvez"},
        {"I don't know", "não sei"},
        {"what", "que"},
        {"who", "quem"},
        {"when", "quando"},
        {"where", "onde"},
        {"why", "por que"},
        {"how", "como"},
        {"much", "quanto"},
        {"many", "quantos"},
        {"few", "poucos"},
        {"some", "alguns"},
        {"all", "todos"},
        {"other", "outro"},
        {"same", "mesmo"},
        {"different", "diferente"},
        {"big", "grande"},
        {"small", "pequeno"},
        {"tall", "alto"},
        {"short", "baixo"},
        {"fat", "gordo"},
        {"thin", "magro"},
        {"old", "velho"},
        {"young", "jovem"},
        {"beautiful", "bonito"},
        {"ugly", "feio"},
        {"good", "bom"},
        {"bad", "mau"},
        {"happy", "feliz"},
        {"sad", "triste"},
        {"angry", "bravo"},
        {"scared", "assustado"},
        {"tired", "cansado"},
        {"hungry", "faminto"},
        {"thirsty", "com sede"},
        {"hot", "quente"},
        {"cold", "frio"},
        {"wet", "molhado"},
        {"dry", "seco"},
        {"light", "leve"},
        {"heavy", "pesado"},
        {"soft", "macio"},
        {"hard", "duro"},
        {"smooth", "liso"},
        {"rough", "áspero"},
        {"clean", "limpo"},
        {"dirty", "sujo"},
        {"new", "novo"},
        {"old", "velho"},
        {"big", "grande"},
        {"small", "pequeno"},
        {"tall", "alto"},
        {"short", "baixo"},
        {"fat", "gordo"},
        {"thin", "magro"},
        {"old", "velho"},
        {"young", "jovem"},
        {"beautiful", "bonito"},
        {"ugly", "feio"},
        {"good", "bom"},
        {"bad", "mau"},
        {"happy", "feliz"},
        {"sad", "triste"},
        {"angry", "bravo"},
        {"scared", "assustado"},
        {"tired", "cansado"},
        {"hungry", "faminto"},
        {"thirsty", "com sede"},
        {"hot", "quente"},
        {"cold", "frio"},
        {"wet", "molhado"},
        {"dry", "seco"},
        {"light", "leve"},
        {"heavy", "pesado"},
        {"soft", "macio"},
        {"hard", "duro"},
        {"smooth", "liso"},
        {"rough", "áspero"},
        {"clean", "limpo"},
        {"dirty", "sujo"},
        {"new", "novo"},
        {"old", "velho"},
        {"big", "grande"},
        {"small", "pequeno"},
        {"tall", "alto"},
        {"short", "baixo"},
        {"fat", "gordo"},
        {"thin", "magro"},
        {"old", "velho"},
        {"young", "jovem"},
        {"beautiful", "bonito"},
        {"ugly", "feio"},
        {"good", "bom"},
    };

    // Get the input sentence.
    char input[MAX_WORD_LEN];
    printf("Enter a sentence in English: ");
    gets(input);

    // Tokenize the input sentence.
    char *tokens[MAX_WORD_LEN];
    int num_tokens = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Translate each token.
    char output[MAX_WORD_LEN];
    for (int i = 0; i < num_tokens; i++) {
        // Find the translation for the token.
        char *translation = NULL;
        for (int j = 0; j < sizeof(dictionary) / sizeof(WordTranslation); j++) {
            if (strcmp(tokens[i], dictionary[j].word) == 0) {
                translation = dictionary[j].translation;
                break;
            }
        }

        // If the translation was not found, skip the token.
        if (translation == NULL) {
            continue;
        }

        // Append the translation to the output sentence.
        strcat(output, translation);
        strcat(output, " ");
    }

    // Print the translated sentence.
    printf("Translated sentence: %s\n", output);

    return 0;
}