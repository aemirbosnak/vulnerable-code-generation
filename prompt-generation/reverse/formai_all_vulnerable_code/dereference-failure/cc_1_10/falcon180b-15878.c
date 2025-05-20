//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
    int width,height;
    unsigned char *data;
}Image;

void CreateImage(Image *img,int w,int h){
    img->width=w;
    img->height=h;
    img->data=(unsigned char *)malloc(w*h*sizeof(unsigned char));
    memset(img->data,0,w*h*sizeof(unsigned char));
}

void FlipImage(Image *img){
    int i,j,temp;
    for(i=0;i<img->height;i++){
        for(j=0;j<img->width/2;j++){
            temp=img->data[i*img->width+j];
            img->data[i*img->width+j]=img->data[i*img->width+img->width-j-1];
            img->data[i*img->width+img->width-j-1]=temp;
        }
    }
}

void ChangeBrightness(Image *img,int b){
    int i,j;
    for(i=0;i<img->height;i++){
        for(j=0;j<img->width;j++){
            img->data[i*img->width+j]+=b;
            if(img->data[i*img->width+j]>255)
                img->data[i*img->width+j]=255;
        }
    }
}

void ChangeContrast(Image *img,int c){
    int i,j;
    for(i=0;i<img->height;i++){
        for(j=0;j<img->width;j++){
            img->data[i*img->width+j]=(img->data[i*img->width+j]+c)%256;
        }
    }
}

void SaveImage(Image *img,char *filename){
    FILE *fp;
    fp=fopen(filename,"wb");
    if(fp==NULL){
        printf("Error saving image\n");
        exit(1);
    }
    fwrite(img->data,1,img->width*img->height*sizeof(unsigned char),fp);
    fclose(fp);
}

int main(){
    Image img;
    CreateImage(&img,100,100);
    for(int i=0;i<img.height;i++){
        for(int j=0;j<img.width;j++){
            img.data[i*img.width+j]=(i*j)%256;
        }
    }
    SaveImage(&img,"original.bmp");
    FlipImage(&img);
    SaveImage(&img,"flipped.bmp");
    ChangeBrightness(&img,50);
    SaveImage(&img,"bright.bmp");
    ChangeContrast(&img,100);
    SaveImage(&img,"contrast.bmp");
    return 0;
}