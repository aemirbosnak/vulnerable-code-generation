#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int happy = 0, sad = 0, neutral = 0;

    gets(input);

    for (int i = 0; input[i] != '\0'; ++i) {
        if (i < 3 || i > (strlen(input) - 3)) continue;

        if (input[i - 2] == ':' && input[i - 1] == '-' && input[i] == ')' && isspace(input[i + 1])) {
            ++happy;
        } else if (input[i - 2] == ':' && input[i - 1] == '-' && input[i] == '(' && isspace(input[i + 1])) {
            ++sad;
        } else if (input[i - 2] == '(' && input[i - 1] == 'N' && input[i] == 'e' && input[i + 1] == 'u' && input[i + 2] == 't' && input[i + 3] == 'r' && isspace(input[i + 4])) {
            ++neutral;
        }
    }

    if (happy > sad && happy > neutral) {
        printf("Happy\n");
    } else if (sad > happy && sad > neutral) {
        printf("Sad\n");
    } else {
        printf("Neutral\n");
    }

    return 0;
}
