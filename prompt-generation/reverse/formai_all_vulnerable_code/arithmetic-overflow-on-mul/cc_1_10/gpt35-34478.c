//FormAI DATASET v1.0 Category: Image Classification system ; Style: interoperable
#include <stdio.h>  
#include <stdlib.h>  

// Define image structure  
typedef struct Image{  
   int width;  
   int height;  
   int* data;  
} Image;  

/* Function to read image and store its data in the Image structure */
Image* readImage(char * filename){  
   
   FILE *file;  
   Image* img;  
   int i, j;  
   
   // Open file in read mode  
   file = fopen(filename,"r");  
   
   if(file == NULL){  
      printf("\nError: cannot open the file");  
      exit(1);  
   }  
   
   // Allocate memory to Image structure   
   img = (Image*)malloc(sizeof(Image));  
   if(img == NULL){  
      printf("\nError: memory not allocated!");  
      exit(1);  
   }  
   
   // Read width and height of image  
   fscanf(file,"%d %d",&(img->width), &(img->height));  
   
   // Allocate memory to store image data  
   img->data = (int*)malloc(img->width * img->height * sizeof(int));  
   if(img->data == NULL){  
      printf("\nError: memory not allocated!");  
      exit(1);  
   }  
   
   // Read image data from file and store it in structure  
   for(i=0;i<img->height;i++){  
      for(j=0;j<img->width;j++){  
         fscanf(file,"%d", &(img->data[i*img->width + j]));  
      }  
   }  
   
   // Close file  
   fclose(file);  
   
   // Return pointer to image structure  
   return img;  
}  

/* Function to classify image based on its pixel values*/
void classifyImage(Image * img){  
   
   int i, j;  
   int count = 0;  
    
   // Count the number of black and white pixels in image data  
   for(i=0;i<img->height;i++){  
      for(j=0;j<img->width;j++){  
         if(img->data[i*img->width + j] == 0){  
            count += 1;  
         }else{  
            count -= 1;  
         }  
      }  
   }  
   
   // Determine the class of image based on count  
   if(count > 0){  
      printf("\n\n The image is classified as Class 1.");  
   }else{  
      printf("\n\n The image is classified as Class 2.");  
   }  
   
}  

int main(){  
    
   // Read the image data from file  
   Image* img = readImage("image.txt");  
   
   // Classify the image based on its pixel values  
   classifyImage(img);  
   
   // Free the allocated memory  
   free(img->data);  
   free(img);  
    
   return 0;  
}