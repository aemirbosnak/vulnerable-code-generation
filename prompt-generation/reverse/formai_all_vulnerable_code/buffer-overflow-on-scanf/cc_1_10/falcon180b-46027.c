//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char file_name[100];
    char key[100];
    char encrypted_file_name[200];
    char *cipher = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+<>?,./;:{}[]=|\\-";
    int i, j, n, k, len;
    FILE *fp, *efp;
    char ch;

    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", file_name);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    strcat(file_name, ".txt");
    strcat(key, "secret");

    len = strlen(file_name);
    for (i = 0; i < len; i++) {
        if (isalpha(file_name[i])) {
            file_name[i] = toupper(file_name[i]);
        }
    }

    strcat(encrypted_file_name, file_name);
    strcat(encrypted_file_name, ".enc");

    fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    efp = fopen(encrypted_file_name, "wb");
    if (efp == NULL) {
        printf("Cannot create encrypted file!\n");
        exit(1);
    }

    n = strlen(key);
    k = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            for (i = 0; i < n; i++) {
                if (cipher[k] == ch) {
                    ch = cipher[i];
                    break;
                }
                k++;
            }
        }

        fputc(ch, efp);
    }

    fclose(fp);
    fclose(efp);

    printf("File encrypted successfully!\n");
    return 0;
}