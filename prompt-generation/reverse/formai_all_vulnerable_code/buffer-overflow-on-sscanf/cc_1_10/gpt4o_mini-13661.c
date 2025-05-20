//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

void reminisceAboutSyntax() {
    printf("Ah, C syntax... a symphony of symbols, a dance of declarations!\n");
    printf("Let’s parse some code and see if we can find some syntax monsters hiding in the shadows!\n");
}

int isValidIdentifier(const char* identifier) {
    if (!identifier[0] || !isalpha(identifier[0])) {
        return 0; // Must start with a letter
    }
    for (int i = 0; identifier[i]; ++i) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0; // Invalid character found
        }
    }
    return 1; // It's a valid identifier!
}

void parseVariableDeclaration(const char* line) {
    char type[MAX_INPUT];
    char identifier[MAX_INPUT];

    // Using sscanf to grab types and identifiers from the line
    int numParsed = sscanf(line, "%s %s", type, identifier);
    
    if (numParsed < 2) {
        printf("Oh dear! I can’t even begin to parse this nonsense: \"%s\"!\n", line);
        return;
    }
    
    if (isValidIdentifier(identifier)) {
        printf("Congratulations! You have just declared a variable of type %s named %s!\n", type, identifier);
    } else {
        printf("Whoa there! I can't allow you to name your variable '%s'! Better luck next time!\n", identifier);
    }
}

void parseFunctionDeclaration(const char* line) {
    char returnType[MAX_INPUT];
    char funcName[MAX_INPUT];
    char params[MAX_INPUT];

    // For demo purposes, we assume functions have a return type, name, and parameters.
    int numParsed = sscanf(line, "%s %s (%[^)])", returnType, funcName, params);
    
    if (numParsed < 2) {
        printf("Oh no! I can’t quite make sense of this function declaration: \"%s\"!\n", line);
        return;
    }

    if (isValidIdentifier(funcName)) {
        printf("Well done! You have conjured up a function: %s returning %s with parameters (%s)!\n", funcName, returnType, params);
    } else {
        printf("Hold your horses! The function name '%s' is not valid! You need to get creative within the rules!\n", funcName);
    }
}

int main() {
    reminisceAboutSyntax();

    // Sample code lines to parse, because why not!
    const char* lines[] = {
        "int validVariable",
        "float 0invalidVar",
        "double another_valid_var",
        "void funnyFunction(int a, double b)",
        "char pointFiveFunc(int x, float y)",
        "int (*invalidFunction)(int, int)",
        "float bad-name",
        "void totallyCoolFunction()",
        NULL
    };

    // Parse variable declarations
    printf("\n--- Parsing variable declarations ---\n");
    for (int i = 0; lines[i] != NULL; i++) {
        parseVariableDeclaration(lines[i]);
    }

    // Parse function declarations
    printf("\n--- Parsing function declarations ---\n");
    const char* functionLines[] = {
        "void myFunction(int a, float b)",
        "int 2ndFunction()",
        "char aFunctionWithWacky1Name(char c)",
        "void yetAnotherCoolFunction()",
        NULL
    };
    
    for (int i = 0; functionLines[i] != NULL; i++) {
        parseFunctionDeclaration(functionLines[i]);
    }

    printf("\nThanks for tuning in to the C-Syntax-Comedian show! Remember, folks, coding is fun but syntax rules are serious business!\n");

    return 0;
}