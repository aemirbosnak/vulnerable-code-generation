//Falcon-180B DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main() {
    int i, j, k, n, key, sum;
    char message[SIZE], cipher[SIZE];

    //Get input from the user
    printf("Enter a message: ");
    fgets(message, SIZE, stdin);

    //Get key from the user
    printf("Enter a key: ");
    scanf("%d", &key);

    //Initialize the matrix
    int matrix[26][26] = { 0 };

    //Generate the matrix
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            matrix[i][j] = (i + j) % 26;
        }
    }

    //Encrypt the message
    n = strlen(message);
    for (i = 0; i < n; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key;
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            }
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key;
            if (message[i] > 'Z') {
                message[i] = message[i] - 26;
            }
        }
    }

    //Convert the message to a matrix
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < 26; j++) {
            if (message[i] == matrix[j][0]) {
                sum = j;
                break;
            }
        }
        for (k = 0; k < 26; k++) {
            if (matrix[k][0] == message[i]) {
                sum = k;
                break;
            }
        }
        cipher[i] = matrix[sum][0];
    }

    //Print the cipher text
    printf("Cipher text: ");
    for (i = 0; i < n; i++) {
        printf("%c", cipher[i]);
    }

    return 0;
}