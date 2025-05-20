//Falcon-180B DATASET v1.0 Category: Text to Morse code conversion ; Style: decentralized
#include <stdio.h>
#include <string.h>

void morse_code(char *message) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char c = message[i];
        if (c >= 'A' && c <= 'Z') {
            printf(". ");
        } else if (c >= 'a' && c <= 'z') {
            printf("- ");
        } else if (c >= '0' && c <= '9') {
            printf("- ");
        } else if (c == '. ') {
            printf(". ");
        } else if (c == ',') {
            printf("- ");
        } else if (c == '?') {
            printf(".. ");
        } else if (c == '!') {
            printf("- ");
        } else if (c == '/') {
            printf("-.. ");
        } else if (c == '(') {
            printf("-.-. ");
        } else if (c == ')') {
            printf("-.--. ");
        } else if (c == '&') {
            printf(". ");
        } else if (c == ':') {
            printf("--- ");
        } else if (c == ';') {
            printf("-.- ");
        } else if (c == '=') {
            printf("-... ");
        } else if (c == '+') {
            printf(". ");
        } else if (c == '-') {
            printf("-.... ");
        } else if (c == '_') {
            printf("..-- ");
        } else if (c == '"') {
            printf(". ");
        } else if (c == '$') {
            printf(". ");
        } else if (c == '@') {
            printf(". ");
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    char message[100];
    printf("Enter a message to convert to Morse code: ");
    scanf("%s", message);
    morse_code(message);
    return 0;
}