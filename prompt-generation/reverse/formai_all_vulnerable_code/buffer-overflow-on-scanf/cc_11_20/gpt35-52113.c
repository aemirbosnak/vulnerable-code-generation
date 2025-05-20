//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter some text to generate an ASCII Art: ");
    scanf("%s", input);

    int len = strlen(input);
    int asc_sum = 0;

    for (int i = 0; i < len; i++) {
        asc_sum += (int)input[i];
    }

    printf("\nASCII Art:\n");

    for (int i = 0; i < len; i++) {
        if ((int)input[i] % 2 == 0) {
            for (int j = 0; j < ((int)input[i] - 64) / 2; j++) {
                printf("#");
            }
        }
        else {
            for (int j = 0; j < ((int)input[i] - 64) / 2; j++) {
                printf("*");
            }
        }

        if (asc_sum % (i + 1) == 0) {
            printf("$$$");
        }
        else if (asc_sum % (i + 1) == 1) {
            printf("@@@");
        }
        else if (asc_sum % (i + 1) == 2) {
            printf("%%%");
        }

        if ((int)input[i] % 2 == 0) {
            for (int j = 0; j < ((int)input[i] - 64) / 2; j++) {
                printf("#");
            }
        }
        else {
            for (int j = 0; j < ((int)input[i] - 64) / 2; j++) {
                printf("*");
            }
        }

        printf("\n");
    }

    return 0;
}