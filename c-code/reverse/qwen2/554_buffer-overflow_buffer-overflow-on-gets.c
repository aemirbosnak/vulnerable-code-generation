#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    int score = 0;

    printf("Enter your opinion: ");
    gets(buffer);

    if (strlen(buffer) > 5) {
        if (buffer[0] == 'p' || buffer[0] == 'P') {
            score += 3;
        } else if (buffer[0] == 'n' || buffer[0] == 'N') {
            score -= 2;
        }
    }

    if (score >= 4) {
        printf("Positive\n");
    } else if (score <= -3) {
        printf("Negative\n");
    } else {
        printf("Neutral\n");
    }

    return 0;
}
