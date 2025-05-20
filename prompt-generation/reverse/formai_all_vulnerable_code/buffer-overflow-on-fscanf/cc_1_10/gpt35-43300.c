//FormAI DATASET v1.0 Category: Image Steganography ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to convert ASCII value of a character into 8-bit binary form
void char_to_binary(char c, char *binary){
    //Iterating over 8 bits and converting them into binary form
    for(int i=7; i>=0; i--){
        binary[7-i] = (c & (1<<i)) ? '1' : '0';
    }
    //Adding NULL terminator at the end of binary string
    binary[8] = '\0';
}

//Main function for Image Steganography
int main(){
    //Initializing variables
    FILE *fptr1, *fptr2,*opfile;
    char filename[100], c, msg[1000], ch[8], buffer[8];
    int len, binarymsgpos=0, count=0, i, j, width, height, maxval, r, g, b, rgb[3], msglen;
    char binarymsg[8000];
    
    //Taking input image file name from user
    printf("Enter Image Filename: ");
    scanf("%s", filename);
    
    //Opening input image file
    fptr1 = fopen(filename, "rb");
    
    //Checking if input image file exists or not
    if(fptr1 == NULL){
        printf("Unable to open file!");
        return 0;
    }

    //Reading header file of PPM image format
    char header[3];
    fscanf(fptr1,"%s\n", header);
    if(strcmp(header, "P6")!=0){
        printf("Invalid image format!!!");
        return 0;
    }
    char buffer1[256];
    fgets(buffer1, sizeof(buffer1), fptr1);
    sscanf(buffer1, "%d %d", &width, &height);
    char buffer2[256];
    fgets(buffer2, sizeof(buffer2), fptr1);
    sscanf(buffer2, "%d", &maxval);
    
    //Printing the width, height and max value from header file of input image
    printf("\nImage Size: %d x %d\n", width, height);
    printf("Max Value: %d\n\n", maxval);
    
    //Taking text message to hide in image from user
    printf("Enter message to hide in image: ");
    scanf(" %[^\n]s", msg);
    len = strlen(msg);
    
    //Converting the text message into binary string
    for(i=0;i<len;i++){
        char_to_binary(msg[i], ch);
        for(j=0;j<8;j++){
            binarymsg[binarymsgpos++] = ch[j];
        }
    }
    binarymsg[binarymsgpos] = '\0';
    msglen = strlen(binarymsg);
    
    //Calculating the number of bits needed to store length of text message
    int msglenbits = 0, temp = msglen;
    while(temp>0){
        temp = temp >> 1;
        msglenbits++;
    }

    //Creating output image file
    opfile = fopen("stegimage.ppm", "wb");
    fprintf(opfile,"%s\n", header);
    fprintf(opfile,"%d %d\n%d\n",width, height,maxval);

    //Storing length of message in image
    count = 0;
    temp = msglen;
    for(i=0;i<msglenbits;i++){
        c = fgetc(fptr1);
        r = c >> 1;
        if((temp & (1<<(msglenbits-1-i)))!=0){
            r = r << 1 | 1;
        }else{
            r = r << 1;
        }
        fputc(r,opfile);
        count++;
    }

    //Storing the binary message in image
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){

            //Reading RGB values of each pixel of the image
            fread(rgb, 1, 3, fptr1);
            r = rgb[0];
            g = rgb[1];
            b = rgb[2];

            //Storing bit of message in red pixel component
            if(binarymsgpos<msglen && count<msglenbits){
                if((binarymsg[binarymsgpos++]=='1' && (r & 1) == 0)){
                    r++;
                }else if((binarymsg[binarymsgpos++]=='0' && (r & 1) == 1)){
                    r--;
                }
                count++;
            }

            //Writing modified RGB values to output image file
            fputc(r,opfile);
            fputc(g,opfile);
            fputc(b,opfile);
        }
    }

    //Closing input and output image file
    fclose(fptr1);
    fclose(opfile);

    //Printing status message
    printf("\nMessage hidden successfully inside image!!!\n");
    
    return 0;
}