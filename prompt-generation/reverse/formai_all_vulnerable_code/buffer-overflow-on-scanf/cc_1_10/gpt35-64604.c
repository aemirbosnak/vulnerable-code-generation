//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: visionary
#include<stdio.h>

/* Function to embed watermark into the image */
void embed_watermark(int *image,int *watermark,int rows,int cols,int w_rows,int w_cols){
    int i,j,k,l;
    k = 0;
    l = 0;

    /* Embed the watermark wherever there is enough space */
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(l<w_cols){
                image[i*cols+j] = (image[i*cols+j]&(~1))|(watermark[k*w_cols+l]&1);
                l++;
            }
            else{
                k++;
                l=0;
                /* If there is not enough space, do not do anything */
                if(k>=w_rows){
                    return;
                }
                j--;
            }
        }
    }
}

/* Function to extract watermark from the image */
void extract_watermark(int *image,int *watermark,int rows,int cols,int w_rows,int w_cols){
    int i,j,k,l;
    k = 0;
    l = 0;

    /* Extract the watermark wherever it is present in the image */
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(l<w_cols){
                watermark[k*w_cols+l] = image[i*cols+j]&1;
                l++;
            }
            else{
                k++;
                l=0;
                /* If watermark has been fully extracted, stop the process */
                if(k>=w_rows){
                    return;
                }
                j--;
            }
        }
    }
}

int main(){

    int image[500][500], watermark[100][100];
    int rows,cols,w_rows,w_cols;
    int i,j;

    /* Read the image and the watermark */
    printf("Enter the number of rows and columns in the image:\n");
    scanf("%d %d",&rows,&cols);
    printf("Enter the image:\n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&image[i][j]);
        }
    }

    printf("Enter the number of rows and columns in the watermark:\n");
    scanf("%d %d",&w_rows,&w_cols);
    printf("Enter the watermark:\n");
    for(i=0;i<w_rows;i++){
        for(j=0;j<w_cols;j++){
            scanf("%d",&watermark[i][j]);
        }
    }

    /* Embed the watermark into the image */
    embed_watermark(&image[0][0],&watermark[0][0],rows,cols,w_rows,w_cols);

    /* Extract the watermark from the image */
    extract_watermark(&image[0][0],&watermark[0][0],rows,cols,w_rows,w_cols);

    /* Print the extracted watermark */
    printf("Extracted watermark:\n");
    for(i=0;i<w_rows;i++){
        for(j=0;j<w_cols;j++){
            printf("%d ",watermark[i][j]);
        }
        printf("\n");
    }

    return 0;
}