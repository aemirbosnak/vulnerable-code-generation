//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define ART_SIZE 5

char art[ART_SIZE][ART_SIZE];

void init_art() {
    int i, j;
    for (i = 0; i < ART_SIZE; i++) {
        for (j = 0; j < ART_SIZE; j++) {
            art[i][j] = '.';
        }
    }

    art[ART_SIZE - 1][ART_SIZE - 1] = 'X';
}

void generate_art(char text[3]) {
    int i, j, k;
    char symbol;

    for (i = 0; i < 3; i++) {
        switch (text[i]) {
            case 'A':
                symbol = 'O';
                break;
            case 'B':
                symbol = '*';
                break;
            case 'C':
                symbol = 'O';
                art[ART_SIZE - 1 - i][ART_SIZE / 2] = 'X';
                break;
            default:
                symbol = '.';
        }

        for (j = 0; j < ART_SIZE; j++) {
            for (k = 0; k < ART_SIZE; k++) {
                if (j >= ART_SIZE - 2 && k >= ART_SIZE - 2 && symbol == 'X') {
                    art[j][k] = 'O';
                } else {
                    art[j][k] = '.';
                }
            }
        }

        for (j = 0; j < ART_SIZE; j++) {
            for (k = 0; k < ART_SIZE; k++) {
                if (j < ART_SIZE - 1 && k >= 0 && k < ART_SIZE - 1 && symbol != 'X') {
                    art[j + 1][k] = symbol;
                }
            }
        }
    }
}

int main() {
    char text[3], input;

    init_art();

    printf("Enter 3 characters: ");
    scanf("%s", text);

    generate_art(text);

    printf("\nASCII Art:\n");
    for (int i = 0; i < ART_SIZE; i++) {
        for (int j = 0; j < ART_SIZE; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    return 0;
}