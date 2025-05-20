//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum{
    FLIP_HORIZONTAL,FLIP_VERTICAL
}FlipType;

struct Image{
    int rows;
    int cols;
    int **data;
};

void malloc_image(int rows,int cols,struct Image *img){
    img->rows=rows;
    img->cols=cols;
    img->data=(int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        img->data[i]=(int*)malloc(cols*sizeof(int));
    }
}

void free_image(struct Image *img){
    for(int i=0;i<img->rows;i++){
        free(img->data[i]);
    }
    free(img->data);   
}

void read_image(char *filename,struct Image *img){
    FILE *fp=fopen(filename,"r");
    if(fp==NULL){
        printf("Could not open file for reading\n");
        exit(1);
    }

    fscanf(fp,"%d %d",&img->rows,&img->cols);
    malloc_image(img->rows,img->cols,img);

    for(int i=0;i<img->rows;i++){
        for(int j=0;j<img->cols;j++){
            fscanf(fp,"%d",&img->data[i][j]);   
        }
    }

    fclose(fp);
}

void write_image(char *filename,struct Image *img){
    FILE *fp=fopen(filename,"w");
    if(fp==NULL){
        printf("Could not open file for writing\n");
        exit(1);
    }

    fprintf(fp,"%d %d\n",img->rows,img->cols);
    for(int i=0;i<img->rows;i++){
        for(int j=0;j<img->cols;j++){
            fprintf(fp,"%d ",img->data[i][j]);  
        }
        fprintf(fp,"\n");
    }

    fclose(fp);
}

void flip_image(struct Image *img,FlipType type){
    int **temp=(int**)malloc(img->rows*sizeof(int*));
    for(int i=0;i<img->rows;i++){
        temp[i]=(int*)malloc(img->cols*sizeof(int));
    }

    if(type==FLIP_HORIZONTAL){
        for(int i=0;i<img->rows;i++){
            for(int j=0;j<img->cols;j++){
                temp[i][j]=img->data[i][img->cols-1-j];
            }
        }
    }
    else if(type==FLIP_VERTICAL){
        for(int i=0;i<img->rows;i++){
            for(int j=0;j<img->cols;j++){
                temp[i][j]=img->data[img->rows-1-i][j];
            }
        }
    }

    for(int i=0;i<img->rows;i++){
        for(int j=0;j<img->cols;j++){
            img->data[i][j]=temp[i][j];
        }
    }

    for(int i=0;i<img->rows;i++){
        free(temp[i]);
    }
    free(temp); 
}

void change_brightness(struct Image *img,double factor){ 
    for(int i=0;i<img->rows;i++){
        for(int j=0;j<img->cols;j++){
            img->data[i][j]=(int)fmin(fmax(factor*img->data[i][j],0.0),255.0);
        }
    } 
}

void change_contrast(struct Image *img,double factor){ 
    double avg,sum=0;
    for(int i=0;i<img->rows;i++){
        for(int j=0;j<img->cols;j++){
            sum+=img->data[i][j];
        }
    }
    avg=sum/(img->rows*img->cols);

    for(int i=0;i<img->rows;i++){
        for(int j=0;j<img->cols;j++){
            img->data[i][j]=(int)fmin(fmax(factor*(img->data[i][j]-avg)+avg,0.0),255.0);
        }
    }
}

int main(){
    struct Image img;
    read_image("input_image.txt",&img);

    flip_image(&img,FLIP_HORIZONTAL);
    write_image("flipped_image.txt",&img);

    flip_image(&img,FLIP_VERTICAL);
    write_image("flipped_image.txt",&img);

    change_brightness(&img,1.5);
    write_image("brightness_image.txt",&img);

    change_contrast(&img,2);
    write_image("contrast_image.txt",&img);

    free_image(&img);

    return 0;
}