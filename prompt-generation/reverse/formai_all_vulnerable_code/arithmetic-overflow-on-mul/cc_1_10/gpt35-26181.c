//FormAI DATASET v1.0 Category: Image compression ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//maximum dimension for the image
#define MAX_DIM 1000

//function to read the input image
void read_image(float image[MAX_DIM][MAX_DIM], int *dim){
    FILE *fp;
    fp = fopen("image.txt", "r");
    fscanf(fp, "%d", dim);
    for(int i=0;i<*dim;i++){
        for(int j=0;j<*dim;j++){
            fscanf(fp, "%f", &image[i][j]);
        }
    }
    fclose(fp);
}

//function to write the compressed image to a file
void write_compressed_image(float compressed_image[MAX_DIM][MAX_DIM], int *dim, int num_coeffs){
    FILE *fp;
    fp = fopen("compressed_image.txt", "w");
    fprintf(fp, "%d\n", *dim);
    fprintf(fp, "%d\n", num_coeffs);
    for(int i=0;i<num_coeffs;i++){
        fprintf(fp, "%.2f ", compressed_image[i/(*dim)][i%(*dim)]);
    }
    fclose(fp);
}

int main(){
    int dim;
    float image[MAX_DIM][MAX_DIM];
    float compressed_image[MAX_DIM][MAX_DIM];
    
    //read input image
    read_image(image, &dim);
    
    //initialize number of coefficients to keep for compression
    int num_coeffs = 100;
    
    //perform DCT
    float dct[MAX_DIM][MAX_DIM];
    for (int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            float sum = 0.0;
            for(int u=0;u<dim;u++){
                for(int v=0;v<dim;v++){
                    float coeff = image[u][v]*cos((2*u+1)*i*M_PI/(2*dim))*cos((2*v+1)*j*M_PI/(2*dim));
                    sum += coeff;
                }
            }
            dct[i][j] = sum * (1/sqrt(2.0*dim)) * (1/sqrt(2.0*dim));
        }
    }
    
    //keep only top num_coeffs coefficients and set other coefficients to zero
    float sorted_coeffs[MAX_DIM*MAX_DIM];
    int index = 0;
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            sorted_coeffs[index] = dct[i][j];
            index++;
        }
    }
    for(int i=num_coeffs;i<dim*dim;i++){
        sorted_coeffs[i] = 0.0;
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            compressed_image[i][j] = sorted_coeffs[i*dim+j];
        }
    }
    
    //write compressed image to file
    write_compressed_image(compressed_image, &dim, num_coeffs);
    
    return 0;
}