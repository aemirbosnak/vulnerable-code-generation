//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

char morse_table[][4] = {
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    ". ",
    "-",
    "=",
    "? ",
    "/",
    "@",
    "&",
    "*",
    "(",
    ")",
    "_",
    "+",
    "~",
    "!"
};

char input_buffer[MAX_LENGTH];
int input_index = 0;

void clear_input_buffer() {
    input_index = 0;
    memset(input_buffer, 0, MAX_LENGTH);
}

void add_character_to_input_buffer(char c) {
    if (input_index == MAX_LENGTH) {
        printf("Input buffer is full. Please clear the buffer before adding more characters.\n");
        return;
    }
    input_buffer[input_index++] = c;
}

void convert_input_to_morse_code() {
    int i, j;
    char c;
    for (i = 0; i < input_index; i++) {
        c = input_buffer[i];
        if (c >= 'A' && c <= 'Z') {
            printf("%c", c);
        } else if (c >= 'a' && c <= 'z') {
            printf("%c", c - 32);
        } else if (c >= '0' && c <= '9') {
            printf("%c", c);
        } else {
            for (j = 0; j < strlen(morse_table[c - 32]); j++) {
                printf("%c", morse_table[c - 32][j]);
            }
        }
    }
}

int main() {
    char c;
    clear_input_buffer();
    printf("Enter text to convert to Morse code:\n");
    while ((c = getchar())!= '\n') {
        add_character_to_input_buffer(c);
    }
    printf("\nMorse code: ");
    convert_input_to_morse_code();
    return 0;
}