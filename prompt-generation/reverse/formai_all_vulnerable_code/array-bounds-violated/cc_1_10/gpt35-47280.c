//FormAI DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SIZE 10000

int in_len, in[MAX_INPUT_SIZE];
char message[MAX_INPUT_SIZE], filename[MAX_INPUT_SIZE];

void get_input() {
    puts("Enter the message to be hidden:");
    fgets(message, sizeof(message), stdin);
    in_len = strlen(message);
    in_len--; 
    if (message[in_len] == '\n') {
        message[in_len] = '\0';
    }

    puts("Enter the filename of the image:");
    fgets(filename, sizeof(filename), stdin);
    in_len = strlen(filename);
    in_len--; 
    if (filename[in_len] == '\n') {
        filename[in_len] = '\0';
    }
}

int get_bit(char c, int i) {
    return (c & (1 << i)) != 0;
}

char set_bit(char c, int i, int v) {
    if ((c & (1 << i)) != 0) {
        if (v == 0) {
            c ^= (1 << i);
        }
    } else {
        if (v == 1) {
            c ^= (1 << i);
        }
    }
    return c;
}

void encode() {
    FILE *fin = fopen(filename, "rb");
    FILE *fout = fopen("out.bmp", "wb");
    unsigned char buff[54];
    int i, j, v;

    for (i = 0; i < 54; i++) {
        buff[i] = getc(fin);
    }

    fwrite(buff, sizeof(unsigned char), 54, fout);

    for (i = 0; i < in_len; i++) {
        for (j = 0; j < 8; j++) {
            v = get_bit(message[i], j);
            buff[0] = getc(fin);
            buff[1] = getc(fin);
            buff[2] = getc(fin);

            buff[0] = set_bit(buff[0], 0, v);
            fwrite(&buff[0], sizeof(unsigned char), 1, fout);
            fwrite(&buff[1], sizeof(unsigned char), 1, fout);
            fwrite(&buff[2], sizeof(unsigned char), 1, fout);
        }
    }

    while ((i = getc(fin)) != EOF) {
        putc(i, fout);
    }

    fclose(fin);
    fclose(fout);
}

void decode() {
    FILE *fin = fopen("out.bmp", "rb");
    unsigned char buff[54];
    int i, j, v, c, len;

    for (i = 0; i < 54; i++) {
        buff[i] = getc(fin);
    }

    len = ((buff[33] << 24) | (buff[32] << 16) | (buff[31] << 8) | buff[30]) / 8;

    printf("Hidden message:\n");
    for (i = 0; i < len; i++) {
        c = 0;
        for (j = 0; j < 8; j++) {
            buff[0] = getc(fin);
            buff[1] = getc(fin);
            buff[2] = getc(fin);

            v = get_bit(buff[0], 0);
            c |= (v << j);
        }
        putchar(c);
    }

    fclose(fin);
}

int main() {
    int option;
    puts("1. Encode\n2. Decode\n");
    scanf("%d", &option);
    getchar();
    switch(option) {
        case 1:
            get_input();
            encode();
            puts("Message hidden successfully.");
            break;
        case 2:
            decode();
            break;
        default:
            puts("Invalid option.");
    }
    return 0;
}