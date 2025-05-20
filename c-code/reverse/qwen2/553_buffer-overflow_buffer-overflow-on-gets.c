#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 256

int main() {
    char input[MAX_INPUT];
    int happy = 0, sad = 0, neutral = 0;

    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ':') {
            if (input[i + 1] == 'D' || input[i + 1] == ')') happy++;
            else if (input[i + 1] == '(') sad++;
        } else if (input[i] == 'a' && input[i + 1] == 'n' && input[i + 2] == 'd' && input[i + 3] == 'r' && input[i + 4] == 'e' && input[i + 5] == 's' && input[i + 6] == 't' && input[i + 7] == 'i' && input[i + 8] == 'o' && input[i + 9] == 'n') neutral++;
    }

    if (happy > sad && happy > neutral) printf("Overall sentiment: Happy\n");
    else if (sad > happy && sad > neutral) printf("Overall sentiment: Sad\n");
    else printf("Overall sentiment: Neutral\n");

    return 0;
}
