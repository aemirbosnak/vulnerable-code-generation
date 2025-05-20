//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct pixel{
    int x,y;
    int r,g,b;
};

struct pixel image[MAX][MAX];

void getpixel(struct pixel *p){
    printf("Enter x coordinate: ");
    scanf("%d",&p->x);
    printf("Enter y coordinate: ");
    scanf("%d",&p->y);
    printf("Enter red value: ");
    scanf("%d",&p->r);
    printf("Enter green value: ");
    scanf("%d",&p->g);
    printf("Enter blue value: ");
    scanf("%d",&p->b);
}

void putpixel(struct pixel p){
    printf("\nPixel at (%d,%d) has the following color values:\n",p.x,p.y);
    printf("Red value: %d\n",p.r);
    printf("Green value: %d\n",p.g);
    printf("Blue value: %d\n",p.b);
}

void displayimage(){
    int i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            if(image[i][j].r!=0 && image[i][j].g!=0 && image[i][j].b!=0){
                putpixel(image[i][j]);
            }
        }
    }
}

int main(){
    int i,j;
    printf("Enter the number of pixels in the image: ");
    scanf("%d",&i);
    printf("Enter the number of pixels in each row: ");
    scanf("%d",&j);
    for(int k=0;k<i;k++){
        for(int l=0;l<j;l++){
            getpixel(&image[k][l]);
        }
    }
    displayimage();
    return 0;
}