//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_CODE_SIZE 256
#define MAX_INPUT_SIZE 1024

// Alien Language Translation Table
const char alienCodeTable[] = {
    'A', 'E', 'I', 'O', 'U', '.', ',', ';', ':', '!', '?',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '_',
    'a', 'e', 'i', 'o', 'u', '*', '#', '%', '&', '@', '(', ')',
    '+', '=', '_', '~', '`', '|', '[', ']', '{', '}', '\\', '/'
};

// Translate Alien Language command from input file to human readable format
void translateAlienCommand(const char *alienCommand, char *humanReadableCommand) {
    int i = 0;
    int j = 0;

    while (alienCommand[i] != '\0') {
        if (alienCommand[i] >= 'A' && alienCommand[i] <= 'Z') {
            humanReadableCommand[j++] = alienCodeTable[alienCommand[i] - 'A'];
        } else if (alienCommand[i] >= 'a' && alienCommand[i] <= 'z') {
            humanReadableCommand[j++] = alienCodeTable[alienCommand[i] - 'a' + 26];
        } else {
            humanReadableCommand[j++] = alienCommand[i];
        }

        i++;
    }

    humanReadableCommand[j] = '\0';
}

int main() {
    FILE *inputFile;
    FILE *outputFile;
    char alienCommand[MAX_INPUT_SIZE];
    char humanReadableCommand[MAX_INPUT_SIZE];

    inputFile = fopen("alien_input.txt", "r");
    outputFile = fopen("alien_output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files.");
        exit(1);
    }

    while (fgets(alienCommand, MAX_INPUT_SIZE, inputFile) != NULL) {
        translateAlienCommand(alienCommand, humanReadableCommand);
        fprintf(outputFile, "%s\n", humanReadableCommand);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}