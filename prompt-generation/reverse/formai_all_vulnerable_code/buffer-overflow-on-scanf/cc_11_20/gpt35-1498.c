//FormAI DATASET v1.0 Category: String manipulation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char str[1000],substring[100];
    int choice;

    printf("Welcome to the String Manipulation Program");
    printf("\nEnter a string: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = 0; //removing '\n' character from fgets

    printf("\nWhat operation do you want to perform?\n");
    printf("1. Convert to uppercase\n");
    printf("2. Convert to lowercase\n");
    printf("3. Reverse string\n");
    printf("4. Find substring\n");
    printf("5. Replace substring\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){

        case 1: 
            for(int i=0;str[i];i++){
                if(str[i]>='a'&&str[i]<='z'){
                    str[i]=str[i]-32;  //converting to uppercase ASCII value
                }
            }
            printf("\nUppercase String: %s",str);
            break;

        case 2:
            for(int i=0;str[i];i++){
                if(str[i]>='A'&&str[i]<='Z'){
                    str[i]=str[i]+32;  //converting to lowercase ASCII value
                }
            }
            printf("\nLowercase String: %s",str);
            break;

        case 3:
            printf("\nReversed String: ");
            for(int i=strlen(str)-1;i>=0;i--){
                printf("%c",str[i]);
            }
            break;

        case 4:
            printf("\nEnter Substring to find: ");
            scanf("%s",substring);
            if(strstr(str,substring)!=NULL){
                printf("\nSubstring %s found at index %d\n",substring,strstr(str,substring)-str);
            }
            else{
                printf("\nSubstring %s not found\n",substring);
            }
            break;

        case 5:
            printf("\nEnter Substring to replace: ");
            scanf("%s",substring);
            char replacement[100];
            printf("\nEnter replacement: ");
            scanf("%s",replacement);
            char *token=strstr(str,substring);
            if(token!=NULL){
                int index=token-str;
                strncpy(str+index,replacement,strlen(replacement));
                printf("\nReplaced string: %s",str);
            }
            else{
                printf("\nSubstring %s not found",substring);
            }
            break;

        default: printf("\nInvalid choice");

    }

    return 0;
}