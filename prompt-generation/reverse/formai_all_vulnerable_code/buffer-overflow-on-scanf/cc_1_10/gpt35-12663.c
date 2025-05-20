//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <string.h>

// Function to sanitize the URL
char* sanitize_url(char* url) {
    // Initialize variables
    int i, j; 
    char* sanitized_url = (char*)malloc(strlen(url) + 1);
    
    // Check if memory allocation was successful
    if(sanitized_url == NULL) {
        printf("Memory allocation failed!");
        return NULL;
    }
    
    // Loop through each character in the URL
    for(i = 0, j = 0; i < strlen(url); i++) {
        // Check if the character is a valid character in a URL
        if((url[i] >= 'a' && url[i] <= 'z') || 
           (url[i] >= 'A' && url[i] <= 'Z') ||
           (url[i] >= '0' && url[i] <= '9') ||
           url[i] == '-' || url[i] == '_' || 
           url[i] == '.' || url[i] == '/') {
            sanitized_url[j++] = url[i];
        }
    }
    
    // Add the null terminator
    sanitized_url[j] = '\0';
    
    // Return the sanitized URL
    return sanitized_url;
}

int main(int argc, char const *argv[]) {
    // Get the URL from the user
    char* url;
    printf("Enter the URL: ");
    scanf("%s", url);
    
    // Sanitize the URL
    char* sanitized_url = sanitize_url(url);
    
    // Print the sanitized URL
    printf("The sanitized URL is: %s\n", sanitized_url);
    
    // Free the memory allocated for the sanitized URL
    free(sanitized_url);
    
    return 0;
}