//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
/* Romeo and Juliet: The URL Sanitizer */

#include <stdio.h>
#include <string.h>

int main()
{
    char url[1000];
    
    // Romeo: Oh Juliet, my love, what is this unsightly URL that I see?
    printf("Romeo: Oh Juliet, my love, what is this unsightly URL that I see?\n");
    
    // Juliet: Nay, kind sir, this URL may contain forbidden characters
    printf("Juliet: Nay, kind sir, this URL may contain forbidden characters\n");

    // Romeo: Fear not, fair maiden, for I have just the solution! 
    printf("Romeo: Fear not, fair maiden, for I have just the solution!\n");
	
    // Prompt user for input
    printf("Romeo: Pray tell, what is this URL that needs sanitizing?\n");
    scanf("%s", url);
	
    // Check for forbidden characters
    if(strstr(url, "<") || strstr(url, ">") || strstr(url, "\"") || strstr(url, "'"))
    {
        // Juliet: Alas! These symbols are not allowed in a URL
        printf("Juliet: Alas! These symbols are not allowed in a URL\n");
        
        // Replace forbidden characters with safe alternatives using string manipulation
        for(int i=0; i<strlen(url); i++)
        {
            if(url[i] == '<')
            {
                url[i] = '(';
            }
            else if(url[i] == '>')
            {
                url[i] = ')';
            }
            else if(url[i] == '\"')
            {
                url[i] = '_';
            }
            else if(url[i] == '\'')
            {
                url[i] = '-';
            }
        }
        
        // Romeo: Fear not, for I have purified this URL of all harmful characters!
        printf("Romeo: Fear not, for I have purified this URL of all harmful characters!\n");
        
        // Print purified URL
        printf("Romeo: Behold, the purified URL: %s\n", url);
    }
    else
    {
        // Romeo: This URL is already pure, my love!
        printf("Romeo: This URL is already pure, my love!\n");
        
        // Print original URL
        printf("Romeo: The URL is: %s\n", url);
    }
    
    return 0;
}