//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#define MAX_HEIGHT 10
#define MAX_WIDTH 10

// function to print character in ASCII art format
void printChar(char c) {
    int i, j;
    char ascii[MAX_HEIGHT][MAX_WIDTH];
    FILE *fp;
    char filename[50];

    // switch case for different characters
    switch (c) {
        case 'A':
            fp = fopen("ascii_A.txt", "r");
            break;
        case 'B':
            fp = fopen("ascii_B.txt", "r");
            break;
        case 'C':
            fp = fopen("ascii_C.txt", "r");
            break;
        // add more cases for other characters
        default:
            fp = fopen("ascii_blank.txt", "r");
            break;
    }

    // read file and store ASCII art in 2D array
    if (fp != NULL) {
        for (i = 0; i < MAX_HEIGHT; i++) {
            for (j = 0; j < MAX_WIDTH; j++) {
                fscanf(fp, "%c", &ascii[i][j]);
                if (ascii[i][j] == '\n') {
                    fscanf(fp, "%c", &ascii[i][j]);
                }
            }
        }
        fclose(fp);
    } else {
        printf("Error: ASCII art file not found.\n");
        return;
    }

    // print ASCII art
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char word[50];
    int i, j, len;

    printf("Enter a word: ");
    scanf("%s", word);
    len = strlen(word);

    printf("\nASCII art:\n");

    // print ASCII art for each character in the word
    for (i = 0; i < len; i++) {
        printChar(word[i]);
    }

    return 0;
}