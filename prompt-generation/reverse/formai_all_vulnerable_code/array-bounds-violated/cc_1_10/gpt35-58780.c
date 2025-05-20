//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Donald Knuth
/* 
 * Spam Detection System 
 *  
 * This program checks for email spam by analyzing the text and 
 * identifying certain keywords and phrases that are commonly 
 * associated with spam messages. 
 * 
 * Algorithm: 
 * 1. Tokenize the message into words. 
 * 2. Check for certain keywords and phrases 
 * 3. If a certain threshold of spam keywords/phrases is reached, 
 *    classify the message as spam. 
 * 
 * Written by [Your Name] 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Function to tokenize the message into words 
char** tokenize(char* message) { 
    char** tokens = (char**)malloc(sizeof(char*) * 100); 
    char* token = strtok(message, " "); 
    int i = 0; 

    while (token != NULL) { 
        tokens[i++] = token; 
        token = strtok(NULL, " "); 
    } 

    tokens[i] = NULL; 
    return tokens; 
} 

// Spam keywords and phrases 
const char* spamKeywords[] = { 
    "Congratulations!", 
    "Act Now", 
    "Limited Time", 
    "Money Back Guarantee", 
    "$$$", 
    "Free", 
    "Buy Now", 
    "Double Your", 
    "Offer" 
}; 

// Function to check if a message is spam 
int isSpam(char* message) { 
    int count = 0; 

    // Tokenize the message into words 
    char** tokens = tokenize(message); 

    // Check each token against the spam keywords 
    for (int i = 0; tokens[i] != NULL; i++) { 
        for (int j = 0; j < sizeof(spamKeywords) / sizeof(spamKeywords[0]); j++) { 
            if (strcmp(tokens[i], spamKeywords[j]) == 0) { 
                count++; 
                break; 
            } 
        } 
    } 

    // If enough spam keywords were found, classify as spam 
    if ((double)count / sizeof(spamKeywords) >= 0.5) { 
        return 1; 
    } 

    return 0; 
} 

int main() { 
    char message[1000]; 

    // Prompt the user for a message 
    printf("Enter a message: "); 
    fgets(message, 1000, stdin); 

    // Remove the newline character from the end of the message 
    message[strlen(message) - 1] = '\0'; 

    // Check if the message is spam 
    if (isSpam(message)) { 
        printf("This message is spam.\n"); 
    } else { 
        printf("This message is not spam.\n"); 
    } 

    return 0; 
}