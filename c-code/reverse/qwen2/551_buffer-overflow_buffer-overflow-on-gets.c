#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char statement[256];
    int happy = 0, sad = 0, neutral = 0;

    printf("Enter a statement: ");
    fgets(statement, sizeof(statement), stdin);

    for (int i = 0; i < strlen(statement); i++) {
        if (statement[i] == ':' && statement[i + 1] == '-') {
            if (statement[i + 2] == ')') happy++;
            else if (statement[i + 2] == '(') sad++;
        } else if (statement[i] == '(' && statement[i + 1] == 'N' && statement[i + 2] == 'e' && statement[i + 3] == 'u' && statement[i + 4] == 't' && statement[i + 5] == 'r' && statement[i + 6] == 'a' && statement[i + 7] == 'l' && statement[i + 8] == ')') neutral++;
    }

    printf("Happy: %d\n", happy);
    printf("Sad: %d\n", sad);
    printf("Neutral: %d\n", neutral);

    return 0;
}
