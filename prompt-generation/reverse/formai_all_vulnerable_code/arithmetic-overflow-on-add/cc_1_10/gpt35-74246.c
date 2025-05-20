//FormAI DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to hide message inside image
void encodeImage(char* image, char* message){
    FILE *fp1, *fp2;
    fp1 = fopen(image, "rb+");
    fp2 = fopen(message, "rb");

    //Get File size of message
    fseek(fp2, 0, SEEK_END);        
    int sizeMsg = ftell(fp2);

    //Calculate pixel required to hide the whole message
    int pixelReq = sizeMsg * 8 / 3;
    
    //Move the pointer position to image data
    fseek(fp1, 54, SEEK_SET);
    
    char msg[sizeMsg+1], ch;
    int i = 0, j, pixelCount = 0, bitCount = 0, flag = 0;

    //Read message from file
    rewind(fp2);
    while((ch=fgetc(fp2))!=EOF){
        msg[i] = ch;
        i++;
    }
    msg[i] = '\0';

    //Loop for reading image data
    while((ch=fgetc(fp1))!=EOF){
        //Check if all the message is hidden
        if(bitCount == sizeMsg * 8){
            break;
        }
        //Check if pixel count is less than pixel required to message
        if(pixelCount < pixelReq){
            if(!flag){
                //Hide data of red pixel
                if(bitCount < sizeMsg * 8){
                    ch |= (msg[bitCount/8] & (1<<(bitCount%8)))>>(bitCount%8);
                    bitCount++;
                }
                fputc(ch, fp1);
            }
            if(!flag){
                flag = 1;
            }
            else{
                //Hide data of green pixel
                if(bitCount < sizeMsg * 8){
                    ch |= (msg[bitCount/8] & (1<<(bitCount%8)))>>(bitCount%8);
                    bitCount++;
    
                }
                fputc(ch, fp1);
                flag = 0;
            }
            pixelCount++;
        }
    }
    printf("Message hidden successfully in the image!\n");
    fclose(fp1);
    fclose(fp2);
}

//Function to extract hidden message from image
void decodeImage(char* image){
    FILE *fp1;
    fp1 = fopen(image, "rb+");

    //Move the pointer position to image data
    fseek(fp1, 54, SEEK_SET);
    
    char ch;
    int bitCount = 0, byteCount = 0;
    char msg[100000];

    //Loop for reading image data
    while((ch=fgetc(fp1))!=EOF){
        //Check if all the message is extracted
        if(bitCount == 300000){
            break;
        }
        //Extract data from red pixel
        if(byteCount%3 == 0){
            msg[bitCount/8] |= (ch & 0b00000001)<<(bitCount%8);
            bitCount++;
        }
        //Extract data from green pixel
        else if(byteCount%3 == 1){
            msg[bitCount/8] |= (ch & 0b00000001)<<(bitCount%8);
            bitCount++;
        }
        //Extract none from blue pixel
        byteCount++;
    }
    msg[bitCount/8] = '\0';

    printf("The hidden message is: %s\n", msg);
    fclose(fp1);
}

//Main Function
int main(int argc, char **argv){
    char* image = argv[1];
    char* message = argv[2];
    char* decodeArg = argv[3];

    //Hide Message in an Image
    if(decodeArg == NULL){
        encodeImage(image, message);
    }
    //Extract Message from Image
    else{
        decodeImage(image);
    }
    return 0;
}