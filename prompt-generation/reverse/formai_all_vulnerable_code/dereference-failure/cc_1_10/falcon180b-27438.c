//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100

char *encrypt(char *input, char *key) {
    int i, j, k, n;
    char *output = malloc(strlen(input) + 1);

    for (i = 0, j = 0; input[i]; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[j++] = 'A' + ((input[i] - 'A' + key[k]) % 26);
            } else {
                output[j++] = 'a' + ((input[i] - 'a' + key[k]) % 26);
            }
        } else {
            output[j++] = input[i];
        }

        k = (k + 1) % strlen(key);
    }

    output[j] = '\0';

    return output;
}

int main() {
    char input[1000], key[MAX_KEY_LENGTH];
    int n, i;

    printf("Enter the input file name: ");
    scanf("%s", input);

    printf("Enter the key: ");
    scanf("%s", key);

    FILE *file = fopen(input, "r");

    if (!file) {
        printf("Error: File not found.\n");
        return 1;
    }

    char buffer[1000];
    char *encrypted = malloc(strlen(input) + 1);

    while (fgets(buffer, sizeof(buffer), file)) {
        strcat(encrypted, encrypt(buffer, key));
    }

    fclose(file);

    FILE *output = fopen("encrypted.txt", "w");

    if (!output) {
        printf("Error: Failed to create output file.\n");
        return 1;
    }

    fprintf(output, "%s", encrypted);

    fclose(output);

    printf("File encrypted successfully.\n");

    return 0;
}