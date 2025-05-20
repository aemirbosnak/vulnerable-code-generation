//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Detect if a message contains suspicious indicators
int detect_spam(char *message) {
    // Initialize counters
    int caps_count = 0, exclamation_count = 0, special_chars = 0, number_count = 0;
    
    // Iterate through the message
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        
        // Check for uppercase letters
        if (isupper(c)) { caps_count++; }
        
        // Check for exclamation marks
        if (c == '!' || c == '?') { exclamation_count++; }
        
        // Check for special characters
        if (!isalnum(c) && c != ' ' && c != '.' && c != ',') { special_chars++; }
        
        // Check for numbers
        if (isdigit(c)) { number_count++; }
    }
    
    // Calculate the spam probability
    int score = (caps_count + exclamation_count + special_chars) - (number_count / 5);
    
    // Return the result
    return (score >= 2);
}

int main() {
    // Get the message from the user
    char message[1000];
    printf("Enter the message to check: ");
    scanf("%[^\n]", message);
    
    // Detect spam
    int is_spam = detect_spam(message);
    
    // Display the result
    if (is_spam) {
        printf("Oh no! This message might be spam.\n");
    } else {
        printf("Phew! This message seems legit.\n");
    }
    
    return 0;
}