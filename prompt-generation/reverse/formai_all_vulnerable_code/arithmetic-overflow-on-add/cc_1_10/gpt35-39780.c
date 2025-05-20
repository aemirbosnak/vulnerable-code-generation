//FormAI DATASET v1.0 Category: Data recovery tool ; Style: medieval
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

void recoverData(char *filename) {  
    FILE *fp = fopen(filename, "rb");  
    if (fp == NULL) {  
        printf("Error opening file\n");  
        return;  
    }  

    fseek(fp, 0, SEEK_END);  
    int filesize = ftell(fp);  
    rewind(fp);  

    char *data = malloc(filesize + 1);  
    if (data == NULL) {  
        printf("Error allocating memory\n");  
        fclose(fp);  
        return;  
    }  
    fread(data, filesize, 1, fp);  

    int i;  
    for (i = 0; i < filesize; i++) {  
        data[i] = ~data[i]; // flip the bits  
    }  

    char *outputFilename = malloc(strlen(filename) + 5);  
    strcpy(outputFilename, filename);  
    strcat(outputFilename, ".rec");  

    FILE *output = fopen(outputFilename, "wb");  
    if (output == NULL) {  
        printf("Error creating output file\n");  
        fclose(fp);  
        free(data);  
        return;  
    }  
    fwrite(data, filesize, 1, output);  

    fclose(fp);  
    fclose(output);  
    free(data);  
    free(outputFilename);  

    printf("Data successfully recovered!\n");  
}  

int main(int argc, char *argv[]) {  
    if (argc != 2) {  
        printf("Usage: %s [filename]\n", argv[0]);  
        return 1;  
    }  

    char *filename = argv[1];  
    recoverData(filename);  

    return 0;  
}