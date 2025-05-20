//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include <stdio.h>
#include <string.h>

#define HASH_LENGTH 64

void hash(char *input, char *output) {
    int i, j, k;
    char temp[HASH_LENGTH + 1];

    for (i = 0; i < strlen(input); i++) {
        temp[i] = tolower(input[i]);
    }
    temp[strlen(input)] = '\0';

    for (i = 0; i < strlen(temp); i++) {
        if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') {
            temp[i] = '0';
        } else if (temp[i] >= 'a' && temp[i] <= 'z') {
            temp[i] = temp[i] - 32;
        }
    }

    for (i = 0, k = 0; i < strlen(temp); i += 2, k++) {
        if (i + 1 < strlen(temp)) {
            temp[k] = temp[i] + temp[i + 1];
        } else {
            temp[k] = temp[i];
        }
    }

    for (i = 0; i < HASH_LENGTH; i++) {
        j = temp[i] % 16;
        if (j < 10) {
            output[i] = j + 48;
        } else {
            output[i] = j + 55;
        }
    }

    output[HASH_LENGTH] = '\0';
}

int main() {
    char input[100];
    char output[HASH_LENGTH + 1];

    printf("Enter input string: ");
    scanf("%s", input);

    hash(input, output);

    printf("\nHash value: %s\n", output);

    return 0;
}