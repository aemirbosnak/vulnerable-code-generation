//FormAI DATASET v1.0 Category: Image Editor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HEIGHT 600
#define WIDTH 800

typedef struct {
    unsigned char r, g, b;
} Pixel;

void load_image(FILE* fp, Pixel image[HEIGHT][WIDTH], int height, int width){
    char buf[4];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            fread(buf, 1, 3, fp);
            image[i][j].r=buf[0];
            image[i][j].g=buf[1];
            image[i][j].b=buf[2];
        }
    }
    fseek(fp, 18, SEEK_SET);
}

void save_image(FILE* fp, Pixel image[HEIGHT][WIDTH], int height, int width){
    char buf[4];
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            buf[0]=image[i][j].r;
            buf[1]=image[i][j].g;
            buf[2]=image[i][j].b;

            fwrite(buf, 1, 3, fp);
        }
    }
    fseek(fp, 18, SEEK_SET);
}

void filter_image_gray(Pixel image[HEIGHT][WIDTH], int height, int width){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int avg=(image[i][j].r+image[i][j].g+image[i][j].b)/3;
            image[i][j].r=avg;
            image[i][j].g=avg;
            image[i][j].b=avg;
        }
    }
}

void filter_image_sepia(Pixel image[HEIGHT][WIDTH], int height, int width){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int tr=image[i][j].r*0.393+image[i][j].g*0.769+image[i][j].b*0.189;
            int tg=image[i][j].r*0.349+image[i][j].g*0.686+image[i][j].b*0.168;
            int tb=image[i][j].r*0.272+image[i][j].g*0.534+image[i][j].b*0.131;

            if(tr>255) tr=255;
            if(tg>255) tg=255;
            if(tb>255) tb=255;

            image[i][j].r=tr;
            image[i][j].g=tg;
            image[i][j].b=tb;
        }
    }
}

int main(){
    int choice=-1;
    Pixel image[HEIGHT][WIDTH];
    FILE *fp=NULL;

    while(choice!=0){
        printf("Select an option:\n");
        printf("1. Load image\n");
        printf("2. Save image\n");
        printf("3. Convert image to grayscale\n");
        printf("4. Convert image to sepia\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                char filename[100];
                printf("Filename: ");
                scanf("%s", filename);

                fp=fopen(filename, "rb");
                if(fp==NULL){
                    printf("Invalid filename\n");
                    break;
                }

                char id[2];
                fseek(fp, 0, SEEK_SET);
                fread(id, 1, 2, fp);

                if(strcmp(id, "BM")!=0){
                    printf("Invalid file format\n");
                    fclose(fp);
                    break;
                }

                int offset=0;
                fseek(fp, 10, SEEK_SET);
                fread(&offset, 4, 1, fp);

                int width=0, height=0;
                fseek(fp, 18, SEEK_SET);
                fread(&width, 4, 1, fp);
                fread(&height, 4, 1, fp);

                load_image(fp, image, height, width);

                printf("Image loaded\n");
                printf("Dimensions: %dx%d\n", width, height);
                fclose(fp);
                break;
            }
            case 2:{
                if(fp==NULL){
                    printf("No image loaded\n");
                    break;
                }

                char filename[100];
                printf("Filename: ");
                scanf("%s", filename);

                fp=fopen(filename, "wb");
                if(fp==NULL){
                    printf("Cannot save file\n");
                    fclose(fp);
                    break;
                }

                save_image(fp, image, HEIGHT, WIDTH);

                printf("Image saved\n");
                fclose(fp);
                break;
            }
            case 3:{
                if(fp==NULL){
                    printf("No image loaded\n");
                    break;
                }

                filter_image_gray(image, HEIGHT, WIDTH);
                printf("Image converted to grayscale\n");
                break;
            }
            case 4:{
                if(fp==NULL){
                    printf("No image loaded\n");
                    break;
                }

                filter_image_sepia(image, HEIGHT, WIDTH);
                printf("Image converted to sepia\n");
                break;
            }
            case 5:{
                printf("Exiting...\n");
                return 0;
            }
            default:{
                printf("Invalid option\n");
                break;
            }
        }
    }

    return 0;
}