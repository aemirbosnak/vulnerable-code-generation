//Falcon2-11B DATASET v1.0 Category: Text to Morse code conversion ; Style: funny
#include <stdio.h>
#include <ctype.h>

void morse_code(char c) {
    if (isalpha(c)) {
        if (c == 'A') {
            printf(".-");
        } else if (c == 'B') {
            printf("-...");
        } else if (c == 'C') {
            printf("-.-.");
        } else if (c == 'D') {
            printf("-..");
        } else if (c == 'E') {
            printf(".");
        } else if (c == 'F') {
            printf("..-.");
        } else if (c == 'G') {
            printf("--.");
        } else if (c == 'H') {
            printf("....");
        } else if (c == 'I') {
            printf(".---");
        } else if (c == 'J') {
            printf(".--.");
        } else if (c == 'K') {
            printf("-.-");
        } else if (c == 'L') {
            printf(".-..");
        } else if (c == 'M') {
            printf("--");
        } else if (c == 'N') {
            printf("-.--");
        } else if (c == 'O') {
            printf("---");
        } else if (c == 'P') {
            printf(".--.");
        } else if (c == 'Q') {
            printf("--.-");
        } else if (c == 'R') {
            printf(".-.");
        } else if (c == 'S') {
            printf("...");
        } else if (c == 'T') {
            printf("-");
        } else if (c == 'U') {
            printf("..");
        } else if (c == 'V') {
            printf("...-");
        } else if (c == 'W') {
            printf(".--.");
        } else if (c == 'X') {
            printf("-..-");
        } else if (c == 'Y') {
            printf("-.--");
        } else if (c == 'Z') {
            printf("--..");
        } else if (c == '0') {
            printf("-----");
        } else if (c == '1') {
            printf(".----");
        } else if (c == '2') {
            printf("..---");
        } else if (c == '3') {
            printf("...--");
        } else if (c == '4') {
            printf("....-");
        } else if (c == '5') {
            printf(".....");
        } else if (c == '6') {
            printf("-....");
        } else if (c == '7') {
            printf("--...");
        } else if (c == '8') {
            printf("---..");
        } else if (c == '9') {
            printf("----.");
        } else {
            printf("What the heck is this? ");
        }
    } else {
        printf("This is not an alphabet character. ");
    }
}

int main() {
    char text[100];
    printf("Enter some text: ");
    scanf("%s", text);

    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        morse_code(text[i]);
        printf("\n");
    }

    return 0;
}