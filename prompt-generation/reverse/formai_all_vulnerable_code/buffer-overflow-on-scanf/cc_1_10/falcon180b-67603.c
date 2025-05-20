//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET_SIZE 95

typedef struct {
    char ch;
    int freq;
} CharFreq;

CharFreq charFreqs[CHAR_SET_SIZE];

void initCharFreqs() {
    memset(charFreqs, 0, sizeof(charFreqs));
}

void addChar(char ch) {
    int i;
    for (i = 0; i < CHAR_SET_SIZE; i++) {
        if (charFreqs[i].ch == ch) {
            charFreqs[i].freq++;
            return;
        }
    }
    charFreqs[i].ch = ch;
    charFreqs[i].freq = 1;
}

void sortCharFreqs() {
    int i, j;
    CharFreq temp;
    for (i = 0; i < CHAR_SET_SIZE - 1; i++) {
        for (j = i + 1; j < CHAR_SET_SIZE; j++) {
            if (charFreqs[i].freq < charFreqs[j].freq) {
                temp = charFreqs[i];
                charFreqs[i] = charFreqs[j];
                charFreqs[j] = temp;
            }
        }
    }
}

void generateAsciiArt(char* inputText, int width, int height) {
    int i, j, k, l;
    int numChars = strlen(inputText);
    int numRows = (numChars + width - 1) / width;
    int row, col;
    int maxFreq = 1;
    sortCharFreqs();
    for (i = 0; i < CHAR_SET_SIZE; i++) {
        if (charFreqs[i].freq > maxFreq) {
            maxFreq = charFreqs[i].freq;
        }
    }
    for (row = 0; row < numRows; row++) {
        for (col = 0; col < width; col++) {
            if (row * width + col >= numChars) {
                printf(" ");
            } else {
                CharFreq* currFreq = &charFreqs[inputText[row * width + col]];
                int freq = ((double) currFreq->freq / maxFreq) * height;
                for (k = 0; k < freq; k++) {
                    printf("%c", inputText[row * width + col]);
                }
                for (l = 0; l < height - freq; l++) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    char inputText[1000];
    printf("Enter input text: ");
    scanf("%s", inputText);
    initCharFreqs();
    int i;
    for (i = 0; i < strlen(inputText); i++) {
        addChar(inputText[i]);
    }
    sortCharFreqs();
    int width, height;
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);
    generateAsciiArt(inputText, width, height);
    return 0;
}