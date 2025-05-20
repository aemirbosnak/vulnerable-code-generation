//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

#define WATERMARK_SIZE 8
#define SECRET_KEY 1234

//Watermark structure
struct watermark{
    unsigned char watermark_bytes[WATERMARK_SIZE];
};

/* Apply digital watermark to the image */
void apply_digital_watermark(FILE *img_file, FILE *wm_file){
    int image_byte, wm_byte, xor_byte;
    struct watermark wm;
    
    /* Read watermark bytes from file */
    fread(&wm, sizeof(struct watermark), 1, wm_file);
    
    /* Calculate XOR byte */
    xor_byte = SECRET_KEY % 256;
    
    /* Apply digital watermark to the image */
    while((image_byte = fgetc(img_file)) != EOF){
        wm_byte = wm.watermark_bytes[0] ^ xor_byte;
        image_byte = image_byte & ~(1u << 0) | (wm_byte & 1u) << 0;
        
        wm_byte = wm.watermark_bytes[1] ^ xor_byte;
        image_byte = image_byte & ~(1u << 1) | (wm_byte & 1u) << 1;
        
        wm_byte = wm.watermark_bytes[2] ^ xor_byte;
        image_byte = image_byte & ~(1u << 2) | (wm_byte & 1u) << 2;
        
        wm_byte = wm.watermark_bytes[3] ^ xor_byte;
        image_byte = image_byte & ~(1u << 3) | (wm_byte & 1u) << 3;
        
        wm_byte = wm.watermark_bytes[4] ^ xor_byte;
        image_byte = image_byte & ~(1u << 4) | (wm_byte & 1u) << 4;
        
        wm_byte = wm.watermark_bytes[5] ^ xor_byte;
        image_byte = image_byte & ~(1u << 5) | (wm_byte & 1u) << 5;
        
        wm_byte = wm.watermark_bytes[6] ^ xor_byte;
        image_byte = image_byte & ~(1u << 6) | (wm_byte & 1u) << 6;
        
        wm_byte = wm.watermark_bytes[7] ^ xor_byte;
        image_byte = image_byte & ~(1u << 7) | (wm_byte & 1u) << 7;
        
        /* Write the new byte to the image */
        fputc(image_byte, img_file);
    }
}

/* Verify the existance of digital watermark in the image */
int verify_digital_watermark(FILE *img_file, FILE *wm_file){
    int image_byte, wm_byte, xor_byte, verify = 1, i;
    struct watermark wm;
    
    /* Read watermark bytes from file */
    fread(&wm, sizeof(struct watermark), 1, wm_file);
    
    /* Calculate XOR byte */
    xor_byte = SECRET_KEY % 256;
    
    /* Verify digital watermark in the image */
    while((image_byte = fgetc(img_file)) != EOF){
        wm_byte = 0;
        
        for(i=0;i<WATERMARK_SIZE;i++){
            wm_byte = wm_byte | ((image_byte & (1u << i)) >> i) << i;
        }
        
        wm_byte = wm_byte ^ xor_byte;
        
        if(wm_byte != wm.watermark_bytes[i]){
            verify = 0;
            break;
        }
    }
    
    return verify;
}

int main(){
    FILE *img_file, *wm_file;
    int choice;
    
    printf("1. Apply digital watermark\n");
    printf("2. Verify digital watermark\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    img_file = fopen("image.jpg", "rb");
    
    if(choice == 1){
        wm_file = fopen("watermark.bin", "rb");
        apply_digital_watermark(img_file, wm_file);
        fclose(wm_file);
    }
    else if(choice == 2){
        wm_file = fopen("watermark.bin", "wb");
        verify_digital_watermark(img_file, wm_file);
        fclose(wm_file);
    }
    
    fclose(img_file);
    
    return 0;
}