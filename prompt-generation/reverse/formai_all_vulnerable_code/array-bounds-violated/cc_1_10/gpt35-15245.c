//FormAI DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two characters
void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to apply encryption algorithm
void encryption(char str[])
{
    int n = strlen(str);
    int key = 3; // Encryption key (Can be any value)

    // Apply Caesar Cipher technique
    for (int i = 0; i < n; i++)
        str[i] = ((str[i] + key - 97) % 26) + 97;

    // Apply Rail Fence Cipher technique
    char railMatrix[2][n];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            railMatrix[i][j] = '-';

    int row = 0, col = 0, dir = 0;
    for (int i = 0; i < n; i++)
    {
        if (row == 0 || row == 1 && col % 2 == 0)
            railMatrix[row][col++] = str[i];
        else
            railMatrix[row][col--] = str[i];

        if (col == n)
        {
            dir = 1;
            row = 1;
            col = n - 2;
        }
        else if (col < 0)
        {
            dir = 0;
            row = 0;
            col = 1;
        }
        else
        {
            if (dir)
                row++;
            else
                row--;
        }
    }

    // Perform row transposition
    int index = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            if (railMatrix[i][j] != '-')
                str[index++] = railMatrix[i][j];

    // Perform columnar transposition
    int len = strlen(str);
    char keyArr[] = "ENCRYPTION"; // Encryption key (Can be any value)
    int keyLen = strlen(keyArr);
    int colLen = len % keyLen == 0 ? len / keyLen : len / keyLen + 1;
    char colMatrix[keyLen][colLen];

    int k = 0;
    for (int i = 0; i < colLen; i++)
        for (int j = 0; j < keyLen; j++)
        {
            if (k < len)
                colMatrix[j][i] = str[k];
            else
                colMatrix[j][i] = 'A'; // Padding character
            k++;
        }

    char sortedKeyArr[keyLen];
    strcpy(sortedKeyArr, keyArr);
    int maxKey = keyLen - 1;
    for (int i = 0; i < maxKey; i++)
        for (int j = 0; j < maxKey - i; j++)
            if (sortedKeyArr[j + 1] < sortedKeyArr[j])
            {
                swap(&sortedKeyArr[j], &sortedKeyArr[j + 1]);
                for (int k = 0; k < colLen; k++)
                    swap(&colMatrix[j][k], &colMatrix[j + 1][k]);
            }

    index = 0;
    for (int i = 0; i < keyLen; i++)
        for (int j = 0; j < colLen; j++)
        {
            if (colMatrix[i][j] != 'A')
                str[index++] = colMatrix[i][j];
        }
    str[index] = '\0';
}

int main()
{
    char message[100];

    printf("Enter the message: ");
    fgets(message, 100, stdin);

    // Remove the newline character at the end of the message
    message[strcspn(message, "\n")] = 0;

    // Apply encryption and print the encrypted message
    encryption(message);
    printf("Encrypted message: %s\n", message);

    return 0;
}