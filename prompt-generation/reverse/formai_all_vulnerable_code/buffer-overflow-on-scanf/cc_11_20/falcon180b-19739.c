//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);

    //Removing all the spaces in the string
    char *ptr = strtok(str," ");
    char result[100];
    while(ptr!=NULL){
        strcat(result,ptr);
        strcat(result,"-");
        ptr = strtok(NULL," ");
    }
    printf("New string: %s\n",result);

    //Reversing the string
    char rev[100];
    strcpy(rev,str);
    int i,j;
    for(i=strlen(rev)-1,j=0;i>=0;i--,j++){
        rev[j] = rev[i];
    }
    printf("Reversed string: %s\n",rev);

    //Counting the vowels in the string
    int count = 0;
    for(int i=0;i<strlen(str);i++){
        if(isalpha(str[i])){
            if(tolower(str[i])=='a' || tolower(str[i])=='e' || tolower(str[i])=='i' || tolower(str[i])=='o' || tolower(str[i])=='u'){
                count++;
            }
        }
    }
    printf("Number of vowels: %d\n",count);

    //Checking if the string is a palindrome
    int flag = 1;
    int l = strlen(str)-1;
    for(int i=0;i<l/2;i++){
        if(tolower(str[i])!=tolower(str[l-i-1])){
            flag = 0;
            break;
        }
    }
    if(flag){
        printf("The string is a palindrome.\n");
    }
    else{
        printf("The string is not a palindrome.\n");
    }

    //Converting the string to uppercase
    char up[100];
    strcpy(up,str);
    for(int i=0;i<strlen(up);i++){
        up[i] = toupper(up[i]);
    }
    printf("Uppercase string: %s\n",up);

    return 0;
}