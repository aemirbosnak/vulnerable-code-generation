//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 500000
#define WIDTH 200

void convertToAscii(char *buffer){
    const char asciiList[] = {' ', '.', '-', '=', '+', '*', 'o', '0', '8', '%', '@'};
    const int asciiSize = sizeof(asciiList)/sizeof(asciiList[0]);
    
    char *asciiBuffer = malloc(sizeof(char)*MAX_SIZE);
    
    int i, j, index;
    for(i=0; i < strlen(buffer); i+=3*WIDTH){ 
        for(j=0; j<3*WIDTH; j+=3){ 
            int r = buffer[i+j];
            int g = buffer[i+j+1];
            int b = buffer[i+j+2];
            
            index = ((r+g+b)/3)*asciiSize/255;

            asciiBuffer[(i/3/WIDTH)*WIDTH*2+(j/3)*2] = asciiList[index];
            asciiBuffer[(i/3/WIDTH)*WIDTH*2+(j/3)*2+1] = asciiList[index];
        }
        asciiBuffer[(i/3/WIDTH)*WIDTH*2+WIDTH*2] = '\n';
    }
    printf("%s", asciiBuffer);
    free(asciiBuffer);
}

int main(){
    FILE *image;
    char filename[100];
    char buffer[MAX_SIZE];
    
    printf("Enter the name of the image file you want to convert: ");
    scanf("%s", filename);
    
    image = fopen(filename, "rb");
    if(image == NULL){
        printf("Failed to open the image file.\n");
        return 1;
    }
    
    fread(buffer, sizeof(char), MAX_SIZE, image);
    
    convertToAscii(buffer);
  
    fclose(image);
    return 0;
}