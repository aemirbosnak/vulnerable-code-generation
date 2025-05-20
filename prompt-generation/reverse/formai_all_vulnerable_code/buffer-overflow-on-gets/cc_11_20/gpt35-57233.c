//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include<stdio.h>
#include<string.h>

int main(){
    char c_cat_language[100];
    int i, j, k;
    printf("Enter the C Cat language: ");
    gets(c_cat_language);
    for(i=0; i<strlen(c_cat_language);){
        if(c_cat_language[i]=='M' && c_cat_language[i+1]=='E' && c_cat_language[i+2]=='O'){
            putchar(' ');
            i+=3;
        }
        else if(c_cat_language[i]=='M' && c_cat_language[i+1]=='E'){
            putchar('H');
            i+=2;
        }
        else if(c_cat_language[i]=='M' && c_cat_language[i+1]=='A'){
            putchar('Y');
            i+=2;
        }
        else if(c_cat_language[i]=='A' && c_cat_language[i+1]=='U'){
            putchar('D');
            i+=2;
        }
        else if(c_cat_language[i]=='O' && c_cat_language[i+1]=='N'){
            putchar('S');
            i+=2;
        }
        else if(c_cat_language[i]=='A'){
            putchar('C');
            i++;
        }
        else if(c_cat_language[i]=='E'){
            putchar('A');
            i++;
        }
        else if(c_cat_language[i]=='H'){
            putchar('T');
            i++;
        }
        else if(c_cat_language[i]=='U' && c_cat_language[i+1]=='S'){
            putchar('I');
            i+=2;
        }
        else{
            putchar(c_cat_language[i]);
            i++;
        }
    }
    return 0;
}