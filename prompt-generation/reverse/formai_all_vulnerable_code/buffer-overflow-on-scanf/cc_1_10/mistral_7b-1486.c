//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char c;
    char* art;
} Character;

Character char_set[] = {
    {'A', "( _ )"},
    {'B', "|_|"},
    {'C', "(_)_)"},
    {'D', "|( _ )|"},
    {'E', "|_) |"},
    {'F', "| o |"},
    {'G', "|( _ )|"},
    {'H', "(_)_)"},
    {'I', "|(_)_)|"},
    {'J', "| o)|"},
    {'K', "|(_)_)"},
    {'L', "|\\_/|"},
    {'M', "|___|"},
    {'N', "|/ o \\|"},
    {'O', "| o   o |"},
    {'P', "|(_)_)|"},
    {'Q', "( o o )"},
    {'R', "|_(_)_)|"},
    {'S', "| o   o |"},
    {'T', "|_|"},
    {'U', "|_|"},
    {'V', "\\V/"},
    {'W', "\\_\\/"},
    {'X', "|_(_)_)|"},
    {'Y', "| o o |"},
    {'Z', "( o o )"},
    {' ', "   "},
    {'1', "|_|"},
    {'2', "|_|"},
    {'3', "|_|"},
    {'4', "|_|"},
    {'5', "|_|"},
    {'6', "|_|"},
    {'7', "|_|"},
    {'8', "|_|"},
    {'9', "|_|"},
    {'0', "|_|"},
};

int main() {
    char text[100];

    printf("Enter a text: ");
    scanf("%s", text);

    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < sizeof(char_set) / sizeof(Character); j++) {
            if (text[i] == char_set[j].c) {
                printf("%s", char_set[j].art);
                break;
            }
        }
    }

    printf("\n");

    return 0;
}