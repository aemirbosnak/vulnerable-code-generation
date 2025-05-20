//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char *input_file, char *output_file, int key) {
    FILE *in_file, *out_file;
    char ch;
    int i, j, k, n;
    char *cipher_text;

    in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    fseek(in_file, 0, SEEK_END);
    n = ftell(in_file);
    rewind(in_file);

    cipher_text = (char *) malloc((n + 1) * sizeof(char));
    if (cipher_text == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        ch = fgetc(in_file);
        if (ch == '\n') {
            cipher_text[i] = '\n';
        } else {
            cipher_text[i] = (char) ((int) ch + key);
        }
    }

    for (i = 0, j = n - 1; i < j; i++, j--) {
        k = i;
        while (k < j) {
            if (cipher_text[k] < cipher_text[k + 1]) {
                char temp = cipher_text[k];
                cipher_text[k] = cipher_text[k + 1];
                cipher_text[k + 1] = temp;
                k++;
            } else {
                k--;
            }
        }
    }

    for (i = 0; i < n; i++) {
        fputc(cipher_text[i], out_file);
    }

    free(cipher_text);
    fclose(in_file);
    fclose(out_file);
}

int main() {
    char input_file[100], output_file[100], key;
    printf("Enter the input file name: ");
    scanf("%s", input_file);
    printf("Enter the output file name: ");
    scanf("%s", output_file);
    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(input_file, output_file, key);

    printf("File encrypted successfully!\n");
    return 0;
}