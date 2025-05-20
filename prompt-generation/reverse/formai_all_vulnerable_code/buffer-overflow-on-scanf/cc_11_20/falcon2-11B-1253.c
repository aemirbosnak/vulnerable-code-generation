//Falcon2-11B DATASET v1.0 Category: String manipulation ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str[100];
    int len = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    printf("Enter the string: ");
    scanf("%s",str);
    len = strlen(str);
    printf("Original String: %s\n",str);

    for(i=0; i<len; i++){
        if(str[i] == 'a'){
            printf("Position of a: %d\n",i);
            k = i;
        }
    }

    for(j=0; j<len; j++){
        if(str[j] == 'b'){
            printf("Position of b: %d\n",j);
            k = j;
            break;
        }
    }

    for(i=0; i<len; i++){
        if(str[i] == 'c'){
            printf("Position of c: %d\n",i);
            k = i;
        }
    }

    for(i=0; i<len; i++){
        if(str[i] == 'd'){
            printf("Position of d: %d\n",i);
            k = i;
        }
    }

    for(i=0; i<len; i++){
        if(str[i] == 'e'){
            printf("Position of e: %d\n",i);
            k = i;
        }
    }

    printf("Final String: %s\n",str);
    str[k] = 'o';
    printf("Final String: %s\n",str);
    return 0;
}