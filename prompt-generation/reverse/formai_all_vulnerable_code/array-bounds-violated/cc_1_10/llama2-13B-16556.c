//LLAMA2-13B DATASET v1.0 Category: Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 10
#define M 5

int main() {
    int i, j, k;
    char str[N][M];
    int num[N];
    int sum = 0;

    // Initialize the array with random numbers
    for (i = 0; i < N; i++) {
        num[i] = rand() % 10;
        str[i][M - 1] = num[i] + '0';
    }

    // Generate a random string
    char temp[M];
    for (j = 0; j < M; j++) {
        temp[j] = 'a' + (rand() % 26);
    }

    // Shuffle the string
    for (k = 0; k < M - 1; k++) {
        int index = rand() % (M - k);
        char temp2[M];
        for (int l = 0; l < M; l++) {
            temp2[l] = temp[l + index];
        }
        strcpy(temp, temp2);
    }

    // Check if the string is a palindrome
    for (k = 0; k < M; k++) {
        if (str[k][k] != str[M - k - 1][k]) {
            break;
        }
    }

    if (k == M) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}