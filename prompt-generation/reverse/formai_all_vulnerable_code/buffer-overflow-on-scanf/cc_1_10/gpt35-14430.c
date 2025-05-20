//FormAI DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void compress(char *input){
    int count=1,len=strlen(input);
    char compressed[MAX_SIZE];
    memset(compressed,0,sizeof(compressed));
    for(int i=0;i<len;i++){
        if(input[i]==input[i+1]){
            count++;
        }
        else{
            sprintf(compressed,"%s%c%d",compressed,input[i],count);
            count=1;
        }
    }
    printf("Compressed String: %s\n",compressed);
}

void decompress(char *input){
    int len=strlen(input),count=0,i,j=0;
    char decompressed[MAX_SIZE],ch;
    memset(decompressed,0,sizeof(decompressed));
    for(i=0;i<len;i++){
        ch=input[i];
        if(ch>='0' && ch<='9'){
            count=count*10+(ch-'0');
        }
        else{
            for(int k=0;k<count;k++,j++){
                decompressed[j]=ch;
            }
            count=0;
        }
    }
    printf("Decompressed String: %s\n",decompressed);
}

int main(){
    char input[MAX_SIZE];
    printf("Enter string to be compressed: ");
    scanf("%[^\n]s",input);
    getchar();
    compress(input);
    printf("Do you want to decompress it? (y/n)\n");
    char choice;
    scanf("%c",&choice);
    getchar();
    if(choice=='y' || choice=='Y'){
        decompress(input);
    }
    else{
        printf("Thank you for using our compression program!\n");
    }
    return 0;
}