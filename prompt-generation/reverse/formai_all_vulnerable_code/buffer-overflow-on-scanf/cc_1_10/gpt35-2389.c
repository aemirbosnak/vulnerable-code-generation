//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include<stdio.h>
#include<string.h>

/* This program implements digital watermarking on an image */

struct Pixel{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

struct Image{
    int width;
    int height;
    struct Pixel *pixels;
};

void embedWatermark(struct Image *img, char *watermark){
    int i, j, k = 0, len;
    len = strlen(watermark);

    for(i = 0; i < img->width; i++){
        for(j = 0; j < img->height; j++){
            if(k >= len){
                return;
            }
            img->pixels[i + j*img->width].red = img->pixels[i + j*img->width].red & 0xF0 | ((int)watermark[k++]) >> 4;
            if(k >= len){
                return;
            }
            img->pixels[i + j*img->width].green = img->pixels[i + j*img->width].green & 0xF0 | ((int)watermark[k++]) >> 4;
            if(k >= len){
                return;
            }
            img->pixels[i + j*img->width].blue = img->pixels[i + j*img->width].blue & 0xF0 | ((int)watermark[k++]) >> 4;
        }
    }
}

void extractWatermark(struct Image *img, char *watermark){
    int i, j, k = 0, len;
    len = strlen(watermark);

    for(i = 0; i < img->width; i++){
        for(j = 0; j < img->height; j++){
            if(k >= len){
                return;
            }
            watermark[k++] = (char)((img->pixels[i + j*img->width].red & 0x0F) << 4 | (img->pixels[i + j*img->width].green & 0x0F));
            if(k >= len){
                return;
            }
            watermark[k++] = (char)((img->pixels[i + j*img->width].blue & 0x0F) << 4 | (img->pixels[i + j*img->width].red & 0x0F));
            if(k >= len){
                return;
            }
            watermark[k++] = (char)((img->pixels[i + j*img->width].green & 0x0F) << 4 | (img->pixels[i + j*img->width].blue & 0x0F));
        }
    }
}

int main(){
    struct Image img;
    FILE *fp;
    char watermark[1000];
    
    fp = fopen("sample_image.bmp", "rb");
    
    fread(&img, sizeof(struct Image), 1, fp);
    
    printf("Enter the watermark:\n");
    scanf("%[^\n]",watermark);
    
    embedWatermark(&img, watermark);
    
    fclose(fp);
    
    fp = fopen("watermarked_image.bmp", "wb");
    
    fwrite(&img, sizeof(struct Image), 1, fp);
    
    fclose(fp);
    
    fp = fopen("watermarked_image.bmp", "rb");
    
    fread(&img, sizeof(struct Image), 1, fp);
    
    extractWatermark(&img, watermark);
    
    printf("Extracted watermark is: %s\n", watermark);
    
    fclose(fp);
    
    return 0; 
}