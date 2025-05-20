//Falcon-180B DATASET v1.0 Category: Encryption ; Style: puzzling
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,k,l,n,m,p,q,r,s,t,u,v,w,x,y,z,a,b,c,d,e,f,g,h;
    int xor_key;
    char message[1000],cipher[1000],decipher[1000];
    printf("\nEnter message to be encrypted:");
    scanf("%[^\n]",message);
    printf("\nEnter XOR key:");
    scanf("%d",&xor_key);
    for(i=0;message[i]!='\0';i++)
    {
        if(isalpha(message[i]))
        {
            if(isupper(message[i]))
            {
                message[i] = message[i] + xor_key;
                if(message[i]>'Z')
                {
                    message[i] = message[i] - 26;
                }
            }
            else
            {
                message[i] = message[i] + xor_key;
                if(message[i]>'z')
                {
                    message[i] = message[i] - 26;
                }
            }
        }
        else
        {
            message[i] = message[i];
        }
    }
    printf("\nEncrypted message is:");
    for(i=0;message[i]!='\0';i++)
    {
        printf("%c",message[i]);
    }
    printf("\nEnter encrypted message:");
    scanf("%[^\n]",cipher);
    printf("\nDecrypted message is:");
    for(i=0;cipher[i]!='\0';i++)
    {
        if(isalpha(cipher[i]))
        {
            if(isupper(cipher[i]))
            {
                cipher[i] = cipher[i] - xor_key;
                if(cipher[i]<65)
                {
                    cipher[i] = cipher[i] + 26;
                }
            }
            else
            {
                cipher[i] = cipher[i] - xor_key;
                if(cipher[i]<97)
                {
                    cipher[i] = cipher[i] + 26;
                }
            }
        }
        else
        {
            cipher[i] = cipher[i];
        }
    }
    printf("\nDecrypted message is:");
    for(i=0;cipher[i]!='\0';i++)
    {
        printf("%c",cipher[i]);
    }
    return 0;
}