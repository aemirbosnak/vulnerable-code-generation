//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char str[1000];
    int i,j;

    printf("Enter a string: ");
    scanf("%[^\n]",str);

    printf("\nOriginal string: %s\n",str);

    //converting the string to uppercase
    for(i=0;str[i]!='\0';i++){
        str[i]=toupper(str[i]);
    }
    printf("\nString in uppercase: %s\n",str);

    //converting the string to lowercase
    for(i=0;str[i]!='\0';i++){
        str[i]=tolower(str[i]);
    }
    printf("\nString in lowercase: %s\n",str);

    //counting the number of words in the string
    j=0;
    for(i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            j++;
        }
    }
    printf("\nNumber of words in the string: %d\n",j+1);

    //reversing the string
    for(i=0;str[i]!='\0';i++){
        str[i]=str[strlen(str)-i-1];
    }
    printf("\nReversed string: %s\n",str);

    //removing all spaces from the string
    j=0;
    for(i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
            str[j++]=str[i];
        }
    }
    str[j]='\0';
    printf("\nString without spaces: %s\n",str);

    return 0;
}