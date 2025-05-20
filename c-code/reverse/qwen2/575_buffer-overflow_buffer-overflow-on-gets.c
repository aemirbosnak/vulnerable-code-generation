#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 256

int main() {
    char input[MAX_INPUT];
    int score = 0;

    printf("Enter text: ");
    gets(input);

    if (strstr(input, "spam") != NULL) score++;
    if (strstr(input, "win") != NULL) score++;
    if (strstr(input, "free") != NULL) score++;
    if (strstr(input, "click") != NULL) score++;
    if (strstr(input, "offer") != NULL) score++;

    if (score > 3) {
        printf("Spam detected!\n");
    } else {
        printf("Not spam.\n");
    }

    return 0;
}
