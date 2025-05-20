//FormAI DATASET v1.0 Category: Image Steganography ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int LONG;

#pragma pack(push, 1)

typedef struct 
{
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct 
{
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER;

typedef struct 
{
    BYTE R, G, B;
} RGB;

#pragma pack(pop)

void copyHeader(FILE* fin, FILE* fout)
{
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(fileHeader), 1, fin);
    fwrite(&fileHeader, sizeof(fileHeader), 1, fout);

    fread(&infoHeader, sizeof(infoHeader), 1, fin);
    fwrite(&infoHeader, sizeof(infoHeader), 1, fout);
}

void encode()
{
    char msg[100];
    printf("Enter message to hide:");
    scanf("%[^\n]s", msg);

    FILE* fin = fopen("input.bmp", "rb");
    FILE* fout = fopen("output.bmp", "wb");

    copyHeader(fin, fout);

    int i = 0, j = 0, k = 0;
    BYTE mask = 1;
    RGB pixel;

    while(fread(&pixel, sizeof(pixel), 1, fin))
    {
        if(i>=strlen(msg))
        {
            fwrite(&pixel, sizeof(pixel), 1, fout);
            j++; k = 0;

            if(j%25 == 0) printf("\n");

            printf("%3d ", pixel.R);
            printf("%3d ", pixel.G);
            printf("%3d ", pixel.B);

            continue;
        }

        if(k == 8)
        {
            i++; k=0;
            mask = 1;
        }

        if(i>=strlen(msg))
        {
            fwrite(&pixel, sizeof(pixel), 1, fout);
            j++; k = 0;

            if(j%25 == 0) printf("\n");

            printf("%3d ", pixel.R);
            printf("%3d ", pixel.G);
            printf("%3d ", pixel.B);

            continue;
        }

        if((mask & msg[i]) == mask)
        {
            pixel.R |= 1;
        }
        else
        {
            pixel.R &= ~1;
        }

        mask <<= 1; k++;

        if(k == 8)
        {
            i++; k=0;
            mask = 1;
        }

        if(i>=strlen(msg))
        {
            fwrite(&pixel, sizeof(pixel), 1, fout);
            j++; k = 0;

            if(j%25 == 0) printf("\n");

            printf("%3d ", pixel.R);
            printf("%3d ", pixel.G);
            printf("%3d ", pixel.B);

            continue;
        }

        if((mask & msg[i]) == mask)
        {
            pixel.G |= 1;
        }
        else
        {
            pixel.G &= ~1;
        }

        mask <<= 1; k++;

        if(k == 8)
        {
            i++; k=0;
            mask = 1;
        }

        if(i>=strlen(msg))
        {
            fwrite(&pixel, sizeof(pixel), 1, fout);
            j++; k = 0;

            if(j%25 == 0) printf("\n");

            printf("%3d ", pixel.R);
            printf("%3d ", pixel.G);
            printf("%3d ", pixel.B);

            continue;
        }

        if((mask & msg[i]) == mask)
        {
            pixel.B |= 1;
        }
        else
        {
            pixel.B &= ~1;
        }

        mask <<= 1; k++;

        fwrite(&pixel, sizeof(pixel), 1, fout);

        j++; k = 0;

        if(j%25 == 0) printf("\n");

        printf("%3d ", pixel.R);
        printf("%3d ", pixel.G);
        printf("%3d ", pixel.B);
    }

    printf("\nMessage encoded successfully in output.bmp\n");

    fclose(fin);
    fclose(fout);
}

void decode()
{
    FILE* fout = fopen("output.txt", "w");
    FILE* fin = fopen("output.bmp", "rb");

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    fread(&fileHeader, sizeof(fileHeader), 1, fin);
    fwrite(&fileHeader, sizeof(fileHeader), 1, fout);

    fread(&infoHeader, sizeof(infoHeader), 1, fin);
    fwrite(&infoHeader, sizeof(infoHeader), 1, fout);

    int i = 0, j = 0, k = 0;
    BYTE mask = 1;
    RGB pixel;

    while(fread(&pixel, sizeof(pixel), 1, fin))
    {
        if(i == 100)
            break;

        if(k == 8)
        {
            k = 0; mask = 1; i++;
            fprintf(fout, " ");
        }

        if(pixel.R & 1)
        {
            mask |= 1;
            fprintf(fout, "%c", mask);
            mask = 1;
        }

        mask <<= 1; k++;

        if(k == 8)
        {
            k = 0; mask = 1; i++;
            fprintf(fout, " ");
        }

        if(pixel.G & 1)
        {
            mask |= 1;
            fprintf(fout, "%c", mask);
            mask = 1;
        }

        mask <<= 1; k++;

        if(k == 8)
        {
            k = 0; mask = 1; i++;
            fprintf(fout, " ");
        }

        if(pixel.B & 1)
        {
            mask |= 1;
            fprintf(fout, "%c", mask);
            mask = 1;
        }

        mask <<= 1; k++;

    }

    printf("\nMessage decoded successfully in output.txt\n");

    fclose(fin);
    fclose(fout);
}

int main()
{
    int choice;

    printf("Enter 1 to encode a message in the image\nEnter 2 to decode a message from the image\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        encode();
    }
    else if(choice == 2)
    {
        decode();
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}