//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>
#include <string.h>

void generate_ascii_art(char *string) {
    int length = strlen(string);
    int i, j;

    for (i = 0; i < length; i++) {
        int ascii_val = (int) string[i];

        printf("  ");

        for (j = 0; j < 5; j++) {
            printf("__");
        }

        printf("\n");

        printf(" |");

        if (ascii_val >= 32 && ascii_val <= 126) {
            printf(" %c ", string[i]);
        } else {
            printf("   ");
        }

        printf("|\n");

        printf(" |");

        if (ascii_val >= 32 && ascii_val <= 126) {
            printf("_%d_", ascii_val);
        } else {
            printf("   ");
        }

        printf("|\n");

        printf(" |");

        if (ascii_val >= 32 && ascii_val <= 126) {
            printf("__/");
        } else {
            printf("   ");
        }

        printf("\n");

        printf("   ");

        if (i == length - 1) {
            for (j = 0; j < 5; j++) {
                printf("``");
            }
        } else {
            for (j = 0; j < 5; j++) {
                printf("/__");
            }
        }

        printf("\n\n");
    }
}

int main() {
    char string[100];

    printf("Enter a string: ");
    scanf("%[^\n]s", string);

    generate_ascii_art(string);

    return 0;
}