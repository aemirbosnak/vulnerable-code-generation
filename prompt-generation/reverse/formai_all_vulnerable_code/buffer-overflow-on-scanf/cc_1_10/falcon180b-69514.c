//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define LEN 100

typedef struct
{
    char hex[LEN];
    char rgb[LEN];
}color;

void init(color *c)
{
    memset(c->hex,0,LEN);
    memset(c->rgb,0,LEN);
}

void input(color *c)
{
    printf("enter the hex code: ");
    scanf("%s",c->hex);
}

void convert(color *c)
{
    char hex_val[3]={'0','x','\0'};
    strcat(c->hex,hex_val);
    strcat(c->rgb,"rgb(");
    int i;
    for(i=0;i<strlen(c->hex);i+=2)
    {
        char hex_char=c->hex[i];
        if(isdigit(hex_char))
        {
            int num=0;
            while(isdigit(hex_char))
            {
                num=num*16+(hex_char-'0');
                hex_char=c->hex[++i];
            }
            sprintf(c->rgb+strlen(c->rgb),"%d,",num);
        }
        else if(hex_char>='a' && hex_char<='f')
        {
            int num=0;
            while(hex_char>='a' && hex_char<='f')
            {
                num=num*16+(hex_char-'a'+10);
                hex_char=c->hex[++i];
            }
            sprintf(c->rgb+strlen(c->rgb),"%d,",num);
        }
        else if(hex_char>='a' && hex_char<='f')
        {
            int num=0;
            while(hex_char>='a' && hex_char<='f')
            {
                num=num*16+(hex_char-'a'+10);
                hex_char=c->hex[++i];
            }
            sprintf(c->rgb+strlen(c->rgb),"%d,",num);
        }
    }
    strcat(c->rgb,")");
}

void display(color *c)
{
    printf("the rgb value of %s is %s\n",c->hex,c->rgb);
}

int main()
{
    color c;
    init(&c);
    input(&c);
    convert(&c);
    display(&c);
    return 0;
}