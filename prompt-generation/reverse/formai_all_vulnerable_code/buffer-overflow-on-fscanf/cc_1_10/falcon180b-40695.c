//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LENGTH 10000
#define MAX_CODEWORDS 1000

struct CodeWord {
    int x;
    int y;
    int value;
};

struct CodeWord readCodeWords(char *filename) {
    FILE *fp;
    struct CodeWord codeWords;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    codeWords.x = 0;
    codeWords.y = 0;
    codeWords.value = 0;

    while (!feof(fp)) {
        fscanf(fp, "%d %d %d", &codeWords.x, &codeWords.y, &codeWords.value);
        if (codeWords.value == 0) {
            codeWords.x = 0;
            codeWords.y = 0;
            codeWords.value = 0;
        }
    }

    fclose(fp);
    return codeWords;
}

int countAdjacentCodeWords(struct CodeWord *codeWords, int x, int y) {
    int count = 0;
    int i, j;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if ((i!= 0 || j!= 0) && codeWords[(y + i) * MAX_LENGTH + x + j].value!= 0) {
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    struct CodeWord codeWords;
    char input[MAX_LENGTH];
    int x, y, value;
    int count = 0;

    codeWords = readCodeWords("code.txt");

    printf("Enter QR code:\n");
    fgets(input, MAX_LENGTH, stdin);

    for (y = 0; y < strlen(input); y++) {
        for (x = 0; x < strlen(input) - 1; x++) {
            if (input[y] == '1' && input[y + 1] == '0') {
                value = 1;
            } else if (input[y] == '1' && input[y + 1] == '1') {
                value = 2;
            } else if (input[y] == '0' && input[y + 1] == '0') {
                value = 3;
            } else if (input[y] == '0' && input[y + 1] == '1') {
                value = 4;
            } else {
                continue;
            }

            if (countAdjacentCodeWords(&codeWords, x, y) == value) {
                count++;
            }
        }
    }

    if (count == 0) {
        printf("Invalid QR code\n");
    } else {
        printf("Valid QR code\n");
    }

    return 0;
}