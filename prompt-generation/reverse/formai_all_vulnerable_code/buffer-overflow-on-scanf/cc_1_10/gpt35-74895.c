//FormAI DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
//Unique C File Encryptor Example Program

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100000

int main()
{
    FILE *fpIn,*fpOut;
    char inFile[100],outFile[100],key[MAX],ch;
    int i,j,k,len_key,len_file;
    
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s",inFile);
    
    printf("Enter the name of the output file: ");
    scanf("%s",outFile);
    
    printf("Enter the key to encrypt the file: ");
    scanf("%s",key);
    
    //Get the length of the key and the input file
    len_key = strlen(key);
    len_file = strlen(inFile);
    
    //Open the input file in read mode and output file in write mode
    fpIn = fopen(inFile,"r");
    fpOut = fopen(outFile,"w");
    
    //Loop through the input file
    for(i=0,j=0;i<len_file;i++)
    {
        //If the end of the key is reached, start at the beginning again
        if(j==len_key)
            j=0;
        
        //Read a character from the input file
        ch = fgetc(fpIn);
        
        //Encrypt the character using XOR operation with the key
        k = ch ^ key[j];
        
        //Write the encrypted character to the output file
        fputc(k,fpOut);
        
        //Update the position in the key
        j++;
    }
    
    //Close the input and output file
    fclose(fpIn);
    fclose(fpOut);
    
    printf("\nFile has been encrypted successfully!\n");
    
    return 0;
}