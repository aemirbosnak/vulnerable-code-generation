//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct word{
    char w_name[50];
    int freq;                
}Word;                       

int main(){
    FILE *fptr;
    char fname[20], str[50], c, temp;
    int w_count=0, len, i, j, k, flag;
    
    printf("Enter the file name: ");
    scanf("%s",fname);
    
    fptr = fopen(fname, "r");
    if(fptr == NULL){
        printf("\nFile does not exist\n");
        exit(0);
    }
    
    Word wrd[100];
    for(i=0;i<100;i++){
        wrd[i].w_name[0] = '\0';
        wrd[i].freq = 0;
    }
    j=0;
    while(1){
        c = fgetc(fptr);
        
        if(c == EOF)
            break;
        
        flag = 0;
        if( isalpha(c) ){       
            str[0] = c;
            len = 1;
            while( isalpha(temp=fgetc(fptr)) ){
                str[len] = temp;
                len++;
            }
            str[len] = '\0';
            
            if(len>2){
                strcpy(wrd[j].w_name, str);
                wrd[j].freq++;
                j++;
            }
        }
    }
    
    w_count = j-1;
    
    printf("\n\nWord Frequency list\n\n");
    for(i=0;i<=w_count;i++){
        printf("%10d\t%s\n",wrd[i].freq,wrd[i].w_name);
    }
    printf("\n\n");
    
    fclose(fptr);
    return 0;
}