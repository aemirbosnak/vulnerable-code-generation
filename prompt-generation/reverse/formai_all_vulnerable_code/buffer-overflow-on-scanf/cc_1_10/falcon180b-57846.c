//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: rigorous
/* Unique C Binary Converter */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_NUM_LEN 100
#define MAX_BIN_LEN 33

int isValid(char *str);
int getNum(char *str);
void binToDec(char *bin, int *num);
void decToBin(int num, char *bin);

int main()
{
    char str[MAX_NUM_LEN+1], bin[MAX_BIN_LEN+1];
    int num;
    
    printf("Enter a decimal number: ");
    scanf("%s", str);
    
    if(isValid(str))
    {
        num = getNum(str);
        decToBin(num, bin);
        printf("Binary representation of %d is: %s\n", num, bin);
    }
    else
    {
        printf("Invalid input!\n");
    }
    
    return 0;
}

int isValid(char *str)
{
    int len = strlen(str);
    
    if(len == 0 || len > MAX_NUM_LEN)
    {
        return 0;
    }
    
    for(int i=0; i<len; i++)
    {
        if(!isdigit(str[i]))
        {
            return 0;
        }
    }
    
    return 1;
}

int getNum(char *str)
{
    int num = 0;
    int sign = 1;
    int len = strlen(str);
    
    if(len == 0)
    {
        return 0;
    }
    
    if(str[0] == '-')
    {
        sign = -1;
        str++;
        len--;
    }
    
    for(int i=0; i<len; i++)
    {
        num = num * 10 + (str[i] - '0');
    }
    
    num *= sign;
    return num;
}

void binToDec(char *bin, int *num)
{
    int len = strlen(bin);
    int dec = 0;
    int pow = 0;
    
    for(int i=len-1; i>=0; i--)
    {
        if(bin[i] == '1')
        {
            dec += pow;
        }
        pow *= 2;
    }
    
    *num = dec;
}

void decToBin(int num, char *bin)
{
    int len = 0;
    char temp[MAX_BIN_LEN];
    int rem;
    
    do
    {
        rem = num % 2;
        num /= 2;
        len++;
    } while(num > 0);
    
    for(int i=len-1; i>=0; i--)
    {
        sprintf(temp, "%d", rem);
        strcat(bin, temp);
        rem /= 2;
    }
}