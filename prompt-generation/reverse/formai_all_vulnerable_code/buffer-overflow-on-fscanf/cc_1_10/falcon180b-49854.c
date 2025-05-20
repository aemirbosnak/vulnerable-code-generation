//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_WORD_LENGTH 80
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} DictionaryEntry;

int main() {
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
    int num_entries = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary_file, "%s", word)!= EOF) {
        if (num_entries >= MAX_DICTIONARY_SIZE) {
            printf("Dictionary is full.\n");
            break;
        }

        dictionary[num_entries].word[0] = toupper(word[0]);
        strncpy(dictionary[num_entries].word + 1, &word[1], MAX_WORD_LENGTH - 1);
        dictionary[num_entries].is_correct = true;
        num_entries++;
    }

    fclose(dictionary_file);

    char text_file_name[80];
    printf("Enter name of text file to check spelling: ");
    scanf("%s", text_file_name);

    FILE *text_file = fopen(text_file_name, "r");
    if (text_file == NULL) {
        printf("Error opening text file.\n");
        return 1;
    }

    char line[80];
    while (fgets(line, sizeof(line), text_file)!= NULL) {
        char word[MAX_WORD_LENGTH];
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);

            bool is_correct = false;
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(dictionary[i].word, word) == 0) {
                    is_correct = true;
                    break;
                }
            }

            if (!is_correct) {
                printf("Possible spelling error: %s\n", word);
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(text_file);

    return 0;
}