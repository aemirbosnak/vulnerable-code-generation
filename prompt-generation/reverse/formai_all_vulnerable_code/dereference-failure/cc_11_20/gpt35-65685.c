//FormAI DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

void clean_buffer(unsigned char buffer[], int size){
    for(int i = 0; i < size; i++){
        buffer[i] = 0;
    }
}

int main(int argc, char *argv[]){
    char *infile = NULL;
    char *outfile = NULL;
    int file_count = 0;

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-i") == 0){
            if(i+1 < argc){
                infile = argv[i+1];
                file_count++;
            }
            else{
                printf("Error: No input file specified.\n");
                return 1;
            }
        }
        else if(strcmp(argv[i], "-o") == 0){
            if(i+1 < argc){
                outfile = argv[i+1];
                file_count++;
            }
            else{
                printf("Error: No output file specified.\n");
                return 1;
            }
        }
    }

    if(file_count != 2){
        printf("Error: Missing input or output file.\n");
        return 1;
    }

    FILE *inptr = fopen(infile, "r");
    if(inptr == NULL){
        printf("Error: Cannot open input file %s.\n", infile);
        return 1;
    }

    FILE *outptr = fopen(outfile, "w");
    if(outptr == NULL){
        fclose(inptr);
        printf("Error: Cannot open output file %s.\n", outfile);
        return 1;
    }

    unsigned char buffer[BLOCK_SIZE];
    int block_count = 0;
    int jpg_found = 0;

    while(fread(buffer, BLOCK_SIZE, 1, inptr) == 1){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            jpg_found = 1;
            block_count = 1;
        }

        if(jpg_found == 1){
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
            clean_buffer(buffer, BLOCK_SIZE);
        }

        if(jpg_found == 1 && buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            fclose(outptr);
            char filename[8];
            sprintf(filename, "%03i.jpg", block_count);
            outptr = fopen(filename, "w");
            block_count++;
        }
    }

    fclose(inptr);
    fclose(outptr);
    return 0;
}