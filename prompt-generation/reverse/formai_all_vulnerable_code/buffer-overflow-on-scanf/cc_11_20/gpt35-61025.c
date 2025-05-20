//FormAI DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_FILE_SIZE 100000

int main(){

    //Variables for opening and reading image files
    FILE *fp_img, *fp_stego_img;
    unsigned char img_data[MAX_FILE_SIZE], stego_img_data[MAX_FILE_SIZE];
    int img_size, stego_img_size;
    char img_path[100], stego_img_path[100];

    //Variables for encoding secret text into image
    char secret_text[1000];
    int secret_text_len;
    char binary_secret_text[8000];
    int binary_secret_text_len;
    int i, j, k, l, m, n, p, q, r, s;

    //Ask user for input image and secret text
    printf("Enter input image path: ");
    scanf("%s", img_path);
    printf("Enter secret text: ");
    getchar();
    fgets(secret_text, 1000, stdin);
    secret_text_len = strlen(secret_text) - 1;

    //Convert secret text to binary
    for(i = 0; i < secret_text_len; i++){
        for(j = 7; j >= 0; j--){
            binary_secret_text[(i*8)+(7-j)] = ((secret_text[i] >> j) & 1) + '0';
        }
    }
    binary_secret_text_len = secret_text_len * 8;

    //Open input image file for reading
    fp_img = fopen(img_path, "rb");
    if(fp_img == NULL){
        printf("Error opening input image file.\n");
        return 0;
    }

    //Get size of input image and read image data
    fseek(fp_img, 0, SEEK_END);
    img_size = ftell(fp_img);
    fseek(fp_img, 0, SEEK_SET);
    fread(img_data, 1, img_size, fp_img);
    fclose(fp_img);

    //Copy input image data to stego image data
    for(i = 0; i < img_size; i++){
        stego_img_data[i] = img_data[i];
    }
    stego_img_size = img_size;

    //Encode binary secret text into stego image data
    m = 0;
    n = 0;
    p = 0;
    q = 0;
    r = 0;
    s = 0;
    for(i = 0; i < binary_secret_text_len; i++){
        if(m >= img_size){
            break;
        }
        stego_img_data[m] &= ~(1 << n);
        stego_img_data[m] |= ((binary_secret_text[i]-'0') << n);
        n++;
        if(n >= 8){
            n = 0;
            m++;
        }
        if(m >= img_size){
            break;
        }
        stego_img_data[m] &= ~(1 << p);
        stego_img_data[m] |= ((binary_secret_text[i]-'0') << p);
        p++;
        if(p >= 8){
            p = 0;
            m++;
        }
        if(m >= img_size){
            break;
        }
        stego_img_data[m] &= ~(1 << q);
        stego_img_data[m] |= ((binary_secret_text[i]-'0') << q);
        q++;
        if(q >= 8){
            q = 0;
            m++;
        }
        if(m >= img_size){
            break;
        }
        stego_img_data[m] &= ~(1 << r);
        stego_img_data[m] |= ((binary_secret_text[i]-'0') << r);
        r++;
        if(r >= 8){
            r = 0;
            m++;
        }
        if(m >= img_size){
            break;
        }
        stego_img_data[m] &= ~(1 << s);
        stego_img_data[m] |= ((binary_secret_text[i]-'0') << s);
        s++;
        if(s >= 8){
            s = 0;
            m++;
        }
    }

    //Ask user for stego image path and open stego image file for writing
    printf("Enter stego image path: ");
    scanf("%s", stego_img_path);
    fp_stego_img = fopen(stego_img_path, "wb");
    if(fp_stego_img == NULL){
        printf("Error opening stego image file.\n");
        return 0;
    }

    //Write stego image data to stego image file and close file
    fwrite(stego_img_data, 1, img_size, fp_stego_img);
    fclose(fp_stego_img);

    //Display success message
    printf("Secret text encoded into image successfully!\n");

    return 0;
}