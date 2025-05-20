//FormAI DATASET v1.0 Category: Image Steganography ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    FILE *fp;
    char ch,message[1000],filename[50];
    int i=0,j=0,binary[8],decimal,size,k=0;

    printf("Enter the name of image file to hide message: ");
    scanf("%s",filename);

    fp=fopen(filename,"rb");
    if(fp==NULL){
        printf("File not found!\n");
        exit(0);
    }

    fseek(fp,0,SEEK_END);
    size=ftell(fp);
    fseek(fp,0,SEEK_SET);

    printf("Enter the message to hide: ");
    fflush(stdin);
    gets(message);

    while(message[i]!='\0'){
        decimal=(int)message[i];

        for(j=7;j>=0;j--){
            binary[j]=decimal%2;
            decimal/=2;
        }

        for(j=0;j<8;j++){
            if(binary[j]==1){
                fseek(fp,k,SEEK_SET);
                ch=getc(fp);

                if(ch%2==0)
                    ch=ch+1;

                fseek(fp,k,SEEK_SET);
                fprintf(fp,"%c",ch);
                k++;
            }
            else{
                fseek(fp,k,SEEK_SET);
                ch=getc(fp);

                if(ch%2==1)
                    ch=ch-1;

                fseek(fp,k,SEEK_SET);
                fprintf(fp,"%c",ch);
                k++;
            }
        }
        i++;
    }
    fclose(fp);
    return 0;
}