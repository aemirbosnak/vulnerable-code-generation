//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate the checksum
int checksum(char *str, int len){
    int sum = 0, i;
    for(i=0; i<len; i++){
        sum += str[i];
    }
    return sum;
}

// Function to embed the watermark recursively
void embed_watermark(char *input_file, char *output_file, char *watermark, int len, int index){
    
    FILE *f1 = fopen(input_file, "rb");
    if(f1 == NULL){
        printf("File not found!\n");
        exit(0);
    }
    
    // Get the length of the input file
    fseek(f1, 0, SEEK_END);
    int input_len = ftell(f1);
    fseek(f1, 0, SEEK_SET);

    // Allocate memory for the input file
    char *input_data = (char*) malloc(input_len);

    // Read input file data
    fread(input_data, sizeof(char), input_len, f1);
    fclose(f1);

    // Calculate checksum of the input file
    int csum = checksum(input_data, input_len);
    
    // Check if the input file contains the watermark
    if(strstr(input_data, watermark) != NULL){
        printf("Watermark already embedded!\n");
        return;
    }
    
    // Check if the input file has enough space to embed the watermark
    if(index+len > input_len){
        printf("Not enough space in the file to embed the watermark!\n");
        return;
    }

    // Embed the watermark in the input data recursively
    int i, j = 0;
    for(i=index; i<index+len; i++){
        input_data[i] = watermark[j];
        j++;
    }

    // Embed the checksum in the input data after the watermark
    char csum_str[10];
    sprintf(csum_str, "%d", csum);
    for(i=index+len; i<=index+len+strlen(csum_str); i++){
        input_data[i] = csum_str[i-index-len];
    }

    // Write the output file with the embedded watermark
    FILE *f2 = fopen(output_file, "wb");
    fwrite(input_data, sizeof(char), input_len, f2);
    fclose(f2);

    // Embed the watermark in the output file again after some space
    if(index+len+strlen(csum_str)+1 < input_len){
        embed_watermark(output_file, output_file, watermark, len, index+len+strlen(csum_str)+1);
    }
}

int main(){
    char input_file[50], output_file[50], watermark[50];
    int len, index;
    printf("Enter the input file name : ");
    scanf("%s", input_file);
    printf("Enter the output file name : ");
    scanf("%s", output_file);
    printf("Enter the watermark to be embedded : ");
    scanf("%s", watermark);
    printf("Enter the length of the watermark : ");
    scanf("%d", &len);
    printf("Enter the starting index to embed the watermark : ");
    scanf("%d", &index);
    embed_watermark(input_file, output_file, watermark, len, index);
    printf("Watermark embedded successfully!\n");
    return 0;
}