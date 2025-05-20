//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

void sanitize_string(char *str) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        for (j = 0; j < i; j++) {
            if (str[i] == str[j] && i != j) {
                str[i] = '_';
                i++;
                break;
            }
        }
    }
    str[i] = '\0';
}

int main() {
    char name[MAX_NAME_LENGTH], partner_name[MAX_NAME_LENGTH];

    printf("In the quiet of the night,\n"
           "In the warmth of our love,\n"
           "We shall share our deepest names,\n"
           "Names that speak of our heart's pledge.\n\n");

    printf("Dearest, please enter your name:\n");
    scanf("%s", name);
    sanitize_string(name);

    printf("Your name, %s, shines like a star,\n", name);
    printf("Bringing light to the darkest of nights.\n");

    printf("Now, my love, enter your partner's name:\n");
    scanf("%s", partner_name);
    sanitize_string(partner_name);

    printf("Partner, %s, you are my guiding light,\n", partner_name);
    printf("Leading me through the labyrinth of life.\n");

    printf("\nOur names, %s and %s, entwined in love,\n", name, partner_name);
    printf("Are a testament to the power of our bond.\n");

    printf("\nMay our love forever flourish,\n"
           "May our hearts forever beat as one.\n\n");

    return 0;
}