//FormAI DATASET v1.0 Category: HTML beautifier ; Style: protected
/*
This C program is an example of a HTML beautifier in a protected style.
The program aims to indent and format the input HTML code automatically.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void print_tabs(int num_tabs);

int main(){

    char input[10000];
    int num_tabs = 0;
    int i,j;
    int len;
    int in_tag = 0;

    printf("Enter the HTML code:\n");
    fgets(input, 10000, stdin);

    len = strlen(input);

    for(i=0;i<len;++i){

        if(input[i]=='<'){
            in_tag = 1;
        }

        if(input[i]=='>'){

            if(input[i-1]=='/'){
                num_tabs--;
                print_tabs(num_tabs);
            }
            printf("%c\n",input[i]);

            in_tag = 0;

        }
        else if(in_tag){

            printf("%c",input[i]);

            if(input[i]==' '){
                while(input[i+1]==' '){
                    i++;
                }
            }
            else if(input[i]=='"' || input[i]=='\''){
                i++;
                while(input[i]!=input[i-1]){
                    printf("%c",input[i]);
                    i++;
                }
            }

        }
        else{
            if(input[i]=='\n'){
                printf("\n");
                print_tabs(num_tabs);
            }
            else{
                printf("%c",input[i]);
            }
        }
    }
    return 0;
}

void print_tabs(int num_tabs){
    int i;
    for(i=0;i<num_tabs;++i){
        printf("\t");
    }
}