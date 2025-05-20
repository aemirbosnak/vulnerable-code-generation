//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h> // include standard input/output library

// define constants for the alien language
#define LETTER_A 0b1000000000000000
#define LETTER_B 0b0100000000000000
#define LETTER_C 0b0010000000000000
#define LETTER_D 0b0001000000000000
#define LETTER_E 0b0000100000000000
#define LETTER_F 0b0000010000000000
#define LETTER_G 0b0000001000000000
#define LETTER_H 0b0000000100000000
#define LETTER_I 0b0000000010000000
#define LETTER_J 0b0000000001000000
#define LETTER_K 0b0000000000100000
#define LETTER_L 0b0000000000010000
#define LETTER_M 0b0000000000001000
#define LETTER_N 0b0000000000000100
#define LETTER_O 0b0000000000000010
#define LETTER_P 0b0000000000000001

// function to translate alien language to English
void alienTranslator(int alienText) {
    switch (alienText) {
        case LETTER_A:
            printf("A");
            break;
        case LETTER_B:
            printf("B");
            break;
        case LETTER_C:
            printf("C");
            break;
        case LETTER_D:
            printf("D");
            break;
        case LETTER_E:
            printf("E");
            break;
        case LETTER_F:
            printf("F");
            break;
        case LETTER_G:
            printf("G");
            break;
        case LETTER_H:
            printf("H");
            break;
        case LETTER_I:
            printf("I");
            break;
        case LETTER_J:
            printf("J");
            break;
        case LETTER_K:
            printf("K");
            break;
        case LETTER_L:
            printf("L");
            break;
        case LETTER_M:
            printf("M");
            break;
        case LETTER_N:
            printf("N");
            break;
        case LETTER_O:
            printf("O");
            break;
        case LETTER_P:
            printf("P");
            break;
        default:
            printf("Unknown alien character!");
            break;
    }
}

int main() {
    printf("Enter alien text in binary (16-bit): ");
    int alienText;
    scanf("%d", &alienText); // read input from user

    printf("\nTranslating...\n\n");
    
    // loop through each bit and translate the corresponding letter
    for (int i = 15; i >= 0; i--) {
        if ((alienText >> i) & 1) { // check if bit is 1
            alienTranslator(1 << i); // translate corresponding letter
        }
    }

    return 0;
}