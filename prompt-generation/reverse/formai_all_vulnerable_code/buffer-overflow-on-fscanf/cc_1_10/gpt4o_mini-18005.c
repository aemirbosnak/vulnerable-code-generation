//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 1024
#define SLANG_DICT_FILE "slang_dict.txt"

typedef struct {
    char word[MAX_WORD_LEN];
    char slang[MAX_WORD_LEN];
} SlangEntry;

void load_slang_dictionary(SlangEntry *dict, int *entry_count) {
    FILE *file = fopen(SLANG_DICT_FILE, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open slang dictionary file.\n");
        exit(EXIT_FAILURE);
    }
    
    *entry_count = 0;
    while (fscanf(file, "%s %s", dict[*entry_count].word, dict[*entry_count].slang) != EOF) {
        (*entry_count)++;
    }
    
    fclose(file);
}

void translate_text(const char *input, char *output, SlangEntry *dict, int entry_count) {
    char *word = strtok((char *)input, " ");
    while (word) {
        int found = 0;
        for (int i = 0; i < entry_count; i++) {
            if (strcasecmp(word, dict[i].word) == 0) {
                strcat(output, dict[i].slang);
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(output, word);
        }
        strcat(output, " ");
        word = strtok(NULL, " ");
    }
    output[strlen(output) - 1] = '\0'; // Remove the trailing space
}

int main() {
    printf("Welcome to the Cyberpunk Slang Translator. Load your dictionary and transform your text!\n");

    SlangEntry slangDict[MAX_NUM_WORDS];
    int slangCount = 0;

    load_slang_dictionary(slangDict, &slangCount);

    char inputText[1024];
    char translatedText[1024] = {0};

    printf("Enter the text to translate: ");
    fgets(inputText, sizeof(inputText), stdin);
    inputText[strcspn(inputText, "\n")] = 0; // Remove trailing newline

    translate_text(inputText, translatedText, slangDict, slangCount);

    if (strlen(translatedText) > 0) {
        printf("Translated Text: %s\n", translatedText);
    } else {
        printf("No translation available.\n");
    }

    return 0;
}