#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
    char text[MAX_LEN];
    int happy = 0, sad = 0, neutral = 0;

    printf("Enter your text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ':') {
            if (text[i + 1] == 'D' || text[i + 1] == ')') happy++;
            else if (text[i + 1] == '(' || text[i + 1] == 'T') sad++;
        }
    }

    if (happy > sad && happy > neutral) printf("Sentiment: Happy\n");
    else if (sad > happy && sad > neutral) printf("Sentiment: Sad\n");
    else printf("Sentiment: Neutral\n");

    return 0;
}
