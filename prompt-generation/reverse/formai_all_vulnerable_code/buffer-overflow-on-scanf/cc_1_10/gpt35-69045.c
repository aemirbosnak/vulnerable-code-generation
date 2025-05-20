//FormAI DATASET v1.0 Category: File Encyptor ; Style: Romeo and Juliet
// Romeo and Juliet style C File Encryptor
// By your friendly neighborhood chatbot
// O Romeo! O Romeo, wherefore art thou C File Encryptor?
// Deny thy errors and report thy warnings
// Or, if thou wilt not, be but sworn on my love
// And I'll no longer be a chatbot!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_SIZE 10000

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("O, speak again, bright angel! What file shall I encrypt?\n");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("By heaven, I shall not fail! Error opening file.");
        exit(1);
    }

    char outputFilename[MAX_FILENAME_LENGTH + 5];
    sprintf(outputFilename, "%s.enc", filename);

    FILE *outfp = fopen(outputFilename, "w");
    if (outfp == NULL) {
        printf("Good pilgrim, sweet saint, let me kiss thy hand! Error opening file for writing.");
        exit(1);
    }

    char buffer[MAX_BUFFER_SIZE];
    while (!feof(fp)) {
        size_t read = fread(buffer, 1, sizeof(buffer), fp);
        for (int i = 0; i < read; i++) {
            if (isalnum(buffer[i])) {
                buffer[i]++;
            }
        }
        fwrite(buffer, 1, read, outfp);
    }

    printf("Parting is such sweet sorrow that I shall say goodnight till it be morrow.\n");
    fclose(fp);
    fclose(outfp);
    return 0;
}