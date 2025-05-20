//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

#define MORSE_TABLE_SIZE 26
#define MAX_WORD_SIZE 20

char morse_table[MORSE_TABLE_SIZE][MAX_WORD_SIZE] = {
    {".-"}, // A
    {"-..."}, // B
    {"-.-."}, // C
    {"-.."}, // D
    {"."}, // E
    {"..-."}, // F
    {"--."}, // G
    {"...."}, // H
    {".."}, // I
    {".---"}, // J
    {"-.-"}, // K
    {".-.."}, // L
    {"--"}, // M
    {"-"}, // N
    {"---"}, // O
    {".--."}, // P
    {"--.-"}, // Q
    {".-."}, // R
    {"..."}, // S
    {"-"}, // T
    {"..-"}, // U
    {"...-"}, // V
    {".--"}, // W
    {"-..-"}, // X
    {"-.--"}, // Y
    {"--.."} // Z
};

void print_morse_code(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        char letter = word[i];
        if (letter >= 'a' && letter <= 'z') {
            letter -= 32;
        }
        int index = letter - 'A';
        if (index >= 0 && index < MORSE_TABLE_SIZE) {
            printf("%s ", morse_table[index]);
        }
    }
    printf("\n");
}

int main() {
    char word[MAX_WORD_SIZE];
    printf("Enter a word to convert to Morse code: ");
    scanf("%s", word);
    print_morse_code(word);
    return 0;
}