//FormAI DATASET v1.0 Category: Image Steganography ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp1, *fp2;
    char ch1, ch2, c;
    int bitcount, flag;

    //opening the cover image file in read mode
    fp1 = fopen("cover_img.bmp", "rb");
    if(fp1 == NULL){
        printf("Error opening cover image file!");
        exit(1);
    }

    //opening the secret file in read mode
    fp2 = fopen("secret_file.txt", "r");
    if(fp2 == NULL){
        printf("Error opening secret file!");
        exit(1);
    }

    //creating a new steganographic image file in write mode
    FILE *fp3 = fopen("steganographic_img.bmp", "wb");

    //copying the initial 54 bytes from the cover file to steganographic file
    for(int i=0;i<54;i++){
        ch1 = fgetc(fp1);
        fputc(ch1, fp3);
    }

    //scanning the cover file bit by bit
    while((ch1=fgetc(fp1))!=EOF){

        //setting a flag to check if a bit of secret file has been written or not
        flag = 0;

        //scanning the first 8 bits of the cover file
        for(bitcount=0;bitcount<8;bitcount++){

            if((ch2=fgetc(fp2))!=EOF){

                //reading the bit from secret file
                int bit = ch2-'0';

                //getting the last bit of the cover file's pixel value
                c = ch1;
                c = c & 1;

                //modifying the pixel value if bit in secret file is different
                if(c==0 && bit==1){
                    c = ch1 | 1;
                    flag = 1;
                }
                else if(c==1 && bit==0){
                    c = ch1 & 0xFE;
                    flag = 1;
                }
            }
            else{
                //if secret file has less bits than the cover file's pixels, filling zeros
                c = ch1 & 0xFE;
                flag = 1;
            }

            fputc(c, fp3);
            ch1 = fgetc(fp1);

            //checking if the end of cover file has been reached
            if(ch1==EOF){
                break;
            }
        }

        //if flag is not set even after scanning 8 bits of the secret file
        //it means end of secret file has been reached but more cover file bytes are remaining
        if(flag == 0){
            break;
        }
        //moving back to the last read character to start scanning next 8 bits
        fseek(fp2, -1, SEEK_CUR);
    }

    //closing all the files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("Steganography done successfully!");

    return 0;
}