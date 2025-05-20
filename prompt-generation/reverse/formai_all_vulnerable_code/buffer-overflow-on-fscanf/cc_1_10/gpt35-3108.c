//FormAI DATASET v1.0 Category: Image Editor ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}RGB;

RGB image[HEIGHT][WIDTH];

void loadImage(RGB (*img)[WIDTH]){
    FILE *fp = fopen("input.ppm","r");
    char tmp[10];
    fscanf(fp,"%s",tmp);
    fscanf(fp,"%s",tmp);
    fscanf(fp,"%s",tmp);

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            fscanf(fp,"%c%c%c",&img[i][j].r,&img[i][j].g,&img[i][j].b);
        }
    }

    fclose(fp);
}

void saveImage(RGB (*img)[WIDTH]){
    FILE *fp = fopen("output.ppm","w");
    fprintf(fp,"P6\n%d %d\n%d\n",WIDTH,HEIGHT,255);

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            fprintf(fp,"%c%c%c",img[i][j].r,img[i][j].g,img[i][j].b);
        }
    }

    fclose(fp);
}

void grayScale(RGB (*img)[WIDTH]){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            unsigned char gray = img[i][j].r*0.3 + img[i][j].g*0.59 + img[i][j].b*0.11;
            img[i][j].r = gray;
            img[i][j].g = gray;
            img[i][j].b = gray;
        }
    }
}

void red(RGB (*img)[WIDTH]){
    for(int i=0;i<HEIGHT/2;i++){
        for(int j=0;j<WIDTH/2;j++){
            img[i][j].r = 255;
        }
    }
}

void blue(RGB (*img)[WIDTH]){
    for(int i=HEIGHT/2;i<HEIGHT;i++){
        for(int j=WIDTH/2;j<WIDTH;j++){
            img[i][j].b = 255;
        }
    }
}

void flipVertical(RGB (*img)[WIDTH]){
    for(int i=0;i<HEIGHT/2;i++){
        for(int j=0;j<WIDTH;j++){
            RGB temp = img[i][j];
            img[i][j] = img[HEIGHT-i-1][j];
            img[HEIGHT-i-1][j] = temp;
        }
    }
}

void rotate(RGB (*img)[WIDTH],double degree){
    double radian = degree/180.0*M_PI;
    RGB newImg[HEIGHT][WIDTH];

    int cx = WIDTH/2;
    int cy = HEIGHT/2;

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            int x = j-cx;
            int y = i-cy;

            int newX = (int)(x*cos(radian)-y*sin(radian)+cx);
            int newY = (int)(x*sin(radian)+y*cos(radian)+cy);

            if(newX<0 || newX>=WIDTH || newY<0 || newY>=HEIGHT) continue;

            newImg[newY][newX] = img[i][j];
        }
    }

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            img[i][j] = newImg[i][j];
        }
    }
}

void translate(RGB (*img)[WIDTH],int dx,int dy){
    RGB newImg[HEIGHT][WIDTH];

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            int newX = j+dx;
            int newY = i+dy;

            if(newX<0 || newX>=WIDTH || newY<0 || newY>=HEIGHT) continue;

            newImg[newY][newX] = img[i][j];
        }
    }

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            img[i][j] = newImg[i][j];
        }
    }
}

void zoomIn(RGB (*img)[WIDTH]){
    RGB newImg[HEIGHT*2][WIDTH*2];

    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            newImg[i*2][j*2] = img[i][j];
            newImg[i*2+1][j*2] = img[i][j];
            newImg[i*2][j*2+1] = img[i][j];
            newImg[i*2+1][j*2+1] = img[i][j];
        }
    }

    for(int i=0;i<HEIGHT*2;i++){
        for(int j=0;j<WIDTH*2;j++){
            img[i][j] = newImg[i][j];
        }
    }
}

void zoomOut(RGB (*img)[WIDTH]){
    RGB newImg[HEIGHT/2][WIDTH/2];

    for(int i=0;i<HEIGHT;i+=2){
        for(int j=0;j<WIDTH;j+=2){
            int r = img[i][j].r + img[i][j+1].r + img[i+1][j].r + img[i+1][j+1].r;
            int g = img[i][j].g + img[i][j+1].g + img[i+1][j].g + img[i+1][j+1].g;
            int b = img[i][j].b + img[i][j+1].b + img[i+1][j].b + img[i+1][j+1].b;

            newImg[i/2][j/2].r = r/4;
            newImg[i/2][j/2].g = g/4;
            newImg[i/2][j/2].b = b/4;
        }
    }

    for(int i=0;i<HEIGHT/2;i++){
        for(int j=0;j<WIDTH/2;j++){
            img[i][j] = newImg[i][j];
        }
    }
}

int main(){
    loadImage(image);

    // grayScale(image);
    // red(image);
    // blue(image);
    // flipVertical(image);
    // rotate(image,45);
    // translate(image,50,50);
    // zoomIn(image);
    // zoomOut(image);

    saveImage(image);

    return 0;
}