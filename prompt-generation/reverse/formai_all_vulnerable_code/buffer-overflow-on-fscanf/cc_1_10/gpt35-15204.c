//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>    
#include <stdlib.h>
#include <string.h>

#define ROWS 512
#define COLUMNS 512
#define MAX_STRING_SIZE 1024

void generate_watermark(int watermark[COLUMNS], char message[MAX_STRING_SIZE]) {  
    int len = strlen(message);  
    for(int i=0; i<len; i++) {  
        char c = message[i];  
        watermark[i] = (int)c;  
    }  
}  

void apply_watermark(int image[ROWS][COLUMNS], int watermark[COLUMNS], int alpha) {  
    for(int i=0; i<ROWS; i++) {  
        for(int j=0; j<COLUMNS; j++) { 
            image[i][j] = image[i][j] + alpha * watermark[j];  
        }  
    }  
}  

void extract_watermark(int image[ROWS][COLUMNS], int watermark[COLUMNS], int alpha) {  
    for(int i=0; i<COLUMNS; i++) {  
        int sum = 0;  
        for(int j=0; j<ROWS; j++) {  
            sum += image[j][i];  
        }  
        watermark[i] = sum / alpha;  
    }  
} 

void print_watermark(int watermark[COLUMNS]) {
    printf("Extracted Watermark: ");
    for(int i=0; i<COLUMNS; i++) {
        printf("%c", (char)watermark[i]);
    }
    printf("\n");
}

int main() {  
    int image[ROWS][COLUMNS];
    int watermark[COLUMNS];

    // Read Image
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Unable to open input file.\n");
        return 0;
    }
    for(int i=0; i<ROWS; i++) {  
        for(int j=0; j<COLUMNS; j++) {  
            fscanf(input_file,"%d",&image[i][j]);  
        }  
    }
    fclose(input_file);

    // Generate and Apply Watermark
    char message[MAX_STRING_SIZE];
    printf("Enter message to watermark: ");
    fgets(message, MAX_STRING_SIZE, stdin);
    int alpha = 20;
    generate_watermark(watermark, message);
    apply_watermark(image, watermark, alpha);

    // Write Watermarked Image
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Unable to open output file.\n");
        return 0;
    }
    for(int i=0; i<ROWS; i++) {  
        for(int j=0; j<COLUMNS; j++) {  
            fprintf(output_file,"%d ",image[i][j]);  
        }  
        fprintf(output_file, "\n");
    }
    fclose(output_file);

    // Read Watermarked Image and Extract Watermark
    FILE *watermarked_file = fopen("output.txt", "r");
    if (watermarked_file == NULL) {
        printf("Unable to open watermarked file.\n");
        return 0;
    }
    for(int i=0; i<ROWS; i++) {  
        for(int j=0; j<COLUMNS; j++) {  
            fscanf(watermarked_file,"%d",&image[i][j]);  
        }  
    }
    fclose(watermarked_file);
    extract_watermark(image, watermark, alpha);

    // Print Extracted Watermark
    print_watermark(watermark);

    return 0;
}