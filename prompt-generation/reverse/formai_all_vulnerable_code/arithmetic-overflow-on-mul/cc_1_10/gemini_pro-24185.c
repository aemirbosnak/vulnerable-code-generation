//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct{
    unsigned char *data;
    int width, height, bpp;
}Image;

Image *loadImage(char *filename){
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) return NULL;
    
    Image *img = malloc(sizeof(Image));
    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);
    fread(&img->bpp, sizeof(int), 1, fp);
    
    img->data = malloc(img->width * img->height * img->bpp);
    fread(img->data, img->width * img->height * img->bpp, 1, fp);
    
    fclose(fp);
    return img;
}

void saveImage(Image *img, char *filename){
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL) return;
    
    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(&img->bpp, sizeof(int), 1, fp);
    
    fwrite(img->data, img->width * img->height * img->bpp, 1, fp);
    
    fclose(fp);
}

Image *watermarkImage(Image *img, char *watermark){
    int wlen = strlen(watermark);
    
    for(int i = 0; i < wlen; i++){
        for(int j = 0; j < 8; j++){
            int bit = (watermark[i] >> j) & 1;
            
            int x = i % img->width;
            int y = i / img->width;
            
            int offset = y * img->width * img->bpp + x * img->bpp + j;
            
            img->data[offset] = (img->data[offset] & ~1) | bit;
        }
    }
    
    return img;
}

char *extractWatermark(Image *img){
    int wlen = 0;
    for(int i = 0; i < img->width * img->height * img->bpp; i++){
        if(img->data[i] & 1){
            wlen++;
        }
    }
    
    char *watermark = malloc(wlen + 1);
    
    int j = 0;
    for(int i = 0; i < img->width * img->height * img->bpp; i++){
        if(img->data[i] & 1){
            watermark[j++] = 0;
            for(int k = 0; k < 8; k++){
                watermark[j++] |= (img->data[i + k] & 1) << k;
            }
        }
    }
    
    watermark[j] = '\0';
    
    return watermark;
}

int main(){
    Image *img = loadImage("image.bmp");
    
    Image *watermarkedImage = watermarkImage(img, "Watermark");
    
    saveImage(watermarkedImage, "watermarked_image.bmp");
    
    char *watermark = extractWatermark(watermarkedImage);
    
    printf("Watermark: %s\n", watermark);
    
    free(img);
    free(watermarkedImage);
    free(watermark);
    
    return 0;
}