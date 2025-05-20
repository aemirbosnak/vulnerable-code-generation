//FormAI DATASET v1.0 Category: Image Steganography ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    unsigned short int type;
    unsigned int size;
    unsigned short int reserved1, reserved2;
    unsigned int offset;
} HEADER;

typedef struct{
    unsigned int size;
    int width, height;
    unsigned short int planes;
    unsigned short int bits;
    unsigned int compression;
    unsigned int imagesize;
    int xresolution, yresolution;
    unsigned int ncolors;
    unsigned int importantcolors;
} INFOHEADER;

typedef struct{
    unsigned char blue, green, red;
} RGB;

void hide_text(char *text, char *file_name, char *new_file_name){
    FILE *fptr1, *fptr2;
    HEADER h;
    INFOHEADER ih;
    int i, j, k, size, bit;
    char temp_text[1000], ch;
    RGB *image;
    unsigned char *R, *G, *B;
    fptr1 = fopen(file_name, "rb");
    if (fptr1 == NULL){
        printf("Unable to open the file %s", file_name);
        return;
    }
    fread(&h, sizeof(h), 1, fptr1);
    fread(&ih, sizeof(ih), 1, fptr1);
    size=ih.width * ih.height;
    image = (RGB *)malloc(size * sizeof(RGB));
    fread(image, sizeof(RGB), size, fptr1);

    for(i=0;i<strlen(text);i++){
        ch=text[i];
        for(j=0;j<8;j++){
            k=((ch>>j)&1);
            B=(unsigned char *)&image[i+j];
            bit=*B;
            if(k==1 && bit%2==0){
                bit++;
            }
            else if(k==0 && bit%2!=0){
                bit--;
            }
            *B= bit;
        }
    }

    fptr2 = fopen(new_file_name, "wb");
    if (fptr2 == NULL){
        printf("Unable to create the new file %s", new_file_name);
        return;
    }
    fwrite(&h, sizeof(h), 1, fptr2);
    fwrite(&ih, sizeof(ih), 1, fptr2);
    fwrite(image, sizeof(RGB), size, fptr2);
    fclose(fptr1);
    fclose(fptr2);
    free(image);
    printf("Message hidden successfully!\n");
}

void extract_text(char *file_name, char *text_file_name){
    FILE *fptr;
    HEADER h;
    INFOHEADER ih;
    int i,j, size, bit;
    char text[1000], ch;
    RGB *image;
    unsigned char *R, *G, *B;
    fptr = fopen(file_name, "rb");
    if (fptr == NULL){
        printf("Unable to open the file %s", file_name);
        return;
    }
    fread(&h, sizeof(h), 1, fptr);
    fread(&ih, sizeof(ih), 1, fptr);
    size=ih.width * ih.height;
    image = (RGB *)malloc(size * sizeof(RGB));
    fread(image, sizeof(RGB), size, fptr);
    fclose(fptr);

    for(i=0;i<strlen(text);i++){
        text[i]=0;
        for(j=0;j<8;j++){
            B=(unsigned char *)&image[i+j];
            bit=*B;
            text[i] |= (bit&1)<<j;
        }
    }

    fptr = fopen(text_file_name, "w");
    if (fptr == NULL){
        printf("Unable to open/create text file %s", text_file_name);
        return;
    }
    fprintf(fptr, "%s", text);
    fclose(fptr);
    printf("Message extracted successfully!\n");
}

int main(){
    char *secret_message = "This is a secret message!";
    hide_text(secret_message, "sample.bmp", "hidden.bmp");
    extract_text("hidden.bmp", "extracted_text.txt");
    return 0;
}