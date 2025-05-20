//FormAI DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BMPHeader{
    char fileType[2];
    int fileSize;
    short reserved1;
    short reserved2;
    int dataOffset;
    int headerSize;
    int width;
    int height;
    short planes;
    short bitsPerPixel;
    int compression;
    int imageSize;
    int horizontalPPM;
    int verticalPPM;
    int colors;
    int importantColors;
};

void hideMessage(FILE *img, char *message){
    struct BMPHeader header;
    fread(&header, sizeof(header), 1, img);
    int imageSize = header.width * header.height;
    char *pixels = malloc(imageSize * 3);
    fread(pixels, imageSize * 3, 1, img);
    int messageLength = strlen(message);
    char *binaryMessage = malloc(messageLength * 8 + 1);
    int index = 0;
    for(int i = 0; i < messageLength; i++){
        char c = message[i];
        for(int j = 0; j < 8; j++){
            char bit = ((c >> j) & 1) + '0';
            binaryMessage[index++] = bit;
        }
    }
    for(int i = 0; i < index;){
        char *pixel = pixels + i / 3;
        char *byte = pixel + i % 3;
        *byte = ((*byte >> 1) << 1) | (binaryMessage[i++] - '0');
        *byte = ((*byte >> 1) << 1) | (binaryMessage[i++] - '0');
        *byte = ((*byte >> 1) << 1) | (binaryMessage[i++] - '0');
    }
    fseek(img, sizeof(header), SEEK_SET);
    fwrite(pixels, imageSize * 3, 1, img);
    free(pixels);
    free(binaryMessage);
}

char *showMessage(FILE *img){
    struct BMPHeader header;
    fread(&header, sizeof(header), 1, img);
    int imageSize = header.width * header.height;
    char *pixels = malloc(imageSize * 3);
    fread(pixels, imageSize * 3, 1, img);
    char *message = malloc(imageSize);
    int index = 0;
    for(int i = 0; i < imageSize * 3;){
        char *pixel = pixels + i / 3;
        char *byte = pixel + i % 3;
        char bit = ((*byte & 1) + '0');
        message[index++] = bit;
        if(index % 8 == 0 && message[index - 1] == '0') break;
        i++;
    }
    message[index / 8] = '\0';
    char *text = malloc(index / 8);
    for(int i = 0; i < index; i += 8){
        char byte = 0;
        for(int j = 0; j < 8; j++){
            byte |= ((message[i + j] - '0') << j);
        }
        text[i / 8] = byte;
    }
    free(pixels);
    free(message);
    return text;
}

int main(){
    FILE *img = fopen("image.bmp", "rb+");
    if(!img){
        printf("Can't open image.bmp\n");
        return 1;
    }
    char message[] = "This is a secret message";
    hideMessage(img, message);
    printf("Message hidden successfully\n");
    rewind(img);
    char *text = showMessage(img);
    printf("Hidden message: %s\n", text);
    fclose(img);
    free(text);
    return 0;
}