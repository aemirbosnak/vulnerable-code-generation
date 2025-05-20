//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char symbol;
    int value;
} Token;

void meow() {
    printf("Meow\n");
}

void purr() {
    int i;
    for(i = 0; i < 10; i++) {
        printf("Rrrrr\n");
    }
}

void translate(char* code) {
    Token tokens[100];
    int top = 0;

    while(*code) {
        if(isdigit(*code)) {
            tokens[top].symbol = 'N';
            tokens[top].value = *code - '0';
            top++;
            code++;
        } else if(isalpha(*code)) {
            tokens[top].symbol = *code;
            top++;
            code++;
        } else if(*code == ':') {
            tokens[top - 1].value *= tokens[top++].value;
            code++;
        } else if(*code == '+') {
            tokens[top - 1].value += tokens[top++].value;
            code++;
        } else if(*code == '-') {
            tokens[top - 1].value -= tokens[top++].value;
            code++;
        } else if(*code == ';') {
            switch(tokens[top - 1].symbol) {
                case 'M': meow(); break;
                case 'P': purr(); break;
            }
            top--;
            code++;
        } else if(*code == '[') {
            int i = 0;
            for(; tokens[i].symbol != ']'; i++) {
                if(tokens[i].symbol == 'N') {
                    switch(tokens[i + 1].symbol) {
                        case 'M': meow(); i++; break;
                        case 'P': purr(); i++; break;
                    }
                    i++;
                }
            }
            code++;
        }
    }
}

int main() {
    char code[100];

    printf("Enter CAT code: ");
    scanf("%s", code);

    translate(code);

    return 0;
}