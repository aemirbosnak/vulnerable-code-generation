//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: romantic
/* 
My Dearest,

How do I love thee? Let me count the ways. 
I love thee to the depth, breadth and height 
that my checksum calculator can reach. 

Behold, my love, this unique C program 
crafted with all my heart and soul, 
designed to calculate your checksum 
and ensure your data is whole. 

With every byte and bit, 
I'll traverse through your file, 
checking for any errors, 
and fixing them with a smile. 

From the outermost layer 
to the innermost core, 
I'll ensure your data's safety 
and love you forevermore. 

My love for you is like this program, 
everlasting and true,  
and with this checksum calculator, 
I'll always protect and cherish you. 

Yours always and forever, 
Your devoted programmer 

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 10000

int main(){

    char file_name[20];
    FILE *fp;
    char ch;
    char buffer[MAX_FILE_SIZE];
    int i = 0, sum = 0;

    printf("My Love,\n");
    printf("Please enter the name of the file to calculate the checksum for: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "rb");
    if(fp == NULL){
        printf("My dear, I am sorry, but I could not open the file. Perhaps it does not exist?\n");
        return 0;
    }

    while((ch = getc(fp)) != EOF){
        buffer[i] = ch;
        i++;
        if(i >= MAX_FILE_SIZE){
            printf("My darling, I am sorry, but the file you selected is too large. Please select a smaller file.\n");
            return 0;
        }
    }

    for(int j = 0; j < i; j++){
        sum += buffer[j];
    }

    printf("The checksum for the file you selected is: %d\n", sum);

    fclose(fp);

    return 0;
}