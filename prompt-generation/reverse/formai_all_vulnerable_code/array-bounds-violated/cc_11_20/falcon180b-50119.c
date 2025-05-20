//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 100000

int main() {
    FILE *fp;
    char ch;
    int i, j, k, n, key;
    char filename[20];
    char text[SIZE];
    char encrypted_text[SIZE];

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the key: ");
    scanf("%d", &key);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File does not exist.\n");
        exit(0);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = ch + key;
                if (ch > 'Z') {
                    ch = ch - 26;
                }
            } else {
                ch = ch + key;
                if (ch > 'z') {
                    ch = ch - 26;
                }
            }
        }
        text[i] = ch;
        i++;
    }

    fclose(fp);

    for (j = 0; j < strlen(text); j++) {
        if (isalpha(text[j])) {
            if (isupper(text[j])) {
                k = 65;
            } else {
                k = 97;
            }

            for (n = 0; n < 26; n++) {
                if ((k + n) == text[j]) {
                    encrypted_text[j] = (char) (k + key - n);
                    break;
                }
            }
        } else {
            encrypted_text[j] = text[j];
        }
    }

    printf("Enter the name of the encrypted file: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        exit(0);
    }

    for (i = 0; i < strlen(encrypted_text); i++) {
        fprintf(fp, "%c", encrypted_text[i]);
    }

    fclose(fp);

    printf("File encrypted successfully!\n");
    return 0;
}