//FormAI DATASET v1.0 Category: Spam Detection System ; Style: complex
#include<stdio.h>
#include<string.h>

int main()
{
    char text[1000], word[100], ch;
    int i = 0, j = 0, flag, count = 0;
    
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter the word to check: ");
    fgets(word, sizeof(word), stdin);
    
    // remove the newline character from word
    int len = strlen(word);
    if(word[len-1] == '\n') 
        word[len-1] = '\0';
    
    // iterate through each character in the text
    while(text[i] != '\0')
    {
        ch = text[i];
        j = 0;
        flag = 1;
        
        // iterate through each character in the word
        while(word[j] != '\0')
        {
            // if characters do not match, set flag to false and break the inner loop
            if(ch != word[j])
            {
                flag = 0;
                break;
            }
            else // if characters match, move to the next character in both text and word
            {
                ch = text[i+j+1];
                j++;
            }
        }
        
        // if flag is true and reached end of word, increase count and move to the next position in text
        if(flag == 1 && word[j] == '\0')
        {
            count++;
            i += j;
        }
        else // otherwise, move to the next position in text by one character
        {
            i++;
        }
    }
    
    // check if count is greater than 0 and print appropriate message
    if(count > 0)
    {
        printf("The text contains the word '%s' %d times.", word, count);
    }
    else
    {
        printf("The text does not contain the word '%s'.", word);
    }
    
    return 0;
}