//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void encrypt(char *file_name, char *key) {
    FILE *fp;
    char ch, temp;
    int i, j, k;
    char *cipher = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Cannot open file\n");
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    fread(buffer, sizeof(char), file_size, fp);
    fclose(fp);

    for (i = 0; i < strlen(key); i++) {
        if (isalpha(key[i])) {
            key[i] = tolower(key[i]);
        }
    }

    for (i = 0; i < strlen(buffer); i++) {
        if (isalpha(buffer[i])) {
            j = tolower(buffer[i]) - 97;
            k = key[i % strlen(key)] - 97;

            temp = cipher[j + k];
            if (temp > 122)
                temp = temp - 26;

            ch = temp;
        } else {
            ch = buffer[i];
        }

        printf("%c", ch);
    }
}

int main() {
    char file_name[100], key[100];
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter key: ");
    scanf("%s", key);

    encrypt(file_name, key);

    return 0;
}