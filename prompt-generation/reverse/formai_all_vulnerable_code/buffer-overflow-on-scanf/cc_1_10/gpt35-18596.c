//FormAI DATASET v1.0 Category: Error handling ; Style: medieval
// A Medieval Style C Error Handling Example Program

#include<stdio.h>
#include<string.h>

void king_speech(char* message)
{
    printf("The King Speaks: %s\n", message);
}

int main()
{
    char user_input[100];
    int number, result;
    
    king_speech("Greetings, brave knight! What is thy name?");
    scanf("%s", user_input);
    
    king_speech("Welcome, Sir ");
    printf("%s", user_input);
    printf(", to the court of King Arthur!\n");
    
    king_speech("We have a task for thee. What is the answer to this riddle?");
    king_speech("I am not alive, but I grow; I don't have lungs, but I need air; I don't have a mouth, but water kills me. What am I?");
    scanf("%d", &number);
    
    // Error Handling Start
    if(number != 0 && number != 3 && number != 8)
    {
        char error_message[100];
        sprintf(error_message, "Thou art wrong, Sir %s! Thou hast failed to solve the riddle and bring dishonor to thy name. Begone from my court!", user_input);
        king_speech(error_message);
        return -1;
    }
    // Error Handling End 
    
    king_speech("Well done, Sir ");
    printf("%s", user_input);
    printf("! Thou hast solved the riddle and hast pleased us!");
    
    king_speech("To show our appreciation, we shall grant thee one wish. What shall it be?");
    scanf("%d", &result);
    
    // Error Handling Start
    if(result < 1 || result > 3)
    {
        char error_message[100];
        sprintf(error_message, "Foolish knight! Thou art asking for more wishes? or Thou art asking for something that we cannot give? or Thou art asking for something inappropriate? Thou art not worthy of our favor! Thou art hereby banished from our kingdom!");
        king_speech(error_message);
        return -1;
    }
    // Error Handling End
    
    king_speech("Very well, thy wish shall be granted. Go forth, Sir ");
    printf("%s", user_input);
    printf(", and spread the glory of our kingdom!");
    
    return 0;
}