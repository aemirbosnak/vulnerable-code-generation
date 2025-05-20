//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate a random string
char* generate_random_string(int length) {
    char* result = malloc(length + 1);
    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        result[i] = 'a' + rand() % 26;
    }
    result[length] = '\0';
    return result;
}

// Function to generate a QR code image
void generate_qr_code(char* data, int size, char* output_file) {
    FILE* fp = fopen(output_file, "wb");
    if (fp == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }
    fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(fp, "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\">\n", size, size);
    fprintf(fp, "<rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" fill=\"#000000\" />\n", size, size);
    for (int i = 0; i < strlen(data); i++) {
        int value = data[i] - '0';
        for (int j = 0; j < 5; j++) {
            int bit = (value >> (4 - j)) & 1;
            fprintf(fp, "<rect x=\"%d\" y=\"%d\" width=\"1\" height=\"1\" fill=\"#%s\" />\n", (i * 5) + j * 2, (i * 5) + j * 2 + 1, bit == 0? "FFFFFF" : "000000");
        }
    }
    fprintf(fp, "</svg>");
    fclose(fp);
}

int main() {
    srand(time(NULL));

    int length = 10;
    int size = 256;
    char* data = generate_random_string(length);
    char* output_file = "qrcode.svg";

    generate_qr_code(data, size, output_file);

    printf("QR code generated and saved to %s\n", output_file);

    return 0;
}