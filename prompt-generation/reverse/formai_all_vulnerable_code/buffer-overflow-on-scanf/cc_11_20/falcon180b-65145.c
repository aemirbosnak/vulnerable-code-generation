//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main(){
    char str[100];
    int i,j,k;
    printf("Enter a string: ");
    scanf("%s",str);
    printf("\nThe string is: %s",str);
    printf("\nThe length of the string is: %d",strlen(str));

    //converting string to uppercase
    for(i=0;str[i]!='\0';i++){
        str[i]=toupper(str[i]);
    }
    printf("\n\nThe string in uppercase is: %s",str);

    //reversing the string
    for(i=0,j=strlen(str)-1;i<j;i++,j--){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    printf("\n\nThe reversed string is: %s",str);

    //removing spaces from the string
    for(i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
            str[k++]=str[i];
        }
    }
    str[k]='\0';
    printf("\n\nThe string without spaces is: %s",str);

    //counting the vowels and consonants in the string
    int vowels=0,consonants=0;
    for(i=0;str[i]!='\0';i++){
        if(isalpha(str[i])){
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'){
                vowels++;
            }
            else{
                consonants++;
            }
        }
    }
    printf("\n\nThe number of vowels in the string is: %d",vowels);
    printf("\nThe number of consonants in the string is: %d",consonants);
}