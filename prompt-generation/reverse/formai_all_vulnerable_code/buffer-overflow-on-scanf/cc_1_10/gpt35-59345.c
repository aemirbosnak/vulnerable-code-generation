//FormAI DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
//Welcome to the world of C Compression algorithms! 
//In this program, we will explore a unique compression algorithm that will blow your mind!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Helper function to get the size of the file
long int getSize(char* filename) {
    FILE* fp = fopen(filename, "rb");
    fseek(fp, 0L, SEEK_END);
    long int size = ftell(fp);
    fclose(fp);
    return size;
}

//Main function starts here
int main() {
    
    printf("Welcome to the C Compression algorithm program!\n");
    printf("Let's get started and compress a file!\n");

    //Get the name of the file to be compressed
    char filename[100];
    printf("Enter the name of the file you want to compress: ");
    scanf("%s", filename);

    //Get the size of the file to be compressed
    long int size = getSize(filename);
    printf("The size of the file is: %ld\n", size);

    //Read the file into a buffer
    FILE* fp = fopen(filename, "rb");
    char* buffer = malloc(sizeof(char) * size);
    fread(buffer, sizeof(char), size, fp);
    fclose(fp);

    //Initialize variables for compression
    int count = 1;
    char current = buffer[0];
    char* compressed = malloc(sizeof(char) * size); //Assume compressed size won't be greater than original size

    //Loop through the buffer and compress
    for(int i = 1; i < size; i++){
        if(buffer[i] == current){
            count++;
        } else {
            compressed[strlen(compressed)] = current;
            compressed[strlen(compressed)] = count;
            count = 1;
            current = buffer[i];
        }
    }

    //Add the last element to the compressed array
    compressed[strlen(compressed)] = current;
    compressed[strlen(compressed)] = count;

    //Write the compressed array to a file
    char newFileName[100];
    strcpy(newFileName, "compressed_");
    strcat(newFileName, filename);
    fp = fopen(newFileName, "wb");
    fwrite(compressed, sizeof(char), strlen(compressed), fp);
    fclose(fp);

    printf("Compression complete!\n");
    printf("The compressed file can be found at: %s\n", newFileName);

    //Free memory
    free(buffer);
    free(compressed);

    return 0;
}