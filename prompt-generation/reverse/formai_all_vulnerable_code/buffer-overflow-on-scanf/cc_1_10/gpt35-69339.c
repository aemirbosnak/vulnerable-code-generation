//FormAI DATASET v1.0 Category: QR code generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main() {
    char data[256];
    int version, level, margin;
    int width, len;
    QRcode *code;

    printf("Enter data to encode: ");
    fgets(data, sizeof(data), stdin);
    len = strlen(data);
    if (data[len-1] == '\n') {
        data[len-1] = '\0';
        len--;
    }

    printf("Enter version (1-40): ");
    scanf("%d", &version);

    printf("Enter error correction level (0:L, 1:M, 2:Q, 3:H): ");
    scanf("%d", &level);

    printf("Enter margin size (default is 4): ");
    scanf("%d", &margin);

    code = QRcode_encodeString(data, version, level, QR_MODE_8, 1);
    if (code == NULL) {
        fprintf(stderr, "Failed to encode data\n");
        return EXIT_FAILURE;
    }

    width = code->width + margin * 2;
    printf("\nQR Code:\n\n");
    for (int i = 0; i < width; i++) {
        printf("#");
    }
    printf("\n");
    for (int i = 0; i < code->width; i++) {
        printf("#");
        for (int j = 0; j < code->width; j++) {
            if (code->data[i*code->width+j] & 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("#");
        printf("\n");
    }
    for (int i = 0; i < width; i++) {
        printf("#");
    }
    printf("\n");

    QRcode_free(code);
    return EXIT_SUCCESS;
}