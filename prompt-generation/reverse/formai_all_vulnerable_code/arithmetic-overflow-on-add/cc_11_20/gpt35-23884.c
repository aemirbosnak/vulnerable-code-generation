//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include<stdio.h>
#include<string.h>

int main()
{
    char message[1000],key[1000],watermark[1000];
    int len_message,len_key,len_watermark,i,j;
    
    printf("Enter original message: ");
    fgets(message, 1000, stdin);
    len_message=strlen(message);
    
    printf("Enter key: ");
    fgets(key, 1000, stdin);
    len_key=strlen(key);
    
    //Embed key in message
    for(i=0,j=0; i<len_message; i++)
    {
        if(message[i]==' ' || message[i]=='\n' || message[i]=='\0')
        {
            watermark[j++]=key[0];
            for(int k=1; k<len_key; k++)
            {
                watermark[j++]=key[k];
            }
            if(message[i]!='\0')
            {
                watermark[j++]=message[i];
            }
            key[0]++; //change key for next embedding
        }
        else
        {
            watermark[j++]=message[i];
        }
    }
    watermark[j]='\0'; //terminate string with null character
    len_watermark=strlen(watermark);
    
    printf("\nWatermarked message: \n%s",watermark);
    
    //Extract key from watermark
    j=0;
    for(i=0; i<len_watermark; i++)
    {
        if(watermark[i]==key[0])
        {
            for(int k=1; k<len_key; k++)
            {
                if(watermark[i+k]!=key[k])
                {
                    break;
                }
                if(k==len_key-1)
                {
                    printf("\nKey found: \n");
                    for(int l=0; l<len_key; l++)
                    {
                        printf("%c",key[l]);
                    }
                }
            }
            key[0]++; //change key for next extraction
        }
    }
    
    return 0;
}