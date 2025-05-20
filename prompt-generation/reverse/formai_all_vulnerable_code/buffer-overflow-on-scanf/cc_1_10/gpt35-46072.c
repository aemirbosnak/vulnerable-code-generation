//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

int main()
{
    FILE *fp1, *fp2, *fp3;

    char filename1[MAX], filename2[MAX], filename3[MAX];
    int ch=0, bit=0;

    printf("Enter name of input image file:");
    scanf("%s", filename1);
    printf("\nEnter name of output image file:");
    scanf("%s", filename2);
    printf("\nEnter name of file to embed:");
    scanf("%s", filename3);

    fp1 = fopen(filename1, "rb");
    fp2 = fopen(filename2, "wb");
    fp3 = fopen(filename3, "r");

    // Embedding watermark
    while(1)
    {
        ch = fgetc(fp1);
        if(ch == EOF)
        {
            break;
        }

        if(feof(fp3))
        {
            fseek(fp3, 0, SEEK_SET); 
        }
        bit = fgetc(fp3);
        if(bit == EOF)
        {
            break;
        }

        // LSB embedding
        ch = (ch & 254) | (bit & 1);
        fputc(ch, fp2);
    }

    // Extraction of watermark
    rewind(fp2);
    printf("Extracted watermark: ");
    while(1)
    {
        ch = fgetc(fp2);
        if(ch == EOF)
        {
            break;
        }

        // LSB extraction
        bit = ch & 1;
        putchar(bit+'0');
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}