//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct img_format{
    short int bits_per_pixel; // bits per pixel
    int img_width; // image width
    int img_height; // image height
    unsigned char *r; // red pixel value
    unsigned char *g; // green pixel value
    unsigned char *b; // blue pixel value 
};

typedef struct{
    int x,y; //pixel co-ordinates
}pixel;

void read_image(FILE *fptr, struct img_format *img);
void write_image(char *filename, struct img_format *img);
void embed_watermark(struct img_format *img, char *watermark);
void extract_watermark(struct img_format *img, char *filename);
unsigned char *decimal_to_binary(int num);

int main(){
    FILE *img_file;
    char filename[50], watermark[50], extracted_filename[50];
    printf("Enter name of the image file: ");
    scanf("%s", filename);
    printf("Enter the text to be watermarked: ");
    scanf("%s", watermark);
    printf("Enter the name of the extracted file: ");
    scanf("%s", extracted_filename);
    struct img_format img;
    img_file =  fopen(filename,"rb");
    if (img_file==NULL){
        printf("Could not open file.");
        exit(0);
    }
    read_image(img_file, &img);
    fclose(img_file);
    embed_watermark(&img, watermark);
    write_image(filename, &img);
    printf("\nWatermark has been embedded successfully in image %s.", filename);
    extract_watermark(&img, extracted_filename);
    printf("\nWatermark has been extracted successfully and saved in %s.\n", extracted_filename);
    return 0;
}

void read_image(FILE *fptr, struct img_format *img){
    short int data_offset;
    int img_size;
    int cols;
    int rows;
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fptr);
    cols = *(int*)&header[18];
    rows = *(int*)&header[22];
    data_offset = *(short int*)&header[10];
    img_size = *(int*)&header[34];
    img->img_width = cols;
    img->img_height = rows;
    img->bits_per_pixel = *(short int*)&header[28];
    fseek(fptr, data_offset, SEEK_SET);
    img->r = (unsigned char*)malloc(img_size);
    img->g = (unsigned char*)malloc(img_size);
    img->b = (unsigned char*)malloc(img_size);
    fread(img->b, sizeof(unsigned char), img_size, fptr);
    fread(img->g, sizeof(unsigned char), img_size, fptr);
    fread(img->r, sizeof(unsigned char), img_size, fptr);
}

void write_image(char *filename, struct img_format *img){
    FILE *fptr;
    fptr = fopen(filename, "wb");
    fseek(fptr, 0, SEEK_SET);
    fwrite(img->b, sizeof(unsigned char), img->img_width*img->img_height, fptr);
    fwrite(img->g, sizeof(unsigned char), img->img_width*img->img_height, fptr);
    fwrite(img->r, sizeof(unsigned char), img->img_width*img->img_height, fptr);
    fclose(fptr);
}

void embed_watermark(struct img_format *img, char *watermark){
    int i,j,idx;
    int watermark_length=strlen(watermark);
    if (watermark_length > img->img_height * img->img_width){
        printf("The watermark is too long for this image.");
        exit(0);
    }
    else{
        pixel *pixels = (pixel*)malloc(sizeof(pixel)*watermark_length);
        for (i=0;i<watermark_length;i++){
            idx=rand()%(img->img_height * img->img_width);
            pixels[i].x=idx%img->img_width;
            pixels[i].y=idx/img->img_width;
            img->r[idx]=img->r[idx]-img->r[idx]%2+(*decimal_to_binary(watermark[i]))%2;
            img->g[idx]=img->g[idx]-img->g[idx]%2+(*(decimal_to_binary(watermark[i])+1))%2;
            img->b[idx]=img->b[idx]-img->b[idx]%2+(*(decimal_to_binary(watermark[i])+2))%2;
        }
        free(pixels);
    }
}

void extract_watermark(struct img_format *img, char *filename){
    int i,j,idx=0;
    int watermark_length=(img->img_height * img->img_width)/8;
    char *watermark = (char*)malloc(sizeof(char)*watermark_length);
    for (i=0;i<img->img_height;i++){
        for (j=0;j<img->img_width;j++){
            if (idx>=watermark_length){
                break;
            }
            if (img->r[i*img->img_width+j]%2==1){
                watermark[idx]=watermark[idx]<<1;
                watermark[idx]+=1;
            }
            else{
                watermark[idx]=watermark[idx]<<1;
            }
            if (img->g[i*img->img_width+j]%2==1){
                watermark[idx]=watermark[idx]<<1;
                watermark[idx]+=1;
            }
            else{
                watermark[idx]=watermark[idx]<<1;
            }
            if (img->b[i*img->img_width+j]%2==1){
                watermark[idx]=watermark[idx]<<1;
                watermark[idx]+=1;
            }
            else{
                watermark[idx]=watermark[idx]<<1;
            }
            if ((i*img->img_width+j)%8==7){
                idx++;
            }
        }
        if (idx>=watermark_length){
            break;
        }
    }
    FILE *fptr;
    fptr = fopen(filename, "wb");
    fputs(watermark, fptr);
    fclose(fptr);
    free(watermark);
}

unsigned char *decimal_to_binary(int num){
    int i;
    static unsigned char bit[8];
    for (i=0;i<8;i++){
        bit[i]=0;
    }
    i=7;
    while(num>0){
        bit[i]=num%2;
        num=num/2;
        i--;
    }
    return bit;
}