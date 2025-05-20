//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 1000

int main(){
    char filename[20],output[20],key[20];
    FILE *file,*out;
    int len,i,j,k,flag=0;
    char ch;
    printf("Enter the name of the file to be encrypted:");
    scanf("%s",filename);
    printf("Enter the key:");
    scanf("%s",key);
    strcat(filename,".txt");
    file=fopen(filename,"r");
    if(file==NULL){
        printf("File not found");
        exit(0);
    }
    out=fopen("encrypted.txt","w");
    if(out==NULL){
        printf("Cannot create file");
        exit(0);
    }
    while((ch=fgetc(file))!=EOF){
        if(isalpha(ch)){
            flag=1;
        }
        else{
            flag=0;
        }
        if(flag==1){
            if(isupper(ch)){
                ch=ch+32;
            }
            else if(islower(ch)){
                ch=ch-32;
            }
            len=strlen(key);
            j=0;
            for(i=0;i<len;i++){
                if(ch==key[i]){
                    ch=key[j];
                    j++;
                    if(j==len){
                        j=0;
                    }
                }
            }
        }
        fprintf(out,"%c",ch);
    }
    fclose(file);
    fclose(out);
    printf("File encrypted successfully");
    return 0;
}