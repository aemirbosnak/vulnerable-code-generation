//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Paranoia level:
    1 - use all caps for watermark bits
    2 - randomly shuffle watermark bits
    3 - add fake watermarks to throw off detection
*/

int main(int argc, char ** argv){
    if(argc != 3){
        printf("Usage: %s [file to watermark] [watermark string]\n", argv[0]);
        return 1;
    }
    // read the file and calculate the checksum
    FILE * file = fopen(argv[1], "rb");
    char * buffer = malloc(sizeof(char) * 1024);
    unsigned long checksum = 0;
    while(fread(buffer, sizeof(char), 1024, file) > 0){
        for(int i = 0; i < 1024; i++){
            checksum += (unsigned long)buffer[i];
        }
    }
    rewind(file);

    // generate the watermark data
    char * watermark = argv[2];
    int watermark_len = strlen(watermark);
    char * watermark_bits = malloc(sizeof(char) * (watermark_len + 1));
    strcpy(watermark_bits, watermark);
    for(int i = 0; i < watermark_len; i++){
        if(watermark_bits[i] >= 'a' && watermark_bits[i] <= 'z'){
            watermark_bits[i] = watermark_bits[i] - 'a' + 'A';
        }
    }

    // embed the watermark bits
    int paranoia_level = 3;
    int embed_pos = 0;
    if(paranoia_level >= 1){
        embed_pos = (checksum % watermark_len);
        for(int i = 0; i < watermark_len; i++){
            if(watermark_bits[i] >= 'a' && watermark_bits[i] <= 'z'){
                watermark_bits[i] = watermark_bits[i] - 'a' + 'A';
            }
        }
    }
    if(paranoia_level >= 2){
        for(int i = 0; i < watermark_len; i++){
            int swap_pos = (checksum % watermark_len);
            char tmp = watermark_bits[i];
            watermark_bits[i] = watermark_bits[swap_pos];
            watermark_bits[swap_pos] = tmp;
            checksum = (checksum * i) % watermark_len;
        }
    }
    if(paranoia_level >= 3){
        int num_fake_watermarks = (checksum % watermark_len) + 1;
        for(int i = 0; i < num_fake_watermarks; i++){
            int fake_pos = (checksum * i) % (watermark_len + 1);
            memcpy(watermark_bits + fake_pos + 1, watermark_bits + fake_pos, watermark_len - fake_pos);
            watermark_bits[fake_pos] = ' ';
        }
    }
    // write the watermarked file
    FILE * output_file = fopen(strcat(argv[1], ".wm"), "wb");
    int watermark_bit_pos = 0;
    int watermark_bit_len = strlen(watermark_bits);
    while(fread(buffer, sizeof(char), 1024, file) > 0){
        for(int i = 0; i < 1024; i++){
            if(embed_pos == 0 && watermark_bit_pos < watermark_bit_len){
                buffer[i] |= watermark_bits[watermark_bit_pos];
                watermark_bit_pos++;
                if(watermark_bit_pos == watermark_bit_len){
                    break;
                }
            } else {
                embed_pos--;
            }
        }
        fwrite(buffer, sizeof(char), 1024, output_file);
    }

    fclose(file);
    fclose(output_file);
    free(buffer);
    free(watermark_bits);
    return 0;
}