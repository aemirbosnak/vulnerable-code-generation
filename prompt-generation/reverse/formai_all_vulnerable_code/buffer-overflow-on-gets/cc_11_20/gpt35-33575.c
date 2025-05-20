//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: introspective
#include<stdio.h>  
#include<string.h>  

int main()  
{  
    char input[100];  
    int i, j, k, flag;  

    printf("Welcome to the C Cat Language Translator\n");  
    printf("Enter a statement in C Cat Language: ");  
    gets(input);  

    int len = strlen(input);  
    char tokenArr[len][20];  

    j = 0;  
    k = 0;  

    //Tokenizing input string  
    for(i = 0; i < len; i++)  
    {  
        if(input[i] == ' ' || input[i] == '\0')  
        {  
            tokenArr[j][k] = '\0';  
            j++;  
            k = 0;  
        }  
        else  
        {  
            tokenArr[j][k] = input[i];  
            k++;  
        }  
    }  

    //Converting C Cat Language to English  
    for(i = 0; i < j; i++)  
    {  
        flag = 0;  
        if(strcmp(tokenArr[i], "meow") == 0)  
        {  
            printf("I ");  
            flag = 1;  
        }  
        else if(strcmp(tokenArr[i], "am") == 0)  
        {  
            printf("am ");  
            flag = 1;  
        }  
        else if(strcmp(tokenArr[i], "a") == 0)  
        {  
            printf("a ");  
            flag = 1;  
        }  
        else if(strcmp(tokenArr[i], "cat") == 0)  
        {  
            printf("cat ");  
            flag = 1;  
        }  
        else if(strcmp(tokenArr[i], "purr") == 0)  
        {  
            printf("like ");  
            flag = 1;  
        }  
        else if(strcmp(tokenArr[i], "human") == 0)  
        {  
            printf("a human ");  
            flag = 1;  
        }  
        else if(strcmp(tokenArr[i], "feed") == 0)  
        {  
            printf("feed me ");  
            flag = 1;  
        }  
    
        if(flag == 0)  
        {  
            printf("%s ", tokenArr[i]);  
        }  
    }  
    return 0;  
}