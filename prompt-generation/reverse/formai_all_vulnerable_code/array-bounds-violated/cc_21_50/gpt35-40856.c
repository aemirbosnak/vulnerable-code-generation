//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include<stdio.h> //header file for standard input output functions
#include<string.h> //header file for string handling functions

int main()
{
    printf("Welcome to the Text Processor Program!\n"); //Introducing the program to the user
    
    char text[1000]; //Declaring the variable to store user input
    printf("\nPlease enter the text you would like to process:\n");
    fgets(text, 1000, stdin); //Taking user input with fgets() function
    
    //Removing the trailing '\n' character from the input string
    if(text[strlen(text)-1]=='\n')
        text[strlen(text)-1] = '\0';

    printf("\nGreat! Now, let's start processing your text...\n"); 
    printf("-----------------------------------------------\n");

    //Printing the given text in reverse order
    printf("\n1. Reversed text: ");
    int i;
    for(i=strlen(text)-1; i>=0; i--) 
        printf("%c",text[i]);

    //Calculating number of vowels and consonants in the given text
    int vowels=0, consonants=0;
    for(i=0; text[i]!='\0'; i++)
    {
        if(text[i]=='a' || text[i]=='e' || text[i]=='i' || text[i]=='o' || text[i]=='u' || text[i]=='A' || text[i]=='E' || text[i]=='I' || text[i]=='O' || text[i]=='U')
            vowels++;
        else if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z'))
            consonants++;
    }

    printf("\n2. Number of vowels: %d", vowels);
    printf("\n3. Number of consonants: %d", consonants);

    //Converting the given text to uppercase
    printf("\n4. Uppercase text: ");
    for(i=0; text[i]!='\0'; i++)
    {
        if(text[i]>='a' && text[i]<='z')
            printf("%c",text[i]-32);
        else
            printf("%c",text[i]);
    }

    printf("\n\nThat's it! Your text has been successfully processed.\n");
    printf("-----------------------------------------------\n");

    return 0; //End of main function
}