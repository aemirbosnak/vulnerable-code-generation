//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* translate(char* input) {
    char* output = malloc(strlen(input) + 1);
    int i = 0;
    while(input[i]) {
        switch(input[i]) {
            case 'a':
                output[i] = 'z';
                break;
            case 'b':
                output[i] = 'y';
                break;
            case 'c':
                output[i] = 'x';
                break;
            case 'd':
                output[i] = 'w';
                break;
            case 'e':
                output[i] = 'v';
                break;
            case 'f':
                output[i] = 'u';
                break;
            case 'g':
                output[i] = 't';
                break;
            case 'h':
                output[i] = 's';
                break;
            case 'i':
                output[i] = 'r';
                break;
            case 'j':
                output[i] = 'q';
                break;
            case 'k':
                output[i] = 'p';
                break;
            case 'l':
                output[i] = 'o';
                break;
            case 'm':
                output[i] = 'n';
                break;
            case 'n':
                output[i] = 'm';
                break;
            case 'o':
                output[i] = 'l';
                break;
            case 'p':
                output[i] = 'k';
                break;
            case 'q':
                output[i] = 'j';
                break;
            case 'r':
                output[i] = 'i';
                break;
            case 's':
                output[i] = 'h';
                break;
            case 't':
                output[i] = 'g';
                break;
            case 'u':
                output[i] = 'f';
                break;
            case 'v':
                output[i] = 'e';
                break;
            case 'w':
                output[i] = 'd';
                break;
            case 'x':
                output[i] = 'c';
                break;
            case 'y':
                output[i] = 'b';
                break;
            case 'z':
                output[i] = 'a';
                break;
            default:
                output[i] = input[i];
                break;
        }
        i++;
    }
    output[i] = '\0';
    return output;
}

int main() {
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Enter 'quit' to exit.\n\n");
    char input[100];
    while(1) {
        printf("Enter text to translate: ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        if(strcmp(input, "quit") == 0) {
            break;
        }
        printf("%s\n", translate(input));
    }
}