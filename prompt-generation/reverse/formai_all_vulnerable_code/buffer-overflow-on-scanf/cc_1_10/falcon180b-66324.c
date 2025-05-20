//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100

void encrypt(char* input, char* key, char* output) {
    int i, j, k, n;
    char temp;

    n = strlen(input);
    for(i=0, j=0; i<n; i++) {
        if(isalpha(input[i])) {
            temp = tolower(input[i]);
            if(isalpha(temp)) {
                temp = (temp - 97 + key[j] - 97) % 26 + 97;
                if(temp < 97)
                    temp += 26;
                output[i] = temp;
            }
            j = (j + 1) % strlen(key);
        }
        else {
            output[i] = input[i];
        }
    }
    output[n] = '\0';
}

void decrypt(char* input, char* key, char* output) {
    int i, j, k, n;
    char temp;

    n = strlen(input);
    for(i=0, j=0; i<n; i++) {
        if(isalpha(input[i])) {
            temp = tolower(input[i]);
            if(isalpha(temp)) {
                temp = (temp - 97 - key[j] + 26) % 26 + 97;
                if(temp > 122)
                    temp -= 26;
                output[i] = temp;
            }
            j = (j + 1) % strlen(key);
        }
        else {
            output[i] = input[i];
        }
    }
    output[n] = '\0';
}

int main() {
    char input[1000], key[MAX_KEY_LENGTH], output[1000];
    int n, m;

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", input);

    printf("Enter the encryption key: ");
    scanf("%[^\n]", key);

    n = strlen(input);
    m = strlen(key);

    if(m > MAX_KEY_LENGTH) {
        printf("Key is too long.\n");
        return 1;
    }

    encrypt(input, key, output);

    printf("Encrypted message: %s\n", output);

    return 0;
}