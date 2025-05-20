//FormAI DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>

int main()
{
    char message[100],reversed[100];
    int length,i,j;
    
    printf("Please enter a message: ");
    scanf("%s",message);
    
    length = strlen(message);
    
    j=0;
    for(i=length-1;i>=0;i--)
    {
        reversed[j] = message[i];
        j++;
    }
    reversed[j] = '\0';
    
    printf("\nThe reversed message is: %s",reversed);
    
    char vowels[] = "AEIOUaeiou";
    int vowel_count = 0, consonant_count = 0;
    
    for(i=0;i<length;i++)
    {
        if(message[i] == ' ')
        {
            continue;
        }
        else if(strchr(vowels,message[i]) != NULL)
        {
            vowel_count++;
        }
        else
        {
            consonant_count++;
        }
    }
    
    printf("\nNumber of vowels: %d",vowel_count);
    printf("\nNumber of consonants: %d",consonant_count);
    
    printf("\nThe message with alternate uppercase letters: ");
    for(i=0;i<length;i++)
    {
        if(i%2==0)
        {
            printf("%c", toupper(message[i]));
        }
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
    
    char search[20];
    printf("\nEnter a string to search in the message: ");
    scanf("%s",search);
    
    if(strstr(message,search) != NULL)
    {
        printf("'%s' is present in the message.",search);
    }
    else
    {
        printf("'%s' is not present in the message.",search);
    }
    
    return 0;
}