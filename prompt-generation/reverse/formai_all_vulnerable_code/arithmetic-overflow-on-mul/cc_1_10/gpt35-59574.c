//FormAI DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int password = 1290; // Global variable to hold the password.

// Function to check if a number is prime or not.
int isPrime(int n){
    int i, flag = 0;

    for(i = 2; i <= sqrt(n); i++){

        if(n % i == 0){
            flag = 1;
            break;
        }
    }

    if(n == 1){
        return 0;
    }
    else{
        if(flag == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
}

// Function to perform steganography encoding.
void steganographyEncode(char *msg, char *cover_image, char *output_image){

    FILE *fp1, *fp2;
    int i, j, k, ch, flag = 0, msg_length;
    long int image_size;
    char secret_char, cover_char;
    int secret_char_binary[8];
    int cover_char_binary[8];

    fp1 = fopen(msg,"r");
    fp2 = fopen(cover_image,"rb");

    if(fp1 == NULL || fp2 == NULL){
        printf("Error opening file.\n");
        exit(0);
    }

    // Finding the length of message.
    fseek(fp1, 0, SEEK_END);
    msg_length = ftell(fp1);
    rewind(fp1);

    // Finding the size of cover_image.
    fseek(fp2, 0, SEEK_END);
    image_size = ftell(fp2);
    rewind(fp2);

    // Checking if the message can be embedded in the image or not.
    if((msg_length + 2) * 8 > image_size){
        printf("Message can not be embedded in the given cover image.\n");
        return;
    }

    // Encoding the length of message and password.
    for(i = 0; i < 32; i++){

        // Reading a character of cover image and converting it to binary.
        ch = getc(fp2);
        for(j = 7; j >= 0; j--){
            cover_char_binary[j] = ch % 2;
            ch = ch / 2;
        }

        if(i < 16){
            cover_char_binary[7] = cover_char_binary[7] | ((msg_length >> (15 - i)) & 1);
        }
        else{
            cover_char_binary[7] = cover_char_binary[7] | ((password >> (i - 16)) & 1);
        }

        ch = 0;

        // Converting binary to integer.
        for(j = 0; j < 8; j++){
            ch = ch * 2 + cover_char_binary[j];
        }

        // Embedding the modified character of cover image to output image.
        putc(ch, fp2);
    }

    // Embedding the message in the cover image.
    for(i = 0; i < msg_length; i++){

        // Reading a character of message and converting it to binary.
        ch = getc(fp1);
        for(j = 7; j >= 0; j--){
            secret_char_binary[j] = ch % 2;
            ch = ch / 2;
        }

        // Reading a character of cover image and converting it to binary.
        ch = getc(fp2);
        for(j = 7; j >= 0; j--){
            cover_char_binary[j] = ch % 2;
            ch = ch / 2;
        }

        // Embedding the secret character in the least significant bit of cover image character.
        for(j = 0; j < 8; j++){
            if(cover_char_binary[j] != secret_char_binary[j]){
                if(cover_char_binary[j] == 0){
                    cover_char_binary[j] = 1;
                }
                else{
                    cover_char_binary[j] = 0;
                }
                flag = 1;
            }
            if(flag == 1){
                break;
            }
        }

        ch = 0;

        // Converting binary to integer.
        for(j = 0; j < 8; j++){
            ch = ch * 2 + cover_char_binary[j];
        }

        // Embedding the modified character of cover image to output image.
        putc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    printf("Steganography encoding successful.\n");
}

// Function to perform steganography decoding.
void steganographyDecode(char *stego_image, char *msg){

    FILE *fp1;
    int i, j, ch;
    int password_binary[16];
    long int image_size, msg_length = 0;
    char temp_secret_binary[8], secret_char, cover_char;
    int secret_char_binary[8];
    int cover_char_binary[8];

    fp1 = fopen(stego_image,"rb");

    if(fp1 == NULL){
        printf("Error opening file.\n");
        exit(0);
    }

    // Retrieving the length of message and password.
    for(i = 0; i < 32; i++){

        // Reading a character of cover image and converting it to binary.
        ch = getc(fp1);
        for(j = 7; j >= 0; j--){
            cover_char_binary[j] = ch % 2;
            ch = ch / 2;
        }

        if(i < 16){
            msg_length = msg_length + (cover_char_binary[7] * pow(2, (15 - i)));
        }
        else{
            password_binary[i - 16] = cover_char_binary[7];
        }

    }

    // Checking the password.
    for(i = 0; i < 16; i++){

        // Reading a character of cover image and converting it to binary.
        ch = getc(fp1);
        for(j = 7; j >= 0; j--){
            cover_char_binary[j] = ch % 2;
            ch = ch / 2;
        }

        if(cover_char_binary[7] != password_binary[i]){
            printf("Password incorrect.\n");
            return;
        }
    }

    // Decoding the message from the stego image.
    fp1 = fopen(stego_image,"rb");
    fp1 = fopen(msg,"w");

    for(i = 0; i < msg_length; i++){

        // Reading a character of cover image and converting it to binary.
        ch = getc(fp1);
        for(j = 7; j >= 0; j--){
            cover_char_binary[j] = ch % 2;
            ch = ch / 2;
        }

        // Extracting the secret character from the least significant bit of cover image character.
        for(j = 0; j < 8; j++){
            secret_char_binary[j] = cover_char_binary[j];
        }

        ch = 0;

        // Converting binary to integer.
        for(j = 0; j < 8; j++){
            ch = ch * 2 + secret_char_binary[j];
        }

        // Writing the secret character to the message file.
        putc(ch, fp1);
    }

    printf("Steganography decoding successful.\n");
}

int main(){

    int choice;
    char msg_file[20], cover_image_file[30], output_image_file[30], stego_image_file[30];

    printf("Enter your choice\n");
    printf("1. Encode message in an image.\n");
    printf("2. Decode message from an image.\n");
    scanf("%d", &choice);

    switch(choice){

        case 1: 
            printf("Enter name of message file: ");
            scanf("%s", msg_file);
            getchar();
            printf("Enter name of cover image file (bmp format only): ");
            scanf("%s", cover_image_file);
            getchar();
            printf("Enter name of output image file: ");
            scanf("%s", output_image_file);
            getchar();
            printf("Enter password: ");
            scanf("%d", &password);

            steganographyEncode(msg_file, cover_image_file, output_image_file);
            break;

        case 2:
            printf("Enter name of stego image file (bmp format only): ");
            scanf("%s", stego_image_file);
            getchar();
            printf("Enter name of output message file: ");
            scanf("%s", msg_file);
            getchar();
            printf("Enter password: ");
            scanf("%d", &password);

            steganographyDecode(stego_image_file, msg_file);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}