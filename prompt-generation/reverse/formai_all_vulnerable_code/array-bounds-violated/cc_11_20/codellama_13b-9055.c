//Code Llama-13B DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void text_to_morse(char *text, char *morse) {
    int i, j;
    char *codes[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    for (i = 0, j = 0; text[i]; i++) {
        if (text[i] == ' ') {
            morse[j++] = ' ';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            morse[j++] = codes[text[i] - 'A'];
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            morse[j++] = codes[text[i] - 'a'];
        } else if (text[i] >= '0' && text[i] <= '9') {
            morse[j++] = codes[text[i] - '0' + 26];
        } else if (text[i] == '.') {
            morse[j++] = '.';
        } else if (text[i] == ',') {
            morse[j++] = ',';
        } else if (text[i] == '?') {
            morse[j++] = "..--..";
        } else if (text[i] == '!') {
            morse[j++] = "-.-.--";
        } else if (text[i] == '/') {
            morse[j++] = "-..-.";
        } else if (text[i] == '(') {
            morse[j++] = "-.--.";
        } else if (text[i] == ')') {
            morse[j++] = "-.--.-";
        } else if (text[i] == '&') {
            morse[j++] = ".-...";
        } else if (text[i] == ':') {
            morse[j++] = "---...";
        } else if (text[i] == ';') {
            morse[j++] = "-.-.-";
        } else if (text[i] == '=') {
            morse[j++] = "-...-";
        } else if (text[i] == '+') {
            morse[j++] = ".-.-.";
        } else if (text[i] == '-') {
            morse[j++] = "-....-";
        } else if (text[i] == '_') {
            morse[j++] = "..--.-";
        } else if (text[i] == '"') {
            morse[j++] = ".-..-.";
        } else if (text[i] == '$') {
            morse[j++] = "...-..-";
        } else if (text[i] == '@') {
            morse[j++] = ".--.-.";
        } else {
            morse[j++] = "?";
        }
    }
    morse[j] = '\0';
}

int main() {
    char text[MAX_LEN];
    char morse[MAX_LEN];

    printf("Enter text: ");
    scanf("%s", text);

    text_to_morse(text, morse);

    printf("Morse code: %s\n", morse);

    return 0;
}