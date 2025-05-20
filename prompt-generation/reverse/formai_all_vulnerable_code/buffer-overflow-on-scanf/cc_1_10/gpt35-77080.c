//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_URL_LEN 100
 
// Function to sanitize the URL
char* sanitize(char url[])
{
    char *temp = (char *)malloc(sizeof(char) * MAX_URL_LEN);
    int i = 0, j = 0;
 
    // Loop through the URL string
    while (url[i])
    {
        // If the character is alphanumeric
        if ((url[i] >= '0' && url[i] <= '9') ||
            (url[i] >= 'A' && url[i] <= 'Z') ||
            (url[i] >= 'a' && url[i] <= 'z'))
        {
            // Copy the character to temp string
            temp[j++] = url[i];
        }
        // If the character is a hyphen or dot
        else if (url[i] == '-' || url[i] == '.')
        {
            // Copy the character to temp string
            temp[j++] = url[i];
        }
        // Else ignore the character
        i++;
    }
 
    // Null terminate the temp string
    temp[j] = '\0';
 
    // Return the sanitized URL
    return temp;
}
 
int main()
{
    char url[MAX_URL_LEN];
 
    // Get input URL from user
    printf("Enter the URL: ");
    scanf("%s", url);
 
    // Call the sanitize function to sanitize the URL
    char *sanitized = sanitize(url);
 
    // Print the sanitized URL
    printf("\nSanitized URL: %s\n", sanitized);
 
    free(sanitized);
 
    return 0;
}