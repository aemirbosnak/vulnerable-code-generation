//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* toMorse(char c) {
    static char* asciiToMorse[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    if (isalpha(c)) {
        c = tolower(c);
        return asciiToMorse[c - 97];
    }
    else if (isdigit(c)) {
        return asciiToMorse[c - 48];
    }
    else {
        switch (c) {
            case ' ':
                return "/";
            case ',':
                return "--..--";
            case '.':
                return ".-.-.-";
            case '?':
                return "..--..";
            case '\'':
                return ".----.";
            case '!':
                return "-.-.--";
            case '/':
                return "-..-.";
            case '(':
                return "-.--.";
            case ')':
                return "-.--.-";
            case '&':
                return ".-...";
            case ':':
                return "---...";
            case ';':
                return "-.-.-.";
            case '=':
                return "-...-";
            case '+':
                return ".-.-.";
            case '-':
                return "-....-";
            case '_':
                return "..--.-";
            case '\"':
                return ".-..-.";
            case '$':
                return "...-..-";
            case '@':
                return ".--.-.";
            default:
                return " ";
        }
    }
}

int main() {
    char str[100];
    printf("Enter a string to convert to Morse code:\n");
    fgets(str, 100, stdin);
    int len = strlen(str);
    if (str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }
    for (int i = 0; i < len; i++) {
        printf("%s ", toMorse(str[i]));
    }
    printf("\n");
    return 0;
}