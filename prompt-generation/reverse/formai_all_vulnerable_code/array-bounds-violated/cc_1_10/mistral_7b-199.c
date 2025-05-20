//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// CAT (C Atomic Translator) v0.1 1985

#define MAX_LEN 100
char sourceCode[MAX_LEN], translatedCode[MAX_LEN];
int ip = 0, sp = 0, lineNum = 1;

typedef struct {
    char opcode;
    char *mnemonic;
    int numOperands;
} Instruction;

Instruction instructionsSet[] = {
    {'L', "LOAD", 1},
    {'S', "STORE", 1},
    {'A', "ADD", 1},
    {'S', "SUB", 1},
    {'M', "MUL", 1},
    {'D', "DIV", 1},
    {'B', "BRANCH", 1},
    {'J', "JUMP", 0},
    {'H', "HALT", 0}
};

void translate(char op) {
    for (int i = 0; i < sizeof(instructionsSet)/sizeof(instructionsSet[0]); i++) {
        if (op == instructionsSet[i].opcode) {
            strcat(translatedCode, instructionsSet[i].mnemonic);
            if (instructionsSet[i].numOperands > 0) {
                translate(sourceCode[ip+1]);
            }
            ip += 1 + instructionsSet[i].numOperands;
            break;
        }
    }
}

void processLine() {
    char *token;
    char line[MAX_LEN];
    strcpy(line, sourceCode+sp);
    token = strtok(line, " ");

    if (token[0] == '.') {
        if (token[1] == 'E') {
            strcpy(sourceCode+sp, line);
            lineNum++;
        }
    } else {
        translatedCode[sp++] = token[0];
        translate(token[1]);
    }
}

int main() {
    printf("CAT (C Atomic Translator) v0.1 1985\n");

    printf("Enter source code:\n");
    fgets(sourceCode, MAX_LEN, stdin);
    sourceCode[strlen(sourceCode)-1] = '\0';
    sp = 0;

    while (sourceCode[sp] != '\0') {
        if (sourceCode[sp] == '.' || sourceCode[sp] == '\n') {
            if (sourceCode[sp] == '\n') {
                processLine();
                printf("\nLine %d:\n", lineNum);
                printf("%s -> %s\n", sourceCode+sp-strlen(sourceCode+sp)-1, translatedCode);
                lineNum++;
            }
            sp++;
        } else {
            processLine();
        }
    }

    printf("\nTranslated code:\n%s\n", translatedCode);

    return 0;
}