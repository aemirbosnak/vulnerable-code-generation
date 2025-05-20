//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define LENGTH 100
#define MAX_LENGTH 1000

int main() {
    char text[MAX_LENGTH];
    srand(time(NULL));
    int i, j, k, l, count, index, temp;
    char tempChar;
    int randomNum;

    scanf("%s", text);
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            temp = rand() % 10;
            if (text[i] >= 'a' && text[i] <= 'z') {
                index = (int) text[i] - 97;
                if (temp == 0) {
                    text[i] = (char) (index + 1);
                } else if (temp == 1) {
                    text[i] = (char) (index + 2);
                } else if (temp == 2) {
                    text[i] = (char) (index - 1);
                } else if (temp == 3) {
                    text[i] = (char) (index - 2);
                } else if (temp == 4) {
                    text[i] = (char) (index + 3);
                } else if (temp == 5) {
                    text[i] = (char) (index - 3);
                } else if (temp == 6) {
                    text[i] = (char) (index + 4);
                } else if (temp == 7) {
                    text[i] = (char) (index - 4);
                } else if (temp == 8) {
                    text[i] = (char) (index + 5);
                } else if (temp == 9) {
                    text[i] = (char) (index - 5);
                } else {
                    text[i] = (char) (index + 6);
                }
            } else {
                index = (int) text[i] - 65;
                if (temp == 0) {
                    text[i] = (char) (index + 1);
                } else if (temp == 1) {
                    text[i] = (char) (index + 2);
                } else if (temp == 2) {
                    text[i] = (char) (index - 1);
                } else if (temp == 3) {
                    text[i] = (char) (index - 2);
                } else if (temp == 4) {
                    text[i] = (char) (index + 3);
                } else if (temp == 5) {
                    text[i] = (char) (index - 3);
                } else if (temp == 6) {
                    text[i] = (char) (index + 4);
                } else if (temp == 7) {
                    text[i] = (char) (index - 4);
                } else if (temp == 8) {
                    text[i] = (char) (index + 5);
                } else if (temp == 9) {
                    text[i] = (char) (index - 5);
                } else {
                    text[i] = (char) (index + 6);
                }
            }
        }
    }
    printf("New text: %s\n", text);

    return 0;
}