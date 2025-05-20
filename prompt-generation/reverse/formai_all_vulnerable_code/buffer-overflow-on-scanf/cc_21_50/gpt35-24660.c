//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>

int main(){
    printf("Welcome to the Text Processing program!\n");
    printf("This program takes a string of text and performs various operations on it.\n");
    
    char text[100];
    printf("Please enter a string of text: ");
    fgets(text, 100, stdin);
    
    printf("Your inputted text is: %s\n",text);
    
    printf("Here are some operations you can perform on the text:\n");
    printf("1. Count the number of words\n");
    printf("2. Reverse the order of the words\n");
    printf("3. Convert all uppercase letters to lowercase\n");
    printf("4. Convert all lowercase letters to uppercase\n");
    printf("5. Count the number of vowels\n");
    
    int choice;
    printf("Please enter the number corresponding to the operation you want to perform: ");
    scanf("%d",&choice);
    getchar(); // to clear the newline character from previous input using fgets
    
    if(choice==1){
        int count = 1; // start with 1 as the first word has no space before it
        for(int i=0; text[i]!='\0'; i++){
            if(text[i] == ' ') count++;
        }
        printf("The number of words in the text is: %d\n",count);
    }
    else if(choice==2){
        printf("The text in reverse order of words is: ");
        char *ptr = text;
        int len = strlen(text);
        // move pointer to end of string
        ptr += len-1;
        for(int i=len-1; i>=0; i--){
            if(text[i] == ' ' || i==0){
                if(ptr!=text) printf(" ");
                // print the word in reverse
                while(ptr!=&text[i-1]){
                    printf("%c",*ptr);
                    ptr--;
                }
            }
            ptr--;
        }
        printf("\n");
    }
    else if(choice==3){
        for(int i=0; text[i]!='\0'; i++){
            if(text[i]>='A' && text[i]<='Z') printf("%c",(text[i] + 32)); // adding 32 converts uppercase to lowercase
            else printf("%c",text[i]);
        }
        printf("\n");
    }
    else if(choice==4){
        for(int i=0; text[i]!='\0'; i++){
            if(text[i]>='a' && text[i]<='z') printf("%c",(text[i] - 32)); // subtracting 32 converts lowercase to uppercase
            else printf("%c",text[i]);
        }
        printf("\n");
    }
    else if(choice==5){
        int count = 0;
        for(int i=0; text[i]!='\0'; i++){
            if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' ||
                text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U') count++;
        }
        printf("The number of vowels in the text is: %d\n",count);
    }
    else{
        printf("Invalid choice entered!\n");
    }
    
    printf("Thank you for using the Text Processing program!\n");
    return 0;
}