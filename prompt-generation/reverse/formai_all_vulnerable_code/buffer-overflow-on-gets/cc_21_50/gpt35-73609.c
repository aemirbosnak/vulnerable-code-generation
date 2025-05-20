//FormAI DATASET v1.0 Category: Text processing ; Style: random
#include<stdio.h>
#include<string.h>

int main(){
    char str[100],str2[100],c,ch;
    int i,j,length=0,count=0;
    
    printf("Enter a string: ");
    gets(str);
    
    //Reverse the string
    length=strlen(str);
    for(i=length-1,j=0;i>=0;i--,j++){
        str2[j]=str[i];
    }
    str2[length]='\0';
    
    //Print the reversed string
    printf("\nReverse of the string: %s",str2);
    
    //Count the number of vowels present in the string
    for(i=0;i<length;i++){
        ch=str[i];
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            count++;
        }
    }
    
    //Print the count of vowels present in the string
    printf("\n\nNumber of vowels present in the string: %d",count);
    
    //Remove all the vowels from the string
    printf("\n\nString after removing all the vowels: ");
    for(i=0;i<length;i++){
        c=str2[i];
        switch(c){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                break;
            default:
                printf("%c",c);
                break;
        }
    }
    printf("\n");
    return 0;
}