//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

char* morse_code(char c) {
    static char* codes[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    if (c >= 'A' && c <= 'Z') {
        return codes[c - 'A'];
    }
    if (c >= 'a' && c <= 'z') {
        return codes[c - 'a'];
    }
    if (c >= '0' && c <= '9') {
        return codes[c - '0' + 26];
    }
    switch (c) {
        case ' ': return "/";
        case '.': return ".-.-.-";
        case ',': return "--..--";
        case '?': return "..--..";
        case '\'': return ".----.";
        case '!': return "-.-.--";
        case '/': return "-..-.";
        case '(':
        case ')': return "-.--.-";
        case '&': return ".-...";
        case ':': return "---...";
        case ';': return "-.-.-.";
        case '=': return "-...-";
        case '+': return ".-.-.";
        case '-': return "-....-";
        case '_': return "..--.-";
        case '\"': return ".-..-.";
        case '$':
        case '@':
        case '*': return ".-.-.";
    }
    return NULL;
}

int main() {
    char input[100];
    printf("Enter text to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    printf("Morse code: ");
    for (int i = 0; i < len; i++) {
        char c = input[i];
        char* code = morse_code(c);
        if (code != NULL) {
            printf("%s ", code);
        }
    }
    printf("\n");
    return 0;
}