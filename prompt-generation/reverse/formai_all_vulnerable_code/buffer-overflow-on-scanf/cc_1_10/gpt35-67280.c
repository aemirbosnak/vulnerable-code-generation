//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* convertToUpper(char* str)
{
    char* result = malloc(strlen(str) + 1);
    strcpy(result, str);
    
    for(int i=0; i<strlen(result); i++)
    {
        result[i] = toupper(result[i]);
    }
    
    return result;
}

char* convertToLower(char* str)
{
    char* result = malloc(strlen(str) + 1);
    strcpy(result, str);
    
    for(int i=0; i<strlen(result); i++)
    {
        result[i] = tolower(result[i]);
    }
    
    return result;
}

char* convertToTitleCase(char* str)
{
    char* result = malloc(strlen(str) + 1);
    strcpy(result, str);
    
    result[0] = toupper(result[0]);
    
    for(int i=1; i<strlen(result); i++)
    {
        if(result[i-1] == ' ')
        {
            result[i] = toupper(result[i]);
        }
        else
        {
            result[i] = tolower(result[i]);
        }
    }
    
    return result;
}

char* convertToSentenceCase(char* str)
{
    char* result = malloc(strlen(str) + 1);
    strcpy(result, str);
    
    if(strlen(result) > 0)
    {
        result[0] = toupper(result[0]);
    }
    
    return result;
}

void handleRequest(char* str, char* type)
{
    char* result;
    
    if(strcmp(type, "UPPER") == 0)
    {
        result = convertToUpper(str);
    }
    else if(strcmp(type, "LOWER") == 0)
    {
        result = convertToLower(str);
    }
    else if(strcmp(type, "TITLE") == 0)
    {
        result = convertToTitleCase(str);
    }
    else if(strcmp(type, "SENTENCE") == 0)
    {
        result = convertToSentenceCase(str);
    }
    else
    {
        printf("Invalid type.\n");
        return;
    }
    
    printf("Result: %s\n", result);
    free(result);
}

int main(void)
{
    char input[100];
    char type[10];
    
    printf("Enter input string: ");
    scanf("%[^\n]s", input);
    getchar();
    
    printf("Enter type (UPPER, LOWER, TITLE, SENTENCE): ");
    scanf("%s", type);
    getchar();
    
    handleRequest(input, type);
    
    return 0;
}