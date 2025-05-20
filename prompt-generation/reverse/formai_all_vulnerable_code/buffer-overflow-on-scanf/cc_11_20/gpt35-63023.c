//FormAI DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h> 

int main() 
{ 
    char string1[50], string2[50];
    int i, j, count1=0, count2=0, isAnagram=0;
    
    printf("Enter first string: "); 
    scanf("%s", string1);
    printf("Enter second string: ");
    scanf("%s", string2);
    
    // Find length of strings
    for(i=0; string1[i]!='\0'; i++)
        count1++;
    
    for(i=0; string2[i]!='\0'; i++)
        count2++;
    
    // Check if both strings have same length
    if(count1 != count2)
        isAnagram = 0;
    else
    {
        // Sort characters in both strings
        for(i=0; i<count1-1; i++)
        {
            for(j=i+1; j<count1; j++)
            {
                if(string1[i] > string1[j])
                {
                    char temp = string1[i];
                    string1[i] = string1[j];
                    string1[j] = temp;
                }
                
                if(string2[i] > string2[j])
                {
                    char temp = string2[i];
                    string2[i] = string2[j];
                    string2[j] = temp;
                }
            }
        }
        
        // Compare sorted strings
        for(i=0; i<count1; i++)
        {
            if(string1[i] != string2[i])
            {
                isAnagram = 0;
                break;
            }
            else
                isAnagram = 1;
        }
    }
    
    if(isAnagram == 1)
        printf("%s and %s are anagrams.\n", string1, string2);
    else
        printf("%s and %s are not anagrams.\n", string1, string2);
    
    return 0; 
}