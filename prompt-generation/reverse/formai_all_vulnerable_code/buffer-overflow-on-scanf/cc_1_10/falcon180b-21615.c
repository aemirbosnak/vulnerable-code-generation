//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000000

struct Pixel{
    int red, green, blue;
}image[MAX_SIZE];

int main(){
    FILE *fp;
    char filename[20];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp=fopen(filename, "rb");
    if (fp==NULL){
        printf("Error opening file\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&image[0].red, sizeof(int), 1, fp);
    fread(&image[0].green, sizeof(int), 1, fp);
    fread(&image[0].blue, sizeof(int), 1, fp);

    int width, height;
    fseek(fp, 28, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    int size=3*width*height;
    for (int i=1; i<size; i++){
        fread(&image[i].red, sizeof(int), 1, fp);
        fread(&image[i].green, sizeof(int), 1, fp);
        fread(&image[i].blue, sizeof(int), 1, fp);
    }

    fclose(fp);

    char message[100];
    printf("Enter the message to be hidden: ");
    scanf("%s", message);

    int message_size=strlen(message);
    int index=0;

    for (int i=0; i<size; i+=3){
        if (i+message_size<=size){
            image[i].red=(image[i].red&0xf0)|(message[index]&0x0f);
            image[i+1].green=(image[i+1].green&0xf0)|(message[index+1]&0x0f);
            image[i+2].blue=(image[i+2].blue&0xf0)|(message[index+2]&0x0f);
            index+=3;
        }
    }

    fp=fopen(filename, "wb");
    if (fp==NULL){
        printf("Error opening file\n");
        exit(1);
    }

    fwrite(&image[0].red, sizeof(int), 1, fp);
    fwrite(&image[0].green, sizeof(int), 1, fp);
    fwrite(&image[0].blue, sizeof(int), 1, fp);

    fseek(fp, 28, SEEK_SET);
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    for (int i=0; i<size; i++){
        fwrite(&image[i].red, sizeof(int), 1, fp);
        fwrite(&image[i].green, sizeof(int), 1, fp);
        fwrite(&image[i].blue, sizeof(int), 1, fp);
    }

    fclose(fp);

    printf("Message hidden successfully\n");

    return 0;
}