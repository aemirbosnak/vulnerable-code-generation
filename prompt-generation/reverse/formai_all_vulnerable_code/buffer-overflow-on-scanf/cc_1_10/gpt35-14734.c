//FormAI DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h> 
#include <string.h> 

int main() { 
    // Declare variables
    char message[] = "Hello! Let's spread happiness together!";
    char name[20];
    int age;
    
    // Print the message and ask for name and age
    printf("%s\n", message);
    printf("What's your name? ");
    scanf("%s", name);
    printf("How old are you? ");
    scanf("%d", &age);
    
    // Greet the user with their name and age
    printf("\nHi %s! It's nice to meet someone who is %d years old and ready to spread some happiness.\n", name, age);
    
    // Manipulate the message and print it out
    int length = strlen(message);
    char newMessage[length+1];
    strcpy(newMessage, message);
    newMessage[6] = ',';
    newMessage[19] = '_';
    newMessage[27] = '@';
    
    printf("\nLet's make the message happier...\n");
    printf("%s\n", newMessage);
    
    // Get user input to add to message
    char hobby[20];
    printf("\nWhat is your favorite hobby? ");
    scanf("%s", hobby);
    
    // Concatenate the user's hobby to the original message and print it out
    strcat(message, " ");
    strcat(message, hobby);
    printf("\nYou know what would make this message even happier? Adding your favorite hobby to it.\n");
    printf("%s\n", message);
    
    // Replace a word in the message with the user's name
    char *ptr = strstr(message, "together");
    if (ptr) {
        strncpy(ptr, name, 4);
    }
    printf("\nLet's make this message even happier by replacing a word with your name.\n");
    printf("%s\n", message);
    
    // Reverse the message and print it out
    printf("\nNow, let's flip the message and make it a happy palindrome.\n");
    int i = 0;
    int j = length - 1;
    while (j > i) {
        char temp = message[j];
        message[j] = message[i];
        message[i] = temp;
        i++;
        j--;
    }
    printf("%s\n", message);
    
    printf("\nThanks for spreading happiness with me, %s! Have a great day!\n", name);
    
    return 0; 
}