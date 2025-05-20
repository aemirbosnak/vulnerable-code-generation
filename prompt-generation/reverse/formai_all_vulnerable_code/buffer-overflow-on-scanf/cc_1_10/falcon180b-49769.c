//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    char hex[10];
    char input[100];
    char red, green, blue;
    int i, j;
    printf("Enter the hexadecimal color code: ");
    scanf("%s", hex);
    strcpy(input, hex);
    for(i=0; input[i]!='\0'; i++)
    {
        if(input[i]=='#')
        {
            strcpy(hex, &input[i+1]);
            break;
        }
    }
    for(i=0; hex[i]!='\0'; i++)
    {
        if(isdigit(hex[i]))
        {
            red = hex[i];
            break;
        }
    }
    for(i=0; hex[i]!='\0'; i++)
    {
        if(isdigit(hex[i]))
        {
            green = hex[i];
            break;
        }
    }
    for(i=0; hex[i]!='\0'; i++)
    {
        if(isdigit(hex[i]))
        {
            blue = hex[i];
            break;
        }
    }
    red = red * 16;
    green = green * 16;
    blue = blue * 16;
    printf("The RGB values of the color code are:\n");
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);
    return 0;
}