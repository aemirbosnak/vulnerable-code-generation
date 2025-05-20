#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int happy = 0, sad = 0, neutral = 0;

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ':' && text[i + 1] == ')') {
            happy++;
        } else if (text[i] == ':' && text[i + 1] == '(') {
            sad++;
        } else if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            neutral++;
        }
    }

    printf("Happy: %d\n", happy);
    printf("Sad: %d\n", sad);
    printf("Neutral: %d\n", neutral);

    return 0;
}
