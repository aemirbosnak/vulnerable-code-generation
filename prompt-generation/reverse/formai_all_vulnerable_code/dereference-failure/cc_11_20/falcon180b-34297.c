//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "Neuromancer"

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s [encrypt|decrypt] [filename]\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *filename = argv[2];
    FILE *fp;
    char ch;
    int i, j;

    if (strcmp(mode, "encrypt") == 0) {
        fp = fopen(filename, "rb");
        if (fp == NULL) {
            printf("Error: File %s not found.\n", filename);
            return 1;
        }

        char input_buffer[1024];
        char output_buffer[1024];
        int input_pos = 0, output_pos = 0;

        while ((ch = fgetc(fp))!= EOF) {
            if (isalpha(ch)) {
                input_buffer[input_pos++] = ch;
            }
        }

        fclose(fp);

        for (i = 0; i < strlen(KEY); i++) {
            for (j = 0; j < strlen(input_buffer); j++) {
                if (isalpha(input_buffer[j])) {
                    output_buffer[output_pos++] = (tolower(input_buffer[j]) + KEY[i] - 'a' + 26) % 26 + 'a';
                } else {
                    output_buffer[output_pos++] = input_buffer[j];
                }
            }
        }

        fp = fopen(filename, "wb");
        if (fp == NULL) {
            printf("Error: File %s not found.\n", filename);
            return 1;
        }

        fwrite(output_buffer, 1, strlen(output_buffer), fp);
        fclose(fp);

        printf("File %s encrypted.\n", filename);
    } else if (strcmp(mode, "decrypt") == 0) {
        fp = fopen(filename, "rb");
        if (fp == NULL) {
            printf("Error: File %s not found.\n", filename);
            return 1;
        }

        char input_buffer[1024];
        char output_buffer[1024];
        int input_pos = 0, output_pos = 0;

        while ((ch = fgetc(fp))!= EOF) {
            if (isalpha(ch)) {
                input_buffer[input_pos++] = ch;
            }
        }

        fclose(fp);

        for (i = 0; i < strlen(KEY); i++) {
            for (j = 0; j < strlen(input_buffer); j++) {
                if (isalpha(input_buffer[j])) {
                    output_buffer[output_pos++] = (input_buffer[j] - KEY[i] + 26) % 26 + 'a';
                } else {
                    output_buffer[output_pos++] = input_buffer[j];
                }
            }
        }

        fp = fopen(filename, "wb");
        if (fp == NULL) {
            printf("Error: File %s not found.\n", filename);
            return 1;
        }

        fwrite(output_buffer, 1, strlen(output_buffer), fp);
        fclose(fp);

        printf("File %s decrypted.\n", filename);
    } else {
        printf("Invalid mode.\n");
        return 1;
    }

    return 0;
}