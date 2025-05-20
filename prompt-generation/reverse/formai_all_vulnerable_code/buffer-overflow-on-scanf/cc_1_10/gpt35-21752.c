//FormAI DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50], str2[50], str3[50], str4[50]; //declaring four string variables of size 50
    int i, j, k; //declaring integers to be used in loops later
    
    printf("Enter a word: "); //prompting user to enter a word
    scanf("%s", str1); //storing user input in str1
    
    printf("Enter another word: "); //prompting user to enter another word
    scanf("%s", str2); //storing user input in str2
    
    printf("\nYou entered the words %s and %s\n", str1, str2); //displaying the words entered by user
    
    //reversing str1 and storing it in str3
    j = strlen(str1)-1; //setting j to the last index of str1
    for(i=0; i<strlen(str1); i++) //loop through str1
    {
        str3[i] = str1[j]; //store the character of str1 at index j in str3 at index i
        j--; //decrement j so that next iteration grabs the previous character
    }
    printf("\nThe reverse of %s is %s\n", str1, str3); //displaying the reverse of str1
    
    //reversing str2 and storing it in str4
    k = strlen(str2)-1; //setting k to the last index of str2
    for(i=0; i<strlen(str2); i++) //loop through str2
    {
        str4[i] = str2[k]; //store the character of str2 at index k in str4 at index i
        k--; //decrement k so that next iteration grabs the previous character
    }
    printf("\nThe reverse of %s is %s\n", str2, str4); //displaying the reverse of str2
    
    //comparing str1 and str2 to see which is longer
    if(strlen(str1) > strlen(str2))
    {
        printf("\n%s is longer than %s\n", str1, str2); //displaying which word is longer
    }
    else if(strlen(str2) > strlen(str1))
    {
        printf("\n%s is longer than %s\n", str2, str1); //displaying which word is longer
    }
    else
    {
        printf("\n%s and %s are the same length\n", str1, str2); //displaying that the words are the same length
    }
    
    //concatenating str1 and str2 and storing the result in str3
    strcat(str1, str2);
    printf("\nAfter concatenation, str1 now holds %s\n", str1); //displaying the concatenated string
    
    //checking if the words entered by user are palindromes
    if(strcmp(str1, str3) == 0)
    {
        printf("\n%s is a palindrome\n", str1); //displaying that str1 is a palindrome
    }
    else
    {
        printf("\n%s is not a palindrome\n", str1); //displaying that str1 is not a palindrome
    }
    
    if(strcmp(str2, str4) == 0)
    {
        printf("\n%s is a palindrome\n", str2); //displaying that str2 is a palindrome
    }
    else
    {
        printf("\n%s is not a palindrome\n", str2); //displaying that str2 is not a palindrome
    }
    
    return 0;
}