//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>

char* to_morse_code(char c) {
    char* morse_codes[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
                            "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                            "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                            "-.--", "--.." };
    int index = -1;
    if (isalpha(c)) {
        index = toupper(c) - 'A';
    }
    else if (isdigit(c)) {
        index = c - '0' + 25;
    }
    else {
        switch (c) {
        case ' ':
            return " / ";
        case ',':
            index = 36;
            break;
        case '.':
            index = 37;
            break;
        case '?':
            index = 38;
            break;
        case ';':
            index = 39;
            break;
        case ':':
            index = 40;
            break;
        case '/':
            index = 41;
            break;
        case '-':
            index = 42;
            break;
        case '(':
            index = 43;
            break;
        case ')':
            index = 44;
            break;
        case '_':
            index = 45;
            break;
        case '+':
            index = 46;
            break;
        case '=':
            index = 47;
            break;
        case '@':
            index = 48;
            break;
        default:
            return "";
        }
    }
    return morse_codes[index];
}

int main() {
    char input[500];
    printf("Enter the text you want to convert to Morse Code: ");
    fgets(input, 500, stdin);
    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[--len] = '\0';
    }
    for (int i = 0; i < len; i++) {
        printf("%s ", to_morse_code(input[i]));
    }
    return 0;
}

/*
Sample Input: HELLO WORLD
Sample Output: .... . .-.. .-.. --- / .-- --- .-. .-.. -..
*/