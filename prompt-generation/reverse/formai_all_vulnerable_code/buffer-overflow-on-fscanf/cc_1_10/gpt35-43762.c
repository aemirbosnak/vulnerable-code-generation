//FormAI DATASET v1.0 Category: Image Steganography ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to convert decimal to binary
void dtob(int n,int *res)
{
    int i=7;
    while(n>0)
    {
        res[i]=n%2;
        n=n/2;
        i--;
    }
}

//function to convert binary to decimal
int btod(int *arr)
{
    int res=0,pw=1;
    for(int i=7;i>=0;i--)
    {
        res+=arr[i]*pw;
        pw*=2;
    }
    return res;
}

//function to perform image steganography
void stegano(char *imgName,char *secretMsg,char *destImgName)
{
    //open input image file
    FILE *img=fopen(imgName,"rb");
    if(img==NULL)
    {
        printf("Error! Cannot open input image file.");
        exit(1);
    }

    //open/ create destination image file
    FILE *destImg=fopen(destImgName,"wb");
    if(destImg==NULL)
    {
        printf("Error! Cannot open/ create destination image file.");
        exit(1);
    }

    //open secret message file
    FILE *sMsg=fopen(secretMsg,"r");
    if(sMsg==NULL)
    {
        printf("Error! Cannot open secret message file.");
        exit(1);
    }

    //get image size
    fseek(img,0,SEEK_END); //move file pointer to end
    int imgSize=ftell(img); //get file size
    fseek(img,0,SEEK_SET); //move file pointer to beginning

    //allocate memory for image data
    unsigned char *imgData=malloc(imgSize);

    //read input image file into memory
    fread(imgData,1,imgSize,img);

    //get secret message size
    fseek(sMsg,0,SEEK_END); //move file pointer to end
    int sMsgSize=ftell(sMsg); //get file size
    fseek(sMsg,0,SEEK_SET); //move file pointer to beginning

    //check if secret message can be embedded into given image
    if(sMsgSize*8 > imgSize/3) //3 bytes per pixel
    {
        printf("Error! Secret message is too large to be embedded into given image.");
        exit(1);
    }

    //embed secret message into image
    int i=0,j=0,singleBits[8],numBits=0;
    char c;
    while(fscanf(sMsg,"%c",&c) != EOF)
    {
        dtob(c,singleBits); //convert character to bits
        for(int k=0;k<8;k++)
        {
            imgData[i*3+j]=imgData[i*3+j] & 0xFE; //clear least significant bit
            imgData[i*3+j]=imgData[i*3+j] | singleBits[k]; //embed bit into least significant bit
            j++;
            if(j==3) //move to next pixel
            {
                i++;
                j=0;
            }
        }
        numBits+=8; //count number of bits embedded
    }

    //finalize message
    int finalBits[8];
    dtob(numBits,finalBits); //get number of bits embedded in binary
    for(int k=0;k<8;k++) //embed binary in image
    {
        imgData[i*3+j]=imgData[i*3+j] & 0xFE; //clear least significant bit
        imgData[i*3+j]=imgData[i*3+j] | finalBits[k]; //embed bit into least significant bit
        j++;
        if(j==3) //move to next pixel
        {
            i++;
            j=0;
        }
    }

    //write embedded image data to destination file
    fwrite(imgData,1,imgSize,destImg);

    //free allocated memory and close files
    free(imgData);
    fclose(img);
    fclose(sMsg);
    fclose(destImg);

    printf("Secret message embedded successfully.");
}

//function to extract secret message from image
void extract(char *imgName,char *destMsgName)
{
    //open image file
    FILE *img=fopen(imgName,"rb");
    if(img==NULL)
    {
        printf("Error! Cannot open image file.");
        exit(1);
    }

    //open/ create destination secret message file
    FILE *destMsg=fopen(destMsgName,"w");
    if(destMsg==NULL)
    {
        printf("Error! Cannot open/ create destination secret message file.");
        exit(1);
    }
    
    //get image size
    fseek(img,0,SEEK_END); //move file pointer to end
    int imgSize=ftell(img); //get file size
    fseek(img,0,SEEK_SET); //move file pointer to beginning

    //allocate memory for image data
    unsigned char *imgData=malloc(imgSize);

    //read image file into memory
    fread(imgData,1,imgSize,img);

    //extract number of embedded bits
    int i=0,j=0,numBits=0,binary[8];
    for(int k=0;k<8;k++) //extract binary
    {
        binary[k]=imgData[i*3+j] & 0x01; //get least significant bit
        j++;
        if(j==3) //move to next pixel
        {
            i++;
            j=0;
        }
    }
    numBits=btod(binary); //convert binary to decimal

    //extract secret message
    int singleBits[8],c=0;
    while(c<numBits)
    {
        for(int k=0;k<8;k++) //extract bits
        {
            singleBits[k]=imgData[i*3+j] & 0x01; //get least significant bit
            j++;
            if(j==3) //move to next pixel
            {
                i++;
                j=0;
            }
        }
        c+=8;
        fputc(btod(singleBits),destMsg); //write character to secret message file
    }

    //free allocated memory and close files
    free(imgData);
    fclose(img);
    fclose(destMsg);

    printf("Secret message extracted successfully.");
}

//driver function
int main()
{
    //perform image steganography
    stegano("inputImage.bmp","secretMsg.txt","outputImage.bmp");

    //extract secret message
    extract("outputImage.bmp","extractedMsg.txt");

    return 0;
}