//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    FILE *input_file;
    char filename[MAX_WORD_LENGTH];
    char buffer[MAX_WORD_LENGTH];
    int word_count = 0;
    int total_characters = 0;
    int current_word_length = 0;
    int is_word_start = 1;

    printf("Enter filename: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(buffer, MAX_WORD_LENGTH, input_file)!= NULL) {
        total_characters += strlen(buffer);

        for (int i = 0; i < strlen(buffer); i++) {
            if (isalnum(buffer[i])) {
                if (is_word_start) {
                    is_word_start = 0;
                    current_word_length = 1;
                } else {
                    current_word_length++;
                }
            } else {
                is_word_start = 1;
            }
        }

        if (current_word_length > 0) {
            word_count++;
        }
    }

    fclose(input_file);

    printf("Total number of words: %d\n", word_count);
    printf("Total number of characters: %d\n", total_characters);

    return 0;
}