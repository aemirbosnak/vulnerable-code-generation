//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

char *morse_table[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
  "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----",
  "----..", "-----.", "-----..", "------.", "------..", "-------."
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    int length = strlen(input);

    if (length > MAX_LENGTH) {
        printf("Input too long. Maximum length is %d.\n", MAX_LENGTH);
        return 1;
    }

    for (int i = 0; i < length; i++) {
        char c = tolower(input[i]);

        if (!isalpha(c)) {
            printf("%c", c);
            continue;
        }

        int index = -1;
        for (int j = 0; j < sizeof(morse_table) / sizeof(char *); j++) {
            if (morse_table[j][0] == c) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            printf("%c", c);
            continue;
        }

        printf("%s ", morse_table[index]);
    }

    printf("\n");

    return 0;
}