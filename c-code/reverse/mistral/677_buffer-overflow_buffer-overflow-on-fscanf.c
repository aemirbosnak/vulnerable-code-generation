#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void pigLatin(char *word) {
    size_t len = strlen(word);
    char vowels[] = "aeiouy";
    char temp[len + 1];
    int consonantIndex = 0;

    for (int i = 0; i < len; ++i) {
        if (strchr(vowels, tolower(word[i])) != NULL) {
            break;
        }
        temp[consonantIndex++] = word[i];
    }

    if (consonantIndex == len) {
        strcpy(temp + consonantIndex, word);
    }

    strcat(temp, "ay");
    strcpy(word, temp);
}

int main(int argc, char *argv[]) {
    FILE *input, *output;
    char word[100];

    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w");

    if (!input || !output) {
        perror("Error opening files");
        return 1;
    }

    while (fscanf(input, "%s", word) != EOF) {
        pigLatin(word);
        fprintf(output, "%s ", word);
    }

    fclose(input);
    fclose(output);

    return 0;
}
