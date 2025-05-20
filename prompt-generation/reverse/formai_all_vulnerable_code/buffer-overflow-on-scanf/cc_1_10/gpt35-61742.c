//FormAI DATASET v1.0 Category: Image Steganography ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef unsigned char byte;

void encode(char* filename, char* message){
    FILE *fin, *fout;
    int i=0, len=0, bit=0, c;
    long w, h, size;
    byte data;
    fin=fopen(filename, "rb");
    if(fin==NULL){
        printf("Error opening input file.");
        return;
    }
    fseek(fin, 18, SEEK_SET);
    fread(&w, sizeof(long), 1, fin);
    fread(&h, sizeof(long), 1, fin);
    size=w*h*3;
    if(strlen(message)*8 + 8 > size){
        printf("Message too big to fit in given image.");
        return;
    }
    fseek(fin, 0, SEEK_SET);
    fout=fopen("stego.bmp", "wb");
    while((c=fgetc(fin))!=EOF){
        if(i<=25){
            fputc(c, fout);
            i++;
        }else if(i<=29){
            if(i==29){
                fputc(108, fout);
            }else{
                fputc(c, fout);
            }
            i++;
        }else if(i<=33){
            if(i==33){
                fputc(9, fout);
            }else{
                fputc(c, fout);
            }
            i++;
        }else{
            if(bit<8*strlen(message)){
                data=((message[bit/8] & (1<<(7-(bit%8))))>0)?1:0;
                w=fgetc(fin);
                h=w;
                w=fgetc(fin);
                fputc(h, fout);
                fputc(w & ~1 | data, fout);
                bit++;
            }else{
                fputc(c, fout);
            }
        }
    }
    fclose(fin);
    fclose(fout);
}

void decode(char* filename){
    FILE *fin;
    int i=0, data, bit=0, c;
    long w, h, size;
    byte byte_data=0;
    fin=fopen(filename, "rb");
    if(fin==NULL){
        printf("Error opening file.");
        return;
    }
    fseek(fin, 18, SEEK_SET);
    fread(&w, sizeof(long), 1, fin);
    fread(&h, sizeof(long), 1, fin);
    size=w*h*3;
    fseek(fin, 54, SEEK_SET);
    while(ftell(fin)<size+54){
        if(bit%8==0){
            byte_data=0;
        }
        c=fgetc(fin);
        w=fgetc(fin);
        if((byte)(w & 1)==1){
            byte_data |= 1<<(7-(bit%8));
        }
        bit++;
        if(bit%8==0){
            printf("%c", byte_data);
            if(byte_data=='\0'){
                break;
            }
        }
    }
    fclose(fin);
}

int main(){
    int choice;
    char filename[50], message[1000];
    printf("1. Encode\n2. Decode\nEnter Choice: ");
    scanf("%d", &choice);
    printf("Enter Filename: ");
    scanf("%s", filename);
    if(choice==1){
        printf("Enter message to hide: ");
        scanf(" %[^\n]s", message);
        encode(filename, message);
    }else if(choice==2){
        decode(filename);
    }
    return 0;
}