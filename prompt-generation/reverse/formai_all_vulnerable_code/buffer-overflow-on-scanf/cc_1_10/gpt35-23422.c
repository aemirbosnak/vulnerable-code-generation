//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void embed_watermark(FILE *input_file, FILE *output_file, int watermark){
    char buffer;
    int bit_pos = 0;
    srand(time(NULL)); //Seed for random generator
    while(fread(&buffer, sizeof(buffer), 1, input_file) == 1){
        for(int i = 0; i < 8; i++){
            if(bit_pos == watermark){ //If watermark has already been embedded
                fwrite(&buffer, sizeof(buffer), 1, output_file); //Just copy the rest of the input file to output file
                while(fread(&buffer, sizeof(buffer), 1, input_file) == 1){
                    fwrite(&buffer, sizeof(buffer), 1, output_file);
                }
                return;
            }
            int random_bit = rand() % 2; //Generate random bit 
            if(random_bit == 1){ //If random bit is 1
                buffer |= 1 << i; //Set the LSB of the buffer to 1
            }
            else{ //If random bit is 0
                buffer &= ~(1 << i); //Clear the LSB of the buffer
            }
            bit_pos++; //Update the position of the current bit in the watermark
        }
        fwrite(&buffer, sizeof(buffer), 1, output_file); //Write the modified buffer to output file
    }
}

int extract_watermark(FILE* input_file){
    char buffer;
    int watermark = 0;
    int bit_pos = 0;
    while(fread(&buffer, sizeof(buffer), 1, input_file) == 1){
        for(int i = 0; i < 8; i++){
            if(bit_pos < 32){ //If watermark has not been extracted yet
                int bit = (buffer >> i) & 1; //Extract the next bit from the buffer
                watermark |= bit << bit_pos; //Set the extracted bit in the watermark
                bit_pos++; //Update the position of the current bit in the watermark
            }
            else{ //If watermark extraction is complete
                return watermark;
            }
        }
    }
    return -1; //Watermark extraction failed
}

int main(){
    FILE *input_file, *output_file, *watermarked_file;
    int watermark;
    char input_file_name[100], output_file_name[100], watermarked_file_name[100];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);
    input_file = fopen(input_file_name, "rb"); //Open input file in binary mode
    if(input_file == NULL){
        printf("Error opening input file!\n");
        return 1;
    }
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);
    output_file = fopen(output_file_name, "wb"); //Open output file in binary mode
    if(output_file == NULL){
        printf("Error opening output file!\n");
        return 1;
    }
    printf("Enter the name of the watermarked file: ");
    scanf("%s", watermarked_file_name);
    watermarked_file = fopen(watermarked_file_name, "wb"); //Open watermarked file in binary mode
    if(watermarked_file == NULL){
        printf("Error opening watermarked file!\n");
        return 1;
    }
    printf("Enter the watermark: ");
    scanf("%d", &watermark);
    embed_watermark(input_file, watermarked_file, watermark); //Embed the watermark in input file and write to watermarked file
    fseek(watermarked_file, 0, SEEK_SET); //Set file pointer at the beginning of watermarked file
    watermark = extract_watermark(watermarked_file); //Extract the watermark from watermarked file
    if(watermark == -1){
        printf("Watermark extraction failed!\n");
        return 1;
    }
    printf("Extracted watermark: %d\n", watermark);
    fclose(input_file);
    fclose(output_file);
    fclose(watermarked_file);
    return 0;
}