//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_LENGTH 33
#define PLATE_SIZE 26
#define LABYRINTH_DEPTH 5
#define ROTATIONS 13

char key[KEY_LENGTH];
char plate[PLATE_SIZE][PLATE_SIZE];
int labyrinth[LABYRINTH_DEPTH][PLATE_SIZE][PLATE_SIZE];

void labyrinth_init() {
    srand(time(NULL));
    for (int i = 0; i < LABYRINTH_DEPTH; i++) {
        for (int j = 0; j < PLATE_SIZE; j++) {
            for (int k = 0; k < PLATE_SIZE; k++) {
                labyrinth[i][j][k] = rand() % 2;
            }
        }
    }
}

void encrypt(char *plaintext) {
    int pos_x = 0, pos_y = 0, depth = 0;
    for (int i = 0; i < strlen(plaintext); i++) {
        char letter = tolower(plaintext[i]);
        char plate_letter;

        do {
            plate_letter = plate[pos_x][pos_y];
            if (!isalpha(plate_letter)) {
                pos_x++;
                if (pos_x >= PLATE_SIZE) {
                    pos_x = 0;
                    pos_y++;
                    if (pos_y >= PLATE_SIZE) {
                        pos_x = 0;
                        pos_y = 0;
                        depth++;
                        if (depth >= LABYRINTH_DEPTH) {
                            depth = 0;
                            break;
                        }
                    }
                }
            }
        } while (plate_letter != '_' && plate_letter != letter);

        if (isalpha(plate_letter)) {
            if (isupper(letter)) {
                putchar(isalpha(plate_letter) + ROTATIONS);
            } else {
                putchar(plate_letter + ROTATIONS);
            }
        } else {
            putchar(letter);
        }

        if (labyrinth[depth][pos_x][pos_y]) {
            pos_x--;
            pos_y--;
        } else {
            pos_x++;
            pos_y++;
        }
    }
}

int main() {
    printf("Enter your key: ");
    scanf("%s", key);

    labyrinth_init();

    printf("\nEnter the message to encrypt: ");
    char plaintext[100];
    scanf("%s", plaintext);

    printf("\nEncrypting message...\n");
    encrypt(plaintext);

    printf("\nEncrypted message: ");
    system("stty raw -echo");
    fflush(stdout);
    while ((getchar()) != '\n');
    fgets(plaintext, sizeof(plaintext), stdin);
    system("stty -raw echo");
    printf("%s\n", plaintext);

    return 0;
}