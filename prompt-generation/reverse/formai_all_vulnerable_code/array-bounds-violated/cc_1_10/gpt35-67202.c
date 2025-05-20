//FormAI DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char name[50];
    char title[20];
    char greeting[100];
    char message[200];
    int name_len, title_len;
    
    // Getting the user's name
    printf("Greetings, traveller! What is thy name?\n");
    fgets(name, 50, stdin);
    name_len = strlen(name);
    
    // Removing the newline character from the user's name
    if (name[name_len - 1] == '\n')
    {
        name[name_len - 1] = '\0'; 
        name_len--; 
    }
    
    // Getting the user's title
    printf("And what is thy title, %s?\n", name);
    fgets(title, 20, stdin);
    title_len = strlen(title);
    
    // Removing the newline character from the user's title
    if (title[title_len - 1] == '\n')
    {
        title[title_len - 1] = '\0'; 
        title_len--; 
    }
    
    // Creating the greeting message
    snprintf(greeting, 100, "Greetings, %s %s! Thou art most welcome.", title, name);
    
    // Printing the greeting message
    printf("%s\n", greeting);
    
    // Asking the user for a message to manipulate
    printf("What message dost thou wish to manipulate, %s?\n", title);
    fgets(message, 200, stdin);
    
    // Reversing the message
    int i;
    int message_len = strlen(message);
    for (i = 0; i < message_len / 2; i++)
    {
        char temp = message[i];
        message[i] = message[message_len - i - 1];
        message[message_len - i - 1] = temp;
    }
    
    // Encoding the message with a simple substitution cipher
    for (i = 0; i < message_len; i++)
    {
        char c = message[i];
        if (c >= 'a' && c <= 'z')
        {
            message[i] = 'a' + (c - 'a' + 3) % 26;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            message[i] = 'A' + (c - 'A' + 3) % 26;
        }
    }
    
    // Printing the manipulated message
    printf("Here is thy manipulated message, %s:\n%s", title, message);
    
    return 0;
}