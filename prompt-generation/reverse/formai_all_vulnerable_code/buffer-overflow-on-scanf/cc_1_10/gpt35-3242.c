//FormAI DATASET v1.0 Category: Image Steganography ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

/* Function to convert a binary string to decimal */
int binToDec(char *bin){
    int dec = 0, base = 1, len = strlen(bin), i;
    for(i = len-1; i >= 0; i--){
        if(bin[i] == '1'){
            dec += base;
        }
        base *= 2;
    }
    return dec;
}

/* Function to convert a decimal to binary */
void decToBin(int dec, char *bin){
    int i = 0, j;
    char temp[8]; // Temporary storage for binary representation
    while(dec > 0){
        temp[i] = dec%2 + '0'; // Convert remainder to char
        dec /= 2;
        i++;
    }
    // Fill remaining bits with 0's
    for(j = i; j < 8; j++){
        temp[j] = '0';
    }
    // Reverse the binary representation
    for(j = 0; j < 8; j++){
        bin[j] = temp[7-j];
    }
}

int main(){
    FILE *original_img, *stego_img, *key_file;
    char original_name[20], stego_name[20], key_name[20], ch;
    int i, key_len, bit_count = 0, byte_count = 0, bit_index, bit_to_hide, dec_key, dec_ch;
    char bit_str[8], key[512], stego_byte[8];

    // Get filenames from user
    printf("Enter filename of original image: ");
    scanf("%s", &original_name);
    printf("Enter filename of steganographed image: ");
    scanf("%s", &stego_name);
    printf("Enter filename of key file: ");
    scanf("%s", &key_name);

    // Open files
    original_img = fopen(original_name, "rb");
    stego_img = fopen(stego_name, "wb");
    key_file = fopen(key_name, "rb");

    // Get key
    fseek(key_file, 0L, SEEK_END);
    key_len = ftell(key_file);
    fseek(key_file, 0L, SEEK_SET);
    fread(key, 1, key_len, key_file);

    // Embed key in stego image header
    fwrite(key, 1, key_len, stego_img);

    // Hide message in image
    while(!feof(original_img)){
        // Read a byte from original image file
        fread(&ch, 1, 1, original_img);

        // Convert byte to binary
        decToBin((int)ch, bit_str);

        for(i = 0; i < 8; i++){
            // Get next bit to hide
            dec_key = binToDec(&key[byte_count]);
            bit_index = dec_key % 8;
            bit_to_hide = (dec_key / 8) % 2;
            byte_count++;
            bit_count++;

            // Hide the bit
            if(bit_str[i] == '0'){
                if(bit_to_hide == 1){
                    bit_str[i] = '1';
                }
            }
            else{
                if(bit_to_hide == 0){
                    bit_str[i] = '0';
                }
            }

            // Add stego byte to image file if full
            if(bit_count == 8){
                stego_byte[7] = bit_str[0];
                stego_byte[6] = bit_str[1];
                stego_byte[5] = bit_str[2];
                stego_byte[4] = bit_str[3];
                stego_byte[3] = bit_str[4];
                stego_byte[2] = bit_str[5];
                stego_byte[1] = bit_str[6];
                stego_byte[0] = bit_str[7];
                fwrite(&stego_byte, 1, 1, stego_img);
                bit_count = 0;
            }
        }
    }

    // Add remaining stego byte to image file if not full
    if(bit_count > 0){
        for(i = bit_count; i < 8; i++){
            bit_str[i] = '0';
        }
        stego_byte[7] = bit_str[0];
        stego_byte[6] = bit_str[1];
        stego_byte[5] = bit_str[2];
        stego_byte[4] = bit_str[3];
        stego_byte[3] = bit_str[4];
        stego_byte[2] = bit_str[5];
        stego_byte[1] = bit_str[6];
        stego_byte[0] = bit_str[7];
        fwrite(&stego_byte, 1, 1, stego_img);
    }

    // Close files
    fclose(original_img);
    fclose(stego_img);
    fclose(key_file);

    printf("Steganography complete!");

    return 0;
}