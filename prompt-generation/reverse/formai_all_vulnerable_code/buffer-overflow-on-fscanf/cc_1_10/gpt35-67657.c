//FormAI DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    unsigned char r,g,b;
}pixel;

typedef struct{
    int width,height;
    pixel *data;
}image;

void load_image(char *filename, image *img);
void save_image(char *filename, image *img);
void destroy_image(image *img);
void invert_colors(image *img);
void grayscale(image *img);
void sepia(image *img);
void flip_horizontal(image *img);
void flip_vertical(image *img);
void rotate_90(image *img);
void rotate_180(image *img);
void rotate_270(image *img);

void load_image(char *filename, image *img){
    FILE *fp;
    char magic[3];
    int maxval,i;

    fp = fopen(filename,"rb");
    if(fp == NULL){
        perror("Error opening file");
        exit(1);
    }

    fscanf(fp,"%s\n",magic);
    if(strcmp(magic,"P6") != 0){
        printf("Error: Invalid PPM file format\n");
        exit(1);
    }

    fscanf(fp,"%d %d\n",&img->width,&img->height);

    fscanf(fp,"%d\n",&maxval);
    if(maxval > 255){
        printf("Error: Only 8-bit PPM files are supported\n");
        exit(1);
    }

    img->data = (pixel*)malloc(img->width*img->height*sizeof(pixel));
    fread(img->data,sizeof(pixel),img->width*img->height,fp);

    fclose(fp);
}

void save_image(char *filename, image *img){
    FILE *fp;

    fp = fopen(filename,"wb");
    if(fp == NULL){
        perror("Error saving file");
        exit(1);
    }

    fprintf(fp,"P6\n%d %d\n255\n",img->width,img->height);

    fwrite(img->data,sizeof(pixel),img->width*img->height,fp);

    fclose(fp);
}

void destroy_image(image *img){
    if(img->data != NULL){
        free(img->data);
        img->data = NULL;
    }
}

void invert_colors(image *img){
    int i;

    for(i=0;i<img->width*img->height;i++){
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void grayscale(image *img){
    int i;
    unsigned char gray_value;

    for(i=0;i<img->width*img->height;i++){
        gray_value = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = gray_value;
        img->data[i].g = gray_value;
        img->data[i].b = gray_value;
    }
}

void sepia(image *img){
    int i;
    unsigned char r,g,b;

    for(i=0;i<img->width*img->height;i++){
        r = img->data[i].r;
        g = img->data[i].g;
        b = img->data[i].b;

        img->data[i].r = (r*0.393 + g*0.769 + b*0.189);
        img->data[i].g = (r*0.349 + g*0.686 + b*0.168);
        img->data[i].b = (r*0.272 + g*0.534 + b*0.131);
    }
}

void flip_horizontal(image *img){
    int i,j;
    pixel temp;

    for(i=0;i<img->height;i++){
        for(j=0;j<img->width/2;j++){
            temp = img->data[i*img->width+j];
            img->data[i*img->width+j] = img->data[i*img->width+(img->width-j-1)];
            img->data[i*img->width+(img->width-j-1)] = temp;
        }
    }
}

void flip_vertical(image *img){
    int i,j;
    pixel temp;

    for(i=0;i<img->height/2;i++){
        for(j=0;j<img->width;j++){
            temp = img->data[i*img->width+j];
            img->data[i*img->width+j] = img->data[(img->height-i-1)*img->width+j];
            img->data[(img->height-i-1)*img->width+j] = temp;
        }
    }
}

void rotate_90(image *img){
    int i,j;
    image rotated_img;

    rotated_img.width = img->height;
    rotated_img.height = img->width;
    rotated_img.data = (pixel*)malloc(rotated_img.width*rotated_img.height*sizeof(pixel));

    for(i=0;i<img->height;i++){
        for(j=0;j<img->width;j++){
            rotated_img.data[j*rotated_img.width+(rotated_img.width-i-1)] = img->data[i*img->width+j];
        }
    }

    destroy_image(img);

    *img = rotated_img;
}

void rotate_180(image *img){
    int i,j;
    pixel temp;

    for(i=0;i<img->height/2;i++){
        for(j=0;j<img->width;j++){
            temp = img->data[i*img->width+j];
            img->data[i*img->width+j] = img->data[(img->height-i-1)*img->width+(img->width-j-1)];
            img->data[(img->height-i-1)*img->width+(img->width-j-1)] = temp;
        }
    }

    if(img->height % 2 != 0){
        for(i=0;i<img->width/2;i++){
            temp = img->data[(img->height/2)*img->width+i];
            img->data[(img->height/2)*img->width+i] = img->data[(img->height/2)*(img->width)+img->width-i-1];
            img->data[(img->height/2)*img->width+img->width-i-1] = temp;
        }
    }

    if(img->width % 2 != 0){
        for(i=0;i<img->height/2;i++){
            temp = img->data[i*img->width+(img->width/2)];
            img->data[i*img->width+(img->width/2)] = img->data[(img->height-i-1)*img->width+(img->width/2)];
            img->data[(img->height-i-1)*img->width+(img->width/2)] = temp;
        }
    }
}

void rotate_270(image *img){
    int i,j;
    image rotated_img;

    rotated_img.width = img->height;
    rotated_img.height = img->width;
    rotated_img.data = (pixel*)malloc(rotated_img.width*rotated_img.height*sizeof(pixel));

    for(i=0;i<img->height;i++){
        for(j=0;j<img->width;j++){
            rotated_img.data[(rotated_img.height-j-1)*rotated_img.width+i] = img->data[i*img->width+j];
        }
    }

    destroy_image(img);

    *img = rotated_img;
}

int main(int argc, char *argv[]){
    image img;
    int choice;
    char filename[100];

    if(argc < 2){
        printf("Usage: %s <image-file>\n",argv[0]);
        exit(1);
    }

    load_image(argv[1],&img);

    printf("1. Invert Colors\n");
    printf("2. Convert to Grayscale\n");
    printf("3. Apply Sepia Filter\n");
    printf("4. Flip Horizontally\n");
    printf("5. Flip Vertically\n");
    printf("6. Rotate 90 degrees\n");
    printf("7. Rotate 180 degrees\n");
    printf("8. Rotate 270 degrees\n\n");

    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            invert_colors(&img);
            break;

        case 2:
            grayscale(&img);
            break;

        case 3:
            sepia(&img);
            break;

        case 4:
            flip_horizontal(&img);
            break;

        case 5:
            flip_vertical(&img);
            break;

        case 6:
            rotate_90(&img);
            break;

        case 7:
            rotate_180(&img);
            break;

        case 8:
            rotate_270(&img);
            break;

        default:
            printf("Invalid choice!\n");
    }

    sprintf(filename,"%s_output.ppm",argv[1]);

    save_image(filename,&img);

    destroy_image(&img);

    return 0;
}