//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE 100

int main()
{
    char input[SIZE];
    char key[SIZE];
    int i,j,k;
    int rows,cols;
    int flag=0;

    printf("Enter the message to be encrypted: ");
    scanf("%s",input);

    printf("Enter the key for encryption: ");
    scanf("%s",key);

    rows=strlen(input);
    cols=strlen(key);

    if(cols>rows)
    {
        printf("Key is too long!\n");
        exit(0);
    }

    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            if(input[i]==key[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Key is incorrect!\n");
            exit(0);
        }
    }

    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            if(input[i]==key[j])
            {
                printf("%c",input[i]);
            }
            else
            {
                printf("%c",input[i]+(int)pow(2,j));
            }
        }
        printf("\n");
    }

    return 0;
}