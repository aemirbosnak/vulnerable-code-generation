//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include<stdio.h>
#include<string.h>

int main(){
    char string1[50],string2[50];
    int choice,length;
    printf("Enter a string: ");
    scanf("%s",string1);
    printf("\n");
    do{
        printf("1: Copy string\n2: Concatenate string\n3: Reverse string\n4: Compare string\n5: Check palindrome\n6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice>=1 && choice<=5){
            printf("Enter the second string: ");
            scanf("%s",string2);
        }
        switch(choice){
            case 1:
                strcpy(string1,string2);
                printf("String 1 after copy: %s\n",string1);
                break;
            case 2:
                strcat(string1,string2);
                printf("String after concatenation: %s\n",string1);
                break;
            case 3:
                length=strlen(string1);
                for(int i=0;i<length/2;i++){
                    char temp=string1[i];
                    string1[i]=string1[length-1-i];
                    string1[length-1-i]=temp;
                }
                printf("String after reversal: %s\n",string1);
                break;
            case 4:
                if(strcmp(string1,string2)==0)
                    printf("Both strings are equal\n");
                else
                    printf("Both strings are not equal\n");
                break;
            case 5:
                length=strlen(string1);
                for(int i=0;i<length/2;i++){
                    if(string1[i]!=string1[length-1-i]){
                        printf("Not a palindrome\n");
                        break;
                    }
                    else if(i==length/2-1)
                        printf("Palindrome\n");
                }
                break;
            case 6:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice, try again\n");
        }
        printf("\n");
    }while(choice!=6);

    return 0;
}