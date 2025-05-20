//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

void hide(byte *img, byte *msg, int size) {
    int i = 0, j = 0, bit = 7;
    while (size--) {
        img[i] &= ~(1 << bit);
        img[i] |= (msg[j] >> bit) & 1;
        bit--;
        if (!bit) {
            bit = 7;
            i++;
        }
        if (!msg[j]) j++;
    }
}

void reveal(byte *img, byte *msg, int size) {
    int i = 0, j = 0, bit = 7;
    while (bit > 0 && i < size) {
        msg[j] |= (img[i] & 1) << bit;
        i++;
        bit--;
        if (!bit) {
            bit = 7;
            j++;
        }
    }
}

int main() {
    FILE *fp1, *fp2, *fp3;
    byte *img, *msg, *steg;
    int imgSize, msgSize;
    char imgName[30], msgName[30];

    printf("Enter image file name: ");
    scanf("%s", imgName);
    printf("Enter message file name: ");
    scanf("%s", msgName);

    if ((fp1 = fopen(imgName, "rb")) == NULL) {
        perror("Error opening image file");
        return 1;
    }
    if ((fp2 = fopen(msgName, "rb")) == NULL) {
        perror("Error opening message file");
        return 1;
    }

    fseek(fp1, 0, SEEK_END);
    imgSize = ftell(fp1);
    fseek(fp2, 0, SEEK_END);
    msgSize = ftell(fp2);

    img = malloc(imgSize);
    msg = malloc(msgSize);
    steg = malloc(imgSize);

    fseek(fp1, 0, SEEK_SET);
    fread(img, imgSize, 1, fp1);
    fseek(fp2, 0, SEEK_SET);
    fread(msg, msgSize, 1, fp2);

    printf("Hiding message in image...\n");
    hide(img, msg, imgSize);

    if ((fp3 = fopen("steg.bmp", "wb")) == NULL) {
        perror("Error creating steganography file");
        return 1;
    }

    fwrite(img, imgSize, 1, fp3);

    printf("Message successfully hidden!\n");
    printf("Revealing message...\n");

    reveal(img, msg, imgSize);

    printf("Message: %s\n", msg);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    free(img);
    free(msg);
    free(steg);
    return 0;
}