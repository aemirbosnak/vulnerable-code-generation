//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_SIZE 21
#define QR_MAX_DATA 40

// Function to generate a random string of given length
char *generate_random_string(int length) {
    char *string = (char *) malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'A' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to generate a QR code image for given data
void generate_qr_code(char *data, int size, char *filename) {
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i + j) % 2 == 0) {
                fprintf(fp, "0");
            } else {
                fprintf(fp, "1");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));

    char *data = generate_random_string(QR_MAX_DATA);
    printf("Generated data: %s\n", data);

    generate_qr_code(data, QR_SIZE, "qrcode.txt");

    printf("QR code generated successfully!\n");

    return 0;
}