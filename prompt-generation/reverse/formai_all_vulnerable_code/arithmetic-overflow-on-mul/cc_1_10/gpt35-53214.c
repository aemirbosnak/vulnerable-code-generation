//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: modular
#include<stdio.h>
#include<stdlib.h>

//function for flipping an image
void flipImage(int width, int height, unsigned char* image_data){
    unsigned char temp;
    int index1, index2, row;

    for(row=0; row<height; row++){
        for(index1=row*width, index2=(row+1)*width-1; index1<index2; index1++, index2--){
            temp = image_data[index1];
            image_data[index1] = image_data[index2];
            image_data[index2] = temp;
        }
    }
}

//function for changing brightness and contrast of an image
void adjustImage(int width, int height, unsigned char* image_data, int brightness, float contrast_factor){
    float contrast_correction_factor = (100.0 + contrast_factor)/100.0;
    unsigned char pixel_value;
    int row, col;

    for(row=0; row<height; row++){
        for(col=0; col<width; col++){
            pixel_value = image_data[row*width+col];
            pixel_value = (unsigned char) (((pixel_value-128)*contrast_correction_factor)+128+brightness);
            if(pixel_value < 0) pixel_value = 0;
            if(pixel_value > 255) pixel_value = 255;
            image_data[row*width+col] = pixel_value;
        }
    }
}

int main(){
    //read image dimensions and data from file
    int image_width, image_height;
    FILE *image_file = fopen("image.dat","rb");
    fread(&image_width,sizeof(int),1,image_file);
    fread(&image_height,sizeof(int),1,image_file);
    unsigned char* image_data = (unsigned char*)malloc(sizeof(unsigned char)*image_width*image_height);
    fread(image_data,sizeof(unsigned char),image_width*image_height,image_file);
    fclose(image_file);

    //flip image
    flipImage(image_width,image_height,image_data);

    //adjust brightness and contrast
    adjustImage(image_width,image_height,image_data,50,40.0);

    //write new image data to file
    FILE *new_image_file = fopen("result.dat","wb");
    fwrite(&image_width,sizeof(int),1,new_image_file);
    fwrite(&image_height,sizeof(int),1,new_image_file);
    fwrite(image_data,sizeof(unsigned char),image_width*image_height,new_image_file);
    fclose(new_image_file);
    free(image_data);

    return 0;
}