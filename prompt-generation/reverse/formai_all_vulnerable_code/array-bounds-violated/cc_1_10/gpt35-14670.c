//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
/*The following is a Spam Detection System Program written in Ada Lovelace style*/
#include <stdio.h>
#include <string.h>

#define MAX_MESSAGES 100 // Maximum number of messages to check
#define MAX_LENGTH 1000 // Maximum length of a message

// Function to check if a message is spam or not
int is_spam(char message[MAX_LENGTH])
{
    char spam_words[][20] = {"buy", "discount", "free", "money", "win"}; // Array of commonly used spam words
    int num_words = 5; // Number of words in the spam_words array
    int i, j;

    // Convert all characters to lower case for case-insensitive checking
    for(i = 0; message[i]; i++)
    {
        message[i] = tolower(message[i]); 
    }

    // Check if any of the spam words are present in the message
    for(i = 0; i < num_words; i++)
    {
        if(strstr(message, spam_words[i]) != NULL)
        {
            return 1; // Message is spam
        }
    }

    return 0; // Message is not spam
}

int main()
{
    char messages[MAX_MESSAGES][MAX_LENGTH]; // Array to store all the messages

    int i, num_messages; 

    printf("Enter the number of messages to check: ");
    scanf("%d", &num_messages); 

    // Read all the messages
    for(i = 0; i < num_messages; i++)
    {
        printf("Enter message %d: ", i+1);
        getchar(); // Read the newline character left by scanf
        fgets(messages[i], MAX_LENGTH, stdin); // Read the message
        messages[i][strlen(messages[i])-1] = '\0'; // Remove the newline character
    }

    printf("\nMessages:\n");

    // Print all the messages
    for(i = 0; i < num_messages; i++)
    {
        printf("%d. %s\n", i+1, messages[i]); 
    }

    printf("\nResults:\n");

    // Check if each message is spam or not
    for(i = 0; i < num_messages; i++)
    {
        if(is_spam(messages[i]))
        {
            printf("%d. Spam\n", i+1);
        }
        else
        {
            printf("%d. Not spam\n", i+1);
        }
    }

    return 0;
}