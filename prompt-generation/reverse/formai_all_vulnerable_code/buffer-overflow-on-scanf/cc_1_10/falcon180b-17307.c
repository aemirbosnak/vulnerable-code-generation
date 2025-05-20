//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//function to compress a string
void compress(char* str){
    int i,j;
    for(i=0,j=0;str[i]!='\0';i++){
        if(str[i]!=str[i+1]){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

//function to decompress a string
void decompress(char* str){
    int i,j;
    for(i=0,j=0;str[i]!='\0';i++){
        if(str[i]!=str[i+1]){
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

//function to copy a string
void copy(char* dest, char* src){
    int i;
    for(i=0;src[i]!='\0';i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

//function to compare two strings
int compare(char* str1, char* str2){
    int i;
    for(i=0;str1[i]!='\0' && str2[i]!='\0';i++)
        if(str1[i]!=str2[i])
            return 0;
    return 1;
}

int main(){
    char str[100];
    int i,j;

    //get input string from user
    printf("Enter a string: ");
    scanf("%s",str);

    //compress the string
    compress(str);

    //display the compressed string
    printf("Compressed string: %s\n",str);

    //decompress the string
    char dest[100];
    decompress(str);
    copy(dest,str);

    //display the decompressed string
    printf("Decompressed string: %s\n",dest);

    //compare the original and decompressed strings
    if(compare(str,dest))
        printf("Strings are equal.\n");
    else
        printf("Strings are not equal.\n");

    return 0;
}